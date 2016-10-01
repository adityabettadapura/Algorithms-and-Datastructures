/****************************
Wave Sort algorithm
Sorts elements such that
a[0] > a[1] < a[2] ...

Time: O(n)
Space: O(n)

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void PopulateVector(vector<int>& input, int size){
	for(int i=0; i<size; i++){
		input.push_back(rand()%(size*2));
	}
}

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}

void WaveSort(vector<int>& input){
	if(input[0] < input[1]) swap(input[0], input[1]);
	for(int i=2; i<input.size()-1; i+=2){
		if(input[i] < input[i-1]) swap(input[i], input[i-1]);
		if(input[i] < input[i+1]) swap(input[i], input[i+1]);
	}
}

int main(){
	srand(time(NULL));
	vector<int> input;
	PopulateVector(input, 10);
	PrintVector(input);
	WaveSort(input);
	PrintVector(input);
	
	return 0;	
}
