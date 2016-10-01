/***************************************
Remove spaces in a string
Author: Aditya Bettadapura
***************************************/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void RemoveSpaces(string& input){
	string::iterator it = input.begin();
	while(it != input.end() ){
		if(*it == ' '){
			it = input.erase(it);
		} else {
			++it;
		}
	}
}

int main(){
	string input="";
	getline(cin,input);
	cout << "Original String = " << input << endl;
	RemoveSpaces(input);
	cout << "Spaces removed= " << input << endl;
	return 0;
}
