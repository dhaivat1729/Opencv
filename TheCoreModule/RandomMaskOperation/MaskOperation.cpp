#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv.h>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {

    if ( argc != 2){
        cout << "Usage: MaskOperation <image path>" << endl;
        return -1;
    }

    Mat image, final;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if(!image.data){
        cout << "No valid image file! " <<  endl;
        return -1;
    }

    final = Mat::ones(image.size(), image.type());
    Mat kern = (Mat_<char>(3,3) <<  0, -1, 0,
                                    -1, 5, -1,
                                    0, -1, 0);

    filter2D(image, final, image.depth(), kern);
    namedWindow("Initial image!",CV_WINDOW_AUTOSIZE);
    namedWindow("Final image!",CV_WINDOW_AUTOSIZE);
    imshow("Initial image!", image);
    imshow("Final image!", final);
    waitKey(0);
    return 0;
}
