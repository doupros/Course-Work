#include <iostream>

using namespace std;

struct node 
{
	int value;
	struct node* left;
	struct node* right;
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
	return 0;
}

//void insert_integer(struct node** tree, int value)
//{
//	struct node* newnode = new struct node;
//	(newnode)->value = value;
//	(newnode)->left = (newnode)->right = null;
//	if (root == null)
//	{
//		root = newnode;
//	}
//	else
//	{
//		node* back= null;
//		node* current = root;
//		while (current != null)
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

void insert_integer(struct node** tree, int value) 
{
	(*tree) = new node;
	(*tree)->value = value;
	(*tree)->left = (*tree)->right = NULL;
	if (root==NULL)
	{
		root = *tree;
	}
	else
	{

	}
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

}