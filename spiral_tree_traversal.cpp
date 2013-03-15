#include <iostream>
#include <stack>

using namespace std;

struct node
{
	node *left, *right;
	int data;
};

node *newNode(int d)
{
	node *temp = (node*)malloc(sizeof(node));
	temp->left = temp->right = NULL;
	temp->data = d;
	return temp;
}


void spiral_traversal(node *root)
{
	stack<node*> currentLevel, nextLevel;
  	bool leftToRight = true;
  	currentLevel.push(root);
  	while (!currentLevel.empty()) {
    		node *currNode = currentLevel.top();
    		currentLevel.pop();
    		if (currNode) {
      			cout << currNode->data << " ";
      			if (leftToRight) {
        			nextLevel.push(currNode->left);
        			nextLevel.push(currNode->right);
      			} else {
        			nextLevel.push(currNode->right);
        			nextLevel.push(currNode->left);
      			}
    		}
    		if (currentLevel.empty()) {
      			cout << endl;
      			leftToRight = !leftToRight;
      			swap(currentLevel, nextLevel);
    		}
  	}
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout<<"hello world\n";	
	spiral_traversal(root);
	
	system("pause");
}
