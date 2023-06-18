#include <bits/stdc++.h>

using namespace std;

void BubbleSort(int a[], int n){
	for (int i = 0; i < n-1; i++){
		for (int j = n-1; j>i; j--){
			if (a[i] < a[j]){
				swap(a[i], a[j]);
			}
		}
	}
}

int main(){
	int a[] = {34, 74, 94, 84, 54, 24};
	BubbleSort(a,6);
	for (int i = 0; i < 6; i++){
		cout <<a[i] <<"\t";
	}
	return 0;
}
