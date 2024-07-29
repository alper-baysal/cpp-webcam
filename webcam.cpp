#include <opencv2/opencv.hpp>
#include `<iostream>`

using namespace cv;

using namespace std;

int main() {
    VideoCapture kamera(0); // Kamera aç
    if (!kamera.isOpened()) {
        cerr << "Kamera acilamadi!" << endl;
        return -1;
    }
    while (true) {
        Mat frame;
        kamera >> frame; // Kare yakala
        if (frame.empty()) {
            break;
        }
        imshow("Webcam", frame); // Görüntüyü göster
        if (waitKey(50) == 'q') { // 'q' tuşuna basıldığında döngüyü kır
            break;
        }
    }
    kamera.release(); // Kamera ve pencereleri serbest bırak
    destroyAllWindows();
    return 0;
}