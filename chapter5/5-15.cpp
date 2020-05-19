#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main()
{
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg",IMREAD_GRAYSCALE);
    if(src.empty())
    {
        return -1;
    }

    Mat dst;
    equalizeHist(src,dst);

    vector<int> params;
    params.push_back(IMWRITE_JPEG_QUALITY);
    params.push_back(100);
    imwrite("imageEq2.jpg",dst,params);

    imshow("dst",dst);
    waitKey();

    return 0;
}