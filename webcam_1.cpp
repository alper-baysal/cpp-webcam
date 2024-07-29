#include `<iostream>`

#include<opencv2/opencv.hpp>

using namespace cv;

using namespace std;

int main() {

    // VideoCapture nesnesini oluştur ve kamerayı aç

    VideoCapture kamera(0);

    // Kamera açılamazsa hata mesajı ver

    if (!kamera.isOpened()) {

    cerr <<"Kamera acilamadi!"<< endl;

    return -1;

    }

    int frameCount =0; // Görüntülerin sayısını takip etmek için bir sayaç

    // Sonsuz döngü başlat

    while (true) {

    Mat videoGoruntu;

    // Kameradan görüntü oku

    kamera >> videoGoruntu;

    // Eğer görüntü alınamazsa döngüyü kır

    if (videoGoruntu.empty()) {

    cerr <<"Görüntü alinamadi!"<< endl;

    break;

    }

    // Görüntüyü göster

    //imshow("Bilgisayar Kamerasi", videoGoruntu);

    // 's' tuşuna basıldığında görüntüyü kaydet

    char key = waitKey(100);  // Bekleme süresini biraz artırdık

    if (key =='s') {

    string dosyaAdi ="goruntu_"+to_string(frameCount++) +".png";

    // Görüntüyü kaydet ve başarılı olup olmadığını kontrol et

    bool kaydedildi = imwrite(dosyaAdi, videoGoruntu);

    if (kaydedildi) {

    cout <<"Görüntü kaydedildi: "<< dosyaAdi << endl;

    } else {

    cerr <<"Görüntü kaydedilemedi: "<< dosyaAdi << endl;

    }

    }

    // 'q' tuşuna basıldığında döngüyü kır

    if (key =='q') {

    break;

    }

    }

    // Kamera ve pencereleri serbest bırak

    kamera.release();

    destroyAllWindows();

    return0;

}
