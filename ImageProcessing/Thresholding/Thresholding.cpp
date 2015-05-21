#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Global variables

int threshold_value = 0;
int threshold_type = 0;
const int threshold_value_max = 255;
const int threshold_type_max = 4;
int const max_BINARY_value = 255;

Mat src, src_gray, dst;
char* window_name = "Threshold Demo: ";
char* trackbar_type = "Type: \n 0: Binary \n 1: Binary inverted \n 2: Truncate \n 3: To zero \n 3: To zero inverted";
char* trackbar_value = "Value";

// Trackbar callback function
void Threshold_demo( int, void*){

    threshold(src_gray, dst, threshold_value, max_BINARY_value, threshold_type);
    imshow(window_name, dst);
}


int main(int argc, char** argv){

    if(argc != 2){

        cout << "usage: Thresholding <image path>" << endl;
        return -1;
    }

    src = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!src.data){

        cout << "No valid image file." << endl;
        return -1;
    }

    // Convert the image to gray
    cvtColor(src, src_gray, CV_RGB2GRAY);

    // window to display results
    namedWindow(window_name, CV_WINDOW_AUTOSIZE);

    // Create trackbar to choose type of threshold
    createTrackbar( trackbar_type, window_name, &threshold_type, threshold_type_max, Threshold_demo);

    // Trackbar to know the value of threshold
    createTrackbar( trackbar_value, window_name, &threshold_value, threshold_value_max, Threshold_demo);

    waitKey(0);
    return 0;


}
