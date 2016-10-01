/******************************************
Program to maximize profit by buying and
selling stocks. (buying and selling allowed
only once)
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<vector>
#include<climits>
#include<cstdlib>

using namespace std;

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}

void FillVector(vector<int>& input, int size){	
	for(int i=0; i<size; ++i){
		input.push_back(rand()%100+i);	
	}
}

pair<int, int> MaxProfit(vector<int>& input){
	int minSoFar = INT_MAX;
	int diff = 0;
	int maxProfit = 0;
	int buy = input[0];
	int buyIdx=0, sellIdx=0;

	for(int i=0; i<input.size(); i++){
		if (input[i] < buy){
			minSoFar = minSoFar<input[i]? minSoFar : input[i];
			buyIdx = i;
		}else if(input[i] > buy){
			buy = buy<minSoFar? buy : minSoFar;
		}

		diff = input[i] - buy;
		if(diff > maxProfit){
			maxProfit = diff;
			sellIdx = i;
		}
	}
	
	return make_pair(buyIdx, sellIdx);
} 

int main(){
	srand(time(0));
	vector<int> stockPrice;
	FillVector(stockPrice, 10);
	PrintVector(stockPrice);
	pair<int,int> result = MaxProfit(stockPrice);
	cout << "Buy on day: " << result.first << " @ " << stockPrice[result.first] << endl;
	cout << "Sell on day: " << result.second << " @ " << stockPrice[result.second] << endl;
	cout << "Max profit = " << stockPrice[result.second] - stockPrice[result.first] << endl;
	return 0;
}
