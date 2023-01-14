#include<stdio.h>
#include<string.h>
#include<math.h>
void sj( long int b[2000]);
int zd(  long int c[2000], int j);
int zx(  long int d[2000], int i);
double pj( long int e[2000], int i);
int main()
{
	int i, n = 1, j;
	long int max, min,len,digit,page,fake=1;
	double ave;
	char c[100];
	long int a[1001] = { 0 };						//初始化									    	//用作回查
	sj(a);										    //调用随机数 
	for (i = 1;; i++)						    	
	{ loop:
		for (j = i * 100; j < (i + 1) * 100; j++)	//输出数组，一次100个数 
		{
			printf("%-6ld", a[j]);
			if (n++ % 10 == 0)                      //一行数目为10个时换行 
				printf("\n");
		}
		max = zd(a, i);
		min = zx(a, i);
		ave = pj(a, i);
		printf("当前页最大值为：%ld\n", max);	//输出最大值
		printf("当前页最小值为：%ld\n", min);	//输出最小值
		printf("当前页平均值为：%f\n", ave);	//输出平均值
		printf("当前页码：%d\n", i);
		printf("press any key to continue:");		    //输出当前页码提示
		gets(c);                                //读入要跳转到的页码
		  len=strlen(c);      
		  if(len==0)//如果输入的为空串（'\n'）那么就按顺序循环页码 
		  {
		  	i++;
		  	if(i>10)//如果循环次数超过10次，又从第一页开始循环 
		  	i-=10;
		  	fake=i;
		  	system("cls");//每次循环后要清屏 
		  	goto loop;
		  	
		  }
		  for(i=0,page=0;i<len;i++)
		  {
		  	page=page*10+c[i]-'0';//将输入的字符转换 
		  }
		  if(page>=1&&page<=10)//输入1到10的页码跳到相应页面 
		  {
		  	i=page-1;//一开始的页码为1，跳到相应页码只要循环（页码数-1）次 
		  }
		  else                //其他的一律跳到第一页 
		   {
		   	page=1;
		   	i=0;
		   }
		  fake=page;
		  system("cls");     //每次循环后都要清屏 
		}
		
	}
	void sj(long int b[2000])						//使用随机数函数以及time函数将系统时间转换成随机数并赋值给数组中元素
{
	int i;
	srand(time(NULL));
	for (i = 0; i <= 1000; i++)
	{
		b[i] = rand();
	}
}
int zd(long int c[2000], int j)					//进行循环求最大值
{
	int i;
	long int max = 0;
	for (i = 100 * j; i < 100 * (j + 1); i++)
	{
		if (c[i] > max)
			max = c[i];
	}
	return max;
}
int zx(long int d[2000], int i)					//进行循环求最小值
{
	int j;
	long int min = 100000;
	for (j = 100 * i; j < (i + 1) * 100; j++)
	{
		if (d[j] < min)
			min = d[j];
	}
	return min;
}
double pj(long int e[2000], int i)					//进行循环求平均值
{
	int j;
	double ave, sum = 0;
	for (j = 100 * i; j < (i + 1) * 100; j++)
	{
		sum = sum + e[j];
	}
	ave = sum / 100;
	return ave;
}
	


