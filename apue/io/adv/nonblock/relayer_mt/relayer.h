
//多线程并发安全版的数据中继引擎
#define JOB_MAX		10000

struct rel_stat_st
{
	int fd1,fd2;
	int job_state;
	int count12,count21;
};


int rel_addjob(int fd1,int fd2);
/*
return: >= 0        成功,返回任务ID
		== -ENOSPC  失败,任务数组已满
		== -EINVAL  失败,参数非法 
		== -ENOMEM	失败，内存申请失败	
*/

int rel_statjob(int id,struct rel_stat_st *st);
/*


*/

int rel_canceljob(int id);
/*




*/

int rel_resumejob(int id)
/*


*/


int rel_waitjob(int id);
/*



*/



