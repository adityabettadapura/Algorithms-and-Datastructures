/****************************
Interpolation search

Time: O(log(log n)) on average

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

int InterpolSearch(vector<int>& input, int lo, int hi, int key){
	
	int mid = ((key-input[lo])*(hi-lo))/(input[hi]-input[lo]);

	if(input[mid] == key) return mid;
	else if(input[mid] > key) return InterpolSearch(input, lo, mid, key);
	else if(input[mid] < key) return InterpolSearch(input, mid+1, hi, key);
	
	return -1;
}

void PopulateVector(vector<int>& input, int size){
	int seed = rand()%(size*2);
	for(int i=0; i<size; i++){
		input.push_back(seed+i);
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
	int idx = InterpolSearch(input, 0, input.size()-1, key);
	if(idx >=0){
		cout << key << " found at " << idx+1 << " position" << endl;
	} else {
		cout << "key not found!" << endl;
	}
	return 0;
}
