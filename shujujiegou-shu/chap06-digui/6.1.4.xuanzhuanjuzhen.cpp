#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

//例6.9】创建一个n阶螺旋矩阵并输出。例如，n=4时的螺旋矩阵如下：
	// 1	2	3	4
	// 12	13	14	5
	// 11	16	15	6
	// 10	9	8	7
int const init = 5;

class Solution
{
public:
int a[init][init];


void Spiral(int x,int y,int start,int n)	//递归创建螺旋矩阵
{  
    if (n<=0) return;		//递归结束条件
    if (n==1)			//矩阵大小为1时
    {  
        a[x][y]=start;
        return;
    }
    for (int j=x;j<x+n-1;j++)	//上一行
    {  
        a[y][j]=start;
        start++;
    }
    for (int i=y;i<y+n-1;i++)	//右一列
    {  
        a[i][x+n-1]=start;
        start++;
    }
    for (int j=x+n-1;j>x;j--)	//下一行
    {  
        a[y+n-1][j]=start;
        start+=1;
    }
    for (int i=y+n-1;i>y;i--)	//左一列
    {  
        a[i][x]=start;
        start++;
    }
    Spiral(x+1,y+1,start,n-2);	//递归调用
    }

};

int main()
{  
    int n=5;
    Solution s;
    s.Spiral(0,0,1,n);
    for (int i=0;i<n;i++)
    {  
        for (int j=0;j<n;j++)
        printf("%3d",s.a[i][j]);
        printf("\n");
    }
}
