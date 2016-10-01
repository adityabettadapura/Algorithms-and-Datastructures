/****************************
Selection Sort algorithm

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
	}
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;

	for(int i=0; i<vec.size()-1; i++){
		int min = i;
		for(int j=i+1; j<vec.size(); j++){
			if(vec[min] > vec[j]) min = j;	
		}
		swap(vec[i],vec[min]);
	}	
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}
