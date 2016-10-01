/******************************************
Equilibrium point of an array
The sum of elements on both sides of the point
is equal

Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}

void FillVector(vector<int>& input, int size){	
	for(int i=0; i<size; ++i){
		input.push_back(rand()%100 - 40);	
	}
}

int EquilibriumPoint(vector<int>& input){
	long arrsum = 0, leftsum=input[0];
	for(int i=0; i<input.size(); i++){
		arrsum += input[i];
	}
	for(int i=1; i<input.size(); i++){
		cout << leftsum << " " << arrsum-leftsum-input[i] << endl;
		if(leftsum == arrsum-leftsum-input[i]){
			return i;
		}
		leftsum += input[i];
	}
	return -1;
} 

int main(){
	srand(time(0));
	vector<int> arr;
	FillVector(arr, 15);
	PrintVector(arr);
	cout << "Found equilibrium point at = " << EquilibriumPoint(arr) << endl;
	return 0;
}
