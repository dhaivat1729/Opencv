
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat image, final;

int erosion_elem;
int erosion_type;
int erosion_size = 3;

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

    cout << "Provide erosion element: \n 0. MORPH_RECT \n 1. MORPH_CROSS \n  2. MORPH_ELLIPSE " << endl;
    cin >> erosion_elem;
    if ( erosion_elem != 0 || erosion_elem != 1 || erosion_elem != 2){
        cout << "No valid erosion type!" << endl;
        return -1;
    }

    if(erosion_elem == 0) { erosion_type = MORPH_RECT; }
    else if(erosion_elem == 1){ erosion_type = MORPH_CROSS; }
    else if(erosion_elem == 2){ erosion_type = MORPH_ELLIPSE; }

    // Defining structural element
    Mat element = getStructuringElement( erosion_type, Size(erosion_size, erosion_size), Point(-1, -1));
    erode(image, final, element);
    namedWindow("Erosion: ",CV_WINDOW_AUTOSIZE);
    imshow("Erosion: ", final);
    waitKey(0);
    return 0;
}
