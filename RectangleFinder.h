#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class RectangleFinder
{
private:
	Mat image;
	vector<vector<Point>> foundContours;
	vector<Vec4i> hierarchy;
	bool isRectangle(vector<Point> contour);
	bool areSimilar(vector<Point> contour1, vector<Point> contour2);
	bool isSimilarWithAnyContour(vector<vector<Point>> contoursVector, vector<Point> contour);
public:
	RectangleFinder(Mat image);
	void find();
	vector<vector<Point>> getFoundContours();
	vector<Vec4i> getHierarchy();
};