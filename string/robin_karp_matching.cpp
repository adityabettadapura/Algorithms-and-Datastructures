/***************************************
Robin-Karp algorithm for string matching
Uses a sliding hash function
Author: Aditya Bettadapura
***************************************/
#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>

using namespace std;

//5 largest primes less than 2^31
unsigned int primes[] = {2147483237, 2147483353, 2147483489, 2147483563, 2147483647};

unsigned int PolyHash(string& input, unsigned int prime, unsigned int x){
	// h(A) = A(x) mod p
	unsigned long long sum = 0;
	for(int i=0; i<input.size(); i++){
		sum = sum*x + input[i];
	}
	return sum%prime;
}

unsigned long long SlidingHash(string& input, string& prevChar, unsigned int x, unsigned long long prevHash){
	// h(A) = A(x) mod p
	unsigned long long sum = prevHash;
	if(prevHash == 0){
		for(int	i=0; i<input.size(); i++){
			sum = sum*x + input[i];
		}
	} else {
		unsigned long long temp = pow(x, input.size()-1);
		sum -= prevChar[0]*temp;
		//cout << "Removing... " << prevChar[0] << endl;
		sum *= x;
		//cout << "Adding... " << input[input.size()-1]<< endl;
		sum += input[input.size()-1];
	}
	return sum;
}

bool PatternMatch(string& needle, string& haystack){
	unsigned int prime = primes[rand()%5];
	//unsigned int x = rand()%prime;
	unsigned int x = 100; 
	unsigned int hashNeedle = PolyHash(needle, prime, x);
	int nsize = needle.size();
	int end = haystack.size() - nsize + 1;
	string prevChar = "";
	unsigned long long prevHash = 0;
	for(int i=0; i<end; i++){
		string temp(haystack.begin()+i, haystack.begin()+i+nsize);
		//cout << temp << endl;
		unsigned long long hashHaystack = SlidingHash(temp, prevChar, x, prevHash);
		//cout << "needle hash = " << hashNeedle << " haystack hash = " << hashHaystack%prime << " " << temp << endl;
		if(hashNeedle == hashHaystack%prime) return true;
		prevChar = temp[0];
		prevHash = hashHaystack;
	}	
	return false;
}

int main(){
	srand(time(0));
	string haystack = "helloworldmarssunmoonvenus";
	string needle = "sun";
	
	bool result = PatternMatch(needle, haystack);
	cout << "Searching for " << needle << " in " << haystack << endl;
	if(result) cout << "Pattern found!" << endl;
	else cout << "Pattern not found!" << endl;

	return 0;
}
