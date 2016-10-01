/****************************
Insertion Sort algorithm

Time: O(n^2) worst case
Space: O(n)

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;


void InsertionSort(vector<int>& input){
	for(int i=0; i<input.size()-1; i++){
		int j=i+1;
		while(j>0 && input[j] < input[j-1]){
			swap(input[j], input[j-1]);
			--j;
		}	
	}	
}

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

int main(){
	srand(time(NULL));
	vector<int> input;
	PopulateVector(input, 10);
	PrintVector(input);
	InsertionSort(input);
//	sort(input.begin(), input.end());
	PrintVector(input);
	
	return 0;	
}
