#include<stdio.h>
#include<math.h>
#include<string.h>
#pragma warning(disable:4996)
int n, i, j, t, joker = 0, cyclone = 0;
double y = 0;//返回值变量
char ch;
double G1[100];
char N[1000];
double G2[1000];

int main(void)
{
	double derivative(double k);
	double A(double a, double na);//幂函数
	double B(double b, double nb);//指数函数
	double C(double c);//余弦函数
	double D(double d);//正弦函数
	double E(double e);//正切函数
	double F(double f);//余切函数
	double G(double g);//正割函数
	double H(double h);//余割函数
	double K(double k, double nk);//对数函数
	double function(double x);//核心输入处理函数
	printf("欢迎使用简易方程计算器\n");
	printf("请参照使用说明进行使用\n");
	char ch;
	int n, i, j, t, joker = 0, cyclone = 0;
	double y = 0;//返回值变量
	printf("请输入非复合函数的项数:\n");
	scanf("%d", &n);
	//printf("请输入非复合函数类型行个数:\n");
	//scanf("%d",&p);

	printf("请输入方程系数，用空格间隔，最后输入回车完成输入\n");
	double G1[1000];//系数数组
	for (i = 0;; i++)
	{
		scanf("%lf%c", &G1[i], &ch);//输入方式，空格分隔
		if (ch == 32) continue;
		else if (ch == '\n') break;
	}
	fflush(stdin);
	printf("请输入方程类型行，用空格间隔，输入回车完成输入\n");
	char N[10];//类型数组，间断申明
	for (i = 0; i <= 4; i++)
	{
		scanf("%c", &N[i]);
	}
	//未解决的问题  用户终止循环的方法 /////宇晨提供///
	fflush(stdin);
	printf("请输入方程参数2行,若无参数2请输入“1”，用回车间隔，最后输入回车完成输入\n");
	double G2[1000];//参数2数组，仅针对部分函数，无参数2的函数输入1
	for (i = 0;; i++)
	{
		scanf("%lf%c", &G2[i], &ch);
		if (ch == 32) continue;
		else if (ch == '\n') break;
	}
	double x0 = 1, precision = 1e-6;//初值和精度
	double lamta = 1;//下山系数
	double f0, f_0, f1, f_1;
	while (1)//死循环
	{
		f0 = function(x0), f_0 = derivative(x0);
		double x1 = x0 - lamta * f0 / f_0;//迭代公式
		f1 = function(x1);
		if (fabs(f1) < precision)
		{
			printf("one root is%f", x1);
			break;//满足精度跳出
		}
		else if (fabs(f1) < fabs(f0))
		{
			x0 = x1;
			lamta = 1;
			continue;//检测是否下山
		}
		else lamta = lamta / 2; continue; //修改下山系数
	}
	return 0;



}
double derivative(double k)
{
	double function(double x);
	double g = 1e-6, t;
	t = (function(k + g) - function(k)) / g;
	return t;//原函数求导
}
double A(double a, double na)//幂函数
{
	double A1;
	A1 = pow(a, na);    //定义幂函数
	return A1;
}
double B(double b, double nb)//指数函数
{
	double B1;
	B1 = pow(b, nb);   //定义指数函数
	return B1;
}
double C(double c)//余弦函数
{
	double C1;
	C1 = cos(c);      //定义余弦函数
	return C1;
}
double D(double d)//正弦函数
{
	double D1;
	D1 = sin(d);      //定义正弦函数
	return D1;
}
double E(double e)//正切函数
{
	double E1;
	E1 = tan(e);      //定义正切函数
	return E1;
}
double F(double f)//余切函数
{
	double F1;
	F1 = 1 / tan(f);      //定义余切函数
	return F1;
}
double G(double g)//正割函数
{
	double G1;
	G1 = 1 / cos(g);      //定义正割函数
	return G1;
}
double H(double h)//余割函数
{
	double H1;
	H1 = 1 / sin(h);      //定义余割函数
	return H1;
}
double K(double k, double nk)//对数函数
{
	double e = 2.71828;
	double K1;
	K1 = log(nk) / log(k);
	return K1;
}
double function(double x)//核心输入处理函数
{
	double y = 0;//返回值变量
	double G3[1000] = { 0 };//收纳函数，存放每一项的数值
	for (i = 0; i <= n - 1; i++)
		G3[i] = 1;
	for (j = 0; j <= n - 1; j++)//读取程序，外层循环，控制项数的变更和推进，走完n项
	{
		for (i = joker, t = cyclone;; i++, t++)
		{
			if (N[i] == 'A') G3[j] *= G1[j] * A(x, G2[t]);//各函数的识别运行，限于已定义函数种类
			if (N[i] == 'B') G3[j] *= G1[j] * B(x, G2[t]);
			if (N[i] == 'C') G3[j] *= G1[j] * C(t);
			if (N[i] == 'D') G3[j] *= G1[j] * D(t);
			if (N[i] == 'E') G3[j] *= G1[j] * E(t);
			if (N[i] == 'F') G3[j] *= G1[j] * F(t);
			if (N[i] == 'G') G3[j] *= G1[j] * G(t);
			if (N[i] == 'H') G3[j] *= G1[j] * H(t);
			if (N[i] == 'K') G3[j] *= G1[j] * K(x, G2[t]);
			if (N[i] == '/')
			{
				joker = i + 1, cyclone = i ;
				break;
			}//跳出一项进入下一项的标志，由用户输入	
		}
	}
	for (i = 0; i <= n - 1; i++)//把所有的项相加
		y += G3[i];
	return y;
}



