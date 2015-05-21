#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

    if(argc!= 2){

        cout << "Usage: ImagePyramid <image path> " << endl;
        return -1;
    }

    Mat src, dst, tmp;
    src = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!src.data){

        cout << "Not valid image file!" << endl;
        return -1;
    }

    tmp = src;
    dst = tmp;

    // Creating a window
    namedWindow("Image Pyramids: ", CV_WINDOW_AUTOSIZE);
    imshow("Image Pyramids: ", dst);

    while( true ){

        int c;
        c = waitKey(10);
        if((char)c == 27){
            break;
        }

        if( (char)c == 'u'){
            pyrUp(tmp, dst, Size(tmp.cols*2, tmp.rows*2));
            printf("** Zoom in: Image * 2 \n");
        }

        else if((char)c == 'd'){
            pyrDown(tmp, dst, Size(tmp.cols/2, tmp.rows/2));
            printf("** Zoom out: Image / 2 \n");
        }

        imshow("Image Pyramids: ", dst);
        tmp = dst;
    }
}
