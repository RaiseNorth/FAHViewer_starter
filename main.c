#include <windows.h>
#include <stdio.h>
#include <io.h>
int main ()
{
	int model;
	printf ("请输入数字并回车，1为只加载最后的文件，2为加载所有文件：");
	scanf ("%d",&model);
	int i=351;
	char filename[30];
	int judge=-1;
	while (judge&&(--i>=0))
	{
		sprintf (filename,"viewerFrame%d.json",i);
		judge=access(filename,0);
	}
	if (i<0){ printf ("找不到viewerFrame.json"); return i; 
	}
	if (model==1){
		char str1[100];
		sprintf (str1,".\\FAHViewer.exe \"viewerTop.json\" \"viewerFrame%d.json\"",i);
		system (str1);
		return 0;
	}
	if (model==2){
		char str[11000]=".\\FAHViewer.exe \"viewerTop.json\" ";
		int n=-1;
		while (++n<=i)
		{
			sprintf (str,"%s\"viewerFrame%d.json\" ",str,n);	
		} 
		system (str);
		return 0;
	}
	
}
