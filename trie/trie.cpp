/*************************
Trie data structure

Implements:
	- Insert
	- Search
	- Remove

Author: Aditya Bettadapura
*************************/

#include<iostream>
#include<string>

using namespace std;

const int ALPHABET = 26;

struct Node{
	Node* parent;
	Node* children[ALPHABET];
	bool isWord;
	Node() : parent(NULL), isWord(false) {}
};

class Trie{
	private:
		Node* root;
		unsigned int count;
	public:
		Trie() : count(0) {root = new Node();} ;
		~Trie() { delete root; };
		void insert(string& word);
		bool search(string& word);
		bool remove(string& word);
		void setCount(int val);
		int getCount(void);
};

void Trie::insert(string& word){
	Node* temp = root;
	//if empty string
	if(word.size() == 0){
		temp->isWord = true;
		return;
	}
	//else
	for(int i=0; i<word.size(); i++){
		if(temp->children[word[i]-'a'] == NULL){
			temp->children[word[i] -'a'] = new Node();
			temp->children[word[i] -'a']->parent = temp;
		}
		temp = temp->children[word[i]-'a'];
	}
	temp->isWord = true;
	setCount(1);
}

bool Trie::search(string& word){
	Node* temp = root;
	//if empty string check root
	if(word.size() == 0){
		return temp->isWord;
	}
	if(getCount() == 0){
		cout << "No words in tree!" << endl;
		return false;
	}
	//else
	for(int i=0; i<word.size(); i++){
		if(temp->children[word[i]-'a'] == NULL){
			return false;
		} else {
			temp = temp->children[word[i] -'a'];
		}
	}
	
	//return temp->isWord? true : false;
	return temp->isWord;
}

bool Trie::remove(string& word){
	Node* temp = root;
	//if empty string check root
	if(word.size() == 0){
		if(temp->isWord){
			temp->isWord = false;
			return true;
		} else {
			return false;
		}
	}
	if(getCount() == 0){
		cout << "No words in tree!" << endl;
		return false;
	}
	//else
	for(int i=0; i<word.size(); i++){
		if(temp->children[word[i]-'a'] == NULL){
			return false;
		} else {
			temp = temp->children[word[i] -'a'];
		}
	}
	if(!temp->isWord) return false;
	
	return true;
}

void Trie::setCount(int val){
	this->count += val;
}

int Trie::getCount(void){
	return this->count;
}

int main(){
	Trie* mytrie = new Trie();
	
	cout << "Inserting into Trie..." << endl;	
	string sentence[] = {"hello", "world", "there", "is", "that", "then", "help", "work", "their", "the"};
	int sentSize = sizeof(sentence)/sizeof(sentence[0]);
	for(int i=0; i<sentSize; i++){
		mytrie->insert(sentence[i]);
		cout << sentence[i] << " ";
	}
	cout << endl;

	cout << "Searching Trie..." << endl;	
	string text[] = {"help", "hell", "worry", "world", "their", "hel"};
	int textSize = sizeof(text)/sizeof(text[0]);
	for(int i=0; i<textSize; i++){
		if(mytrie->search(text[i])){
			cout << text[i] << " : present" << endl;
		} else {
			cout << text[i] << " : not present" << endl;
		}
	}
	cout << endl;
	
	cout << "Removing from Trie..." << endl;	
	string removeList[] = {"hell", "their", "the", "yelp"};
	int removeSize = sizeof(removeList)/sizeof(removeList[0]);
	for(int i=0; i<removeSize; i++){
		if(mytrie->remove(removeList[i])){
			cout << removeList[i] << " : removed!" << endl;
		} else {
			cout << removeList[i] << " : not present" << endl;
		}
	}
	cout << endl;
	
	cout << "Testing..." << endl;	
	string test[] = {"help", "hell", "hello", "world", "there", "then"};
	int testSize = sizeof(test)/sizeof(test[0]);
	for(int i=0; i<testSize; i++){
		if(mytrie->search(test[i])){
			cout << test[i] << " : present" << endl;
		} else {
			cout << test[i] << " : not present" << endl;
		}
	}
	cout << endl;
	
	return 0;
}
