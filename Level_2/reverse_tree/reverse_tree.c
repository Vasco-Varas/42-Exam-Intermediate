//
// Created by Vasco Varas on 14-01-20.
//


struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};



void reverse_tree(struct s_node *root)
{

	// Swap the left and right child nodes
	struct s_node *tmp = root->right;
	root->right = root->left;
	root->left = tmp;

	// Reverse child nodes if they exist
	if (root->right)
		reverse_tree(root->right);
	if(root->left)
		reverse_tree(root->left);

}


/*
#include<stdio.h>
#include<stdlib.h>

void print_tree(struct s_node *node)
{
	if (!node)
		return;
	printf("[%i]\n", node->value);

	if(node->right)
	{
		printf("RIGHT::\n");
		print_tree(node->right);
	}
	if(node->left)
	{
		printf("LEFT::\n");
		print_tree(node->left);
	}
}

int main()
{
	struct s_node *nde= ( struct s_node *)malloc(sizeof( struct s_node));

	nde->right = ( struct s_node *)malloc(sizeof(struct s_node));
	nde->left = ( struct s_node *)malloc(sizeof(struct s_node));

	nde->right->right = 0;
	nde->right->left = 0;
	nde->left->right = 0;
	nde->left->left = 0;

	nde->value = 231;
	nde->left->value = 12;
	nde->right->value = 1;

	print_tree(nde);
	printf("REVERSE\n\n");
	reverse_tree(nde);
	print_tree(nde);

}

*/
