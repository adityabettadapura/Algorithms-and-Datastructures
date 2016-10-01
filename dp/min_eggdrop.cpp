/**********************************
Minimum egg drops required to floor
from which a dropped egg will break

Author: Aditya Bettadapura
**********************************/
#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int EggDrop(int floors, int eggs){
	if(floors == 1 || floors == 0) return 1;
	if(eggs == 1) return floors;

	int trials=0, minsofar = INT_MAX;

	for(int i=1; i<=floors; i++){
		trials = max(EggDrop(i-1, eggs-1), EggDrop(floors-i, eggs));
		minsofar = minsofar < trials ? minsofar : trials;
	}

	return 1+minsofar;
}

int main(){
	int floors = 10;
	int eggs = 2;

	cout << "Floors = " << floors << " Eggs = " << eggs << endl;
	cout << "Min number of trials required = " << EggDrop(floors,eggs) << endl;
	return 0;
}
