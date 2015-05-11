#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cv.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

    Mat src1,src2,final;
    src1 = imread("/home/dhaivat666/Opencv codes/standard_test_images/lena_color_512.tif",CV_LOAD_IMAGE_COLOR); // This is not python. So do not forget double inverted comma. :P
    src2 = imread("/home/dhaivat666/Opencv codes/standard_test_images/peppers_color.tif",CV_LOAD_IMAGE_COLOR);
    double alpha = 0.5;
    double beta = 1.0 - alpha;
    namedWindow("Final blended image.", CV_WINDOW_AUTOSIZE);
    addWeighted(src1,alpha,src2,beta,0.0,final);
    imshow("Final image",final);
    waitKey(0);
    return 0;
}
