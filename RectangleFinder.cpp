#include "RectangleFinder.h"

RectangleFinder::RectangleFinder(Mat image)
{
	this->image = image;
}

void RectangleFinder::find()
{
	medianBlur(image, image, 3);
	Canny(image, image, 1, 10);

	vector<vector<Point>> contours;
	vector<vector<Point>> contours0;
	vector<vector<Point>> rectangularContours;

	findContours(image, contours0, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);

	contours.resize(contours0.size());
	for (size_t k = 0; k < contours0.size(); k++)
	{
		Mat curve(contours0[k]);
		double epsilon = arcLength(curve, true) * 0.15;
		approxPolyDP(curve, contours[k], epsilon, true);

		if (isRectangle(contours[k]))
		{
			if (!isSimilarWithAnyContour(rectangularContours, contours[k]))
			{
				rectangularContours.push_back(contours[k]);
			}
		}
	}

	foundContours = rectangularContours;
}

bool RectangleFinder::isRectangle(vector<Point> contour)
{
	return contour.size() == 4 && fabs(contourArea(Mat(contour))) > 800 && isContourConvex(Mat(contour));
}

bool RectangleFinder::areSimilar(vector<Point> contour1, vector<Point> contour2)
{
	bool contoursAreSimilar = false;
	for (int i = 0; i < contour1.size(); i++)
	{
		bool foundSimilarPoint = false;
		for (int j = 0; j < contour2.size(); j++)
		{
			if (fabs(contour1[i].x - contour2[j].x) <= 5 && fabs(contour1[i].y - contour2[j].y))
			{
				foundSimilarPoint = true;
			}
		}

		if (foundSimilarPoint)
		{
			contoursAreSimilar = true;
		}
	}

	return contoursAreSimilar;
}

vector<vector<Point>> RectangleFinder::getFoundContours()
{
	return foundContours;
}

vector<Vec4i> RectangleFinder::getHierarchy()
{
	return hierarchy;
}

bool RectangleFinder::isSimilarWithAnyContour(vector<vector<Point>> contoursVector, vector<Point> contour)
{
	for (int i = 0; i < contoursVector.size(); i++)
	{
		if (areSimilar(contoursVector[i], contour))
		{
			return true;
		}
	}

	return false;
}
