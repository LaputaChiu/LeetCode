#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

////////////////////////////////////////////////////////////////////////////////

 /* Definition for a binary tree node. */
typedef struct _TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

////////////////////////////////////////////////////////////////////////////////

/* Definition for DFS stack */
typedef struct _SumStackNode{
	int currentSum;
	struct TreeNode *treeNode;
	struct SumStackNode *next;
}SumStackNode;

SumStackNode *StackCreate(){
	return NULL;	
}

SumStackNode *StackPush(SumStackNode *top, TreeNode *tNode, int sum){
	SumStackNode *sumNode = (SumStackNode*)calloc(1, sizeof(SumStackNode));
	sumNode->currentSum = sum + tNode->val;
	sumNode->treeNode = tNode;
	sumNode->next = top;
	return sumNode;
}
 
SumStackNode *StackPop(SumStackNode *top){
	SumStackNode *next = top->next;
	free(top);
	return next;
}

bool isStackEmpty(SumStackNode *top){
	return (top == NULL)?true:false;
}

////////////////////////////////////////////////////////////////////////////////


bool hasPathSum(struct TreeNode* root, int sum) {
	if(!root) return false;

	SumStackNode *stackTop = StackCreate(); 
	stackTop = StackPush(NULL, root, 0);

	while(!isStackEmpty(stackTop)){
		int summary = stackTop->currentSum;
		TreeNode *currentNode = stackTop->treeNode;
		stackTop = StackPop(stackTop);

		while(currentNode->left || currentNode->right){
			if(currentNode->left && currentNode->right){
				stackTop = StackPush(stackTop, currentNode->right, summary);
				currentNode->right = NULL;
			}
			
			currentNode = (currentNode->left)?currentNode->left:currentNode->right;
			summary += currentNode->val;
		}
		if(summary == sum) return true;
	}

	return false;    
}

/*       5
 *      / \	
 *     2  3	
 *    /  / \
 *   1  7   9
 */

int main(){
	TreeNode *root = (TreeNode*)calloc(1, sizeof(TreeNode));		
	TreeNode *n2 = (TreeNode*)calloc(1, sizeof(TreeNode));		
	TreeNode *n3 = (TreeNode*)calloc(1, sizeof(TreeNode));		
	TreeNode *n1 = (TreeNode*)calloc(1, sizeof(TreeNode));		
	TreeNode *n7 = (TreeNode*)calloc(1, sizeof(TreeNode));		
	TreeNode *n9 = (TreeNode*)calloc(1, sizeof(TreeNode));		
	
	root->val = 5;
	root->left = n2;
	root->right = n3;

	n2->val = 2;
	n2->left = n1;
	n2->right = NULL;
	
	n1->val = 1;
	n1->left = NULL;
	n1->right = NULL;
	
	n3->val = 3;
	n3->left = n7;
	n3->right = n9;
	
	n7->val = 7;
	n7->left = NULL;
	n7->right = NULL;
	
	n9->val = 9;
	n9->left = NULL;
	n9->right = NULL;

	int sum = 15;
	if(hasPathSum(root, sum)) printf("Bingo!! \n", sum);
	else printf("Nope ..\n");

	sum = 14;
	if(hasPathSum(root, sum)) printf("Bingo!! \n", sum);
	else printf("Nope ..\n");

	sum = 5;
	if(hasPathSum(root, sum)) printf("Bingo!! \n", sum);
	else printf("Nope ..\n");

	sum = 8;
	if(hasPathSum(root, sum)) printf("Bingo!! \n", sum);
	else printf("Nope ..\n");
	return 0;
}
