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
	long int a[1001] = { 0 };						//��ʼ��									    	//�����ز�
	sj(a);										    //��������� 
	for (i = 1;; i++)						    	
	{ loop:
		for (j = i * 100; j < (i + 1) * 100; j++)	//������飬һ��100���� 
		{
			printf("%-6ld", a[j]);
			if (n++ % 10 == 0)                      //һ����ĿΪ10��ʱ���� 
				printf("\n");
		}
		max = zd(a, i);
		min = zx(a, i);
		ave = pj(a, i);
		printf("��ǰҳ���ֵΪ��%ld\n", max);	//������ֵ
		printf("��ǰҳ��СֵΪ��%ld\n", min);	//�����Сֵ
		printf("��ǰҳƽ��ֵΪ��%f\n", ave);	//���ƽ��ֵ
		printf("��ǰҳ�룺%d\n", i);
		printf("press any key to continue:");		    //�����ǰҳ����ʾ
		gets(c);                                //����Ҫ��ת����ҳ��
		  len=strlen(c);      
		  if(len==0)//��������Ϊ�մ���'\n'����ô�Ͱ�˳��ѭ��ҳ�� 
		  {
		  	i++;
		  	if(i>10)//���ѭ����������10�Σ��ִӵ�һҳ��ʼѭ�� 
		  	i-=10;
		  	fake=i;
		  	system("cls");//ÿ��ѭ����Ҫ���� 
		  	goto loop;
		  	
		  }
		  for(i=0,page=0;i<len;i++)
		  {
		  	page=page*10+c[i]-'0';//��������ַ�ת�� 
		  }
		  if(page>=1&&page<=10)//����1��10��ҳ��������Ӧҳ�� 
		  {
		  	i=page-1;//һ��ʼ��ҳ��Ϊ1��������Ӧҳ��ֻҪѭ����ҳ����-1���� 
		  }
		  else                //������һ��������һҳ 
		   {
		   	page=1;
		   	i=0;
		   }
		  fake=page;
		  system("cls");     //ÿ��ѭ����Ҫ���� 
		}
		
	}
	void sj(long int b[2000])						//ʹ������������Լ�time������ϵͳʱ��ת�������������ֵ��������Ԫ��
{
	int i;
	srand(time(NULL));
	for (i = 0; i <= 1000; i++)
	{
		b[i] = rand();
	}
}
int zd(long int c[2000], int j)					//����ѭ�������ֵ
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
int zx(long int d[2000], int i)					//����ѭ������Сֵ
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
double pj(long int e[2000], int i)					//����ѭ����ƽ��ֵ
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
	


