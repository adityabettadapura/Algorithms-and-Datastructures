/****************************
Reverse a linked list using 
constant memory and stack
Time: O(n)
Space: O(1)
	   O(n) for stack

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	node* next;
};

void PopulateList(node* head){
	int num = rand()%20;
	node* input = head;	
	int n = 8;
	int i=0;
	while(i < n){
		input->data = num+(i*3);
		if(i<n-1){
			input->next = new node();
		} else {
			input->next = NULL;
		}
		input = input->next;
		++i;
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

node* ReverseList(node* head){
	node *curr = NULL;
	node *prev = NULL;
	node *nxt = head;
	while(nxt != NULL){
		curr = nxt;
		nxt = nxt->next;
		curr->next = prev;
		prev = curr;
	}
	return curr;			
}

node* ReverseListStack(node* head){
	node *temp = head;
	stack<int> stk;
	while(temp != NULL){
		stk.push(temp->data);
		temp = temp->next;
	}
	temp = head;
	while(temp != NULL){
		temp->data = stk.top();
		stk.pop();
		temp = temp->next;
	}
	return head;	
}

int main(){
	srand(time(0));
	node *head = new node();
	PopulateList(head);
	PrintList(head);
	ReverseList(head);
	PrintList(head);
	ReverseListStack(head);
	PrintList(head);
	return 0;
}
