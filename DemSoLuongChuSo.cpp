#include <iostream>

using namespace std;

int countDigit (int num){
	if (num == 0) {
		return 0;
	}
	return 1 + countDigit(num/10);
}

int main(){
	cout <<"Nhap vao so nguyen duong: ";
	int n; cin >> n;	
	cout << "So luong chu so: " << countDigit(n);
	return 0;
}
