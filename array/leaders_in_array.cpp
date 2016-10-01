/******************************************
Leaders in an array
Set of numbers who do not have any larger numbers
to their right
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}

void Leaders(vector<int>& input){
	vector<int> output;
	output.push_back(input[input.size()-1]);
	int maxsofar = input[input.size()-1];
	for(int i=input.size()-1; i>0; i--){
		if(input[i]>maxsofar){
			output.push_back(input[i]);
			maxsofar = input[i];
		}
	}
	PrintVector(output);
}

int main(){
	vector<int> vec;
	for(int i=0; i<18; i++) vec.push_back(-9+rand()%25);
	PrintVector(vec);
	Leaders(vec);
	return 0;	
}
