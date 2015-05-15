#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <cv.h>

using namespace std;
using namespace cv;

// image variables
Mat src, dst1, dst2, dst3, dst4;

// Blur parameters:
int blur_parameter = 1;
const int blur_parameter_max = 100;

// Normalized box filter trackbar function

void blur_trackbar( int, void*){

    blur(src, dst1, Size(2* blur_parameter + 1, 2 * blur_parameter + 1), Point(-1, -1));
    imshow("Normalized box filter: ", dst1);
}

// Gaussian blur parameters:
int gaussian_parameter = 1;
const int gaussian_parameter_max = 100;

// Gaussian smoothing trackbar function

void gaussian_trackbar(int, void*){

    GaussianBlur(src, dst2, Size(2 * gaussian_parameter + 1, 2 * gaussian_parameter + 1), 0, 0);
    imshow("Gaussian filter: ", dst2);
}

// Median filter parameters
int median_parameter = 1;
const int median_parameter_max = 100;

// Median smoothing trackbar function

void median_trackbar(int, void*){
    medianBlur(src, dst3, 2 * median_parameter + 1);
    imshow("Median filter: ", dst3);
}

int main( int argc, char** argv){

    if(argc != 2){

        cout << "Usage: Smoothing <image path>" << endl;
        return -1;
    }

    src = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if (!src.data) {

        cout << "No valid image file!" << endl;
        return -1;
    }

    // Window and trackbar for Normalized box filter
    namedWindow("Normalized box filter: ", CV_WINDOW_AUTOSIZE);
    createTrackbar("Blur parameter: ", "Normalized box filter: ", &blur_parameter, blur_parameter_max, blur_trackbar);

    // Window and trackbar for gaussian smoothing
    namedWindow("Gaussian filter: ", CV_WINDOW_AUTOSIZE);
    createTrackbar("Gaussian parameter: ", "Gaussian filter: ", &gaussian_parameter, gaussian_parameter_max, gaussian_trackbar);

    // Window and trackbar for median smoothing
    namedWindow("Median filter: ", CV_WINDOW_AUTOSIZE);
    createTrackbar("Median blur parameter: ", "Median filter: ", &median_parameter, median_parameter_max, median_trackbar);

    waitKey(0);
    return 0;

}
