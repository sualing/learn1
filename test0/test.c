#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h> 
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "filerw.h"

int main(int argc ,char *argv[])
{
	//使用argv；添加完内容反馈，显示一下
	printf("test demo\n");
	filecopy();
	filerw();
	return 0;
}
