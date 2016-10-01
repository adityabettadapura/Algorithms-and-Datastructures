/****************************
Binary search algorithm

Time: O(log n) per search

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

int BinarySearch(vector<int>& input, int lo, int hi, int key){
	int mid = (lo+hi)/2;

	if(input[mid] == key) return mid;
	else if(input[mid] > key) return BinarySearch(input, lo, mid, key);
	else if(input[mid] < key) return BinarySearch(input, mid+1, hi, key);
	
	return -1;
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
	PopulateVector(input, 1000000);
//	PrintVector(input);
	sort(input.begin(), input.end());
//	PrintVector(input);
	int key = input[rand()%input.size()];
	int idx = BinarySearch(input, 0, input.size()-1, key);
	if(idx >=0){
		cout << key << " found at " << idx+1 << " position" << endl;
	} else {
		cout << "key not found!" << endl;
	}
	return 0;
}
