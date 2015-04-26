#include <stdio.h>
#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

double alpha; // For contrast control
double beta; // For brightness control

int main( int argc, char** argv){

    Mat src, final;
    src = imread( argv[1], CV_LOAD_IMAGE_COLOR);
    final = Mat::zeros(src.size(), src.type());
    cout << "Enter the value of alpha[1.0 - 3.0]: ";
    cin >> alpha;
    cout << "Enter the value of beta[0.0 - 100.0]: ";
    cin >> beta;
    for(int y = 0;y < src.rows; y++){
        for(int x = 0;x < src.cols; x++){
            for( int c=0; c < 3; c++){

                final.at<Vec3b>(y,x)[c] = ( alpha*(src.at<Vec3b>(y,x)[c]) + beta );
            }
        }
    }

    namedWindow("Final image", CV_WINDOW_AUTOSIZE);
    imshow("Final image", final);
    waitKey(0);
    return 0;
}
