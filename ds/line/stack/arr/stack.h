#ifndef STACK_H__
#define STACK_H__

#define MAXSIZE		6

typedef struct
{
	int data[MAXSIZE];
	int top;
}STACK;

STACK *stack_create();
void stack_create2(STACK **);

int stack_isempty(STACK *);
int stack_isfull(STACK *);

int stack_push(STACK *, const int *x);
int stack_pop(STACK *, int *x);
int stack_top(STACK *,int *x);	//取栈顶元素查看,不出栈

void stack_display(STACK *);

void stack_destroy(STACK *);


#endif




