// This programs changes the brightness and contrast with the help of trackbars.

#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
#include <iostream>

using namespace std;
using namespace cv;

// Global variables
Mat image, final;
const int alpha_max = 30;
int alpha = 0; // for brightness
double brightness = 0.0;
const int beta_max = 3000;
double contrast = 0.0;
int beta = 0; // for contrast

// trackbar callback funtion
void on_trackbar( int,void* ){

    brightness = (double)alpha/10.0;
    contrast = (double)beta/10.0;

    for ( int y = 0; y < image.rows; y++){
        for ( int x = 0; x < image.cols; x++){
            for ( int c = 0; c <3; c++){

                final.at<Vec3b>(y,x)[c] = saturate_cast<uchar> ( brightness * image.at<Vec3b>(y,x)[c] + contrast);
            }
        }
    }

    imshow("Final image!", final);

}

// Main function

int main( int argc, char** argv){

    if(argc != 2){

        cout << "Usage: Trackbar <image path>";
        return -1;
    }

    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    final.create(image.size(), image.type());

    namedWindow("Final image!", CV_WINDOW_AUTOSIZE);
    namedWindow("Input image!", CV_WINDOW_AUTOSIZE);
    imshow("Input image!", image);

    // Create trackbars to control brightness and contrast

    createTrackbar("Contrast: ", "Final image!", &alpha, alpha_max, on_trackbar);
    createTrackbar("Brightness: ", "Final image!", &beta, beta_max, on_trackbar);

    waitKey(0);
    return 0;
}
