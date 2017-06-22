//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <stdio.h>
//#include <math.h>
//
//using namespace std;
//using namespace cv;
//
///// Global Variables
//Mat img; Mat result; Mat img_display;
//char* image_window = "Source Image";
//char* result_window = "Result window";
//const string INPUT_IMAGE_PATH = "C:\\Temp\\input\\image.jpg";
//const string TEMPLATE1_IMAGE_PATH = "C:\\Temp\\input\\template1.jpg";
//const string TEMPLATE2_IMAGE_PATH = "C:\\Temp\\input\\template2.jpg";
//const string TEMPLATE3_IMAGE_PATH = "C:\\Temp\\input\\template3.jpg";
//const string TEMPLATE4_IMAGE_PATH = "C:\\Temp\\input\\template4.jpg";
//const string OUTPUT_IMAGE_PATH = "C:\\Temp\\output\\image.jpg";
//
//int match_method;
//int max_Trackbar = 5;
//
///// Function Headers
//Point MatchingMethod(int, void*, Mat);
//
//RotatedRect deskew(double angle, Point upperLeft, Point bottomRight)
//{
//	vector<Point> points;
//	points.push_back(upperLeft);
//	points.push_back(bottomRight);
//	RotatedRect box = minAreaRect(Mat(points));
//	Mat rot_mat = getRotationMatrix2D(box.center, angle, 1);
//
//	warpAffine(img_display, img_display, rot_mat, img_display.size(), INTER_CUBIC);
//
//	return box;
//}
//
//void crop(RotatedRect box) 
//{
//	cv::Size box_size = box.size;
//	if (box.angle < -45.)
//		std::swap(box_size.width, box_size.height);
//	cv::Mat cropped;
//	cv::getRectSubPix(img_display, box_size, box.center, cropped);
//}
//
///** @function main */
//int main(int argc, char** argv)
//{
//	/// Load image and template
//	img = imread(INPUT_IMAGE_PATH, COLORMAP_RAINBOW);
//	Mat templ1 = imread(TEMPLATE1_IMAGE_PATH, IMREAD_COLOR);
//	Mat templ2 = imread(TEMPLATE2_IMAGE_PATH, IMREAD_COLOR);
//	Mat templ3 = imread(TEMPLATE3_IMAGE_PATH, IMREAD_COLOR);
//	Mat templ4 = imread(TEMPLATE4_IMAGE_PATH, IMREAD_COLOR);
//
//	/// Source image to display
//	img.copyTo(img_display);
//
//	Point upperLeft = MatchingMethod(0, 0, templ1);
//	/*Point upperRight = MatchingMethod(0, 0, templ2);
//	Point bottomLeft = MatchingMethod(0, 0, templ3);
//	Point bottomRight = MatchingMethod(0, 0, templ4);*/
//	
//	//upperRight.x += templ2.cols;
//	//
//	//bottomLeft.y += templ3.rows;
//
//	//bottomRight.x += templ4.cols;
//	//bottomRight.y += templ4.rows;
//
//	//int dx = bottomLeft.x - upperLeft.x;
//	//int dy = bottomLeft.y - upperLeft.y;
//
//	//double angle = atan(double(dx) / dy) * 360 / 6.28;
//
//	//RotatedRect box = deskew(-angle, upperLeft, bottomRight);
//
//	//// TODO Do this for other corners as well
//	//int startingX = upperLeft.x > bottomLeft.x ? upperLeft.x : bottomLeft.x;
//
//	//img_display = img_display(Rect(startingX, upperLeft.y, bottomRight.x - startingX, bottomRight.y - upperLeft.y));
//
//	imwrite(OUTPUT_IMAGE_PATH, img_display);
//k
//	waitKey(0);
//	return 0;
//}
//
//Point MatchingMethod(int x, void* y, Mat templ)
//{
//	/// Create the result matrix
//	int result_cols = img.cols - templ.cols + 1;
//	int result_rows = img.rows - templ.rows + 1;
//
//	result.create(result_rows, result_cols, CV_32FC1);
//
//	/// Do the Matching and Normalize
//	matchTemplate(img, templ, result, match_method);
//	//normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
//
//	/// Localizing the best match with minMaxLoc
//	double minVal; double maxVal; Point minLoc; Point maxLoc;
//	Point matchLoc;
//
//	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
//	if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED)
//	{
//		matchLoc = minLoc;
//	}
//	else
//	{
//		matchLoc = maxLoc;
//	}
//
//	rectangle(img_display, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(0, 255, 0), -1, 8, 0);
//	
//	return matchLoc;
//}