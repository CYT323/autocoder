#include <stdio.h>

//函数初始化 
void conver(int num_in); 

int main ()
{
	int w1[] = {-1511.49914069, -9128.06426525, -2894.97068506, -1144.74467517,
         -2045.73064164, -9219.57395371, -1816.95060838, -4108.79710565};
         
	int w2[] = {-1100.21665174, -9511.6730222 ,  -467.96607105,  1072.65541743,
         -1711.595673  ,  -367.36824355, -2737.02421946,  -176.39198633};
	
	int	w3[] = {-1363.26516735, 22924.72014775, -2082.61493887, -1748.37461798,
          1741.69183138, -4149.41071957, -1080.51023586, -2254.80957266} ;
	
	int w4[] = {1804.41967758, 42413.06596932, -2403.11940004, -2669.45641709,
         -1912.09990507,  -370.82387852, -2326.08037326, -1748.96422029};
	
//	int w5[] = {};
//	int w5[] = {};
//	int w5[] = {};
//	int w5[] = {};
//	int w5[] = {};
//	int w5[] = {};
//	int w5[] = {};
//	int w5[] = {};
	

	for (int i = 0;i < (sizeof(w1) / sizeof(w1[0])); i++)
		{
			printf("	parameter w%d_1 = ", i);
			conver(w1[i]);	
		} 
 } 
 
 
 
//自设函数区域 
 
//有符号十进制转换有符号N进制

#define NUM 2	// N进制修改 
#define BIT	21 //  转换后位数 

void conver(int num_in)
{
	int num	;
	int flag;
	int a[BIT];
	int i=1,j,m;
	int seg	;
	printf("%d'b",BIT);
	if (num_in < 0)
		{
			flag = 1;
			num = 0-num_in; 
		}
	else 
		num = num_in;
	for(j=0;j<BIT;j++)
	{
		i=num%NUM;
		num=num/NUM;
		a[j]=i;
	}
	if (flag)
		{
			for(m=0;m<BIT;m++)
			if(a[m] == 1)
				a[m]  = 0;
			else
				a[m]  = 1;
		}
	
	if (flag)
		{
			for(j=0;j<BIT;j++)
		{
			if(j==0)
				a[j]++;
			if(a[j] + seg > 1)
				{
					a[j] = a[j] + seg - 2;
					seg = 1;
				}
			else
				seg = 0;
		}		
		}
	
	for(j=BIT - 1;j>=0;j--)
	{
		printf("%d",a[j]);
		if(!(j%4) && j)
		printf("_");
	}
	printf(",\n");
}
