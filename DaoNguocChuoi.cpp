#include <iostream>
#include <string.h>

using namespace std;

void reserveString (char a[], int n ){
	    if(n == 0) {
        return;
    }
    cout << a[n-1];
    reserveString(a, n-1);
}

int main(){
	char a[100];
	cout <<"Nhap vao chuoi: ";
	fflush(stdin); gets(a); 
	int n = strlen(a);
	reserveString (a,n);
	return 0;
}
