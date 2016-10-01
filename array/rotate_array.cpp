/******************************************
Rotate array by k positions
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<cstdlib>

using namespace std;

void Reverse(int arr[], int m){
	for(int i=0; i<m/2; i++){
		swap(arr[i], arr[m-i-1]);
	}
}

void Rotate(int arr[], int k, int n){
	Reverse(arr,k);
	Reverse(arr,n);
	Reverse(arr, n-k);
}

int main(){
	int arr[12];
	int k=0;
	cin >> k;
	if(k>12) k=k%12;
	for(int i=0; i<12; i++){
		arr[i] = rand()%20;
		cout << arr[i] << " ";
	}
	cout << endl;
	
	Rotate(arr, k, 12);
	
	for(int i=0; i<12; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	
	return 0;
}
