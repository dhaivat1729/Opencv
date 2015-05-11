#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cv.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

    // check if user provided image or not
    if(argc != 2){
        cout << "Usage: MaskOperation <image_path>" << endl;
        return -1;
    }

    Mat image, final;

    // Loading user provided image
    image = imread(argv[1],CV_LOAD_IMAGE_COLOR);

    if(!image.data){

        cout << "No valid image data!" << endl;
        return -1;
    }

    // Similar to final = Mat::ones(image.size(),image.type())
    final.create(image.size(),image.type());

    // Creating mask
    Mat kern = (Mat_<char>(3,3) <<  0,-1,0,
                                   -1,5,-1,
                                    0,-1,0);
    // Applying mask on input image
    filter2D(image, final, image.depth(), kern);
    namedWindow("Input image!",CV_WINDOW_AUTOSIZE);
    imshow("Input image!",image);
    namedWindow("Final image!",CV_WINDOW_AUTOSIZE);
    imshow("Final image!",final);
    waitKey(0);
    return 0;
}
