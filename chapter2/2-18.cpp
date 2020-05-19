#include <opencv2/opencv.hpp>
#include <opencv2/core/core_c.h>

using namespace std;
using namespace cv;

int main()
{
    CvMat *pA = cvCreateMat(2,3,CV_32FC1);
    Ptr<CvMat> matA(pA);

    CV_MAT_ELEM(*matA, float,0,0) = 1.0f;
    CV_MAT_ELEM(*matA, float,0,1) = 2.0f;
    CV_MAT_ELEM(*matA, float,0,2) = 3.0f;
    CV_MAT_ELEM(*matA, float,1,0) = 4.0f;
    CV_MAT_ELEM(*matA, float,1,1) = 5.0f;
    CV_MAT_ELEM(*matA, float,1,2) = 6.0f;

    Mat A = cvarrToMat(matA);
    cout << "A= " << A << endl;

    Ptr<FILE> outFile(fopen("matA.txt","w"));

    if(outFile.empty())
    {
        return -1;
    }
    int x,y;
    for(y=0; y<matA->rows; y++){
        for(x=0; x<matA->cols; x++){
            fprintf(outFile,"%6.2f",cvmGet(matA,y,x));
            fprintf(outFile,"%6.2f",*(float*)cvPtr2D(matA,y,x));
            fprintf(outFile,"%6.2f",CV_MAT_ELEM(*matA,float,y,x));
            int k = y*matA -> cols+x;
            fprintf(outFile,"%6.2f",matA->data.fl[k]);
        }
        fprintf(outFile,"\n");
    }

    return 0;
}