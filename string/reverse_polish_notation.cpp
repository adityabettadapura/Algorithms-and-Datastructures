#include<iostream>
#include<string>
#include<stack>

using namespace std;

int RNP(string& input){
	stack<int> stk;
	for(int i=0; i<input.size(); i++){
		if( input[i] >= '0' && input[i] <= '9' ) {
			stk.push( input[i]-'0' );
			cout << "pushing" << stk.top() << endl;
		} else{
			int a =stk.top(); stk.pop();
			int b = stk.top(); stk.pop();
			int c = 0;
			if(input[i] == '+') stk.push(a+b);
			if(input[i] == '*') stk.push(a*b);
			if(input[i] == '-') stk.push(a-b);
			if(input[i] == '/') stk.push(a/b);
		}
		cout << "stack top" << stk.top() << endl;
	}	
	return stk.top();
}

int main(){
	string input;
	getline(cin, input);
	int result = RNP(input);
	cout << result << endl;
	return 0;
}
