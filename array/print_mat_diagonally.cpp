/******************************************
Printing a matrix diagonally
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

void PrintDiagonally(int input[4][4], int row, int col){
	vector<vector<int> > diagonals;
	map<int, vector<int> > mymap;
	int idxMax = row-1 + col-1;
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			mymap[i+j].push_back(input[i][j]);

	map<int, vector<int> >::iterator itr = mymap.begin();
	while(itr != mymap.end()){
		for(int i=0; i<(itr->second).size(); i++){
			cout << (itr->second)[i] << " ";
		}
		cout << endl;
		++itr;
	}
}
int main(){
	int row = 4;
	int col = 4;
	int input[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	PrintDiagonally(input, row, col);
	return 0;
}
