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

int MaxSubarray(vector<int>& input, int k){
	int maxsum=0,sum=0;
	for(int i=0; i<k; i++) sum += input[i];
	maxsum=sum;
	for(int i=k; i<input.size(); i++){
		sum = sum+input[i]-input[i-k];
		maxsum = sum>maxsum?sum:maxsum;
	}
	return maxsum;
}

int main(){
	vector<int> vec;
	int k=0;
	cin >> k;
	for(int i=0; i<12; i++) vec.push_back(-9+rand()%19);
	PrintVector(vec);
	cout << MaxSubarray(vec,k) << endl;
	return 0;	
}
