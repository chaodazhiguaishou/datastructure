//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };

//方法一，递归法
//使用递归，先顺次递归，回溯的时候直接更改指向
class Solution1 {
public:
    ListNode* reverseList1(ListNode* head) {
        //return recur(head,head->next) 该写法会导致报错，因为递归回溯的时候没有处理原先head的指向！！！
        //原先head反转后作为单链表的尾节点应该指向null
        return recur(nullptr,head);
    }

private:
    ListNode* recur(ListNode* former,ListNode* latter){
        if (latter == nullptr){ //尾指针为空代表遍历完成，返回当前的最后一个节点
            return former;
        }
        //recur(former->next,latter->next);
        ListNode* res =  recur(latter,latter->next);//！！！很重要这里
        //！！！！不是直接递归！！！因为需要返回最后的节点作为反转后的头指针
        
        latter->next = former;
        return res;
    }

};

//方法二，迭代法
//使用两个节点，遍历移动更改节点指向
class Solution2 {
public:
    ListNode* reverseList2(ListNode* head) {
        ListNode* front = nullptr;
        ListNode* back = head;
        while(back!=nullptr){
            ListNode* uu = back->next; //暂存后指针的下一位
            back->next = front; //后指针指向上一位
            front = back; //前指针后移一位
            back = uu; //后指针后移一位
        }
        return front;
    }
};

//打印链表数据 
void printList(ListNode* head) {
    ListNode* current = head;
    printf("链表所存数据: ");
	//表头为空，结束循环 
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
        // 实例化节点
    ListNode *n1 = new ListNode(4); // 节点 head
    ListNode *n2 = new ListNode(5);
    ListNode *n3 = new ListNode(1);

    // 构建引用指向
    n1->next = n2;
    n2->next = n3;

    // Solution1 s1;
    // ListNode* rep1 = s1.reverseList1(n1);
    // printList(rep1);

    Solution2 s2;
    ListNode* rep2 = s2.reverseList2(n1);
    printList(rep2);
    return 0;
};


//  //此题不能直接用从尾到头打印链表，因为那道题输出的是数组，但是是不是可以拿数组暂存？
//  //如何根据数组创建链表
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         recur(head);
//         int len = res.size();
//         for (int i=0;i<len-1;i++){
//             ListNode* newnode = new ListNode(res[i]);
            
//         }
//         return head;
//     }

// private:
//     vector<int> res;
//     void recur(ListNode* head) {
//         if(head == nullptr) return;
//         recur(head->next);
//         res.push_back(head->val);
//     }

// };