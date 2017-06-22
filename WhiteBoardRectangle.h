#pragma once
#include "opencv2\core.hpp"
#include "WhiteBoardCorners.h"

using namespace cv;
using namespace std;

class WhiteBoardRectangle
{
private:
	int x;
	int y;
	int width;
	int height;
public:
	WhiteBoardRectangle(int x, int y, int width, int height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
	
	WhiteBoardRectangle(Mat image, WhiteBoardCorners whiteBoardCorners);

	int getX()
	{
		return x;
	}
	
	int getY()
	{
		return y;
	}
	
	int getWidth()
	{
		return width;
	}
	
	int getHeight()
	{
		return height;
	}
};