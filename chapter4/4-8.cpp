#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat A = (Mat_<uchar>(2,3)<<0,50,100,150,200,255);
    cout << "A = " << A << endl;

    Mat_<uchar> lut(1,256);
    for(int i=0; i<256; i++){
        lut(i) = 255 - i;
    }
    cout << "lut = " << lut << endl;

    Mat dst;
    LUT(A,lut,dst);
    cout << "dst =" << dst << endl;
    return 0;
}
