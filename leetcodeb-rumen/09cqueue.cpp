//用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead
//分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

//两个栈，栈a用于尾部插入，栈b作为辅助栈用于头部删除

#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> stacka;
    stack<int> stackb;

    CQueue() {
    }
    
    void appendTail(int value) {
        //添加到队尾则直接加入栈a
        stacka.push(value);
    }
    
    int deleteHead() {
        //要删除头部则需要在栈b为空的时候把栈a倒过来，这样先进栈的才可以先出

        //倒栈a需要栈b为空！如果栈b不空的时候，说明此时栈b的栈顶才是队列头部，此时的栈a是后加入的
        //所以栈b不为空的时候直接读取栈b的栈顶，正是整个队列的头部
        if(!stackb.empty()){
            int tmp = stackb.top();
            stackb.pop();
            return tmp;
        }

        //如果栈b为空，栈a不为空则一律倒过去
        if (!stacka.empty()){
            while(!stacka.empty()){
                int change=stacka.top();
                stacka.pop();
                stackb.push(change);
            }
        }

        //若栈b，栈a都为空说明队列为空
        if (stacka.empty()){
            if(stackb.empty()){
                return -1;
            }
        }

        //栈a倒到栈b后，直接读取栈b顶即是队列头部
        int tmp = stackb.top();
        stackb.pop();
        return tmp;

    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */


int main(int argc, const char * argv[]) {
    // insert code here...
    CQueue* obj = new CQueue();
    cout<<obj->deleteHead()<<endl;
    obj->appendTail(5);
    obj->appendTail(2);
    cout<<obj->deleteHead()<<endl;
    cout<<obj->deleteHead()<<endl;
    return 0;
};
