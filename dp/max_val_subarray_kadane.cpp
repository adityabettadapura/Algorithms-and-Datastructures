/**********************************
Max value subarray using Kadane's algorithm

Author: Aditya Bettadapura
**********************************/
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

int Kadane(vector<int>& input){
	int maxsofar=0,maxhere=0;
	for(int i=0; i<input.size(); i++){
		maxhere = max(0,maxhere+input[i]);
		maxsofar = max(maxsofar, maxhere);
	}
	return maxsofar;
}

int main(){
	srand(time(0));
	vector<int> vec;
	for(int i=0; i<12; i++) vec.push_back(-9+rand()%19);
	PrintVector(vec);
	cout << Kadane(vec) << endl;
	return 0;	
}
