/*************************
KMP string matching algorithm

Author: Aditya Bettadapura
*************************/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}

vector<int> ComputeLPS(string& needle){
	vector<int> table;
	for(int i=0; i<needle.size(); i++){
		table.push_back(0);
	}
	int i=1, len=0;

	while(i<needle.size()){
		if(needle[i] == needle[len]){
			++len;
			table[i] = len;
			++i;
		} else {
			//len == 0
			if(len == 0){
				table[i] = 0;
				++i;
			} else {
				len = table[len-1];
			}
		}
	}
	return table;	
}

bool KMP(string& haystack, string& needle){
	if(haystack.length() < needle.length()) return false;
	if(haystack.length() == needle.length()) return haystack == needle;

	vector<int> lps = ComputeLPS(needle);
	PrintVector(lps);

	int i=0,j=0;
	while(i<haystack.size()){
		if(needle[j] == haystack[i]){
			++i;
			++j;
		}
		if(j==needle.size()){
			cout << "Pattern found at " << i << endl;
			return true;
		} 

		else if(i < haystack.size() && needle[j] != haystack[i]){
			if (j==0) {
				++i;
			} else {
				j = lps[j-1];
			}
		}
	}
	return false;
}

int main(){
	string haystack = "bacbababaabcbab";
	string needle = "abababca";
	bool result = KMP(haystack, needle);
	return 0;
}
