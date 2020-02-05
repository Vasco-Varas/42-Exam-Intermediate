//
// Created by Vasco Varas on 05-02-20.
//

struct s_node {
	int           value;
	struct s_node **nodes;
};

#define MAX(a, b) a > b ? a : b

int height_tree(struct s_node *root)
{
	if (!root)
		return -1;

	int height = 0;
	for (int i = 0; root->nodes[i]; i++) {
		height = MAX(height, height_tree(root->nodes[i]) + 1);
	}
	return height;
}