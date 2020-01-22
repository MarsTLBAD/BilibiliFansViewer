#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
/*本程序需要同一目录下的wget下载器，切勿单独编译运行*/
int main()
{
	FILE* fp;
	double speed=1;
	int id,follow,wst,bck,fans;
	char cmd[100] = "wget https://api.bilibili.com/x/relation/stat?vmid=";
	char fln[30] = "stat@vmid=";
	char delf[30] = "del stat";
	char uid[11] = {0};
	printf("请输入要查询的UP主的UID：\n");
	scanf("%10s", uid);
	printf("请输入显示循环间隔：\n");
	scanf("%lf", &speed);
	speed *= 6e8;
	strcat(cmd, uid);
	strcat(cmd, ">nul 2>nul");
	strcat(fln, uid);
	strcat(delf,"*");
start:
	system(cmd);
	fp = fopen(fln, "r");
	if (fp == NULL)
	{
		printf("文件访问错误！按任意键退出。\n");
		getch();
		exit(0);
	}
	fscanf(fp,"{\"code\":0,\"message\":\"0\",\"ttl\":1,\"data\":{\"mid\":%d,\"following\":%d,\"whisper\":%d,\"black\":%d,\"follower\":%d}}", &id, &follow,&wst, &bck,&fans);
	printf("当前粉丝数：%d\n", fans);
	fclose(fp);
	system(delf);
	for (int i = 0;i < speed;i++);
	goto start;
/*本程序将一直循环显示粉丝数直到手动关闭*/
}