#include <bits/stdc++.h>
#define MAX 8

using namespace std;



struct SinhVien{
	int maSV;
	char hoDem[25];
	char ten[8];
	char gioiTinh[4];
	int namSinh;
	double diemTK;
};

struct List{
	int count;
	SinhVien e[MAX];
};

void Create (List &L){
	L.count = -1;
}

int Empty (List &L){
	return L.count == -1;
}

int Full (List L){
	return L.count == MAX - 1;
}

int Add (List &L, SinhVien sv){
	if (Full(L)){
		return 0;
	}
	else{
		L.count++;
		L.e[L.count] = sv;
		return 1;
	}
}

SinhVien taoSV (int maSV, char *hoDem, char *Ten, char *gioiTinh, int namSinh, double diemTK){
	SinhVien sv;
	sv.maSV = maSV;
	strcpy (sv.hoDem, hoDem);
	strcpy (sv.ten, Ten);
	strcpy (sv.gioiTinh, gioiTinh);
	sv.namSinh = namSinh;
	sv.diemTK = diemTK;
	return sv;
}

void Input (List &L){
	Add (L, taoSV(1001, "Tran Van", "Thanh", "Nam", 1997, 7.5));
	Add (L, taoSV(1002, "Nguyen Thi", "Huong", "Nu", 1998, 8.5));
	Add (L, taoSV(1003, "Nguyen Van", "Binh", "Nam", 1997, 7.5));
	Add (L, taoSV(1004, "Bui Thi", "Hong", "Nu", 1996, 9));
	Add (L, taoSV(1005, "Duong Van", "Giang", "Nam", 1997, 9.5));
}

void HienThiSinhVien (SinhVien sv){
	cout << fixed;
	cout << setw(5) << right << sv.maSV <<" ";
	cout << setw(12) << left << sv.hoDem;
	cout << setw(6) << left << sv.ten;
	cout << setw(8) << left << sv.gioiTinh;
	cout << setw(9) << right << sv.namSinh;
	cout << setw(12) << setprecision(1) << sv.diemTK << endl;
}

void HienThiDanhSach (List L){
	cout << setw(6) << left << "Ma SV" ;
	cout << setw(18) << left << "Ho va ten";
	cout << setw(13) << left << "Gioi tinh";
	cout << setw (10) << left <<"Nam sinh";
	cout << setw(10) << left <<"Diem TK" << endl;
	for (int i = 0; i <= L.count; i++){
		HienThiSinhVien(L.e[i]);
	}
} 

void XoaSinhVienDauTien(List &L){
	if (Empty(L)){
		cout <<"\nDanh sach rong" << endl;
		return;
	}
	for (int i = 1; i <= L.count; i++){
		L.e[i-1] = L.e[i];
	} 
	L.count--;
}

void ChenViTriThu3 (List &L){
	SinhVien sv;
	sv = taoSV(1006, "Le Thi", "Doan", "Nu", 1998, 8);
	for (int i = L.count; i>= 2; i--){
		L.e[i+1] = L.e[i];
	}
	L.e[2] = sv;
	L.count++;
}

void SapXep(List &L){
	for ( int i = 0; i < L.count; i++){
		int m = i;
		for (int j = i=1; j <= L.count; j++){
			if (strcmpi(L.e[j].ten, L.e[m].ten) < 0){
				m = j;
			} 
		}
		SinhVien tg = L.e[i];
		L.e[i] = L.e[m];
		L.e[m] = tg;
	}
}

int main (){
	List L;
	SinhVien sv;
	Create(L);
	Input(L);
	cout <<"==========DANH SACH SINH VIEN===========" << endl;
	HienThiDanhSach(L); 
	cout <<"-------------------------------" << endl;
	XoaSinhVienDauTien(L);
	cout <<"==========DANH SACH SINH VIEN SAU KHI XOA================" << endl;
	HienThiDanhSach(L);
	cout <<"----------------------------" << endl;
	ChenViTriThu3(L);
	cout<<"===========DANH SACH SINH VIEN SAU KHI CHEN==================" << endl;
	HienThiDanhSach(L);
	return 0;
}
