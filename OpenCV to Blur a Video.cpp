#include <opencv2/opencv.hpp>

int main() {
    // Open a video file
    cv::VideoCapture cap("video.mp4");
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file!" << std::endl;
        return -1;
    }

    cv::Mat frame, blurredFrame;
    cv::namedWindow("Blurred Video", cv::WINDOW_AUTOSIZE);

    while (true) {
        // Read a frame from the video
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        // Apply Gaussian blur to the frame
        cv::GaussianBlur(frame, blurredFrame, cv::Size(15, 15), 0);

        // Display the blurred frame
        cv::imshow("Blurred Video", blurredFrame);

        // Break the loop if 'q' is pressed
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
