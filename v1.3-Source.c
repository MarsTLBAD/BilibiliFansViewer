#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
/*粉丝数显示器v1.3*/
/*更新内容：修复时间显示错误问题和显示间隔错乱问题*/
/*本程序需要同一目录下的wget下载器，切勿单独编译运行*/
int main()
{
	FILE* FansData, * LikesData, * record;
	double speed = 1, plays;
	int id, follow, whister, black, fans, reads, likes, hour;
	char GetFans[100] = "wget https://api.bilibili.com/x/relation/stat?vmid=";
	char GetLikes[100] = "wget https://api.bilibili.com/x/space/upstat?mid=";
	char FansFileName[30] = "stat@vmid=";
	char delFansFile[30] = "del stat";
	char LikesFileName[30] = "upstat@mid=";
	char delLikesFile[30] = "del upstat";
	char uid[12] = { 0 };
	time_t timep;
	struct tm* p;
	printf("请输入要查询的UP主的UID：\n");
	scanf("%10s", uid);
	printf("请输入循环显示间隔(近似秒)：\n");
	scanf("%lf", &speed);
	speed *= 4e8;
	strcat(GetFans, uid);
	strcat(GetFans, ">nul 2>nul");
	strcat(FansFileName, uid);
	strcat(delFansFile, "*");
	strcat(GetLikes, uid);
	strcat(GetLikes, ">nul 2>nul");
	strcat(LikesFileName, uid);
	strcat(delLikesFile, "*");
	record = fopen("record.txt", "a+");
	fprintf(record, "正在观测的用户UID：%s\n", uid);
	fclose(record);
start:
	time(&timep);
	p = localtime(&timep);
	record = fopen("record.txt", "a+");
	if (record == NULL)
	{
		printf("文件访问错误！按任意键退出。\n");
		getch();
		exit(0);
	}
	system(GetFans);
	system(GetLikes);
	FansData = fopen(FansFileName, "r");
	if (FansData == NULL)
	{
		printf("文件访问错误！按任意键退出。\n");
		getch();
		exit(0);
	}
	LikesData = fopen(LikesFileName, "r");
	if (LikesData == NULL)
	{
		printf("文件访问错误！按任意键退出。\n");
		getch();
		exit(0);
	}
	fscanf(FansData, "{\"code\":0,\"message\":\"0\",\"ttl\":1,\"data\":{\"mid\":%d,\"following\":%d,\"whisper\":%d,\"black\":%d,\"follower\":%d}}", &id, &follow, &whister, &black, &fans);
	fscanf(LikesData, "{\"code\":0,\"message\":\"0\",\"ttl\":1,\"data\":{\"archive\":{\"view\":%lf},\"article\":{\"view\":%d},\"likes\":%d}}", &plays, &reads, &likes);
	printf("%02d-%02d %02d:%02d:%02d 当前粉丝数：%d，当前点赞数：%d\n", 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, fans, likes);
	fprintf(record, "%02d-%02d %02d:%02d:%02d 当前粉丝数：%d，当前点赞数：%d\n", 1 + p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec, fans, likes);
	fclose(FansData);
	fclose(LikesData);
	system(delFansFile);
	system(delLikesFile);
	fclose(record);
	for (double i = 0;i < speed;i++);
	goto start;
	/*本程序将一直循环显示粉丝数直到手动关闭*/
}