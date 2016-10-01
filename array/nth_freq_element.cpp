/******************************************
Nth most frequent element in the array
Author: Aditya Bettadapura
******************************************/
#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

int main(){
	int arr[] = {1,2,2,4,4,4,5,5,5,5,8,8,8,8,8};
	int size = sizeof(arr)/sizeof(arr[0]);
	unordered_map<int,int> mmap;
	for(int i=0;i<size;i++){
		mmap[arr[i]] += 1;
	}
	priority_queue<pair<int,int>> pq;
	auto it = mmap.begin();
	while(it!=mmap.end()){
		cout << it->first << "->" << it->second << endl;
		pq.push(make_pair(it->second,it->first));
		++it;
	}
	while(!pq.empty()){	
		cout << pq.top().second << endl;
		pq.pop();
	}
	return 0;
}
