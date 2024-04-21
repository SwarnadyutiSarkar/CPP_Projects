#include <opencv2/opencv.hpp>

int main() {
    // Read an image
    cv::Mat image = cv::imread("shapes.jpg", cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // Apply binary thresholding
    cv::Mat binaryImage;
    cv::threshold(image, binaryImage, 127, 255, cv::THRESH_BINARY_INV);

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binaryImage, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // Draw contours
    cv::Mat contourImage = cv::Mat::zeros(image.size(), CV_8UC3);
    for (size_t i = 0; i < contours.size(); ++i) {
        cv::drawContours(contourImage, contours, static_cast<int>(i), cv::Scalar(255, 255, 255), 2);
    }

    // Display images
    cv::imshow("Original Image", image);
    cv::imshow("Binary Image", binaryImage);
    cv::imshow("Contours", contourImage);

    cv::waitKey(0);
    return 0;
}
