#include <iostream>

using namespace std;

struct node 
{
	int value;
	struct node* left= NULL;
	struct node* right = NULL;
};

struct node* root = NULL;

// implement the functions described by these headers
void insert_integer(struct node** tree, int value);
void print_tree(struct node* tree);
void terminate_tree(struct node* tree);

int main() 
{
	int array[] = { 100,4,2,3,15,35,6,45,55,20,1,14,56,57,58 };
	int length;
	length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
		insert_integer(&root , array[i]);
	}
	cout << endl;
	print_tree(root);
	terminate_tree(root);
	return 0;
}

//void insert_integer(struct node** tree, int value)
//{
//	 node* newnode = new struct node;
//	(newnode)->value = value;
//	(newnode)->left = (newnode)->right = NULL;
//	if (root == NULL)
//	{
//		root = newnode;
//	}
//	else
//	{
//		node* back = nullptr;
//		node* current = root;
//		while (current != nullptr)
//		{
//			back = current;
//			if (current->value > value)
//				current = current->left;
//			else
//				current = current->right;
//			
//		}
//		if (back->value > value)
//			back->left = newnode;
//		else
//			back->right = newnode;
//	}
//}
//
void insert_integer(struct node** tree, int value) 
{
	if ((*tree) == NULL)
	{
		(*tree) = new node;
		(*tree)->value = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		return;
	}
	if (value>(*tree)->value)
		insert_integer(&(*tree)->right, value);
	else
		insert_integer(&(*tree)->left, value);
}


void print_tree(struct node* tree)
{
	if (NULL!= tree)
	{
		print_tree(tree->left);
		cout << tree->value << endl;
		print_tree(tree->right);
	}
}

void terminate_tree(struct node* tree)
{
	delete tree;
	tree = NULL;
}