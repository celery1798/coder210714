#ifndef _MYTBF_H__
#define _MYTBF_H__

#define MYTBF_MAX	1024

typedef void mytbf_t;

mytbf_t *mytbf_create(int cps,int burst);

int mytbf_fetchtoken(mytbf_t *, int n);

int mytbf_returntoken(mytbf_t *,int n);

void mytbf_destroy(mytbf_t *);



#endif







