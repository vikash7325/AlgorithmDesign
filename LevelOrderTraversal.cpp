/*Level order traversal Goldman sachs vikash kumar*/
#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *newNode(int data){
	Node *temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void LevelOrderTraversal(Node *root){
	if (NULL == root){
		return;
	}
	
	queue<Node *> q;
	q.push(root);
	
	while(false == q.empty()){
		Node *node = q.front();
		cout<<node->data<<"\t";
		q.pop();
		
		if (node->left != NULL){
			q.push(node->left);
		}
		if (node->right != NULL){
			q.push(node->right);
		}
	}
	return;
}

int main(){
	Node *root = newNode(1);
	root->left =newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->right = newNode(5);
	LevelOrderTraversal(root);
	return 0;
}
