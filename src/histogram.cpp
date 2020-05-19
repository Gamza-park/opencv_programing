#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;


Mat mareHistogram(Mat& img, int t)
{

	//col or row histogram?
	int sz = (t) ? img.rows : img.cols;
	Mat mhist = Mat::zeros(1, sz, CV_8U);

	//count nonzero value and check max V
	int max = -100;
	for (int j = 0; j < sz; ++j)
	{
		Mat data = (t) ? img.row(j) : img.col(j);
		int v = countNonZero(data);
		mhist.at< unsigned char >(j) = v;
		if (v > max)
			max = v;
	}

	Mat histo;
	int width, height;
	if (t)
	{
		width = max;
		height = sz;
		histo = Mat::zeros(Size(width, height), CV_8U);

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < mhist.at< unsigned char >(i); ++j)
				histo.at< unsigned char >(i, j) = 255;
		}

	}
	else {
		width = sz;
		height = max;
		histo = Mat::zeros(Size(width, height), CV_8U);

		for (int i = 0; i< width; ++i)
		{
			for (int j = 0; j< mhist.at< unsigned char >(i); ++j)
				histo.at< unsigned char >(max - j - 1, i) = 255;
		}

	}



	return histo;

}

int main()
{
	Mat img;
	img = imread("/home/park/Opencv_practice/num.png", 0);


	threshold(img, img, 128, 255, THRESH_BINARY);

	//0 horizontal(width), 1 vertical(height)
	Mat hHisto = mareHistogram(img, 0);
	Mat vHisto = mareHistogram(img, 1);


	imshow("origin", img);
	imshow("hh", hHisto);
	imshow("vv", vHisto);

	waitKey(0);
    return 0;
}