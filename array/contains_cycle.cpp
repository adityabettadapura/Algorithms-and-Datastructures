/******************************************
Determines whether a circular array of relative
indices contains a complete cycle
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

bool ContainsCycle(const vector<int>& input){

	if(input.size() == 0) return false;

	if(input.size() == 1){
		return input[0]==0;
	}

	int size = input.size();
	vector<bool> vec(input.size());
	int count = 0;
	int idx = 0;
	while(true){
		if(vec[idx]) break;	
		vec[idx] = true;
		++count;
		idx = (input[idx] + idx + size)%size;
		if(idx < 0) idx += size;
	}
	if(count == size) return true;

	return false;
}

int main(){
	vector<int> input;
	FillVector(input, 20);
	PrintVector(input);
	cout << "Input contains cycle? " << ContainsCycle(input) << endl;
	return 0;
}
