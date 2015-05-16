#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat image, final;

int main( int argc, char** argv){

    if(argc != 2){

        cout << "Usage: Dilation <image path>" << endl;
        return -1;
    }

    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!image.data){

        cout << "Please load valid image file!" << endl;
        return -1;
    }

    int dilation_elem;
    int dilation_type;
    int dilation_size = 2;
    cout << "Enter dilation element: \n 0. MORHP_RECT \n 1. MORPH_CROSS \n 2. MORPH_ELLIPSE" << endl;
    cin >> dilation_elem;
    if (dilation_elem == 0){ dilation_type = MORPH_RECT; }
    else if (dilation_elem == 1){ dilation_type = MORPH_CROSS; }
    else if (dilation_elem == 2){ dilation_type = MORPH_ELLIPSE; }
    else {
        cout << "Invalid dilation type! " << endl;
        return -1;
    }

    Mat element = getStructuringElement(dilation_type, Size(2*dilation_size + 1, 2*dilation_size + 1),Point(-1, -1));
    dilate(image, final, element);
    namedWindow("Dilation: ", CV_WINDOW_AUTOSIZE);
    imshow("Dilation: ", final);
    waitKey(0);
    return 0;
}
