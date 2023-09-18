//
//  main.cpp
//  datastructure
//
//  Created by 赵一田 on 2023/9/11.
//

//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

//在 C++ 语言中， string 被设计成「可变」的类型（参考资料），因此可以在不新建字符串的情况下实现原地修改。

#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int length = s.size();
        int len = length;
        //遍历字符串，根据空格数量扩展长度
        //‘’和‘ ’是不一样的！
        for(char c : s){
            if(c == ' '){
                length = length + 2;
            }
        }
        s.resize(length);
        //完成扩展后倒序遍历修改，通过两个“指针”i和j来依次修改
        for(int i=len-1, j=length-1 ; i < j ; )
        {
            if(s[i] != ' '){
                s[j] = s[i];
                i--;
                j--;
            }
            else {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                i--;
                j=j-3;
            }
        }
        return s;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s; //类内函数对象调用
    cout<<s.replaceSpace("We are happy.")<<endl;
    return 0;
}
