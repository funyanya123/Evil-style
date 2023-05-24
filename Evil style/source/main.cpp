#include <opencv2/opencv.hpp>
#include "cartoonify.h"

int main() {
    // Open the camera
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) {
        std::cerr << "Error 1\n";
        return -1;
    }

    // Load the face cascade classifier
    cv::CascadeClassifier feacs;
    if (!feacs.load("haarcascadeshaarcascade_frontalface_default.xml")) {
        std::cerr << "Error 2\n";
        return -1;
    }

    // Set the camera resolution
    camera.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    camera.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    while (true) {
        // Capture a frame from the camera
        cv::Mat frame;
        camera >> frame;    

        if (frame.empty()) {
            std::cerr << "NO\n";
            return 0;
        }

        // Create a copy of the frame for displaying
        cv::Mat displayFrame(frame.size(), CV_8UC3);

        // Apply cartoonify transformation to the frame
        Cartoonifycamera(frame, displayFrame);

        // Display the cartoonified frame
        cv::imshow("Evil style", displayFrame);

        // Wait for a keypress
        char keypress = cv::waitKey(20);
        if (keypress == 27) {
            break;
        }
    }

    return 0;
}
