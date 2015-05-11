#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <cv.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

    if(argc!=2){

        cout << "Usage: LoadModifyAndSave <image path>" << endl;
        return 0;
    }
    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if(!image.data){
        cout << "Input data is not valid!" << endl;
        return 0;
    }
    Mat gray_image;
    cvtColor(image, gray_image,CV_BGR2GRAY);
    imwrite("./gray_lena.jpg",gray_image);
    namedWindow("Display Color Image",WINDOW_AUTOSIZE);
    namedWindow("Display Gray Image",WINDOW_AUTOSIZE);
    imshow("Display Color Image",image);
    imshow("Display Gray Image",gray_image);
    waitKey(0);
    return 0;
}
