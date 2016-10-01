/****************************
Merge two linked lists of
lengths m and n.

Time: O(m+n)

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
	int num = rand()%30;
	node* input = head;	
	int i=0;
	while(i < 4){
		input->data = num+(i*3);
		if(i<3){
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

node* MergeList(node* leftNode, node* rightNode){
	node* left = leftNode;
	node* right = rightNode;
	node* temp = new node();
	node* head = temp;
	while(left && right){
		if(left->data <= right->data){
			temp->data = left->data;
			temp->next = new node();
			temp = temp->next; 
			left = left->next;
		}else if(left->data > right->data){
			temp->data = right->data;
			temp->next = new node(); 
			temp = temp->next; 
			right = right->next;
		}
	}
	while(left){
		temp->data = left->data;
		temp->next = new node(); 
		temp = temp->next; 
		left = left->next;
	}
	while(right){
		temp->data = right->data;
		temp->next = new node(); 
		temp = temp->next; 
		right = right->next;
	}
	return head;
}

int main(){
	srand(time(0));
	node *left = new node();
	node *right = new node();	
	
	PopulateList(left);
	PrintList(left);
	PopulateList(right);
	PrintList(right);
	
	node *result = MergeList(left,right);			
	PrintList(result);
	return 0;
}
