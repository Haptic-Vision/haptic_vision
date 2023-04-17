#include <iostream>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <chrono>

using namespace std;
using namespace cv;
using namespace dnn;

const string CONFIG_FILE = "yolov4-tiny.cfg";
const string WEIGHTS_FILE = "yolov4-tiny.weights";
const float CONFIDENCE_THRESHOLD = 0.5;
const float NMS_THRESHOLD = 0.4;


void processFrame(Mat& frame, Net& net) {
    int frameWidth = frame.cols;
    int frameHeight = frame.rows;

    Mat inputBlob = blobFromImage(frame, 1 / 255.F, Size(414, 414), Scalar(), true, false);
    net.setInput(inputBlob);
    vector<Mat> outputBlobs;
    net.forward(outputBlobs, net.getUnconnectedOutLayersNames());

    vector<int> classIds;
    vector<float> confidences;
    vector<Rect> boxes;

    for (auto& output : outputBlobs) {
        auto* data = (float*)output.data;
        for (int i = 0; i < output.rows; ++i, data += output.cols) {
            Mat scores = output.row(i).colRange(5, output.cols);
            Point classIdPoint;
            double confidence;
            minMaxLoc(scores, nullptr, &confidence, nullptr, &classIdPoint);
            if (confidence > CONFIDENCE_THRESHOLD) {
                int centerX = (int)(data[0] * frameWidth);
                int centerY = (int)(data[1] * frameHeight);
                int width = (int)(data[2] * frameWidth);
                int height = (int)(data[3] * frameHeight);
                int left = centerX - width / 2;
                int top = centerY - height / 2;

                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(Rect(left, top, width, height));
            }
        }
    }

    vector<int> indices;
    NMSBoxes(boxes, confidences, CONFIDENCE_THRESHOLD, NMS_THRESHOLD, indices);
    
    float minDistance = numeric_limits<float>::max();
    string position;
    for (int idx : indices) {
        Rect box = boxes[idx];
        int centerX = box.x + box.width / 2;

        float distance = static_cast<float>(box.width * box.height);
        if (distance < minDistance) {
            minDistance = distance;
            if (centerX < frameWidth / 3) {
                position = "left";
            } else if (centerX > 2 * frameWidth / 3) {
                position = "right";
            } else {
                position = "center";
            }
        }        
    }

    cout << "Closest object is in the " << position << endl;
}

int main() {

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

    imshow("Camera Stream", frame);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    int delay = max(1, (int)(16 - chrono::duration <double, milli> (diff).count()));
    this_thread::sleep_for(chrono::milliseconds(delay));

}

cap.release();
destroyAllWindows();

return 0;
}
