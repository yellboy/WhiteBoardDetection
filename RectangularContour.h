#pragma once
#include "opencv2\core.hpp"
#include "WhiteBoardRectangle.h"
using namespace cv;
using namespace std;

class RectangularContour
{
private:
	vector<Point> contour;

public:
	RectangularContour(vector<Point> contour)
	{
		this->contour = contour;
	}
	RectangularContour(WhiteBoardRectangle whiteBoardRectangle);

	Point getUpperLeft()
	{
		return contour[3];
	}

	Point getBottomLeft()
	{
		return contour[2];
	}

	Point getBottomRight()
	{
		return contour[1];
	}

	Point getUpperRight()
	{
		return contour[0];
	}

	vector<Point> getContour()
	{
		return contour;
	}

	static vector<RectangularContour> contourVectorToRectangularContourVector(vector<vector<Point>> contour);
};