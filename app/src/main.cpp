#include <iostream>

int main() {

    wiringPiSetup();

    pinMode(LEFT_PIN, OUTPUT);
    pinMode(RIGHT_PIN, OUTPUT);

    Net net = readNetFromDarknet(CONFIG_FILE, WEIGHTS_FILE);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "Error: Unable to open the camera." << endl;
        return -1;
    }

    Mat frame;
    while (true) {
        auto start = chrono::steady_clock::now();
        cap >> frame;
        if (frame.empty()) {
            cerr << "Error: No frame captured from the camera." << endl;
            break;
        }       
    processFrame(frame, net);

    try {
    	imshow("Camera Stream", frame);
    } catch (const cv::Exception& e) {
        continue;
    }

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    int delay = max(1, (int)(16 - chrono::duration <double, milli> (diff).count()));
    this_thread::sleep_for(chrono::milliseconds(delay));

    if (waitKey(1) >= 0) {
	digitalWrite(LEFT_PIN, LOW);
        digitalWrite(RIGHT_PIN, LOW);
        break;
    }
}

cap.release();
destroyAllWindows();

return 0;
}
