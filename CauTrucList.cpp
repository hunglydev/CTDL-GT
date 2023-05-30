#include <bits/stdc++.h>

using namespace std;

struct SinhVien{
	int maSV;
	char hoDem[25];
	char ten[9];
	char gioiTinh[5];
	int namSinh;
	double diemTK;
};

struct Node{
	SinhVien infor;
	Node *next;
};

typedef Node* Tro;

void Create (Tro &L){
	L = NULL;
}

int Empty (Tro L){
	return L == NULL;
}

SinhVien TaoSV(int maSV, char hoDem[25], char ten[9], char gioiTinh[5], int namSinh, double diemTK){
	SinhVien sv;
	sv.maSV = maSV;
	strcpy(sv.hoDem, hoDem);
	strcpy (sv.ten, ten);
	strcpy (sv.gioiTinh, gioiTinh);
	sv.namSinh = namSinh;
	sv.diemTK = diemTK;
	return sv;
}

void Display (SinhVien sv){
	cout << fixed;
	cout << setw(6) << left << sv.maSV;
	cout << setw(15) << sv.hoDem;
	cout << setw(8) << sv.ten;
	cout << setw(7) << sv.gioiTinh;
	cout << setw(8) << right << sv.namSinh;
	cout << setw(7) << setprecision(2) << sv.diemTK;
 }

void Add (Tro &L, SinhVien sv){
	Tro Q = L, P = new Node;
	P -> infor = sv;
	P -> next = NULL;
	if (Empty(L)){
		L = P;
	}
	else{
		while (Q -> next != NULL){
			Q = Q -> next;
		}
		Q -> next = P;
	}
}

void TaoDS (Tro &L){
	Add (L, TaoSV (1001, "Tran Van", "Thanh", "Nam", 1997, 7.5));
	Add (L, TaoSV (1002, "Nguyen Thi", "Hong", "Nu", 1997, 8));
	Add (L, TaoSV (1003, "Tran Minh", "Phuong", "Nu", 2000, 9.5));
	Add (L, TaoSV (1004, "Tran Van", "Hiep", "Nam", 1999, 8.5));
	Add (L, TaoSV (1005, "Nguyen Van", "Nam", "Nam", 1997, 8.5));
}

void HTDS (Tro L){
	Tro Q = L;
	while (Q != NULL){
		Display(Q -> infor);
		Q = Q -> next;
	}
	cout <<"-----------------------------------" << endl;
}

void XoaPhanTuDauTien (Tro &L){
	if (Empty(L)){
		cout <<"Danh sach rong" << endl;
		return ;
	}
	Tro Q = L;
	L = L -> next;
	delete Q;
}

Tro SearchK (Tro L, int k){
	int d = 1;
	Tro Q = L;
	while (d < k - 1&& Q -> next != NULL){
		d++;
		Q = Q -> next;
	}
	if (d < k-1){
		return NULL;
	}
	return Q;
}

void Insert (Tro &L, Tro Q, SinhVien sv){
	Tro P;
	P = new Node;
	P -> infor = sv;
	P -> next = Q -> next;
	Q -> next = P;
}

void ChenVaoViTriThu3 (Tro &L){
	Tro Q = SearchK (L, 3);
	if ( Q == NULL){
		cout <<"Khong tim the vi tri chen" << endl;
		return ;
	}
	Insert(L, Q, TaoSV(1006, "Ly Hai", "Hung", "Nam", 2003, 10));
}

void SapXepChon (Tro &L){
	Tro P, Q, M;
	P = L;
	while (P -> next != NULL){
		M = P;
		Q = P -> next;
		while (Q != NULL){
			if (strcmp(Q -> infor.ten, M -> infor.ten) < 0){
				M = Q;
			}
			Q = Q->next;
		}
		SinhVien tg = P->infor;
		P->infor = M->infor;
		M->infor = tg;
		P = P->next;
	}
}

int main(){
	Tro L, Create (L); TaoDS(L);
	cout <<"Hien thi danh sach vua tao " << endl ;
	HTDS(L);
	return 0;
}
