#include "WhiteBoardRectangle.h"

WhiteBoardRectangle::WhiteBoardRectangle(Mat image, WhiteBoardCorners whiteBoardCorners)
{
	Point* upperLeft = whiteBoardCorners.getUpperLeft();
	Point* upperRight = whiteBoardCorners.getUpperRight();
	Point* bottomLeft = whiteBoardCorners.getBottomLeft();
	Point* bottomRight = whiteBoardCorners.getBottomRight();

	if (upperLeft == NULL && upperRight == NULL && bottomLeft == NULL && bottomRight == NULL)
	{
		return;
	}

	int startingX = 0;
	int startingY = 0;
	int finalX = image.cols - 1;
	int finalY = image.rows - 1;

	if (upperLeft || bottomLeft)
	{
		if (upperLeft && bottomLeft)
		{
			startingX = upperLeft->x < bottomLeft->x ? upperLeft->x : bottomLeft->x;
		}
		else
		{
			startingX = upperLeft ? upperLeft->x : bottomLeft->x;
		}
	}

	if (upperLeft || upperRight)
	{
		if (upperLeft && upperRight)
		{
			startingY = upperLeft->y < upperRight->y ? upperLeft->y : upperRight->y;
		}
		else
		{
			startingY = upperLeft ? upperLeft->y : upperRight->y;
		}
	}

	if (upperRight || bottomRight)
	{
		if (upperRight && bottomRight)
		{
			finalX = upperRight->x > bottomRight->x ? upperRight->x : bottomRight->x;
		}
		else
		{
			finalX = upperRight ? upperRight->x : bottomRight->x;
		}
	}

	if (bottomLeft || bottomRight)
	{
		if (bottomLeft && bottomRight)
		{
			finalY = bottomLeft->y > bottomRight->y ? bottomLeft->y : bottomRight->y;
		}
		else
		{
			finalY = bottomLeft ? bottomLeft->y : bottomRight->y;
		}
	}

	x = startingX;
	y = startingY;
	width = finalX - startingX;
	height = finalY - startingY;
}
