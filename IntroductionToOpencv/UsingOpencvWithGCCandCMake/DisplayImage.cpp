#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){

    if ( argc!= 2){
        printf(" Usage: DisplayImage.out <Image path> \n");
        return -1;
    }

    Mat image;
    image = imread( argv[1],1 );

    if ( !image.data ){
        printf("No image data!\n");
        return -1;
    }
    namedWindow("Display image", WINDOW_AUTOSIZE);
    imshow("Display image", image);

    waitKey(0);
    return 0;
}
