//之前的程序放到 viewerTop.json文件夹，导致提交包后无法清理本程序从而使任务卡住
//现在修复该问题，现在需将本软件放入work文件夹内 
//------------------------------------------------------- 
#include <stdio.h>
#include <windows.h>
#include <io.h>
#include <process.h>
int num=-1;
int choose;
void fun1(void *pointer)
{
	char str2[80];
	sprintf (str2,"FAHViewer.exe \".\\%02d\\viewerTop.json\" \".\\%02d\\viewerFrame%d.json\"",choose,choose,num);
	system (str2);
 	_endthread();
}
int isinArray(int a,int b,int*p)
{
	int j,k=0;
	for (j=0;j<b;j++)
	{
		if (a==*(p+j))
		{
			k=1;
			break;
		}
	}
	if (k) return 1;
	else return 0;
}
int main()
{
	printf ("本程序运行后将定期扫描是否有最新的viewerFrame文件并载入\n");
	printf ("请将本程序放入work文件夹下\n"); 
	printf ("作者：RaiseNorth  如有bug请见谅，已开源github.com/RaiseNorth/FAHViewer_starter\n"); 
	printf ("感谢 洛丝萝琳 提供了建议和bug测试\n\n"); 
	int id,Foldernum=0;
	int Folders[100];
	char pathstr[40];
	for (id=0;id<100;id++)
	{
		sprintf (pathstr,".\\%02d\\viewerTop.json",id);
		if (!access (pathstr,0))//如果路径下存在 viewerTop.json文件 
		{
			Folders[Foldernum]=id;//存入数组 
			Foldernum++;
		}
	}
	if (!Foldernum)
	{
		printf ("找不到符合条件的文件夹，请检查是否放于work文件夹下且有任务包\n");
		system ("pause");
		return 2; 
	}
	printf ("\n----------------\n");
	printf ("找到以下任务文件夹，请输入你需要预览的任务并回车，例如：%02d\n----------------\n",Folders[0]);
	for (id=0;id<Foldernum;id++)	printf ("%02d  ",Folders[id]); 
	printf ("\n----------------\n");
	scanf ("%d",&choose);
	if (!isinArray(choose,Foldernum,Folders))
	{
		while (!isinArray(choose,Foldernum,Folders))
		{
			printf ("您的输入有误，请重新输入：");
			scanf ("%d",&choose);
		}
	}
	printf ("请输入刷新间隔（单位：秒），按回车启动程序：");
	int time=60;
	scanf ("%d",&time);
	printf ("\n一开始显示1次“错误: 没有找到进程 \"FAHViewer.exe\"。”是正常情况\n");
	while (1)
	{
		int i=351;
		char filename[50];
		int judge=-1;
		while (judge&&(--i>=0))
		{
			sprintf (filename,".\\%02d\\viewerFrame%d.json",choose,i);
			judge=access(filename,0);
		}
		if (i!=num)
		{
			num=i;
			system ("taskkill /F /IM FAHViewer.exe");
			Sleep(50);//50ms
			_beginthread(fun1,0,NULL);
		}
		Sleep (time*1000);
	}
}
