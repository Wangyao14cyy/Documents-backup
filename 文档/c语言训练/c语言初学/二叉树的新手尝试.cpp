#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
	int date;
	struct tree *left;
	struct tree *right;
}node;
typedef node *b_tree;
void tree(b_tree *ptree,int x)/*创建结点*/ 
{
	if((*ptree)==NULL)
	{
		(*ptree)=(b_tree)malloc(sizeof(node));
		(*ptree)->date=x;
		(*ptree)->left=NULL;
		(*ptree)->right=NULL;
	}
	else
	{
		tree(&(*ptree)->left,x-1);
		tree(&(*ptree)->right,x+1);
	}
	printf("\t%p\t%p\t%d\t%p\n",(*ptree),(*ptree)->left,(*ptree)->date,(*ptree)->right);
}
void create_tree(b_tree *ptree)
{
	int x,floor=1;
	printf("input a number of intergers,end wint ctrl+z\n");
	while(scanf("%d",&x)!=EOF)
	{	
		printf("floor=%d x=%d\n",floor++,x);
		tree(ptree,x);
	}
}
void preorder_traverse(b_tree root)
{	
	if(root!=NULL)
	{
	printf("\t%p\t%p\t%d\t%p\n",root,root->left,root->date,root->right);
	preorder_traverse(root->left);
	preorder_traverse(root->right);
	}
}
b_tree find_tree(b_tree root,int x)
{
	if(root==NULL)
	return NULL;
	else if(root->date==x)
	return root;
		else
		{
			find_tree(root->left,x);
			find_tree(root->right,x);
		}
}
int main()
{	
	int x;
	b_tree root=NULL,p;
	create_tree(&root);
	printf("\taddr\t	left\t	date\tright\n");
	preorder_traverse(root);printf("\n");
	printf("input the number to find:\n");
	scanf("%d",&x);
	p=find_tree(root,x);
	printf("addr: %p\tvalue: %d\n",p,p->date);
	return 0; 				
}
