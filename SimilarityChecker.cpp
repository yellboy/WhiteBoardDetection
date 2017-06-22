#include "SimilarityChecker.h"

SimilarityChecker::SimilarityChecker(Mat originalImage, Mat templateImage)
{
	originalImage.copyTo(this->originalImage);
	templateImage.copyTo(this->templateImage);

	resize(this->templateImage, this->templateImage, this->originalImage.size());

	cvtColor(this->originalImage, this->originalImage, CV_BGR2HSV);
	cvtColor(this->templateImage, this->templateImage, CV_BGR2HSV);

}

double SimilarityChecker::checkSimilarity()
{
	int rows = originalImage.rows < templateImage.rows ? originalImage.rows : templateImage.rows;
	int cols = originalImage.cols < templateImage.cols ? originalImage.cols : templateImage.cols;

	int count = 0;

	for (int x = 0; x < cols; x++)
	{
		for (int y = 0; y < rows; y++)
		{
			Point p(x, y);

			Scalar pixel1 = originalImage.at<Vec3b>(p);
			Scalar pixel2 = templateImage.at<Vec3b>(p);

			if (fabs(pixel1.val[0] - pixel2.val[0]) <= 20)
			{
				count++;
			}
		}
	}

	return ((double)count) / (rows * cols);
}
