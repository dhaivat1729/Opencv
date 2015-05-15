/* Smoothing using opencv to reduce noise. */
// Four methods:
// 1. Normalized box filter
// 2. Gaussian filter
// 3. Median filter
// 4. Bilateral filter

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

// image variables
Mat src, dst1, dst2, dst3, dst4;

const int  MAX_KERNEL_LENGTH = 31;

/**
 * @function main
 */
 int main( int argc, char** argv){

     if(argc != 2){

         cout << "Usage: Smoothing <image path>" << endl;
         return -1;
     }

     namedWindow("Normalized box filter.", CV_WINDOW_AUTOSIZE);
     namedWindow("Gaussian filter.",CV_WINDOW_AUTOSIZE);
     namedWindow("Median filter.",CV_WINDOW_AUTOSIZE);

     /// load the source image
     src = imread(argv[1],CV_LOAD_IMAGE_COLOR);

     if(!image.data){

         cout << "Please input valid image file." << endl;
         return -1;
     }

     // Normalized box filter
     for (int i = 1; i < MAX_KERNEL_LENGTH; i += 2){
         blur(src, dst1, Size(i, i), Point(-1,-1));
     }

     // Gaussian smoothing
     for ( int i=1; i < MAX_KERNEL_LENGTH; i += 2){
         GaussianBlur( src, dst2, Size(i, i), 0, 0);
     }

     // Median filter
     for(int i = 1; i < MAX_KERNEL_LENGTH; i += 2){
         medianBlur(src, dst3, i);
     }

     // Bilateral filter
     for(int i = 1; i < MAX_KERNEL_LENGTH; i +=2){
         bilateralFilter(src, dst4, i, i*2, i/2);
     }

     namedWindow("Normalized box filter.", CV_WINDOW_AUTOSIZE);
     namedWindow("Gaussian filter.",CV_WINDOW_AUTOSIZE);
     namedWindow("Median filter.",CV_WINDOW_AUTOSIZE);
     namedWindow("Bilateral filter.", CV_WINDOW_AUTOSIZE);
     imshow("Normalized box filter.", dst1);
     imshow("Gaussian filter.", dst2);
     imshow("Median filter.", dst3);
     imshow("Bilateral filter.", dst4);
     waitKey(0);
     return 0;
 }
