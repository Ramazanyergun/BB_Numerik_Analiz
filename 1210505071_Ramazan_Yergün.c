#include <stdio.h>
#include <stdlib.h>

int noktaSayisi;

//Nokta sayısının alınması ve değer aralığı kontrolü
void noktaSayisiAl() {
    printf("Nokta sayisini [2, 15] araliginda girin: ");
    scanf("%d", &noktaSayisi);
    if (noktaSayisi < 2 || noktaSayisi > 15) {
        printf("Gecersiz nokta sayisi girdiniz. Tekrar deneyin!\n");
        noktaSayisiAl();
    }
}

double lagrangeInterpolasyon(double hesaplanacakDeger, double x_degerleri[], double y_degerleri[], int noktaSayisi) {
    double polinom = 0.0;

    //Pn() formülünün hesaplanması
    for (int i = 0; i < noktaSayisi; i++) {
        double terim = y_degerleri[i];

        //Li() formülünün hesaplanması
        for (int j = 0; j < noktaSayisi; j++) {
            if (j != i){ 
                terim *= (hesaplanacakDeger - x_degerleri[j]) / (x_degerleri[i] - x_degerleri[j]);   //i j'ye eşit değilse işlem gerçekleşiyor
            }else{
                continue;  //i j'ye eşit ise o adım atlanıp devam ediliyor
            }
        }
        polinom += terim;
    }

    return polinom;
}

int main() {

    printf("------ Lagrange Interpolasyon Polinomu ------\n\n");
    noktaSayisiAl();

    //F(x) = y değerlerinin alınması
    double x_degerleri[noktaSayisi], y_degerleri[noktaSayisi];
    printf("Olusturulacak polinom icin F(x) = y degerlerini girin:\n\n");
    for (int i = 0; i < noktaSayisi; i++) {
        printf("%d. F(x) Degeri: ", i);
        scanf("%lf", &x_degerleri[i]);
        printf("F(%.0lf) Degerinin sonucu: ", x_degerleri[i]);
        scanf("%lf", &y_degerleri[i]);
    }
    printf("\n");

    //Hesaplanacak değerin alınması
    double hesaplanacakDeger;
    printf("Polinomda hesaplanacak x degerini girin: ");
    scanf("%lf", &hesaplanacakDeger);

    //Sonucun hesaplanması ve yazdırılması
    double sonuc = lagrangeInterpolasyon(hesaplanacakDeger, x_degerleri, y_degerleri, noktaSayisi);
    printf("Sonuc: %lf\n", sonuc);

    return 0;
}
