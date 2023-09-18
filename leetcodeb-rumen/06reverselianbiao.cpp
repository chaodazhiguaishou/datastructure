//
//  testnew.cpp
//  datastructure
//
//  Created by 赵一田 on 2023/9/11.
//
//

//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

//

#include <iostream>
#include <stdio.h>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//第一种处理方法，递归
//顺序遍历，回溯的时候将节点值加入数组
class Solution1 {
public:
    vector<int> reversePrint1(ListNode* head) {
        recur(head);
        return res;
    }
private:
    vector<int> res;
    void recur(ListNode* head) {
        if(head == nullptr) return; //如果遇到null说明遍历结束，开始回溯
        recur(head->next);
        res.push_back(head->val); //回溯的时候每次
    }
};


//方法二，使用辅助栈
//利用栈的先进后出实现先遍历的最后出结果
 class Solution2 {
 public:
     vector<int> reversePrint2(ListNode* head) {
         stack<int> stk;
         while(head != nullptr) { //顺次遍历链表加入栈
             stk.push(head->val);
             head = head->next;
         }
         vector<int> res; //最后输出的可变数组
         while(!stk.empty()) { //依次出栈
             res.push_back(stk.top());
             stk.pop();
         }
         return res;
     }
 };


int main(int argc, const char * argv[]) {
    // insert code here...

    // 实例化节点
    ListNode *n1 = new ListNode(4); // 节点 head
    ListNode *n2 = new ListNode(5);
    ListNode *n3 = new ListNode(1);

    // 构建引用指向
    n1->next = n2;
    n2->next = n3;


    Solution1 s1;
    Solution2 s2;
    vector<int> output = s1.reversePrint1(n1);
    //当定义变量为非字符符数组时，采用cout << 数组名; 系统会输出数组的地址，如：
    //如果需要输出非字符数组中的内容，则需要采用循环，逐个输出数组中的元素
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
    return 0;
};

