#include <stdio.h>

// Sharpe Oranini hesaplayan fonksiyon
double hesaplaSharpeOrani(double getiri, double risksizFaiz, double standartSapma) {
    // Standart sapmanin sifir olmasi durumunda bolme hatasini onlemek icin kontrol
    if (standartSapma == 0) {
        return -1.0; // Hata degeri olarak -1.0 dondurulur
    }

    // Sharpe Orani = (Yatirim Getirisi - Risksiz Faiz Orani) / Standart Sapma
    return (getiri - risksizFaiz) / standartSapma;
}

int main() {
    // Kullanicidan alinacak degerler
    double yatirimGetirisi;
    double risksizFaizOrani;
    double standartSapma;
    double sharpeOrani;

    printf("--- Sharpe Orani Hesaplayicisina Hos Geldiniz ---\n\n");

    // 1. Yatirim Getirisi bilgisini alma
    printf("1. Yatirim Getirisini (ornegin %%15 icin 0.15) girin: ");
    if (scanf("%lf", &yatirimGetirisi) != 1) {
        printf("Hatali giris. Program sonlandiriliyor.\n");
        return 1;
    }

    // 2. Risksiz Faiz Orani bilgisini alma
    printf("2. Risksiz Faiz Oranini (ornegin %%5 icin 0.05) girin: ");
    if (scanf("%lf", &risksizFaizOrani) != 1) {
        printf("Hatali giris. Program sonlandiriliyor.\n");
        return 1;
    }

    // 3. Portfoyun Standart Sapmasi (Risk) bilgisini alma
    printf("3. Portfoyun Standart Sapmasini (ornegin %%12 icin 0.12) girin: ");
    if (scanf("%lf", &standartSapma) != 1) {
        printf("Hatali giris. Program sonlandiriliyor.\n");
        return 1;
    }

    // Sharpe Oranini hesaplama
    sharpeOrani = hesaplaSharpeOrani(yatirimGetirisi, risksizFaizOrani, standartSapma);

    printf("\n--- SONUCLAR ---\n");

    if (sharpeOrani == -1.0) {
        printf("HATA: Standart sapma (risk) sifir olamaz. Hesaplama yapilamadi.\n");
    } else {
        // Hesaplanan orani yazdirmak
        printf("Hesaplanan **Sharpe Orani**: %.2lf\n", sharpeOrani);

        // Sharpe oraninin genel kabul goren degerlendirmesini yapma
        printf("Genel Degerlendirme: ");
        if (sharpeOrani >= 3.0) {
            printf("**Mukemmel** (Risk birimi basina cok yuksek fazladan getiri).\n");
        } else if (sharpeOrani >= 2.0) {
            printf("**Cok Iyi** (Risk birimi basina yuksek fazladan getiri).\n");
        } else if (sharpeOrani >= 1.0) {
            printf("**Iyi** (Risk birimi basina makul fazladan getiri).\n");
        } else if (sharpeOrani >= 0.0) {
            printf("Kabul Edilebilir/Ortalama. (Risksiz oranin uzerinde getiri sagliyor).\n");
        } else {
            printf("Kotu. (Risksiz orandan daha dusuk getiri sagliyor veya yuksek risk var).\n");
        }
    }

    return 0;
}
