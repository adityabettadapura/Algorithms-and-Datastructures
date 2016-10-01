/**********************************
Longest common subsequence between
two strings. The sequence need not
be contiguous

Author: Aditya Bettadapura
**********************************/
#include<iostream>
#include<string>

using namespace std;

int LCS(string& s1, string& s2){
	int row = s1.size()+1;
	int col = s2.size()+1;
	int dptable[row][col];

	//initialzie dptable to 0
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			dptable[i][j] = 0;

	for(int i=1; i<row; i++){
		for(int j=1; j<col; j++){
			if(s2[j-1] == s1[i-1]){
				dptable[i][j] = dptable[i-1][j-1] + 1;
			} else {
				dptable[i][j] = max(dptable[i-1][j], dptable[i][j-1]);
			}
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
	string s1 = "abcdaf";
	string s2 = "acbcdef";

	cout << "Longest common subsequence = " << LCS(s1, s2) << endl;
	return 0;
}
