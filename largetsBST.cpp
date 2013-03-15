//http://www.geeksforgeeks.org/category/tree/

struct node
{
	node *left, *right;
	int data;
};

// returns true if its a bst and updates the minimum value and maximum value and size
int largestBST(node *root, int *minVAL, int *maxVAL, int *size, int *isBSTRef)
{
	if(root == NULL)
	{
		*isBSTRef = 1;
		return 0;
	}

	int mini = INT_MAX;
	bool isLeftBST = false;
	bool isRightBSt = false;
	int ls, rs;

	*maxVAL = INT_MIN;
	ls = largestBST(root->left, minVAL, maxVAL, size, isBSTRef);
	if(isBSTRef == 1 && root->data > maxVAL)
		isLeftBST = true;

	mini = *minVAL;
	*minVAL = INT_MAX;
	rs = largestBST(root->right, minVAL, maxVAL, size, isBSTRef);
	if(isBSTRef == 1 && root->data < minVAL)
		isRightBSt = 1;

	if(mini < *minVAL)
		*minVAL = mini;
	if(root->data < *minVAL)
		*minVAL = root->data;
	if(root->data > *maxVAL)
		*maxVAL = root->data;

	if(isRightBSt && isLeftBST)
	{
		if(ls + rs + 1 > *size)
			*size = ls + rs + 1;
		return ls + rs + 1;
	} else
	{
		isBSTRef = 0;
		return 0;
	}
}
	

}


