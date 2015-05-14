/* This code blends two images by changing the value of trackbar.*/

#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace std;
using namespace cv;

// global variables
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

// Image variables
Mat image1, image2, final;

// Callback function on_trackbar
void on_trackbar( int, void*){

    alpha = (double)alpha_slider/alpha_slider_max;
    beta = 1.0 -alpha;
    addWeighted(image1, alpha, image2, beta, 0.0, final);
    imshow("Linear blend!", final);
}

int main(int argc, char** argv){

    if(argc != 3){

        cout << "Usage: Trackbar <image path 1> <image path 2>" << endl;
        return -1;
    }

    image1 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    image2 = imread(argv[2], CV_LOAD_IMAGE_COLOR);
    final.create(image1.size(), image1.tyep());

    if ( !image1.data || !image2.data){

        cout << "Image files are not valid! Please try again." << endl;
        return -1;
    }

    alpha_slider = 0;

    // Creating window
    namedWindow("Linear blend!", CV_WINDOW_AUTOSIZE);

    // Create trackbar
    createTrackbar("Alpha value", "Linear blend!", &alpha_slider, alpha_slider_max, on_trackbar);
    waitKey(0);
    return 0;
}
