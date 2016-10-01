#include<iostream>

using namespace std;

void PreCompute(int arr[]){
	int a = 0, b = 1;
	for(int i = 0; i < 20; i++){
		arr[i] = a + b;
		a = b;
		b = arr[i];
	}
}

int Fibonacci(int n, int arr[] ){
	if(n<20) return arr[n];

	return ( Fibonacci(n-1, arr) + Fibonacci(n-2, arr) );
}

int main(){
	int n;
	std::cin >> n;
	int fibs[20];
	PreCompute(fibs);
	int fib = Fibonacci(n, fibs);
	std::cout << n << "th fibonacci number is = " << fib << std::endl;
	return 0 ;
}
	
