/****************************
Detects loop in a linked list 
using slow and fast pointers

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	node* next;
};

void PopulateList(node* head){
	int arr[] = {8, 1, 9, 4, 2, 3, 7, 2, 9};
	node* temp = head;
	node* loop = head;
	for(int i=0; i<9; i++){
		temp->data = arr[i];
		temp->next = new node();
		if(i==4) loop = temp;
		if(i<8){
			temp = temp->next;
		} else { 
			temp->next = loop;
		}
	}
}

void PrintList(node* head){
	node* input = head;
	while(input){
		cout << input->data << " ";
		input = input->next;
	}
	cout << endl;
}

void DetectLoop(node* head){
	node *fast, *slow;
	fast=slow=head;
	slow = slow->next;
	fast = fast->next->next;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next->next;
	}
	slow = head;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	cout << slow->data << endl;	
}

int main(){
	srand(time(0));
	node *head = new node();
	PopulateList(head);
//	PrintList(head);
	DetectLoop(head);
	return 0;
}
