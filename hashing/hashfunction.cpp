/****************************
Universal hashing function
h(k) = ((ak+b) mod p) mod m
h(k) - hash value
p - prime number < 2^31
a -  random no. < p
b - random no. < p

IntegerHash - Maps an integer to a value
PolyHash - Maps an array to a value

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<cstdlib>
#include<climits>
#include<string>

using namespace std;

//5 largest primes less than 2^31
unsigned int primes[] = {2147483237, 2147483353, 2147483489, 2147483563, 2147483647};

unsigned int IntegerHash(unsigned int key, int m){
	// h(k) = ((ak+b) mod p) mod m
	unsigned int prime = primes[rand()%5];
	unsigned int a = rand()%(prime-1);
	unsigned int b = rand()%(prime-1);
	unsigned int hash =  ((a*key+b)%prime)%m;
	return hash;
}
unsigned int PolyHash(string& input){
	// h(A) = A(x) mod p
	unsigned int prime = primes[rand()%5];
	unsigned int x = rand()%(prime-1);
	unsigned long long sum = 0;
	for(int i=0; i<input.size(); i++){
		sum = sum*x + input[i];
	}
	return sum%prime;
}

int main(){
	srand(time(0));
	unsigned int x = rand()%UINT_MAX;
	cout << "Hash of " << x << " = " << IntegerHash(x,100) << endl;

	string str = "helloworld";
	cout << "Hash of " << str << " = " << PolyHash(str) << endl;
	return 0;
}
