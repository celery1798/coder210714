




void f1(void *p)
{
	printf("f1():%s\n",p);
}

void f2(void *p)
{
    printf("f2():%s\n",p);
}

//..bbb...aaa..ccc................
int main()
{
	int job1;

	job1 = at_addjob(5,f1,"aaa");
	if(job1 < 0)
	{
		fprintf(stderr,"at_addjob():%s\n",strerror(-job1));
		exit(1);	
	}
	at_addjob(2,f2,"bbb");

	at_addjob_repeat(7,f1,"ccc");

	while(1)
	{
		write(1,".",1);
		sleep(1);
	}


	exit(0);
}











