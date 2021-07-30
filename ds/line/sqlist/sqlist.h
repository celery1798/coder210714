#ifndef _SQLIST_H__
#define _SQLIST_H__

#define DATAMAX		128

typedef struct
{
	int data[DATAMAX];
	int last;
}SQLIST;

/*
sqlist_create:create a sqlist
return SQLIST *
*/
SQLIST *sqlist_create();

int sqlist_isempty(SQLIST *);
int sqlist_isfull(SQLIST *);
int sqlist_setempty(SQLIST *);

/*
sqlist_insert:insert a int to sqlist
@ptr:sqlist
@pos:the position where the int to insert
@newdata:a point to a int which to be inserted.
return :-1 error, 0 successed.
*/
//pos
int sqlist_insert(SQLIST *ptr, int pos ,int *newdata);
int sqlist_delete(SQLIST *ptr,int pos,int *x);

//value
int sqlist_insert_value(SQLIST *ptr,int *newdata);
int sqlist_delete_value(SQLIST *ptr,int *x);

int sqlist_find(SQLIST *ptr, int *x);

//dest:ptr1   ptr1->1 2 3 4   ptr2-> 1 3 5 7   ptr1->1 2 3 4 5 7 
int sqlist_union(SQLIST *ptr1,SQLIST *ptr2);

void sqlist_display(SQLIST *ptr);

void sqlist_destroy(SQLIST *ptr);



#endif




