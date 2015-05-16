#include <stdio.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

// Images
Mat image, final;

// global variables
int operation;
const int operation_max = 4;
int morph_elem;
int elem_type;
const int elem_type_max = 2;
int elem_size;
const int elem_size_max = 10;

// trackbar callback function

void morphology( int, void* ){

    morph_elem = operation + 2;
    Mat element = getStructuringElement(elem_type, Size(2*elem_size + 1, 2*elem_size + 1), Point(-1, -1));
    morphologyEx(image, final, morph_elem, element);
    imshow("Morphological operation: ", final);
}


int main(int argc, char** argv){

    if(argc != 2){

        cout << "Usage: Morphological_operation <image path>" << endl;
        return -1;
    }

    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if( !image.data ){

        cout << "No valid image data." << endl;
    }

    // creating window
    namedWindow("Morphological operation: ", CV_WINDOW_AUTOSIZE);

    char* morph_operation =  "Operator: \n 0. Opening \n 1. Closing \n 2. Gradient \n 3. Top hat \n 4. Black hat";

    char* morphological_type = "Element: \n 0. MORPH_RECT \n 1. MORPH_CROSS \n 2. MORPH_ELLIPSE";

    char* mask_size = "Kernel size: ";

    // Creating trackbars
    createTrackbar(morph_operation, "Morphological operation: ", &operation, operation_max, morphology);

    createTrackbar(morphological_type, "Morphological operation: ", &elem_type, elem_type_max, morphology);

    createTrackbar(mask_size, "Morphological operation: ", &elem_size, elem_size_max, morphology);

    waitKey(0);
    return 0;
}
