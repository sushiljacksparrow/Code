void inorder(node *b1)
{
	if(b1== null)
		return;
	inorder(b1->left)
	cout<<b1->value;
	inorder(b1->right);
}

void iterative_inorder(node *b1)
{
	stack<node*>b1;
	b1.push