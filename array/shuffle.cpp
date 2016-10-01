/******************************************
Shuffle the elements of an array
Initial array: a1 a2 a3...an b1 b2 b3... bn
Final array: a1 b1 a2 b2... an bn

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
	for(int i=0; i<size/2; ++i){
		input.push_back(0);	
	}
	for(int i=size/2; i<size; ++i){
		input.push_back(1);	
	}
}

void Reverse(vector<int>& input, int start, int end){
	for(int i=start; i<end; i++){
		input[i] = input[end-i];
	}
}

void Shuffle(vector<int>& input, int lo, int hi){
	if(input.size() == 2) return;

	int mid = (lo+hi)/2;
	int i = mid-(mid/2);
	int j = mid+(mid/2);

	Reverse(input, i, j);
	Shuffle(input, lo, mid);	
	Shuffle(input, mid+1, hi);
	
	return;
}

int main(){
	vector<int> input;
	FillVector(input, 20);
	PrintVector(input);
	Shuffle(input, 0, input.size()-1);
	PrintVector(input);	
	return 0;
}
