#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

//KMP算法的改进
//简而言之就是在求next数组的时候多进行一次判断。因为kmp算法根据next数组进行模式串的回溯，且第一次回溯失败会再次回溯
//那么直接对next数组进行优化，在求出next[j]=k的时候判断当前t[j]和t[k]
//（即t[next[j]],在使用kmp的时候如果断点在t[j]的时候是要回退t[next[j]]的)
//如果不相等，那kmp断点回退的时候需要再比较一次，跟kmp一样直接赋值
//如果相等，那kmp断点回退的时候无需比较就知道要直接回退，那么直接在求next的时候回退
//这样求出来的数组成为nextval数组

void GetNextval(string t,int* nextval)	//由模式串t求出nextval值
{  
    int j=0,k=-1;
    nextval[0]=-1;
    while (j<t.length())
    {  
        if (k==-1 || t[j]==t[k])		//k为-1或比较的字符相等时
        {  
            j++;k++;                
            if (t[j]!=t[k])			//使用kmp时如果断点在t[j]的时候是要回退t[next[j]]，即t[k]
                nextval[j]=k;       //如果不相等，说明kmp回退还需要再比较的，跟求next一样赋值
            else
                nextval[j]=nextval[k];     //如果相等，说明kmp回退了还得回退，直接在这里先处理
        }
        else 
        {
            k=nextval[k]; //k回退
        }			
    }
}


int KMPval(string s,string t)			//改进的KMP算法，直接next换成nextval就写
{  
    int n=s.length(),m=t.length();
    int* nextval=new int[m];
    GetNextval(t,nextval);			//求出nextval数组
    int i=0,j=0;
    while (i<n && j<m) 
    {  
        if (j==-1 || s[i]==t[j])
        {  
            i++;					//i,j各增1 
            j++;
        }
        else j=nextval[j];			//i不变,j回退
    }
    if (j>=m) 
        return i-m;
    else 
        return -1;
}


int main() {
    // insert code here...

};


//本算法的时间复杂度也为O(n+m)。
