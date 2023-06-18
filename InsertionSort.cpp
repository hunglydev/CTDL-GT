#include <bits/stdc++.h>

using namespace std;

void InsertSort(int a[], int n){
	for (int i = 0; i < n; i++){
		int temp = a[i];
		int j = i-1;
		while(j > -1 && a[j] > temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}

int main(){
	int a[] = {50, 8, 34, 6, 98, 17, 83, 25, 66, 42, 21, 59, 63, 71, 85};
	int n = sizeof(a)/sizeof(a[0]);
	InsertSort(a,n);
		for (int i = 0; i < n; i++){
		cout <<a[i] <<"\t";
	}
	return 0;
}
