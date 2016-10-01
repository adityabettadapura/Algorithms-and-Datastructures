/****************************
Find Nth node from end of list
Works in a single pass
Time: O(n)

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

void FindNthNode(node* head, int n){
	node *ptr1, *ptr2;
	ptr1 = ptr2 = head;
	int count = 0;
	while(count < n && ptr1){
		ptr1 = ptr1->next;
		++count;
	}
	while(ptr1){
		ptr2 = ptr2->next;
		ptr1 = ptr1->next;	
	}
	cout << ptr2->data << endl;
}

int main(){
	srand(time(0));
	node *head = new node();
	PopulateList(head);
	PrintList(head);
	FindNthNode(head, 6);
	return 0;
}
