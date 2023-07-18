#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 

int filerw()
{
    int offset,fd,fd_read,fd_write,fd_m;
    char C; 
    char path[100];
    char buf_r[1024]={"\0"};
    char buf_w[1024]={"\0"};
    char buf_m[1024]={"\0"};
    printf("输入操作的文件路径：\n");
    scanf("%s",path);
    fd=open(path,O_CREAT|O_RDWR,0777);  
    if(fd==-1){
        printf("无法打开文件\n");
        }
    printf("选择操作(r:读,w:写):");
    getchar();
    while((C=getchar()) != '\n')
    {
        if((C=='r')|(C=='w')){
            fd_read=read(fd,buf_r,50);
            if(fd_read==-1){
            printf("无法读取文件\n");
                    }
            printf("%s",buf_r);
            close(fd_read);
        }
        if(C=='w')
        {
            printf("\n输入要添加的内容：\n");
            scanf("%s",buf_w);
            printf("在何处添加内容(输入和开头处的偏移量)：\n");
            scanf("%d",&offset);
            lseek(fd,offset,SEEK_SET);
            fd_read=read(fd,buf_m,50);
            lseek(fd,offset,SEEK_SET);
            fd_write=write(fd,buf_w,strlen(buf_w));
            fd_write=write(fd,buf_m,strlen(buf_m));
            if(fd_write==-1){
            printf("无法编辑文件\n");
                }
            close(fd_write);
        }
    }
    close(fd);
    return 0;
}
