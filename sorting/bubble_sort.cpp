/****************************
Bubble Sort algorithm

Time: O(n^2) worst case
Space: O(n)

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

int main(){
	vector<int> vec;
	for(int i=0; i<12; i++){
		vec.push_back(rand()%30);
		cout << vec[i] << " ";
	}
	cout << endl;

	for(int i=0; i<vec.size()-1; i++){
		for(int j=0; j<vec.size()-1-i; j++){
			if(vec[j+1]<vec[j]) swap(vec[j], vec[j+1]);
		}
	}	
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}
