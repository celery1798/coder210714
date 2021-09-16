#ifndef _PROTO_H__
#define _PROTO_H__

#define KEYPATH		"/etc/services"
#define KEYPROJ		'A'	

#define PATHSIZE	1024
#define DATASIZE	512

enum
{
	MSG_PATH=1,
	MSG_S2C,
};

typedef struct msg_path_st
{
	long mtype;				/*must be  MSG_PATH*/
	char path[PATHSIZE];
}msg_path_t;

typedef struct msg_s2c_st
{
	long mtype;             /*must be  MSG_S2C*/
	int datalen;
	/*
		datalen > 0    MSG_DATA
				= 0	   MSG_EOT
				< 0    MSG_ERR  -errno
	*/
	char data[DATASIZE];
}msg_s2c_t;

#endif


S:

msg_s2c_t sbuf;


msgsend(sbuf,);




C:
	msgsend(path);

	msg_s2c_t  rbuf;

	msgrcv(&rbuf,  );














