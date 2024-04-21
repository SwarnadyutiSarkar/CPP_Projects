#include <opencv2/opencv.hpp>

int main() {
    // Load an image
    cv::Mat image = cv::imread("coins.jpg", cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // Convert image to grayscale
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Apply Gaussian blur
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(5, 5), 0);

    // Apply binary thresholding
    cv::Mat binaryImage;
    cv::threshold(blurredImage, binaryImage, 127, 255, cv::THRESH_BINARY_INV);

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binaryImage, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Draw contours and detect circles
    cv::Mat contourImage = image.clone();
    for (const auto& contour : contours) {
        double area = cv::contourArea(contour);
        if (area > 1000) {  // Filter small contours
            cv::drawContours(contourImage, std::vector<std::vector<cv::Point>>{contour}, -1, cv::Scalar(0, 255, 0), 2);
        }
    }

    // Display images
    cv::imshow("Original Image", image);
    cv::imshow("Contours", contourImage);

    cv::waitKey(0);
    return 0;
}
