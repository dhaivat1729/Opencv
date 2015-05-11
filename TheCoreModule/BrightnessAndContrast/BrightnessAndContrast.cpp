#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
#include <iostream>

using namespace std;
using namespace cv;

double alpha; // to control the contrast
double beta; // to control the brightness

int main(int argc, char** argv){

    if(argc!=2){
        cout << "Usage: BrightnessAndContrast <Image path>." << endl;
        return -1;
    }

    Mat image; // image to be read
    image = imread(argv[1],CV_LOAD_IMAGE_COLOR);
    if(!image.data){
        cout << "Invalid file!" << endl;
        return -1;
    }

    // initializing final image which is yet to be processed
    Mat final = Mat::ones(image.size(),image.type());


    cout << "Provide a value of alpha to control contrast: ";
    cin >> alpha;
    cout << endl;
    cout << "Provide a value if beta to control brightness: ";
    cin >> beta;
    cout << endl;

    // processing image row and column wise
    for (int y=0; y < image.rows; y++){
        for ( int x = 0; x < image.cols; x++){
            for( int c = 0; c < 3; c++){

                final.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha * image.at<Vec3b>(y,x)[c] + beta);
            }
        }
    }

    namedWindow("Final image!", CV_WINDOW_AUTOSIZE);
    imshow("Final image", final);
    waitKey(0);
    return 0;
}
