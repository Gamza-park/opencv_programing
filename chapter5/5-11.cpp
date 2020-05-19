#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
int main()
{
    Mat src = imread("/home/park/opencv_programing/chapter5/lena.jpg");
    if(src.empty())
    {
        return -1;
    }

    int histSize[] = {64,64};
    float range1[] = {0,256};
    float range2[] = {0,256};

    const float* ranges[] = {range1,range2};
    const int channels[] = {0,1};
    int dims = 2;

    Mat hist;
    calcHist(&src,1,channels,Mat(),hist,dims,histSize,ranges);
    cout << "hist.size() = " << hist.size() << endl;
    normalize(hist,hist,0,255,NORM_MINMAX,CV_32F);
    Mat img(512,512,CV_8U,Scalar(255));
    int binW = cvRound((double)img.cols / histSize[1]);
    int binH = cvRound((double)img.rows/histSize[0]);

    int x,y;
    Rect rt;
    Mat roi;
    for(int i=0; i<histSize[1]; i++)
    {
        for(int j=0; j<histSize[0]; j++){
            float hValue = hist.at<float>(j,i);
            x = i*binW;
            y = j*binH;
            rt = Rect(x,y,binW,binH);
            img(rt) = hValue;
        }
    }

    imshow("img",img);
    waitKey();

    return 0;
}