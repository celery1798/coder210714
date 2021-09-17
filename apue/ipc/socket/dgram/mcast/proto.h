#ifndef PROTO_H__
#define PROTO_H__

#include <stdint.h>

#define MGROUP			"224.2.2.2"
#define RCVER_PORT		"2989"		


#define NAMESIZE	13

struct msg_st
{
	uint8_t name[NAMESIZE];
	uint32_t math;
	uint32_t chinese;
}__attribute__((packed));




#endif




