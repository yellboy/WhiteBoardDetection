#pragma once
#include "opencv2\core.hpp"

using namespace cv;
using namespace std;

class WhiteBoardCorners
{
private:
	Point* upperLeft = NULL;
	Point* bottomLeft = NULL;
	Point* bottomRight = NULL;
	Point* upperRight = NULL;
public:
	void setUpperLeft(Point upperLeft);
	void setBottomLeft(Point bottomLeft);
	void setBottomRight(Point bottomRight);
	void setUpperRight(Point upperRight);

	Point* getUpperLeft();
	Point* getBottomLeft();
	Point* getBottomRight();
	Point* getUpperRight();
};