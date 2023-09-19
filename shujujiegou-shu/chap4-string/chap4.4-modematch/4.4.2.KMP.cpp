#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

//基本KMP算法

//tj的前面有多少个连续字符（不含t0）和t开头的连续字符相同！
// 用next数组存放，这里next[3]=2。
// 下一次做si/tnext[j]比较。

//求next数组
//理解来说就是 next[j]=k表示t[0]到t[j-1]共j个元素，其长度为k的前后缀相同
//那么如果t[j]=t[k]，正好两个都加一
//但是如果两个不相等，我就去找这长度为k的前缀，相当于找公约数！
//如果公约数完t[j]=t[next[k]]，那就继续两个都加一，如果没有就继续找公约数！

//求出来next数组
//如果比较到t[j]出现断电，那只需要查询next[j]得到相同前缀数
//下一次直接从t[相同前缀数-1+1]继续比就行

//主要是消除了目标串指针的回溯，从而使算法效率有了某种程度的提高。


void GetNext(string t,int* next)	//由模式串t求出next值
{  
    int j=0, k=-1;
    next[0]=-1;
    while (j<t.length()-1)
    {  
        if (k==-1 || t[j]==t[k])	//k为-1或比较的字符相等时 next[j]变成next[j+1]
        {
            j++; k++;			//依次移到下一个字符
            next[j]=k;
        }
        else 
        {
            k=next[k];   //比较的字符不相等时k回退
        }      			
   }
}

int KMP(string s,string t)		//基本KMP算法
{  
    int n=s.length(),m=t.length();
    int* next=new int[m];
    GetNext(t,next);			//求出局部匹配信息next数组
    int i=0,j=0;
    while (i<n && j<m)			//s和t均没有遍历完
    {
        if (j==-1 || s[i]==t[j])	//j=-1或者比较的字符相同时
        {  
            i++;
            j++;				//i,j各增1
        }
        else j=next[j];			//否则i不变,j回退
    }
    if (j>=m) return i-m;		//t串遍历完毕：匹配成功
    else return -1;			//匹配不成功，返回-1
}


int main() {
    // insert code here...

};