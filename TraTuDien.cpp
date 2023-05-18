#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main (){
    string dictionary[] = {"apple", "banana", "cherry", "grape", "kiwi", "orange", "peach", "pear", "pineapple", "strawberry"};
	string str1;
	cout <<"Nhap vao tu can tim kiem: ";
	cin >> str1; fflush(stdin);
	int left = 0;
	int right = dictionary.size();
	cout <<"so phan tu mang: "  << right;
	return 0;
}
