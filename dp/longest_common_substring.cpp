/**********************************
Longest common substring between
two strings. 

Author: Aditya Bettadapura
**********************************/
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int LCS(string& str1, string& str2){
	int row = str1.size();
	int col = str2.size();
	int length = 0;
	int dptable[row][col];
	//initialize dptable to zero
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			dptable[i][j] = 0;
	}

	for(int i=0; i<col; i++)
		if(str1[0] == str2[i]) dptable[0][i] = 1;	
	for(int i=0; i<row; i++)
		if(str2[0] == str1[i]) dptable[i][0] = 1;	

	for(int i=1; i<row; i++){
		for(int j=1; j<col; j++){
			if(str2[j] == str1[i]){
				dptable[i][j] = dptable[i-1][j-1] + 1;
				length = max(length, dptable[i][j]);
			} else {
				dptable[i][j] = 0;
			}
		}
	}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << dptable[i][j] << " ";
		cout << endl;
	}

	return length; 
}

int main(){
	string str1 = "abcdef";
	string str2 = "azbcdf";
	cout << "The longest common substring = " << LCS(str1, str2) << endl;
	return 0;
}
