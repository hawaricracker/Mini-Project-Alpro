#include<bits/stdc++.h>
using namespace std;

struct User{
    string nama,password;
};

string Lokasi[4] = {"Rajabasa","Way Halim","Kedaton","Sukarame"};

int cari(const User user[], string target){
    for(int i = 0; i < 4;i++){
        if(user[i].nama == target){
            return i;
            break;
        }
    }
    return -1;
}

int main(){
    int asal, tujuan,idx;
    User user[4];
    string uname,pw;
    
    //Database
    user[0].nama = "Admin";
    user[0].password = "Admin";
    user[1].nama = "Someone";
    user[1].password = "123456";
    user[2].nama = "User1";
    user[2].password = "qwerty";
    user[3].nama = "User2";
    user[3].password = "hello123";
    
    cout << "Masukan Username : ";
    getline(cin,uname);
    idx = cari(user, uname);
    if(idx >= 0){
        cout<<"Masukkan password: ";
        cin>>pw;
        while(user[idx].password != pw){
            cout<<"Password Salah!!!"<<endl;
            cout<<"Masukkan Password : ";
            cin>>pw;
        }
    }
    
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
