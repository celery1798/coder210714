#ifndef PROTO_H__
#define PROTO_H__

#define KEYPATH		"/etc/services"
#define KEYPROJ		'A'			//		12   "12"

#define NAMESIZE	32

struct msg_st
{
	long mtype;
	char name[NAMESIZE];
	int math;
	int chinese;
};


#endif




