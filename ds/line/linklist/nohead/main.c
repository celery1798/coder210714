#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE	32

struct student_st
{
	int id;
	char name[NAMESIZE];
	int math;
};

typedef struct node_st
{
	struct student_st data;
	struct node_st *next;
}LIST;

//功能：第0个位置的插入
int insert(LIST **ptr, struct student_st *data)
{
	LIST *new;

	new = malloc(sizeof(*new));
	if(new == NULL)
		return -1;
	new->data = *data;
	new->next = *ptr;
	*ptr = new;

	return 0;
}
//功能：删除第0个位置
int delete(LIST **ptr)
{

}

void show(LIST *ptr)
{
	LIST *cur = ptr;
	
	for( ; cur != NULL ; cur = cur->next)
		printf("%d %s %d\n",cur->data.id, cur->data.name, cur->data.math);
}

int main()
{
	LIST *handler = NULL;
	struct student_st data;
	int i;

	for(i = 0 ; i < 7; i++)
	{
		data.id = i;
		data.math = 100-i;
		snprintf(data.name, NAMESIZE, "STU%d",i);

		insert(&handler,&data);
	}

	show(handler);
	

	exit(0);
}


