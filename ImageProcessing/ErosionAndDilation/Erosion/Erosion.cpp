
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat image, final;

// global variables
int erosion_type;
int erosion_elem = 0;
const int erosion_elem_max = 2;
int erosion_size = 1;
const int erosion_size_max = 15;

// Trackbar for erosion
void erosion( int, void* ){

    if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
    else if(erosion_elem == 1){ erosion_type = MORPH_CROSS; }
    else if(erosion_elem == 2){ erosion_type = MORPH_ELLIPSE; }

    // Defining structuring element
    Mat element = getStructuringElement( erosion_type, Size(2*erosion_size + 1, 2*erosion_size + 1), Point(-1, -1));
    erode(image, final, element);
    imshow("Erosion: ", final);

}

int main( int argc, char** argv){

    if( argc!= 2){

        cout << "Usage: ErosionAndDilation <image path>" << endl;
        return -1;
    }

    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if( !image.data ){

        cout << "No valid image data." << endl;
        return -1;
    }

    char* Erosion_element = "Provide erosion element: \n 0. MORPH_RECT \n 1. MORPH_CROSS \n 2. MORPH_ELLIPSE ";
    char* Erosion_size = "Erosion size: ";
    namedWindow("Erosion: ", CV_WINDOW_AUTOSIZE);

    // trackbar for erosion element
    createTrackbar(Erosion_element, "Erosion: ", &erosion_elem, erosion_elem_max, erosion);

    // trackbar for erosion size
    createTrackbar(Erosion_size, "Erosion: ", &erosion_size, erosion_size_max, erosion);

    waitKey(0);
    return 0;
}
