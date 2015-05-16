#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat image, final;

// global variables

int dilation_elem = 0;
const int dilation_elem_max = 2;
int dilation_type;
int dilation_size = 1;
const int dilation_size_max = 10;

// Trackbar callback funtion
void dilation( int, void*){

    if ( dilation_elem == 0){ dilation_type = MORPH_RECT; }
    else if( dilation_elem == 1) { dilation_type = MORPH_CROSS; }
    else if ( dilation_elem == 2) { dilation_type = MORPH_ELLIPSE; }

    Mat element = getStructuringElement(dilation_type, Size(2*dilation_size + 1, 2*dilation_size + 1), Point(-1, -1));
    dilate(image, final, element);
    imshow("Dilation: ", final);
}

int main( int argc, char** argv){

    if(argc != 2){

        cout << "Usage: Dilation <image path>" << endl;
        return -1;
    }

    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!image.data){

        cout << "Please load valid image file!" << endl;
        return -1;
    }

    // Trackbar names
    char* Dilation_element = "Choose dilation type: \n 0. MORPH_RECT \n 1. MORPH_CROSS \n 2. MORPH_ELLIPSE";
    char* Dilation_size = "Vary dilation mask size: ";

    // Window
    namedWindow("Dilation: ", CV_WINDOW_AUTOSIZE);

    // trackbars
    createTrackbar(Dilation_element, "Dilation: ", &dilation_elem, dilation_elem_max, dilation);
    createTrackbar(Dilation_size, "Dilation: ", &dilation_size, dilation_size_max, dilation);

    waitKey(0);
    return 0;
}
