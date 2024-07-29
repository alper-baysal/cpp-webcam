#include `<iostream>`
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
    // VideoCapture nesnesini oluştur ve kamerayı aç
    VideoCapture kamera(0);

    // Kamera açılamazsa hata mesajı ver
    if (!kamera.isOpened()) {
        cerr << "Kamera acilamadi!" << endl;
        return -1;
    }

    // VideoWriter nesnesi
    VideoWriter videoKayit;
    int frame_width = static_cast`<int>`(kamera.get(CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast `<int>`(kamera.get(CAP_PROP_FRAME_HEIGHT));
    Size frame_size(frame_width, frame_height);
    int fps = 20;

    // Video kaydetme parametreleri (codec, dosya adı, fps, frame boyutu)
    videoKayit.open("video_kayit.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, frame_size, true);

    // Eğer VideoWriter açılamazsa hata mesajı ver
    if (!videoKayit.isOpened()) {
        cerr << "Video yazıcı acilamadi!" << endl;
        return -1;
    }

    int duration = 15; // Kayıt süresi (saniye)
    int frameCount = 0; // Frame sayısı sayacı
    int totalFrames = duration * fps; // Toplam frame sayısı

    // Sonsuz döngü başlat
    while (frameCount < totalFrames) {
        Mat videoGoruntu;
        // Kameradan görüntü oku
        kamera >> videoGoruntu;

    // Eğer görüntü alınamazsa döngüyü kır
        if (videoGoruntu.empty()) {
            cerr << "Görüntü alinamadi!" << endl;
            break;
        }

    // Görüntüyü göster
        //imshow("Bilgisayar Kamerasi", videoGoruntu);

    // Video kaydına frame ekle
        videoKayit.write(videoGoruntu);

    // 'q' tuşuna basıldığında döngüyü kır
        char key = waitKey(1000 / fps);
        if (key == 'q') {
            break;
        }

    frameCount++;
    }

    // Kamera ve pencereleri serbest bırak
    kamera.release();
    videoKayit.release();
    destroyAllWindows();

    cout << "Video kaydi tamamlandi!" << endl;

    return 0;
}