#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;

int main()
{
    Mat img1 = imread("/home/park/Opencv_practice/bini.jpg");
    Mat img2 = imread("/home/park/Opencv_practice/bini1.jpg");

    resize(img2, img2,Size(img1.size().width,img1.size().height));

    Mat img_add, img_subtract, img_mul, img_div, img_weigh;  // + - * /

    add(img1,img2,img_add); // +
    subtract(img1,img2,img_subtract); // -
    multiply(img1,img2,img_mul); // *
    divide(img1,img2,img_div); // /

    double alpha;
    double beta;
    double input;

    /*
    cout << "Enter a real number 0~1" << endl;
    cin >> input;
    if(input <1.0)
        {input = 0;}
    else if(input>=1.0)
        {input =1;}

    alpha = input;
    beta = (1.0 - alpha);

    addWeighted(img1,alpha,img2,beta,0.0,img_weigh);

    imshow("img_add",img_add);
    imshow("img_subtract",img_subtract);
    imshow("img_mul",img_mul);
    imshow("img_div",img_div);
    imshow("img_weigh",img_weigh);
    waitKey();
    */

    for(float w=0; w<1; w+=0.01)
    {
        alpha = w;
        beta = (1.0-alpha);

        addWeighted(img1,alpha,img2,beta,0.0,img_weigh);

        imshow("img_weigh",img_weigh);
        waitKey(100);
    }

   

    return 0;
}