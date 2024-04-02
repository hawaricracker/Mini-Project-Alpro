#include<bits/stdc++.h>
using namespace std;

struct User{
    string nama;
    int id;
};

string Lokasi[4] = {"Rajabasa","Way Halim","Kedaton","Sukarame"};

int main(){
    int asal,tujuan;
    cout<<"Selamat Datang Di Aplikasi Ojek Online"<<endl;
    cout<<"Silakan masukkan lokasi awal dan tujuan"<<endl;
    cout<<"1. Rajabasa"<<endl;
    cout<<"2. Way Halim"<<endl;
    cout<<"3. Kedaton"<<endl;
    cout<<"4. Sukarame"<<endl<<endl;
    cout<<"Masukkan lokasi awal: ";
    cin>>asal;
    cout<<"Masukkan lokasi tujuan: ";
    cin>>tujuan;
    return 0;
}
