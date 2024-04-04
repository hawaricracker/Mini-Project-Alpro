#include<bits/stdc++.h>
using namespace std;

struct User{
    string nama,password;
};

bool operator==(const User& user, const string& nama){
    return user.nama == nama;
}

int Gacha(int kendaraan){
    random_device rd;
	mt19937 gen(rd()*kendaraan);
	uniform_int_distribution<int> distr(1, 10); 
    return distr(gen);
}

int Total(int harga, double diskon){
    return harga - (harga*double(diskon/100));
}

int Discount(){
    return ((Gacha(1)*10) + Gacha(1))/ Gacha(1);
}

int Harga(int asal, int tujuan, int kendaraan){
    if (asal == tujuan)
    {
        return 0;
    }else if (tujuan == 0)
    {
        srand(time(0));
        int N = 100000;
        int ip = rand()%N;
        return (Gacha(kendaraan)*10000)+ip;
    }else
    {
        return Harga(asal-1, tujuan-1, kendaraan) + Harga(asal-1, tujuan, kendaraan);
    }
}

void menu(bool stat){

    string Lokasi[4] = {"Rajabasa","Way Halim","Kedaton","Sukarame"};

    int asal, tujuan, kendaraan;
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
        cout<<"Pilih Kendaraan"<<endl;
        cout<<"1. Motor"<<endl;
        cout<<"2. Mobil"<<endl;
        cout<<"Jawab: ";
        cin>>kendaraan;
        int harga = Harga(asal, tujuan, kendaraan);
	if(tujuan,asal >= 1 && tujuan,asal <= 4 && kendaraan <= 2 && kendaraan >= 1) {
	        cout<<"Menghitung Harga....."<<endl;
	        cout<<"Harga yang didapat adalah: "<<harga<<endl;
	        cout<<"Menghitung Discount....."<<endl;
	        double discount = Discount();
	        cout<<"Discount yang didapat adalah: "<<discount<<"%"<<endl;
	        cout<<"Harga total adalah: "<<Total(harga, discount)<<endl;
	} else {
		cout << "error pada inputan asal, tujuan, dan kendaraan" << endl;
	}
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
