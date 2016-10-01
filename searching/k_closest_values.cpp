/****************************
K closest values to a target

Time: O(nlogn) to sort the input
O(log n + k) for the k values

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;


void PrintVector(vector<int>& input);

void FindKClosest(vector<int>& input, int key, int k){
	cout << "key = " << key << endl;
	vector<int>::iterator low, up;
	low = lower_bound(input.begin(), input.end(), key);
	up = upper_bound(input.begin(), input.end(), key);
	int size = k;
	--low;
	vector<int> result;
	while(size){
		while(low != input.begin() && up != input.end()){
			int diff1 = *low-key;
			int diff2 = *up-key;
			if(diff1<diff2){
				result.push_back(*low);
				--low; --size;
			} else { 
				result.push_back(*up);
				++up; --size;
			}
		}	
		while(low != input.begin()){
			result.push_back(*low);
			--low; --size;
		}	
		while(up != input.end()){
			result.push_back(*up);
			++up; --size;
		}	
	}
	PrintVector(result);	
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
	PopulateVector(input, 15);
	PrintVector(input);
	sort(input.begin(), input.end());
	PrintVector(input);
	int key = input[rand()%input.size()];
	int k = rand()%(input.size()/2);
	FindKClosest(input, key, k);
	return 0;
}
