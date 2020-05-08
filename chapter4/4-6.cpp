#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat src = imread("/home/park/opencv_programing/chapter4/lena.jpg");
    if(src.empty()){
        return -1;
    }

    vector<Mat> img(1,src);
    vector<Mat> planes(1,Mat(src.rows,src.cols,src.type()));
    int fromTo[] = {0,0,0,1,0,2};
    mixChannels(img,planes,fromTo,3);

    Mat dst = planes[0];
    imshow("dst",dst);
    waitKey();
    return 0;
}
