#include <iostream>
using namespace std;

class Date {
	private:
		int d, m, y;
	public:
		Date();
		Date(int, int, int);
		void Nhap();
		void Nhap(int, int, int);
		void Xuat();
		int operator >=(Date);
		int Ktra();
};

Date::Date() {}
Date::Date(int ngay, int thang, int nam) {
	d = ngay;
	m = thang;
	y = nam;
}

void Date::Nhap() {
	cout << "Nhap ngay: "; cin >> d;
	cout << "Nhap thang: "; cin >> m;
	cout << "Nhap nam: "; cin >> y;
	cin.ignore();
}

void Date::Nhap(int ngay, int thang, int nam) {
	d = ngay;
	m = thang;
	y = nam;
}

void Date::Xuat() {
	cout << "Ngay: " << d << "/" << m << "/" << y << endl;
}

int Date::operator >=(Date d1) {
	if (y > d1.y) return 1;
	else if (y == d1.y && m > d1.m) return 1;
	else if (y == d1.y && m == d1.m && d >= d1.d) return 1;
	else return 0;
}

int Date::Ktra() {
  return ((d > 0) && (m > 0) && (y > 0));
}


class HangHoa {
	private:
		string maHH, tenHH, donVi;
		Date ngayNhap;
		Date ngayXuat;
		int	soLuong;
		long long giaThanh;
	public:
		HangHoa();
		HangHoa(string, string, string, Date, Date, int, long long);
		void Nhap();
		void Xuat();
		string getMaHH();
		string getTenHH();
		string getDonVi();
		Date getNgayNhap();
		Date getNgayXuat();
		int	getSoLuong();
		long long getGiaThanh();
		int operator > (HangHoa);
		int operator >= (HangHoa);
		int operator < (HangHoa);
		friend void traoDoi(HangHoa&, HangHoa&);
};

HangHoa::HangHoa() {}
HangHoa::HangHoa(string maHH, string tenHH, string donVi,Date ngayNhap, Date ngayXuat,int soLuong, long long giaThanh) {
	this->maHH = maHH;
	this->tenHH = tenHH;
	this->donVi = donVi;
	this->ngayNhap = ngayNhap;
	this->ngayXuat = ngayXuat;
	this->soLuong = soLuong;
	this->giaThanh = giaThanh;
}

string HangHoa::getMaHH() {
	return maHH;
}

string HangHoa::getTenHH() {
	return tenHH;
}

string HangHoa::getDonVi() {
	return donVi;
}

Date HangHoa::getNgayNhap() {
	return ngayNhap;
}

Date HangHoa::getNgayXuat() {
	return ngayXuat;
}

int HangHoa::getSoLuong() {
	return soLuong;
}


long long HangHoa::getGiaThanh() {
	return giaThanh;
}

void HangHoa::Nhap() {
	cout << "Nhap ma hang hoa: "; getline(cin, maHH);
	cout << "Nhap ten hang hoa: "; getline(cin, tenHH);
	cout << "Nhap don vi hang hoa: "; getline(cin, donVi);
	cout << "Nhap ngay nhap kho: \n"; ngayNhap.Nhap();
		cout <<	"Nhap ngay xuat kho (neu co thi nhap 'Y' khong thi nhap 'N'): ";
  		if (cin.get() != 'N') {
    	ngayXuat.Nhap();
  		}
  		else {
   		ngayXuat.Nhap(-1, -1, -1);
  		}
	cout << "Nhap so luong hang hoa: "; cin >> soLuong;
	cout << "Nhap gia thanh hang hoa: "; cin >> giaThanh;
	cin.ignore();
}

void HangHoa::Xuat() {
	cout << " Ma HH: " << maHH << endl;
	cout << " Ten HH: " << tenHH << endl;
	cout << " Ngay nhap kho: "; ngayNhap.Xuat();
	cout << " Ngay xuat kho: "; 
  	if (ngayXuat.Ktra()) ngayXuat.Xuat();
  	else cout << "Chua xuat kho" << endl;
	cout << " So luong: " << soLuong <<" "<< donVi <<endl;
	cout << " Gia thanh hang hoa : " << giaThanh << " VND/"<< donVi<< endl;
	cout << " Tong tien cua loai hang hoa: "<<(long long) soLuong * giaThanh << " VND"<<endl;
}

int HangHoa::operator >(HangHoa hh) {
	return this->soLuong >= hh.soLuong;
}

int HangHoa::operator >=(HangHoa hh) {
	return this->giaThanh >= hh.giaThanh;
}

int HangHoa::operator <(HangHoa hh) {
	if (tenHH < hh.tenHH) return 1;
	else return 0;
}

void traoDoi(HangHoa &hh1, HangHoa &hh2) {
	HangHoa tmp = hh1;
	hh1 = hh2;
	hh2 = tmp;
}

int main() {
	
	HangHoa ds[100];
	int n;
	
	// Nhap thong tin HangHoa
	cout << "Nhap so luong hang hoa khac nhau: ";
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin cho hang hoa thu " << i + 1 << ": " << endl;
		ds[i].Nhap();
	}
	cout << "\n----------------------------------\n";
	cout << "\nDS hang hoa xuat nhap khau: \n";
	for (int i = 0; i < n; i++) {
		cout << "\nThong tin hang hoa thu " << i + 1 << endl;
		ds[i].Xuat();
	}
	
//	// Sap xep theo so luong lon nhat
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (!(ds[i] > ds[j])) traoDoi(ds[i], ds[j]);
//		}
//	}
//	cout << "\n----------------------------------\n";
//	cout << "\nDS hang hoa sau khi sap xep theo thu tu tang cua so luong tung loai hang: \n";
//	for (int i = 0; i < n; i++) {
//		cout << "\nThong tin hang hoa thu " << i + 1 << endl;
//		ds[i].Xuat();
//	}
//	
//	// Sap xep theo gia thanh
//	for(int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			if (!(ds[i] >= ds[j])) traoDoi(ds[i], ds[j]);
//		}
//	}
//	cout << "\n----------------------------------\n";
//	cout << "\nDS hang hoa sap xep theo giam dan cua gia thanh: \n";
//	for (int i = 0; i < n; i++) {
//		cout << "\nThong tin hang hoa thu " << i + 1 << endl;
//		ds[i].Xuat();
//	}
//	
//	// In ra ds hang hoa nhap hoac xuat sau ngay cu the nao do (chay 1 trong 2 Nhap hoac Xuat, khong chay dc ca 2 cung luc)
//	// Nhap: ngay cu the o day la 20/5/2000
//	Date ngay(20,5,2000);
//	cout << "\n----------------------------------\n";
//	cout << "\nCac hang hoa nhap sau 20/5/2000 la: \n";
//	for (int i = 0; i < n; i++) {
//		if (ds[i].getNgayNhap() >= ngay) ds[i].Xuat();
//	}
//	// Xuat : ngay cu the o day la 20/9/2000
//	Date ngay(20,9,2000);
//	cout << "\n----------------------------------\n";
//	cout << "\nCac hang hoa nhap sau 20/9/2000 la: \n";
//	for (int i = 0; i < n; i++) {
//		if (ds[i].getNgayXuat() >= ngay) ds[i].Xuat();
//	}
//	
//	// Tim theo ma hang hoa 
//	string maHH;
//	cout << "\n----------------------------------\n";
//	cout << "\nNhap ma hang hoa can tim: ";
//	getline(cin, maHH);
//	for (int i = 0; i < n; i++) {
//		if (maHH == ds[i].getMaHH()) {
//			cout << "\n----------------------------------\n";
//			cout << "\nThong tin hang hoa can tim: \n";
//			ds[i].Xuat();
//			break;
//		}
//		else if (i == n - 1) {
//			cout << "Khong tim thay";
//		}
//	}
	
	return 0;
}
