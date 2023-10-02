#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() 
{  string s1="",s2,s3="Bye";
   s1.append("Good morning");		//s1="Good morning"
   s2=s1;				//s2="Good morning"
   int i=s2.find("morning");		//i=5
   s2.replace(i,s2.length()-i,s3);	//相当于s2.replace(5,7,s3)
   cout << "s1: " << s1 << endl;
   cout << "s2: " << s2 << endl;
   cout << "s3: " << s3 << endl;
   string s4=s1;
   reverse(s4.begin(),s4.begin()+4);	//逆置s4的前面4个字符
   cout << "s4: " << s4 << endl;
   return 0;
}

// string容量的主要成员函数及其说明
// empty()	判断当前字符串是否为空串
// length()、size()	返回当前字符串的实际字符个数（返回结果为size_t类型）
// [p]	返回当前字符串位于序号p的字符，序号i从0开始。
// front()	返回当前字符串的首字符
// back()	返回当前字符串的尾字符
// compare(const string& s)	返回当前字符串与字符串s的比较结果，若两者相等返回0，若前者小于后者返回-1，否则返回1
// append(s)	在当前字符串的末尾添加一个字符串s
// push_back(char c)	在当前字符串的末尾添加一个字符c
// pop_back()	在当前字符串中删除末尾字符
// insert(size_t p,const string& s)	在当前字符串的序号p处插入一个字符串s
// insert(IT p,char c)	在当前字符串中迭代器p指向的位置上插入一个字符c
// find(string& s,size_t p=0)	在当前字符串中p位置开始查找字符串s的第一个位置，找到后返回其位置，没有找到返回-1
// find(char c,size_t p=0)	在当前字符串中p位置开始查找字符c的第一个位置，找到后返回其位置，没有找到返回-1
// rfind(string& s,size_t p=0)	在当前字符串中p位置开始查找字符串s的最后一个位置，找到后返回其位置，没有找到返回-1
// rfind(char c,size_t p=0)	在当前字符串中p位置开始查找字符c的最后一个位置，找到后返回其位置，没有找到返回-1
// replace(size_t p,size_t len,const string& s)	将当前字符串中起始于p的len个字符用一个字符串s替换
// replace(IT beg,IT end,const string& s)	将当前字符串中[beg,end)迭代器区间（不含end）的所有字符用字符串s替换
// substr(size_t p)	返回当前字符串起始于p的子串
// substr(size_t p,size_t len)	返回当前字符串起始于p的长度为len的子串
// clear()	删除当前字符串中的所有的字符
// erase()	删除当前字符串中的所有的字符
// erase(size_t p)	删除当前字符串的从序号p开始的所有字符
// erase(size_t p,size_t len)	删除当前字符串的从序号p开始的len个字符
// erase(IT beg,IT end)	删除当前字符串中[beg,end)迭代器区间的所有字符
// begin()	返回容器中第一个元素的迭代器
// end()	返回容器中尾元素后面一个位置的迭代器
// rbegin()	返回容器中尾元素的反向迭代器
// rend()	返回容器中首元素前面一个位置的反向迭代器

// 可以使用getline函数从cin流中提取若干字符存放到string中。