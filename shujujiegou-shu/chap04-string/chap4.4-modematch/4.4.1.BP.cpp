#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

//BF brute-force 也被称为简单匹配算法
//目标串s="s0s1…sn-1"，模式串t="t0t1…tm-1"
// 第1趟：从s0/t0开始比较，若相等，则继续逐个比较后续字符。
// 如果对应的字符全部相同且t的字符比较完，说明t是s的子串，返回t在s中的起始位置，表示匹配成功；
// 如果对应的字符不相同，说明第一趟匹配失败。
// 第2趟：从s1/t0开始比较，若相等，则继续逐个比较后续字符。
// 如果对应的字符全部相同且t的字符比较完，说明t是s的子串，返回t在s中的起始位置，表示匹配成功；
// 如果对应的字符不相同，说明第一趟匹配失败。
// 依次类推。只要有一趟匹配成功，则说明t是s的子串，返回t在s中的起始位置。
// 如果i超界都没有匹配成功，说明t不是s的子串，返回-1。

int BF(string s,string t)		    //BF模式匹配算法 
{  int i=0,j=0;
   while (i<s.length() && j<t.length()) //两串未遍历完时循环
   {  if (s[i]==t[j])			    //比较的两个字符相同时
      {  i++; j++; }			    //s和t串依次移到下一个字符
      else				    //比较的两个字符不相同时
      {  i=i-j+1;			    //i回退到s本趟开始的下一个字符 
         j=0;				    //j移动到t串的开头
      }
   }
   if (j>=t.length()) return i-t.length(); //t串遍历完毕：匹配成功 
   else return -1;			    //匹配不成功, 返回-1
}

int main() {
    // insert code here...

};


// 该算法在最好情况下的时间复杂度为O(m)，即主串的前m个字符正好等于模式串的m个字符。
// 最坏情况下的时间复杂度为O(n×m)。
// 平均情况下的时间复杂度为O(n×m)。