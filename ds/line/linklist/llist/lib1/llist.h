#ifndef __LLIST_H__
#define __LLIST_H__

#define LLIST_FORWARD		1
#define LLIST_BACKWARD		2

struct llist_node_st
{
	void *data;
	struct llist_node_st *prev,*next;
};

typedef struct 
{
	int size;
	struct llist_node_st head;
}LLIST;


LLIST* llist_create(int size);

int llist_insert(LLIST *, const void *data,int mode);

//llist_delete();

//llist_find();

     llist_travel();

//void llist_destroy();



#endif

