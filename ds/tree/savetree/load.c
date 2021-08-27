#include <stdio.h>
#include <stdlib.h>

struct node_st
{
	char data;
	struct node_st *l,*r;
};


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


struct node_st *load_(FILE *fp)
{
	int ch;
	struct node_st *root;


	ch = fgetc(fp);
	if(ch != '(')
	{
		fprintf(stderr,"read error().\n");
		return NULL;
	}

	ch = fgetc(fp);
	if(ch == ')')
		return NULL;

	root = malloc(sizeof(*root));	
	root->data = ch;
	root->l = load_(fp);
	root->r = load_(fp);

	fgetc(fp);		// (

	return root;
}

struct node_st *load(const char *path)
{
	FILE *fp;
	struct node_st *root;

	fp = fopen(path,"r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}
	root = load_(fp);
	fclose(fp);
	return root;   
}


int main()
{

	struct node_st *tree = NULL;
	
	tree = load("tree.log");

	draw(tree);


	exit(0);
}









