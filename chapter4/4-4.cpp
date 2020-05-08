#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter4/lena.jpg");
    if(src.empty()){
        return -1;
    }

    vector<Mat> planes;
    split(src,planes);

    imshow("planes[0]",planes[0]);
    imshow("planes[1]",planes[1]);
    imshow("planes[2]",planes[2]);
    
    Mat dst;
    merge(planes,dst);
    
    imshow("dst",dst);
    waitKey();
    return 0;
}
