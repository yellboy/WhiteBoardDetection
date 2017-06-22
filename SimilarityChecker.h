#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class SimilarityChecker
{
private:
	Mat originalImage;
	Mat templateImage;
public:
	SimilarityChecker(Mat originalImage, Mat templateImage);
	double checkSimilarity();
};