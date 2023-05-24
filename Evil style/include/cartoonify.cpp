#include <opencv2/opencv.hpp>

// Function to cartoonify the camera
void Cartoonifycamera(const cv::Mat& input, cv::Mat& output) {
    // Convert the input image to grayscale
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);

    // Apply median blur to reduce noise
    cv::medianBlur(gray, gray, 7);

    // Detect edges using adaptive thresholding
    cv::Mat edges;
    cv::adaptiveThreshold(gray, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 9, 2);

    // Convert the edges camera to color (BGR)
    cv::cvtColor(edges, output, cv::COLOR_GRAY2BGR);

    // Additional processing to give an "evil" effect
    cv::bitwise_not(output, output);
    cv::add(output, cv::Scalar(0, 0, 100), output);
}
