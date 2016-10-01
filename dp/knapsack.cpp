/**********************************
Solution to 0/1 Knapsack problem

Author: Aditya Bettadapura
**********************************/
#include<iostream>
#include<vector>

using namespace std;

int SolveKnapsack(int values[4], int weights[4], int size, int cap){
	int row = size;
	int col = cap+1;
	int dptable[row][col+1];
	
	//If capacity is zero
	for(int i=0; i<row; i++)
		dptable[i][0] = 0;
	//If there is only one item
	for(int j=0; j<col; j++)
		dptable[0][j] = j<weights[0]?0:values[0];

	
	for(int i=1; i<row; i++){
		for(int j=1; j<col; j++){
			if(j<weights[i]){
				dptable[i][j] = dptable[i-1][j];
			} else {
				//It is max of taking an item, or without taking an item
				dptable[i][j] = max(values[i]+dptable[i-1][j-weights[i]], dptable[i-1][j]);
			} 
		}
	}

	return dptable[row-1][col-1];
}

int main(){
	int val[] = {1, 4, 5, 7};
	int wt[] = {1, 3, 4, 5};
	int size = 4;
	int C = 7;
	cout << "Max val in capacity " << C << " knapsack = " << SolveKnapsack(val, wt, size, C) << endl;
	
	int val2[] = {10, 40, 30, 50};
	int wt2[] = {5, 4, 6, 3};
	int size2 = 4;
	int C2 = 10;
	cout << "Max val in capacity " << C2 << " knapsack = " << SolveKnapsack(val2, wt2, size2, C2) << endl;
	return 0;
}
