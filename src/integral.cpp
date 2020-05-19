 #include <opencv2/opencv.hpp>

 using namespace std;
 using namespace cv;

 int main()
 {
    Mat img = Mat(10,10,CV_8UC1);
    randu(img,0,10);

    cout << img << endl;

    int x=3, y=4, w=4, h=4;

    int sum = 0;
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<h; j++)
        {
            sum = sum + img.at<unsigned char>((y+j),(x+i));
        }
    }
    cout << sum << endl;

    Mat intergrallmg;
    integral(img,intergrallmg,CV_64F);
    cout <<  intergrallmg << endl;

    double p1 = intergrallmg.at<double>((y),(x));
    double p2 = intergrallmg.at<double>((y),(x+w));
    double p3 = intergrallmg.at<double>((y+h),(x));
    double p4 = intergrallmg.at<double>((y+h),(x+w));

    cout << p1 << "," << p2 << "," << p3 << "," << p4 << endl;
    cout << (p1+p4) - (p2+p3) << endl;

    return 0;
 }