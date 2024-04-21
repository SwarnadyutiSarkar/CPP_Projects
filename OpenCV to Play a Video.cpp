#include <opencv2/opencv.hpp>

int main() {
    // Open a video file
    cv::VideoCapture cap("video.mp4");
    if (!cap.isOpened()) {
        std::cerr << "Error opening video file!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        // Read a frame from the video
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        // Display the frame
        cv::imshow("Video Playback", frame);

        // Break the loop if 'q' is pressed
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
