#include <iostream>
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2/highgui/highgui.hpp>  // Video write
#include "opencv2/video/background_segm.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <chrono>

using namespace cv;
using namespace std;

typedef chrono::high_resolution_clock Timer;

void set_parameters (VideoCapture* camera){
    camera->set(CV_CAP_PROP_FPS , 30);
    camera->set(CV_CAP_PROP_FRAME_HEIGHT, 640);
    camera->set(CV_CAP_PROP_FRAME_WIDTH, 480);
}


int main() {

    VideoCapture video(0);

    set_parameters(&video);

    chrono::time_point<chrono::system_clock> start, end;
    start = Timer::now();

    for(;;)
    {
        Mat frame;
        end = Timer::now();
        cout << "FPS : " << (double)1000/(chrono::duration_cast<chrono::milliseconds> (end - start).count()) << std::endl;
        start = end;
        video >> frame; // get a new frame from camera
        imshow("Preview", frame);
        if(waitKey(30) >= 0) break;
    }

    return 0;
}