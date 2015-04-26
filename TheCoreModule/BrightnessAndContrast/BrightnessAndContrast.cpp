#include <stdio.h>
#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

double alpha; // to control the brightness
double beta; // to control the contrast

int main( int argc, char** argv ){

    Mat src, final;
    if ( argc != 2){
        cout << "Usage : BrighnessAndContrast <Image path> " << endl;
    }

    src = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    final = Mat::zeros(src.size(),src.type());
    if( !src.data ){
        cout << "No valid image data!" << endl;
    }

    // Take the values of alpha and beta from user
    cout << "Enter a value to control contrast: " << endl;
    cin >> alpha;
    cout << "Enter a value to control brighness: " << endl;
    cin >> beta;

    for( int y = 0; y < src.rows; y++){
        for( int x = 0; x < src.cols; x++){
            for( int c = 0; c<3; c++){
                final.at<Vec3b>(y,x)[c] = ( alpha * src.at<Vec3b>(y,x)[c] + beta );
            }

        }
    }

    namedWindow( "Final Image Display",CV_WINDOW_AUTOSIZE);
    imshow( "FInal Image Display", final);
    waitKey(0);
    return 0;   

}
