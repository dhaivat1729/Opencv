#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

    if(argc != 2){

        cout << "Usage: LinearFilters <image path>" << endl;
        return -1;
    }

    Mat src, dst;
    src = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    if(!src.data){

        cout << "No valid image file!" << endl;
        return -1;
    }

    dst.create(src.size(), src.type());
    Mat mask = (Mat_<char>(3,3) << 0,0,5,
                                    0,5,0,
                                    5,0,0);

    filter2D(src, dst, src.depth(), mask);
    namedWindow("Final image: ", CV_WINDOW_AUTOSIZE);
    imshow("Final image: ", dst);
    waitKey(0);
    return 0;
}
