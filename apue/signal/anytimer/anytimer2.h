#ifndef __ANYTIMER_H__
#define __ANYTIMER_H__

#define  JOB_MAX		1024

typedef void at_jobfunc_t(void *);

int at_addjob(int sec, at_jobfunc_t *jobp, void *arg);
/*
return:	>= 0		成功,返回任务ID
		== -ENOSPC	失败,任务数组已满
		== -EINVAL	失败,参数非法 
*/

int at_addjob_repeat(int sec, at_jobfunc_t *jobp, void *arg);
/*
同上
*/

int at_canceljob(int id);
/*
return: == 0		成功,指定任务已被取消 
		== -EINVAL  失败,参数非法
		== -ECANCELED	失败,指定任务早已被取消 
		== -EBUSY		失败,指定任务已完成 
*/

int at_waitjob(int id);
/*
return:	== 0		成功,指定任务已释放空间
		== -EINVAL  失败,参数非法
		== -EBUSY   失败,指定任务为周期性任务 
*/

#endif




