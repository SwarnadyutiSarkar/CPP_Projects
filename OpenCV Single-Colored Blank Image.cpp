#include <opencv2/opencv.hpp>

int main() {
    int width = 640;
    int height = 480;

    // Create a blank image
    cv::Mat image(height, width, CV_8UC3, cv::Scalar(255, 0, 0));  // Blue color

    // Check if the image was created successfully
    if (image.empty()) {
        std::cout << "Could not create image." << std::endl;
        return -1;
    }

    // Display the image
    cv::imshow("Blank Image", image);
    cv::waitKey(0);

    return 0;
}
