#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
#include<algorithm>

using namespace std;

void PrintVector(vector<int>& input){
	for(int i=0; i<input.size(); i++){
		cout << input[i] << " ";
	}
	cout << endl;
}
int main(){
	vector<int> chocolates;
	for(int i=0; i<10; ++i){
		chocolates.push_back(rand()%15+i);	
	}
	PrintVector(chocolates);
	sort(chocolates.begin(), chocolates.end());

	int mindiff=INT_MAX;
	int first=0,last=0;
	int n = 8;
	for(int i=0; i+n-1<chocolates.size(); ++i){
		if((chocolates[i+n-1] - chocolates[i]) < mindiff){
			mindiff = chocolates[i+n-1] - chocolates[i];
			first = i;
			last = i+n-1;
		}
	}
	cout << "First = " << first << "Last = " << last << endl;
	unsigned long long int x = 0;
	cout << x-1 << endl;
	return 0;
}
