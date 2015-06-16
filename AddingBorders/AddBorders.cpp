#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/// Global variables
Mat src, dst;
int top, bottom, Left, Right;
int borderType;
Scalar value;
char* window_name = "copyMakeBorder Demo";
RNG rng(12345); // RNG is nothing but random number generator. Used to generate the random border color.

/// Main function
int main(int argc, char** argv){

    int c;

    /// Load an imahe
    src = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!src.data){
        cout << "Invalid file." << endl;
        return -1;
    }

    cout << "Image padding." << endl;
    cout << "Press 'c' to set the border to random constant value. \n" << endl;
    cout << "Press 'r' to set the border to be replicated. \n" << endl;
    cout << "Press 'ESC' to exit the program. \n" << endl;

    // Create window
    namedWindow(window_name, CV_WINDOW_AUTOSIZE);

    /// Initialize arguments for the filter
    top = (int)(0.05 * src.rows);
    Left = (int)(0.05 * src.cols);
    bottom = (int)(0.05 * src.rows);
    Right = (int)(0.05 * src.cols);
    dst = src;

    imshow(window_name, dst);
    while(true){
        c = waitKey(500);

        if((char)c == 27){
            break;
        }
        else if((char)c == 'c'){
            borderType = BORDER_CONSTANT;
        }
        else if((char)c == 'r'){
            borderType = BORDER_REPLICATE;
        }

        value = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        copyMakeBorder(src, dst, top, bottom, Left, Right, borderType, value);
        imshow(window_name, dst);
    }

    return 0;

}
