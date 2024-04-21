#include <opencv2/opencv.hpp>

int main() {
    // Load pre-trained face detection model
    cv::CascadeClassifier faceCascade;
    if (!faceCascade.load(cv::samples::findFile("haarcascade_frontalface_alt.xml"))) {
        std::cerr << "Error loading face detection model!" << std::endl;
        return -1;
    }

    // Open a video capture device
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error opening video capture device!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        // Read a frame from the video capture device
        cap >> frame;
        if (frame.empty()) {
            break;
        }

        // Convert frame to grayscale
        cv::Mat grayFrame;
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        // Detect faces
        std::vector<cv::Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces);

        // Draw rectangles around detected faces
        for (const auto& face : faces) {
            cv::rectangle(frame, face, cv::Scalar(0, 255, 0), 2);
        }

        // Display frame
        cv::imshow("Face Detection", frame);

        // Break the loop if 'q' is pressed
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
