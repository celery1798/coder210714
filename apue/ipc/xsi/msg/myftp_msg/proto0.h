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

#endif


