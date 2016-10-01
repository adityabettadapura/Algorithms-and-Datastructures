/******************************************
Binary search in a rotated array by 
finding pivot point
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}

int FindPivot(vector<int>& vec, int lo, int hi){
	if(vec[lo] < vec[hi]) return -1;
	int mid = (lo+hi)/2;
	
	if(vec[mid] < vec[mid+1] && vec[mid] < vec[mid+1]) return mid;
	if(vec[mid] >= vec[lo]){
		vector<int> temp(vec.begin()+mid, vec.end());
		return FindPivot(temp, mid, hi);
	} else if (vec[mid] < vec[lo]){
		vector<int> temp(vec.begin(), vec.begin()+mid);
		return FindPivot(temp, lo, mid);
	}
	return -1;		
}
bool Find(vector<int>& input, int key, int pidx){
	if(pidx == -1) return binary_search(input.begin(), input.end(), key);
	if(key < input[0]) return binary_search(input.begin()+pidx, input.end(), key);
	if(key > input[0]) return binary_search(input.begin(), input.begin()+pidx, key);

	return false;
}

int main(){
	vector<int> vec = {4,5,6,7,1,2,3};
	PrintVector(vec);
	int key=0;
	cin >> key;
	int pidx = FindPivot(vec, 0, vec.size()-1);
	cout << pidx << endl;
	bool result = Find(vec, key, pidx);
	cout << result << endl;
	return 0;	
}
