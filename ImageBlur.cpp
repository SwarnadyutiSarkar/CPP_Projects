#include <opencv2/opencv.hpp>

int main() {
    // Load an image
    cv::Mat image = cv::imread("image.jpg");
    if (image.empty()) {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    // Apply Gaussian blur
    cv::Mat blurredImage;
    cv::GaussianBlur(image, blurredImage, cv::Size(15, 15), 0);

    // Display the original and blurred images
    cv::imshow("Original Image", image);
    cv::imshow("Blurred Image", blurredImage);

    cv::waitKey(0);
    return 0;
}
