#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h> 
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd1;
	int fd2;
	int fd_read;
	int fd_write;
	char buf[50];
	int len;
	fd1=open("/home/lixl/test0/file1",O_CREAT|O_RDONLY,0777);
	fd2=open("/home/lixl/test0/file2",O_CREAT|O_RDWR,0777);
	if(fd2 == -1)
	{
		printf("error\n");
	}
	fd_read=read(fd1,buf,50);
	if(fd_read == -1)
	{
		printf("read error\n");
	}
	len=strlen(buf);
	printf("%d\n%s\n",len,buf);
	fd_write=write(fd2,buf,strlen(buf));
	printf("copy success!");
    return 0;
}