/****************************
Finds the intersection node of
two lists

Author: Aditya Bettadapura
****************************/

#include<iostream>
#include<stack>

using namespace std;

struct node{
	int data;
	node* next;	
};

void FindIntersectionStk(node* list1, node* list2){
	stack<node*> nodestk1;
	stack<node*> nodestk2;
	node* temp1 = list1;
	node* temp2 = list2;
	while(temp1 && temp2){
		nodestk1.push(temp1);
		temp1 = temp1->next;
		nodestk2.push(temp2);
		temp2 = temp2->next;
	}
	while(temp1){
		nodestk1.push(temp1);
		temp1 = temp1->next;
	}
	while(temp2){
		nodestk2.push(temp2);
		temp2 = temp2->next;
	}
	
	while(!nodestk1.empty() && !nodestk2.empty()){
		node* intersect;
		if(nodestk1.top() == nodestk2.top()){
			intersect = nodestk1.top();
			nodestk1.pop();
			nodestk2.pop();
		} else {
			cout << "Intersection node (using stack)= " << intersect->data << endl;
			break;
		}
	}	
}

void FindIntersection(node* list1, node* list2){
	node* temp1 = list1;
		
	while(temp1 != NULL){
		node* temp2 = list2;
		while(temp2 != temp1 && temp2 != NULL){
			temp2 = temp2->next;
		}
		if(temp1 == temp2){
			cout << "Intersection node = " << temp1->data << endl;
			break;
		}
		temp1 = temp1->next;
	}		
}

void PopulateList(node* list1, node* list2){
	node* temp1 = list1;
	node* temp2 = list2;
	node* intersect = list1;

	int arr1[] = {8, 1, 9, 4, 2, 3, 7, 2, 9};
	int arr2[] = {5, 6, 4, 2, 1};

	for(int i=0; i<9; i++){
		temp1->data = arr1[i];
		if(i==5) intersect = temp1;
		if(i<8){
			temp1->next = new node();
			temp1 = temp1->next;
		} else { 
			temp1->next = NULL;
		}
	}
	for(int i=0; i<5; i++){
		temp2->data = arr2[i];
		if(i<4){
			temp2->next = new node();
			temp2 = temp2->next;
		} else { 
			temp2->next = intersect;
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
int main(){
	node* list1= new node();
	node* list2 = new node();
	PopulateList(list1, list2);
	PrintList(list1);
	PrintList(list2);
	FindIntersection(list1, list2);
	FindIntersectionStk(list1, list2);
	
	return 0;
}
