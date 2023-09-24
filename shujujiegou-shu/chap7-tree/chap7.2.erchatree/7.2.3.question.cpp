#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

//同一个指针变量p，可以多次st.push(p)，但是每次进去的都是同一个（地址是一样的！）
//但是如果对p = new BTNode('B')，此时出现的p是新的p

struct BTNode // 二叉链中结点类型
{
   char data;                               // 数据元素
   BTNode *lchild;                          // 指向左孩子结点
   BTNode *rchild;                          // 指向右孩子结点
   BTNode() : lchild(NULL), rchild(NULL) {} // 构造函数
   BTNode(char d)                           // 重载构造函数
   {
      data = d;
      lchild = rchild = NULL;
   }
};

void test1()
{
    BTNode *p = new BTNode('a');
    stack<BTNode *> st;
    st.push(p);
    st.push(p);
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    //输出为
    // a
    // 0x7fe9bd904080
    // 0
    // a
    // 0x7fe9bd904080
    // 1
}

void test2()
{
    BTNode *p = new BTNode('a');
    stack<BTNode *> st;
    st.push(p);
    st.push(p);
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    p->data = 'b';
    cout << st.empty() << endl;
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    //输出为
    // a
    // 0x7f81d5804120
    // 0
    // b
    // 0x7f81d5804120
    // 1
}

void test3()
{
    BTNode *p = new BTNode('a');
    stack<BTNode *> st;
    st.push(p);
    p = new BTNode('B');
    st.push(p);
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    //输出为
    // B
    // 0x7f886e705eb0
    // 0
    // a
    // 0x7f886e705e90
    // 1

}

void test4()
{
    BTNode *p ;
    stack<BTNode *> st;

    p = new BTNode('a');
    st.push(p);
    p = new BTNode('B');
    st.push(p);
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    cout << st.top()->data << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.empty() << endl;
    //输出为

}
int main() {
    // insert code here...
    test4();
    return 0 ;
};