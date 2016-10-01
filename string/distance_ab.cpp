/***************************************
Gives cumulative distance between all a,b
pairs in the input string

Author: Aditya Bettadapura
***************************************/
#include<iostream>
#include<string>

using namespace std;

int Dist(string& input){
	int distB = 0;
	int countB = 0;
	int cumulative = 0;

	for(int i=0; i<input.size(); i++){
		if(input[i] == 'b'){
			distB += i+1;
			++countB;
		}
	}
	
	cout << "DistB = " << distB << endl;;
	cout << "CountB = " << countB << endl;

	for(int i=0; i<input.size(); i++){
		if(input[i] == 'a'){
			cumulative += distB - (i)*countB;
		} else if(input[i] == 'b') {
			distB -= i+1;
			--countB;
		}
	}
	return cumulative;
}

int main(){
	string str = "abcdaabba";
	cout << "Cumulative ab length = " << Dist(str) << endl;
	return 0;
}
