#ifndef _PROTO_H__
#define _PROTO_H__

#define KEYPATH		"/etc/services"
#define KEYPROJ		'A'	

#define PATHSIZE	1024
#define DATASIZE	512

enum
{
	MSG_PATH=1,
	MSG_DATA,
	MSG_ERR,
	MSG_EOT
};

typedef struct msg_path_st
{
	long mtype;				/*must be  MSG_PATH*/
	char path[PATHSIZE];
}msg_path_t;

typedef struct msg_data_st
{
	long mtype;				/*must be  MSG_DATA*/
	char data[DATASIZE];
	int datalen;
}msg_data_t;

typedef struct msg_err_st
{
	long mtype;				/*must be  MSG_ERR*/
	int myerrno;
}msg_err_t;

typedef struct msg_eot_st
{
	long mtype;				/*must be  MSG_EOT*/
}msg_eot_t;


union msg_s2c_st
{
	long mtype;
	msg_data_t datamsg;
	msg_err_t errmsg;
	msg_eot_t eotmsg;
};

#endif

S: 
	union msg_s2c_st  a;

	a.errmsg.mtype = MSG_ERR;
	a.errmsg.myerrno = errno;

	msgsnd(a );


C:
	union msg_s2c_st  b;
	msgrcv(b);
	switch(b.mtype)
	{
		case MSG_ERR:
			
	}









