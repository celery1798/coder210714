#include <stdio.h>
#include <stdlib.h>

struct node_st
{
	char data;
	struct node_st *l,*r;
};

static struct node_st *tree = NULL;

int insert(struct node_st **root, int data)
{
	struct node_st *node;

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = data;
		node->l = node->r = NULL;
		*root = node;
		return 0;
	}

	if(data <=  (*root)->data)
		return insert(&(*root)->l,data);
	return insert(&(*root)->r,data);
}

static void draw_(struct node_st *root,int level)
{
	int i;

	if(root == NULL)
		return ; 

	draw_(root->r,level+1);

	for(i = 0 ; i < level; i++)
		printf("    ");
	printf("%c\n",root->data);

	draw_(root->l,level+1);

}

void draw(struct node_st *root)
{
	draw_(root,0);
}

void save(struct node_st *root)
{
	putchar('(');
	if(root == NULL)
	{
		putchar(')');
		return ;
	}	
	putchar(root->data);

	save(root->l);

	save(root->r);

	putchar(')');

}

int main()
{
	char arr[] = "CEFADJBH";
	int i;

	for(i = 0 ; i < sizeof(arr)-1 ; i++)
	{
		insert(&tree,arr[i]);
	}

	draw(tree);

	save(tree);

	putchar('\n');

	exit(0);
}









