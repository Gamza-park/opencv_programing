#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;

int main(){
    Mat image = imread("/home/park/opencv_programing/chapter4/lena.jpg",IMREAD_COLOR);
    Mat matA = Mat(image);

    Mat matB;
    flip(matA, matB,0);
    imshow("flip img1",matB);

    Mat matC;
    flip(matA,matC,1);
    imshow("flip img2",matC);
    
    waitKey();
    return 0;
}
