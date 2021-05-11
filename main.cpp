#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gecikme.h"
using namespace std;

class kitap{
    int miktar;
    float fiyat;
    char isim[20];
    char yazar[20];
    char tarih[20];
    char aciklama[20];
    char kiralik[20];

public:
    void detayEkle(){
        cout<<"Kitabin Ismini Giriniz: ";
        cin>>isim;
        cout<<"Kitabin Miktarini Giriniz: ";
        cin>>miktar;
        cout<<"Kitabin Yazarini Giriniz: ";
        cin>>yazar;
        cout<<"Kitabin Fiyatini Giriniz: ";
        cin>>fiyat;
        cout<<"Kitabin Satin Alinma Tarihini Giriniz: ";
        cin>>tarih;
        cout<<"Kitabin Aciklamasini Giriniz: ";
        cin>>aciklama;
    }

    void veriGoster(){
        cout<<"Kitabin Miktari: "<<miktar<<endl;
        cout<<"Kitabin Fiyati: "<<fiyat<<endl;
        cout<<"Kitabin Adi: "<<isim<<endl;
        cout<<"Kitabin Yazari: "<<yazar<<endl;
        cout<<"Kitabin Satin Alinma Tarihi: "<<tarih<<endl;
        cout<<"Kitabin Aciklamasi: "<<aciklama<<endl;
    }

    char* isimAl(){
        return isim;
    }

    int miktarAl(){
        return miktar;
    }
};

void kayitEkle(){
    fstream dosya;
    dosya.open("kitap12.dat",ios::binary|ios::app|ios::out);
    dosya.seekg(0);
    gecikme();

    char tercih;
    kitap kitap;

    do{
        cout<<"Kitap Bilgilerini Giriniz: "<<endl;
        kitap.detayEkle();
        dosya.write(reinterpret_cast<char *>(&kitap),sizeof(kitap));
        cout<<"Baska Bir Kitap Kaydi Girecek Misiniz?(e/h): ";
        cin>>tercih;
    }while(tercih=='e');

    dosya.close();
}

void kayitGoster(){
    fstream dosya;
    kitap kitap;
    dosya.open("kitap12.dat",ios::binary|ios::in);
    dosya.read(reinterpret_cast<char *>(&kitap),sizeof(kitap));

    while(!dosya.eof()){
        kitap.veriGoster();
        dosya.read(reinterpret_cast<char *>(&kitap),sizeof(kitap));
        cout<<endl;
    }

    dosya.close();
}

void ara(){
    cout<<"Arama Menusune Hos Geldiniz"<<endl;
    fstream dosya;
    kitap kitap;

    dosya.open("kitap12.dat",ios::binary|ios::in);
    dosya.read(reinterpret_cast<char *>(&kitap),sizeof(kitap));

    char dizi[30];
    cin>>dizi;

    while(!dosya.eof()){
        if(strcmp(dizi,kitap.isimAl())==0){
            kitap.veriGoster();
        }

        dosya.read(reinterpret_cast<char *>(&kitap),sizeof(kitap));
    }
}

void kira(){
    system("cls");
    cout<<"Kitap Kiralamak Icin"<<endl;
    kayitGoster();

    int tercih2;
    char kitapIsmi[20];
    cout<<"Kiralamak Istediginiz Kitabin Adini Giriniz: "<<endl;
    cin>>kitapIsmi;

    fstream dosya;
    kitap kitap;

    dosya.open("kitap12.dat",ios::binary|ios::in);
    dosya.read(reinterpret_cast<char *>(&kitap),sizeof(kitap));

    while(!dosya.eof()){
        if(strcmp(kitapIsmi,kitap.isimAl())==0){
            if(kitap.miktarAl()==0){
                cout<<"Stok Tukendi";
            }
            else{
                kitap.veriGoster();
                cout<<"Kitabi Kiralamak Istiyor Musun (0/1)?"<<endl;
                cin>>tercih2;

                if(tercih2==1){
                    cout<<"Kitap Kiralandi";
                }
                else{
                    kira();
                }
            }
        }

    }
    dosya.read(reinterpret_cast<char *>(&kitap),sizeof(kitap));

}

int main(){
    kayitEkle();
    kayitGoster();
    kira();
}











