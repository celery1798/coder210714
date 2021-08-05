#ifndef _LIST_H__
#define _LIST_H__

struct list_head
{
	struct list_head *prev,*next;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
    struct list_head name = LIST_HEAD_INIT(name)

static inline void __list_add(struct list_head *new,
		struct list_head *prev,
		struct list_head *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}


#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)






#define offsetof(TYPE, MEMBER)  ((size_t)&((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
		const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
		(type *)( (char *)__mptr - offsetof(type,member) );})

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

/*
ptr=cur, type=struct score_st, member=node


list_entry(cur,struct score_st, node)
container_of(cur,struct score_st, node)

({  
//const typeof( ((struct score_st *)0)->node ) *__mptr = (cur);    

(struct score_st *)( (char *)cur - ((int)&((struct score_st *)0)->node));
})





*/



#endif




