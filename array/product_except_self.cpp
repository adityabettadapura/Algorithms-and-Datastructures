/******************************************
Product of all the elements of the array 
except current element

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
		input.push_back(1+rand()%5);	
	}
}

void ProductExceptSelf(vector<int>& input){
	if(input.size() < 2) exit(0);
	
	vector<int> left;
	vector<int> right;

	left.push_back(0);
	right.push_back(0);
	for(int i=1; i<input.size(); i++){
		left.push_back()
	}
}

int main(){
	vector<int> vec;
	FillVector(vec, 5);
	PrintVector(vec);
	ProductExceptSelf(vec);
	return 0;
}
