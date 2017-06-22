#include "WhiteBoardCorners.h"

void WhiteBoardCorners::setUpperLeft(Point upperLeft)
{
	this->upperLeft = new Point(upperLeft);
}

void WhiteBoardCorners::setBottomLeft(Point bottomLeft)
{
	this->bottomLeft = new Point(bottomLeft);
}

void WhiteBoardCorners::setBottomRight(Point bottomRight)
{
	this->bottomRight = new Point(bottomRight);
}

void WhiteBoardCorners::setUpperRight(Point upperRight)
{
	this->upperRight = new Point(upperRight);
}

Point * WhiteBoardCorners::getUpperLeft()
{
	return upperLeft;
}

Point * WhiteBoardCorners::getBottomLeft()
{
	return bottomLeft;
}

Point * WhiteBoardCorners::getBottomRight()
{
	return bottomRight;
}

Point * WhiteBoardCorners::getUpperRight()
{
	return upperRight;
}
