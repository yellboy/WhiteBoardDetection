#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "RectangularContour.h"
#include "RectangleFinder.h"
#include "SimilarityChecker.h"
#include "WhiteBoardCorners.h"

using namespace std;
using namespace cv;

const string INPUT_IMAGE_PATH = "C:\\Temp\\input\\image.jpg";
const string TEMPLATE1_IMAGE_PATH = "C:\\Temp\\input\\template1.jpg";
const string TEMPLATE2_IMAGE_PATH = "C:\\Temp\\input\\template2.jpg";
const string TEMPLATE3_IMAGE_PATH = "C:\\Temp\\input\\template3.jpg";
const string TEMPLATE4_IMAGE_PATH = "C:\\Temp\\input\\template4.jpg";
const string OUTPUT_IMAGE_PATH = "C:\\Temp\\output\\image.jpg";
const string CONTOURED_IMAGE_PATH = "C:\\Temp\\output\\contours.jpg";

void deskew(double angle, vector<Point> points, Mat image)
{
	RotatedRect box = minAreaRect(Mat(points));
	Mat rot_mat = getRotationMatrix2D(box.center, angle, 1);

	warpAffine(image, image, rot_mat, image.size(), INTER_CUBIC);
}

double findAngle(Point point1, Point point2)
{
	int dx = point1.x - point2.x;
	int dy = point1.y - point2.y;

	double arctg = fabs(dx) > fabs(dy) ? atan(double(dy) / dx) : atan(double(dx) / dy);

	return arctg * 360 / (2 * M_PI);
}

void rotateImageAccordingToRectangularContour(Mat image, RectangularContour rectangularContour)
{
	double angle1 = findAngle(rectangularContour.getUpperLeft(), rectangularContour.getUpperRight());
	double angle2 = findAngle(rectangularContour.getUpperRight(), rectangularContour.getBottomRight());
	double angle3 = findAngle(rectangularContour.getBottomRight(), rectangularContour.getBottomLeft());
	double angle4 = findAngle(rectangularContour.getBottomLeft(), rectangularContour.getUpperLeft());

	double angle = (angle1 + angle2 + angle3 + angle4) / 4;
	
	deskew(angle, rectangularContour.getContour(), image);
}

WhiteBoardCorners findCorners(Mat image, vector<vector<Point>> contours, Mat templ1, Mat templ2, Mat templ3, Mat templ4)
{
	vector<RectangularContour> rectangularContours = RectangularContour::contourVectorToRectangularContourVector(contours);

	double maxSimilarity1 = 0;
	double maxSimilarity2 = 0;
	double maxSimilarity3 = 0;
	double maxSimilarity4 = 0;

	int similarityIndex1 = -1;
	int similarityIndex2 = -1;
	int similarityIndex3 = -1;
	int similarityIndex4 = -1;

	WhiteBoardCorners whiteBoardCorners;

	for (int i = 0; i < rectangularContours.size(); i++)
	{
		Mat temporaryImage;
		image.copyTo(temporaryImage);

		rotateImageAccordingToRectangularContour(temporaryImage, rectangularContours[i]);

		int startingX = rectangularContours[i].getUpperLeft().x < rectangularContours[i].getBottomLeft().x ? rectangularContours[i].getUpperLeft().x : rectangularContours[i].getBottomLeft().x;
		int startingY = rectangularContours[i].getUpperLeft().y < rectangularContours[i].getUpperRight().y ? rectangularContours[i].getUpperLeft().y : rectangularContours[i].getUpperRight().y;
		int finalX = rectangularContours[i].getUpperRight().x > rectangularContours[i].getBottomRight().x ? rectangularContours[i].getUpperRight().x : rectangularContours[i].getBottomRight().x;
		int finalY = rectangularContours[i].getBottomLeft().y > rectangularContours[i].getBottomRight().y ? rectangularContours[i].getBottomLeft().y : rectangularContours[i].getBottomRight().y;
	
		temporaryImage = temporaryImage(Rect(startingX, startingY, finalX - startingX, finalY - startingY));

		SimilarityChecker similarityChecker1(temporaryImage, templ1);
		double similarity1 = similarityChecker1.checkSimilarity();
		if (similarity1 > 0.5 && similarity1 > maxSimilarity1)
		{
			maxSimilarity1 = similarity1;
			similarityIndex1 = i;
		}

		SimilarityChecker similarityChecker2(temporaryImage, templ2);
		double similarity2 = similarityChecker2.checkSimilarity(); 
		if (similarity2 > 0.5 && similarity2 > maxSimilarity2)
		{
			maxSimilarity2 = similarity2;
			similarityIndex2 = i;
		}

		SimilarityChecker similarityChecker3(temporaryImage, templ3);
		double similarity3 = similarityChecker3.checkSimilarity();
		if (similarity3 > 0.5 && similarity3 > maxSimilarity3)
		{
			maxSimilarity3 = similarity3;
			similarityIndex3 = i;
		}

		SimilarityChecker similarityChecker4(temporaryImage, templ4);
		double similarity4 = similarityChecker4.checkSimilarity();
		if (similarity4 > 0.5 && similarity4 > maxSimilarity4)
		{
			maxSimilarity4 = similarity4;
			similarityIndex4 = i;
		}
	}

	if (similarityIndex1 != -1)
	{
		whiteBoardCorners.setUpperLeft(rectangularContours[similarityIndex1].getUpperLeft());
	}
	if (similarityIndex2 != -1)
	{
		whiteBoardCorners.setUpperRight(rectangularContours[similarityIndex2].getUpperRight());
	}
	if (similarityIndex3 != -1)
	{
		whiteBoardCorners.setBottomLeft(rectangularContours[similarityIndex3].getBottomLeft());
	}
	if (similarityIndex4 != -1)
	{
		whiteBoardCorners.setBottomRight(rectangularContours[similarityIndex1].getBottomRight());
	}

	return whiteBoardCorners;
}

void main()
{
	Mat image = imread(INPUT_IMAGE_PATH, IMREAD_COLOR);
	Mat imageCopy = imread(INPUT_IMAGE_PATH, IMREAD_GRAYSCALE);

	Mat templ1 = imread(TEMPLATE1_IMAGE_PATH, IMREAD_COLOR);
	Mat templ2 = imread(TEMPLATE2_IMAGE_PATH, IMREAD_COLOR);
	Mat templ3 = imread(TEMPLATE3_IMAGE_PATH, IMREAD_COLOR);
	Mat templ4 = imread(TEMPLATE4_IMAGE_PATH, IMREAD_COLOR);

	RectangleFinder rectangleFinder(imageCopy);
	rectangleFinder.find();
	vector<vector<Point>> rectangularContours = rectangleFinder.getFoundContours();
	vector<Vec4i> hierarchy = rectangleFinder.getHierarchy();

	Mat counturedImage = Mat::zeros(image.size(), CV_8UC3);
	drawContours(counturedImage, rectangularContours, -1, Scalar(0, 255, 0), 2, LINE_AA, hierarchy);

	imwrite(CONTOURED_IMAGE_PATH, counturedImage);

	WhiteBoardCorners corners = findCorners(image, rectangularContours, templ1, templ2, templ3, templ4);
	WhiteBoardRectangle rectangle(image, corners);

	rotateImageAccordingToRectangularContour(image, RectangularContour(rectangle));

	image = image(Rect(rectangle.getX(), rectangle.getY(), rectangle.getWidth(), rectangle.getHeight()));
	imwrite(OUTPUT_IMAGE_PATH, image);
}