#ifndef LIST_H__
#define LIST_H__

typedef struct node_st
{
	int data;
	struct node_st *next;
}LIST;

LIST *list_create();

int list_isempty(LIST *);

//pos
int list_insert(LIST *,int pos, int *newdata);
int list_delete(LIST *,int pos, int *newdata);

//value
int list_insert_value(LIST *,int *newdata);
int list_delete_value(LIST *,int *newdata);

int list_find(LIST *int *data);

void list_display(LIST *);

void list_destroy(LIST *);


#endif



