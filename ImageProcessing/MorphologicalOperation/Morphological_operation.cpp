#include <stdio.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

Mat image, final;

int main(int argc, char** argv){

    if(argc != 2){

        cout << "Usage: Morphological_operation <image path>" << endl;
        return -1;
    }

    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if( !image.data ){

        cout << "No valid image data." << endl;
    }

    // Variables for type of morphological operation
    int operation;
    int morph_operator;
    cout << "Operator: \n 0. Opening \n 1. Closing \n 2. Gradient \n 3. Top hat \n 4. Black hat" << endl;
    cin >> morph_operator;
    operation = morph_operator + 2;

    // morph_operator
    int morph_elem;
    cout << "Element: \n 0. MORPH_RECT \n 1. MORPH_CROSS \n 2. MORPH_ELLIPSE";
    cin >> morph_elem;

    // Element size
    int element_size = 3;

    // Defining structuring element
    Mat element = getStructuringElement(morph_elem, Size(element_size, element_size), Point(-1, -1));
    morphologyEx(image, final, operation, element);
    namedWindow("Morphological operation: ", CV_WINDOW_AUTOSIZE);
    imshow("Morphological operation: ", final);
    waitKey(0);
    return 0;
}
