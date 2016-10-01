/****************************
Merge Sort algorithm

Time: O(nlog n) worst case
Space: O(nlog n)

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

vector<int> Merge(vector<int>& left, vector<int>& right){
	int i=0,j=0;
	vector<int> out;
	while(i<left.size() && j<right.size() ){
		if(left[i] <= right[j]){
			out.push_back(left[i]);
			++i;
		} else {
			out.push_back(right[j]);
			++j;
		}
	}
	
	while(i<left.size()){
		out.push_back(left[i]);
		++i;
	}
	
	while(j<right.size()){
		out.push_back(right[j]);
		++j;
	}
	return out;
}

vector<int> MergeSort(vector<int>& input){
	if(input.size() == 1) return input;

	vector<int>::iterator mid = input.begin()+input.size()/2;
	vector<int> left(input.begin(), mid);
	vector<int> right(mid, input.end() );
	
	left = MergeSort(left);
	right = MergeSort(right);

	return Merge(left,right);
}

int main(){
	vector<int> vec;
	for(int i=0; i<6000; i++){
		vec.push_back(rand()%12000);
//		cout << vec[i] << " ";
	}
	cout << endl;

	vector<int> result = MergeSort(vec);

	for(int i=0; i<result.size(); i++){
//		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}
