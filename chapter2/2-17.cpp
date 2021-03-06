#include <opencv2/opencv.hpp>
#include <opencv2/core/core_c.h>

using namespace std;
using namespace cv;

int main()
{
    Ptr<CvMat> matA(cvCreateMat(2,3,CV_32FC1));

    CV_MAT_ELEM( *matA,float,0,0) = 1.0f;
    CV_MAT_ELEM( *matA,float,0,1) = 2.0f;
    CV_MAT_ELEM( *matA,float,0,2) = 3.0f;

    CV_MAT_ELEM( *matA,float,1,0) = 4.0f;
    CV_MAT_ELEM( *matA,float,1,1) = 5.0f;
    CV_MAT_ELEM( *matA,float,1,2) = 6.0f;

    Mat A = cvarrToMat(matA);
    cout << "A = " << A << endl;

    return 0;
}