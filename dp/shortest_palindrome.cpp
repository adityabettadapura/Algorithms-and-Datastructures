/******************************************
Shortest palindrome
This program computes the minimum number 
of letters that have to be inserted before
the original string to make it a palindrome

Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int KMP(string& str){
	int len = 0;
	int i=1;
	vector<int> table;
	for(int i=0; i<str.size(); i++)
		table.push_back(0);

	while(i < str.size()){
		if(str[len] == str[i]){
			++len;
			table[i] = len;
			++i;
		} else {
			if(len == 0){
				table[i] = 0;
				++i;
			}else{
				len = table[len-1];
			}
		}
	}
	return table[str.size()-1];
}

string MakePalindrome(string& s1){
	string temp = s1;
	reverse(s1.begin(), s1.end());
	temp += s1;
	
	int remove = KMP(temp);
	string result(temp.begin()+s1.size(), temp.end()-remove);

	return result;
}

int main(){
	string s1 = "ananab";
	cout << "Add " << MakePalindrome(s1) << " To make " << s1 << " a palindrome" << endl;
}
