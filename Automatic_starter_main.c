#include <stdio.h>
#include <windows.h>
#include <io.h>
#include <process.h>
int num=-1;
void fun1(void *pointer)
{
	char str2[50];
	sprintf (str2,"FAHViewer.exe \"viewerTop.json\" \"viewerFrame%d.json\"",num);
	system (str2);
 	_endthread();
}
int main()
{
	printf ("本程序运行后将定期扫描是否有最新的viewerFrame文件并载入\n");
	printf ("只需将本程序放入viewerTop.json所在的文件夹后运行即可\n"); 
	printf ("作者：RaiseNorth  如有bug请见谅，已开源github.com/RaiseNorth/FAHViewer_starter\n"); 
	if (access("viewerTop.json",0)==-1)
	{
		printf ("\n未找到viewerTop.json文件，请检查本程序的位置\n");
		system ("pause");
		return 2; 
	}
	printf ("请输入刷新间隔（单位：秒），按回车启动程序：");
	int time=60;
	scanf ("%d",&time);
	printf ("\n一开始显示1次“错误: 没有找到进程 \"FAHViewer.exe\"。”是正常情况\n");
	while (1)
	{
		int i=351;
		char filename[30];
		int judge=-1;
		while (judge&&(--i>=0))
		{
			sprintf (filename,"viewerFrame%d.json",i);
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

