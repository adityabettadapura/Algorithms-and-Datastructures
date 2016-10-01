/**********************************
Edit distance is the minimum number
of transformations required to make
the input same as the target

Author: Aditya Bettadapura
**********************************/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int EditDistance(string& input, string& target){
	int row = target.size()+1;
	int col = input.size()+1;
	int dptable[row][col];
	
	//edit distances to get to null from input
	for(int i=0; i<col; i++)
		dptable[0][i] = i;
	//edit distances to get to target from null
	for(int i=1; i<row; i++)
		dptable[i][0] = i;
	
	//edit distances to get to target from input
	for(int i=1; i<row; i++){
		for(int j=1; j<col; j++){
			if(input[j-1] == target[i-1])
				dptable[i][j] = dptable[i-1][j-1];
			else
				dptable[i][j] = 1 + min(min(dptable[i-1][j-1], dptable[i-1][j]), dptable[i][j-1]);
		}	
	}


	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << dptable[i][j] << " ";
		cout << endl;
	}

	return dptable[row-1][col-1];
}

int main(){
	string str1 = "abcdef";
	string str2 = "azced";
	cout << str1 << endl << str2 << endl << "Edit distance = " << EditDistance(str1, str2) << endl;
	
	string str3 = "abcdef";
	string str4 = "bcdefa";
	cout << str3 << endl << str4 << endl << "Edit distance = " << EditDistance(str3, str4) << endl;
	return 0;
}
