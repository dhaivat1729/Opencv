#include <stdio.h>
#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

double alpha;  // to control the contrast
double beta; // to control the brightness

int main( int argc, char** argv){

    if(argc != 2){

        cout << "Usage: BrightnessAndContrast <Image path>" << endl;
    }
        Mat src, final;
        src = imread(argv[1], CV_LOAD_IMAGE_COLOR);
        final = Mat::ones(src.size(), src.type());

        cout << "Provide the value of alpha: ";
        cin >> alpha;
        cout << endl;
        cout << "Provide the value of beta: ";
        cin >> beta;
        cout << endl;

        if(!src.data){
            cout << "No valid image file!" << endl;
        }

        for( int y = 0;y < src.rows; y++){
            for (int x = 0; x < src.cols; x++ ){
                for( int c = 0; c < 3; c++){
                    final.at<Vec3b>(y,x)[c] = saturate_cast<uchar>(alpha * src.at<Vec3b>(y,x)[c] + beta);
                }
            }
        }

        namedWindow("Final image",CV_WINDOW_AUTOSIZE);
        imshow("Final image", final);
        waitKey(0);
        return 0;
}
