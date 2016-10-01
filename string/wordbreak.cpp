/***************************************
Checks if given string has valid words
Author: Aditya Bettadapura
***************************************/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

bool HasValidWords(string& input, unordered_set<string>& dict){
	if(input.size() == 0){
		if(dict.find(input) != dict.end()) return true;
		else return false;
	}
	bool validwords[input.size()] = {false};
	
	string temp="";
	for(int i=0; i<input.size(); i++){
		temp += input[i];
		if(dict.find(temp) != dict.end()){
			validwords[i] = true;
			temp = "";
		}
	}	
	
	if(validwords[input.size()-1] != true) return false;
	return true;	
}

int main(){
	string input = "indiahelloworldipsumloren";	
	unordered_set<string> dict({"", "hello", "world", "loren", "ipsum", "india"});
	
	bool output = HasValidWords(input, dict);
	
	if(output){ cout << "Has valid words!" << endl; }
	else { cout << "No valid words... Doh!" << endl; }

	return 0;
}
