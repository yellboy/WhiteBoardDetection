#include "RectangularContour.h"

RectangularContour::RectangularContour(WhiteBoardRectangle whiteBoardRectangle)
{
	contour.push_back(Point(whiteBoardRectangle.getX() + whiteBoardRectangle.getWidth(), whiteBoardRectangle.getY()));
	contour.push_back(Point(whiteBoardRectangle.getX() + whiteBoardRectangle.getWidth(), whiteBoardRectangle.getY() + whiteBoardRectangle.getHeight()));
	contour.push_back(Point(whiteBoardRectangle.getX(), whiteBoardRectangle.getY() + whiteBoardRectangle.getHeight()));
	contour.push_back(Point(whiteBoardRectangle.getX(), whiteBoardRectangle.getY()));
}

vector<RectangularContour> RectangularContour::contourVectorToRectangularContourVector(vector<vector<Point>> contourVector)
{
	vector<RectangularContour> rectangularContourVector;

	for (int i = 0; i < contourVector.size(); i++)
	{
		rectangularContourVector.push_back(RectangularContour(contourVector[i]));
	}

	return rectangularContourVector;
}
