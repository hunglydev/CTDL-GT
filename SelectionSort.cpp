#include <bits/stdc++.h>

using namespace std;

void SelectionSort (int a[], int n){
	for (int i = 0; i < n; i++){
		int m = i;
		for (int j = m; j < n; j++){
			if (a[j] > a[m]){
				m = j;
			}
		}
		swap(a[i], a[m]);
	}
}

int main(){
	int a[] = {50, 8, 34, 6, 98, 17, 83, 25, 66, 42, 21, 59, 63, 71, 85};
	int n = sizeof(a)/sizeof(a[0]);
	SelectionSort(a,n);
	for (int i = 0; i < n; i++){
		cout <<a[i] <<"\t";
	}
	return 0;
}
