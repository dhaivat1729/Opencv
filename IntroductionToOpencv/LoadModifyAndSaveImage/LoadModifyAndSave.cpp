#include <stdio.h>
#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main( int argc, char** argv ){

    char* imagename = argv[1];
    Mat image;
    image = imread( imagename, CV_LOAD_IMAGE_COLOR);


    if ( argc != 2 || !image.data ){

        printf (" No image data! ");
        return -1;
    }

    Mat gray_image;
    cvtColor( image , gray_image, CV_BGR2GRAY);
    imwrite( "./gray_lena.jpg", gray_image );
    namedWindow( imagename, CV_WINDOW_AUTOSIZE );
    namedWindow( "Gray image", CV_WINDOW_AUTOSIZE );
    imshow( imagename, image);
    imshow( "Gray image", gray_image);
    waitKey(0);
    return 0;

}
