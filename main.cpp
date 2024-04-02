#include<bits/stdc++.h>
using namespace std;

struct User{
    string nama,password;
};

bool operator==(const User& user, const string& nama){
    return user.nama == nama;
}

void menu(bool stat){

    string Lokasi[4] = {"Rajabasa","Way Halim","Kedaton","Sukarame"};

    int asal, tujuan;
    if (stat)
    {
        cout<<"Berhasil Login!!!"<<endl;
        cout<<"Silakan masukkan lokasi awal dan tujuan"<<endl;
        cout<<"1. Rajabasa"<<endl;
        cout<<"2. Way Halim"<<endl;
        cout<<"3. Kedaton"<<endl;
        cout<<"4. Sukarame"<<endl<<endl;
        cout<<"Masukkan lokasi awal: ";
        cin>>asal;
        cout<<"Masukkan lokasi tujuan: ";
        cin>>tujuan;
    }else{
        cout<<"Berakhir";
    }
}

void addUser(vector<User>& user, string username, string pw){
    user.push_back({username, pw});
    cout<<"Akun Berhasil Dibuat!!!"<<endl;
}

void login(vector<User>& user){
    string uname, username,pw;
    vector<User>::iterator idx;

    cout<<"Selamat Datang Di Aplikasi Ojek Online"<<endl;
    cout << "Masukan Username : ";
    cin>>ws;
    getline(cin,uname);

    idx = find(user.begin(), user.end(), uname);
    if(idx != user.end()){
        cout<<"Masukkan password: ";
        cin>>pw;
        while(idx->password != pw){
            cout<<"Password Salah!!!"<<endl;
            cout<<"Masukkan Password : ";
            cin>>pw;
        }
        menu(1);
    }else{
        cout<<"Akun Tidak Ditemukan Ingin membuat baru?(Y/N)"<<endl;
        char ans;
        cin>>ans;
        if (ans == 'Y')
        {
            cout<<"Masukkan Username: ";
            cin>>username;
            cout<<"Masukkan Password: ";
            cin>>pw;
            addUser(user, username, pw);
            login(user);
        }else
        {
            menu(0);
        }
    }
}

int main(){
    vector<User> user;
    string uname;
    
    //Initial Database
    user.push_back({"Admin", "Admin"});
    user.push_back({"Someone", "123456"});
    user.push_back({"User1", "qwerty"});
    user.push_back({"User2", "hello123"});

    login(user);
    
    return 0;
}
