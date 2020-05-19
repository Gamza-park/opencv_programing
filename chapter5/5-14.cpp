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

    int histSize[] = { L };
    float valueRange[] = {0,L};
    const float* ranges[] = {valueRange};
    int channels[] = {0};
    int dims = 1;

    Mat hist;
    calcHist(&src,1,channels,Mat(),hist,dims,histSize,ranges,true);
    Mat pdf;
    normalize(hist,pdf,L-1,0,NORM_L1);

    Mat cdf(pdf.size(),pdf.type());
    cdf.at<float>(0) = pdf.at<float>(0);
    for(int i=1 ; i<pdf.rows; i++);
    {
        cdf.at<float>(i)=cdf.at<float>(i-1)+pdf.at<float>(i);
    }
    cout << "cdf = " << cdf << endl;

    Mat table(cdf.size(),CV_8U);
    table.at<uchar>(0)=0;
    for(int i =1; i<pdf.rows; i++)
    {
        table.at<uchar>(i) = cvRound(cdf.at<float>(i));
    }
    
    Mat dst;
    LUT(src,table,dst);

    vector<int>params;
    params.push_back(IMWRITE_JPEG_QUALITY);
    params.push_back(100);
    imwrite("img.jpg",dst,params);

    imshow("dst",dst);
    waitKey();

    return 0;
}