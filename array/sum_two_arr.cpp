/******************************************
Subsetsum
Check if a subset of numbers can add up 
to the target
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool SumTwoVectors(vector<int>& veca, vector<int>& vecb, int target){
	sort(vecb.begin(), vecb.end());
	for(int i=0; i<veca.size(); i++){
		if(binary_search(vecb.begin(), vecb.end(), target-veca[i])) return true;
	}
	return false;
}

void FillVector(vector<int>& input, int size){	
	for(int i=0; i<size; ++i){
		input.push_back(rand()%100+i);	
	}
}

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}

int main(){
	srand(time(0));
	vector<int> veca, vecb;
	FillVector(veca,10);
	FillVector(vecb,10);
	PrintVector(veca);
	PrintVector(vecb);
	int target = rand()%100;
	bool result = SumTwoVectors(veca, vecb, target);
	cout << target << " present in the two vectors = " << result << endl;
	return 0;
}
