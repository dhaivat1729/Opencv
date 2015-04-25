#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main ( int argc, char **argv){

    if( argc != 2) {
        cout << " Usage: LoadAndDisplayImage <Image path>" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if ( !image.data ){
        cout << "No valid image data! " << endl;
        return -1;
    }

    namedWindow("Load and Display Image", WINDOW_AUTOSIZE);
    imshow("Load and Display Image", image);

    waitKey(0);
    return 0;
}
