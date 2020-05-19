#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat src;
    src.create(512,512,CV_8UC3);

    for(int i=0; i<src.rows; i++)
    {
        for(int j=0; j<src.cols; j++){
            src.at<Vec3b>(i,j) = Vec3b(255,255,255);
        }
    }

    imshow("src",src);
    waitKey();

    return 0;
}