#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE	32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

struct node_st
{
	struct score_st data;
	struct node_st *l,*r;
};

void print_s(void *data)
{
	struct score_st *d = data;
	printf("%d %s %d\n",d->id, d->name, d->math);
}

int insert(struct node_st **root, struct score_st *data)
{
	struct node_st *node;

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = *data;
		node->l = node->r = NULL;
		*root = node;
		return 0;
	}

	if(data->id <=  (*root)->data.id)
		return insert(&(*root)->l,data);
	return insert(&(*root)->r,data);
}

struct score_st *find(struct node_st *root, int id)
{
	if(root == NULL)
		return NULL;
	if(root->data.id == id)
		return &root->data;

	if(id < root->data.id)
		return find(root->l,id);
	return find(root->r,id);
}

static void draw_(struct node_st *root,int level)
{
	int i;

	if(root == NULL)
		return ; 

	draw_(root->r,level+1);

	for(i = 0 ; i < level; i++)
		printf("    ");
	print_s(&root->data);

	draw_(root->l,level+1);

}

void draw(struct node_st *root)
{

	draw_(root,0);

}

int main()
{
	struct node_st *tree = NULL;
	int arr[] = {1,2,3,7,6,5,9,8,4};
	int i;
	struct score_st tmp, *retp;

	for(i = 0 ; i < sizeof(arr)/sizeof(*arr) ; i++)
	{
		tmp.id = arr[i];
		tmp.math = 100-arr[i];
		snprintf(tmp.name, NAMESIZE,"STU%d",arr[i]);
		
		insert(&tree,&tmp);
	}

/*
	int findid = 16;
	retp = find(tree,findid);
	if(retp == NULL)
		printf("Can not find\n");
	else
		print_s(retp);
*/

	draw(tree);

	balance(   );

	draw(tree);

	exit(0);
}










