/***************************************
First unique character in a string
Author: Aditya Bettadapura
***************************************/
#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>

using namespace std;
int firstUniqChar(string s) {
	if(s.size() == 0) return -1;
	if(s.size() == 1) return 0;

	unordered_map<char, int> charCount;
	unordered_map<char, int> charIdx;
	for(int i=0; i<s.size(); i++){
		charCount[s[i]] += 1;
		charIdx[s[i]] = i;
	}

	int min = INT_MAX, idx=-1;
	unordered_map<char, int>::iterator itr = charCount.begin();
	while(itr != charCount.end()){
		if(itr->second == 1 && charIdx[itr->first] < min){
			idx = charIdx[itr->first];
			min = charIdx[itr->first];
		}
		++itr;
	}

	return idx;
}

int main(){
	string input = "abracladabra";
	int result = firstUniqChar(input);
	if(result >= 0){
		cout << "First unique character = " << input[result] << endl;
	} else { 
		cout << "No unique character" << endl;
	}
	return 0;
}
