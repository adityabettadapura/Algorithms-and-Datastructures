/*************************************
Generates all permutations of a string
Author: Aditya Bettadapura
*************************************/
#include<iostream>
#include<cstring>
#include<unordered_set>
#include<algorithm>

using namespace std;

void PrintSet(unordered_set<string>& in){
	auto it = in.begin();
	while(it != in.end()){
		cout << *it << " ";
		++it;
	}
	cout << endl;
}	

unordered_set<string> GenerateStrPerm(string& input){
	unordered_set<string> perm;
	if(input.size() == 0) return perm;
	if(input.size() == 1) {perm.insert(input); return perm;}
	if(input.size() == 2) {
		perm.insert(input);
		reverse(input.begin(), input.end());
		perm.insert(input);
		return perm;
	}
	string rem(input.begin()+1, input.end());
	unordered_set<string> temp = GenerateStrPerm(rem);
	auto it = temp.begin();
	while(it != temp.end() ){
		for(int i=0; i<(*it).size()+1; ++i){
			string t = *it;
			t.insert(i, 1, input[0]);
			perm.insert(t);
		}
		++it;
	}
	return perm;		
}

int main(){
	string input="";
	cin >> input;
	
	unordered_set<string> output = GenerateStrPerm(input);
	PrintSet(output);
	return 0;
}
