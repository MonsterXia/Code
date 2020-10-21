// <copyright file="Test.c" company="B231">
//  Copyright (c) B231. All rights reserved.
// </copyright>
// <author>Xia Yuchen,Xu Jianzhi,Ma Chenyang,Ruan Kuifeng</author>
// <date> 2020-10-21 </date>
// <summary>实现求非线性函数的解</summary>
// <modify>
// 修改人：Xia Yuchen,Xu Jianzhi,Ma Chenyang,Ruan Kuifeng
// 修改时间：2020-10-21
// 修改描述：Create
// 版本：1.0
//</modify>
#include <stdio.h>
#include <math.h>

double function(double x);
double derivative(double k);

int main(int argc, char const *argv[])
{
	double x0=1, precision=1e-6;//初值和精度
	double lamta=1;//下山系数
	double f0, f_0, f1, f_1;
	
	while (1)//死循环
	{
		double x1 = x0-lamta*f0/f_0;//迭代公式

		f0=function(x0);
		f_0=derivative(x0);
		f1=function(x1);
		
		if (fabs(f1) < precision)//满足精度跳出
		{
			printf("one root is%f",x1);
			break;
		}//if
		else if (fabs(f1) < fabs(f0) )//检测是否下山
		{	
			x0 = x1;
		 	lamta = 1;
		 	continue;
		}//else if
		else//修改下山系数
		{
			lamta = lamta/2;
			continue;
		}//else
	}//while

	return 0;
}

double function(double x)
{
	double y;
	
	y=pow(fabs(x), x)-3*pow(x, 2)+6*x+9;
	
	return y;
}

double derivative(double k)
{
	double g=1e-6, t;
	
	t=(function(k+g)-function(k))/g;
	
	return t;
}