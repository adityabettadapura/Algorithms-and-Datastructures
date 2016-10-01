/*************************
Binary Tree data structure

Implements:
	- Add
	- Delete
	- Find Min
	- Find Max
	- Find key
	- Size
	- height
	- Kth Smallest element
	- Inorder traversal
	- Preorder traversal
	- Postorder traversal
	- Levelorder traversal
	- Eulerian Traversal

Author: Aditya Bettadapura
*************************/

#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>

using namespace std;

struct node{
	int data;
	node* left;
	node* right;
	node* parent;
};

class BST{
private:
	node* root;
	int count;
public:
	BST() : root(NULL), count(0) { }
	
	void add(int input){
		if(!root){
			root = new node();
			root->data = input;
			root->left = NULL;
			root->right = NULL;
			root->parent = NULL;
		} else {
			addToTree(root, input);
		}
		++count;
	}
	
	void addToTree(node* root, int input){
		if(input <= root->data){
			if(root->left){
				addToTree(root->left, input);
			}else{
				root->left = new node();
				root->left->data = input;
				root->left->parent = root;
			}
		}else{
			if(root->right) {
				addToTree(root->right, input);
			}else{
				root->right = new node();
				root->right->data = input;
				root->right->parent = root;	
			}
		}
	}
	
	int findMin(void){
		node *temp = root;
		while(temp->left){
			temp = temp->left;
		}
		return temp->data;
	}
	
	int findMax(void){
		node *temp = root;
		while(temp->right){
			temp = temp->right;
		}
		return temp->data;
	}
	
	int size(void){
		return this->count;	
	}

	bool find(int key){
		node* temp = root;
		if(!temp) return false;
		if(key == temp->data ) return true;
		else if(key < temp->data) return findKey(temp->left, key);
		return findKey(temp->right, key);
	}
	
	bool findKey(node* root, int key){
		while(root->data != key && (root->left || root->right)){
			if(key <= root->data) root = root->left;
			else root = root->right;
		}
		return root->data == key;
	}
	
	void fillTree(int size){
		for(int i=0; i<size; i++){
			this->add(rand()%100);
		}
	}
	
	void inOrder(void){
		if(!root) cout << "No elements in tree!" << endl;
		node* temp = root;
		inOrderTraversal(temp);
		cout << endl;
	}

	void preOrder(void){
		if(!root) cout << "No elements in tree!" << endl;
		node* temp = root;
		preOrderTraversal(temp);
		cout << endl;
	}

	void postOrder(void){
		if(!root) cout << "No elements in tree!" << endl;
		node* temp = root;
		postOrderTraversal(temp);
		cout << endl;
	}

	void levelOrder(void){
		if(!root) cout << "No elements in tree!" << endl;
		node* temp = root;
		levelOrderTraversal(temp);
		cout << endl;
	}
	
	void eulerTour(void){
		if(!root) cout << "No elements in tree!" << endl;
		node* temp = root;
		eulerianTraversal(temp);
		cout << endl;
	}

	void inOrderTraversal(node* root){
		if(root->left)	inOrderTraversal(root->left);
		cout << root->data << " ";
		if(root->right)	inOrderTraversal(root->right);
	}	
	
	void preOrderTraversal(node* root){
		cout << root->data << " ";
		if(root->left)	preOrderTraversal(root->left);
		if(root->right)	preOrderTraversal(root->right);
	}	
	
	void postOrderTraversal(node* root){
		if(root->left)	postOrderTraversal(root->left);
		if(root->right)	postOrderTraversal(root->right);
		cout << root->data << " ";
	}
	
	void levelOrderTraversal(node* root){
		queue<node*> nodeQueue;
		nodeQueue.push(root);
	
		while(!nodeQueue.empty()){
			if(nodeQueue.front()->left) nodeQueue.push(nodeQueue.front()->left);
			if(nodeQueue.front()->right) nodeQueue.push(nodeQueue.front()->right);
			cout << nodeQueue.front()->data << " ";
			nodeQueue.pop();
		}		
	}	

	void eulerianTraversal(node* root){
		cout << root->data << " ";
		if(root->left) eulerianTraversal(root->left);	
		cout << root->data << " ";
		if(root->right) eulerianTraversal(root->right);	
		cout << root->data << " ";
	}
	
	int height(void){
		if(!root){
			cout << "No nodes in tree!" << endl;
			return 0;
		} else {
			node* temp = root;
			return 1+max(treeHeight(temp->left), treeHeight(temp->right));
		}
	}
	
	int treeHeight(node* root){
		if(!root) return 0;

		if(root->left && !root->right){
			return 1+treeHeight(root->left);
		} else if(!root->left && root->right){
			return 1+treeHeight(root->right);	
		}
		return 1+max(treeHeight(root->left), treeHeight(root->right));
	}
	
	void printAncestors(int target){
		if(!root) cout << "No nodes in tree!" << endl;
		if(!find(target)) cout << "Target not present in tree!" << endl;
		node* temp = root;
		nodeAncestor(temp, target);
		cout << endl;
	}
	
	void nodeAncestor(node* root, int target){
		if(target < root->data)
			nodeAncestor(root->left, target);
		else if(target > root->data)
			nodeAncestor(root->right, target);

		cout << root->data << " ";
	}
	
	int randomElement(void){
		if(!root){
			cout << "No elements in tree!" << endl;
			return 0;
		}
		node* temp = root;
		return randTreeElement(temp);
	}

	int randTreeElement(node* root){
		int x = rand()%3;
		if(x == 1 && root->left) return randTreeElement(root->left);
		else if(x == 2 && root->right) return randTreeElement(root->right);
	
		return root->data;
	}
	
	int kOrderStat(int k){
		if(!root){
			cout << "No elements in tree!" << endl;
			return 0;
		}
		node* temp = root;
		stack<int> rankStk;
		return kthSmallestElement(root, k, rankStk);
	}
	
	int kthSmallestElement(node* root, int k, stack<int>& rankStk){
		if(root->left) kthSmallestElement(root->left, k, rankStk);
		if(rankStk.size() == k) return rankStk.top();
		rankStk.push(root->data);
		if(root->right) kthSmallestElement(root->right, k ,rankStk);
	
		return rankStk.top();
	}
	
};
	
int main(){
	srand(time(NULL));

	BST *tree = new BST();
	tree->fillTree(10);	
	cout << "Tree size = " << tree->size() << endl;
	cout << "9 in tree? " << tree->find(9) << endl;
	cout << "30 in tree? " << tree->find(10) << endl;
	cout << "min element in tree = " << tree->findMin() << endl;
	cout << "max element in tree = " << tree->findMax() << endl;
	tree->inOrder();
	tree->preOrder();
	tree->postOrder();
	tree->levelOrder();
	tree->eulerTour();
	cout << "Height of the tree = " << tree->height() << endl;
	int x = tree->randomElement();
	cout << "Ancestors of node " << x << " = ";
	tree->printAncestors(x);
	int k = 4;
	int kos = tree->kOrderStat(k);
	cout << k << "th order statistic = " << kos << endl;
	return 0;
}

