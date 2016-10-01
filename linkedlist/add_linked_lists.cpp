/****************************
Add two lists: the digits of two numbers
are represented as nodes of 2 lists.

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

node* StackToList(stack<int> stk){
	stack<int> reverse;
	int carry = 0;
	while(!stk.empty()){
		reverse.push(stk.top()%10);
		carry = stk.top()/10;
		stk.pop();
		if(!stk.empty()) stk.top() += carry;
	}
	if(carry) reverse.push(carry);

	node *head = new node();
	node *temp = head;
	while(!reverse.empty()){
		temp->data = reverse.top();
		reverse.pop();
		if(!reverse.empty()){
			temp->next = new node();
			temp = temp->next;
		} else {
			temp->next = NULL;	
		}
	}

	return head;	
}

node* AddLists(node* l1, node* l2){
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;

	stack<int> sumstk;
	node *ptr1 = l1;
	node *ptr2 = l2;

	while(ptr1 && ptr2){
		sumstk.push(ptr1->data + ptr2->data);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	while(ptr1){
		sumstk.push(ptr1->data);
		ptr1 = ptr1->next;
	}
	while(ptr2){
		sumstk.push(ptr2->data);
		ptr2 = ptr2->next;
	}

	node* out = StackToList(sumstk);
	return out;	
		
}


void PopulateList(node* head){
	node* input = head;	
	int n = 5;
	int i=0;
	while(i < n){
		input->data = rand()%10;
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

int main(){
	srand(time(0));
	node *list1 = new node();
	node *list2 = new node();
	PopulateList(list1);
	PrintList(list1);
	PopulateList(list2);
	PrintList(list2);
	node *result = AddLists(list1, list2);
	PrintList(result);
	free(list1);
	free(list2);
	free(result);
	return 0;
}

