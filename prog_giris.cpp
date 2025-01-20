// Ödev no: 3
// Ödev konusu : Sipariş Planlama

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <locale.h>

using namespace std;

const int bayi_sayilar = 10;
int* adresler[bayi_sayilar];
int siparis[bayi_sayilar];
struct Store {
    int number;
    int order;
};

//  rastgele sıralama
void shuffleOrders(Store bayiler[]) {
    for (int i = 0; i < bayi_sayilar; i++) {
        int j = rand() % bayi_sayilar;
        Store temp = bayiler[i];
        bayiler[i] = bayiler[j];
        bayiler[j] = temp;
    }
}

int main() {
    setlocale(LC_ALL, "Turkish");
    // 1-100 arası eleman oluşturma
    for (int i = 0; i < bayi_sayilar; i++) {
        siparis[i] = rand() % 100 + 1;
    }

    int stok = 1000;
    srand(time(NULL));

    ofstream dosya;
    dosya.open("siparisler1.txt", ios::out);

    dosya << "Bayi No" << '\t' << '\t' << " Adres" << '\t' << '\t' << "Talep sayısı" << endl;

    for (int i = 0; i < bayi_sayilar; i++) {
        dosya << i + 1 << '\t' << '\t' << &adresler[i] << '\t' << '\t' << siparis[i] << endl;
    }

    Store bayiler[bayi_sayilar];
    for (int i = 0; i < bayi_sayilar; i++) {
        bayiler[i].number = i + 1;
        bayiler[i].order = siparis[i];
    }

    shuffleOrders(bayiler);

    // yeni liste 
    for (int i = 0; i < bayi_sayilar; i++) {
        cout << bayiler[i].number << '\t' << '\t' << &adresler[i] << '\t' << '\t' << bayiler[i].order << endl;
    }

    dosya << "Belirlenen dağıtım rotası" << endl;


    dosya << "Bayi no" << '\t' << '\t' << "Adres" << '\t' << '\t' << "Talep sayısı" << endl;

    for (int i = 0; i < bayi_sayilar; i++) {
        dosya << bayiler[i].number << '\t' << '\t' << &adresler[i] << '\t' << '\t' << bayiler[i].order << endl;
    }

    int toplam = 0;

    for (int i = 0; i < bayi_sayilar; i++) {
        toplam += siparis[i];
    }

    dosya << "Kalan Miktar:" << 1000 - toplam;

    cout << "Kalan Miktar:" << 1000 - toplam;


    dosya.close();

    return 0;
}
