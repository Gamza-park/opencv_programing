#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat A(3,3,CV_32F);
    int idx[2];
    for(int i=0; i<A.rows; i++){
        for(int j=0; j<A.cols; j++){
            A.at<float>(i,j) = i*A.cols +j;
            A.at<float>(Point(i,j)) = i * A.cols + j;

            idx[0] = i;
            A.at<float>(idx) = i*A.cols+j;
        }
    }
    cout << "A = " << A << endl;

    int nSum = 0;
    for(int i=0; i<A.rows; i++){
        for(int j=0; j<A.cols; j++){
            nSum += A.at<float>(i,j);

        }
    }

    cout << "nSum = " << nSum << endl;

    
    return 0;
}