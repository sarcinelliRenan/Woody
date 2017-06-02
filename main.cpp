#include <iostream>
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui/highgui.hpp>  // Video write
#include "opencv2/video/background_segm.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>

using namespace cv;
using namespace std;

void set_parameters (VideoCapture* camera){
    camera->set(CV_CAP_PROP_FPS , 10);
    camera->set(CV_CAP_PROP_FRAME_HEIGHT, 640);
    camera->set(CV_CAP_PROP_FRAME_WIDTH, 480);
}


int main() {

    VideoCapture video(0);

    set_parameters(&video);

    for(;;)
    {
        Mat frame;
        video >> frame; // get a new frame from camera
        imshow("!!OLHA O VIADO!!", frame);
        if(waitKey(30) >= 0) break;
    }

    return 0;
}