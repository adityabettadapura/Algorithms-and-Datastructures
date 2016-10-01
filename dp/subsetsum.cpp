
/******************************************
Subsetsum
Check if a subset of numbers can add up 
to the target
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

void FillVector(vector<int>& input, int size){
	for(int i=0; i<size; i++)
		input.push_back(rand()%10);
}

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}
void SubsetSum(vector<int>& input, int target){
	int row = input.size()+1;
	int col = target+1;
	bool dptable[row][col];

	//Zero is a subset of all values
	for(int i=0; i<row; i++)
		dptable[i][0] = true;
	//We cannot reach value using only zero
	for(int i=1; i<col; i++)
		dptable[0][i] = false;


	for(int i=1; i<row; i++){
		for(int j=1; j<col; j++){
			//element is greater than sum
			if(input[i-1] > j){
				dptable[i][j] = false;
			} else {
				//sum is equal to set element
				if(j == input[i-1]) dptable[i][j] = true;
			
				//current target j can be reached from subset of values
				else if(dptable[i-1][j] == true) dptable[i][j] = true;
				
				//check if j-input[i-1] target can be reached
				else if(dptable[i-1][j] == false && j>input[i-1]){
					dptable[i][j] = dptable[i-1][j - input[i-1]] || dptable[i-1][j];	
				}
			}
		}
	}

	//print dp table
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			cout << dptable[i][j] << " ";
		cout << endl;
		}
	

	if(dptable[row-1][col-1]) cout << "Target can be formed from subsets!" << endl;
	else cout << "Target cannot be formed!" << endl;
}

int main(){
	srand(time(0));
	vector<int> input;
	FillVector(input, 4);
	PrintVector(input);
	int target = rand()%20;
	cout << "Target = "<< target << endl;
	SubsetSum(input,target);
	return 0;
}
