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

    namedWindow("Normalized box filter: ", CV_WINDOW_AUTOSIZE);
    createTrackbar("Blur parameter: ", "Normalized box filter: ", &blur_parameter, blur_parameter_max, blur_trackbar);
    waitKey(0);
    return 0;

}
