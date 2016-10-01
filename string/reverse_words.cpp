/***************************************
Reverse words in a string
Example:
Original: Hello World loren ipsum
Reversed: ipsum loren World Hello
Author: Aditya Bettadapura
***************************************/
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string ReverseWords(string& input){
	string temp(input);
	reverse(temp.begin(), temp.end() );
	std::size_t pos = 0;
	std::size_t next = temp.find_first_of(" ");
	while(next != std::string::npos){
		reverse(temp.begin()+pos, temp.begin()+next);
		pos = next+1;
		next = temp.find_first_of(" ", pos+1);
	}
	reverse(temp.begin()+pos, temp.end());
	return temp;
}

int main(){
	string input="";
	getline(cin,input);
	cout << "Original String = " << input << endl;
	string output = ReverseWords(input);
	cout << "Words reversed = " << output << endl;
	return 0;
}
