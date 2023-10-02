#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

//两次转换，一次将exp转换为postexp，一次将postexp转换为

//第一次转换需要使用运算符栈opor
// while (若exp未读完)
// {  从exp读取字符ch;
//    ch为数字：将后续的所有数字均依次存放到postexp中;
//    ch为左括号'('：将'('进栈到opor;
//    ch为右括号')'：将opor栈中'('以前的运算符依次出栈并存放到postexp中,再将'('退栈;
//    若ch的优先级高于栈顶运算符优先级，则将ch进栈；否则将栈顶元素出栈并存放到postexp中直到该条件成立,再将ch进oper栈;
//    就算优先级相同，也要讲栈顶元素出栈
//    ！！！！！栈的特性，栈里应该满足优先级高的在栈顶先出。优先级相同的时候，已经在栈内的说明早进栈得先运算
// 字符串exp扫描完毕,则退栈opor的所有运算符并存放到postexp中

//第二次转换需要使用运算数栈opand
// while (若postexp未读完)
// {  从postexp读取字符ch;
//    ch为'+'：从opand栈出栈两个数值a和b,计算c=b+a;将c进栈opand;
//    ch为'-'：从opand栈出栈两个数值a和b,计算c=b-a;将c进栈opand;
//    ch为'*'：从opand栈出栈两个数值a和b,计算c=b*a;将c进栈opand;
//    ch为'/'：从opand栈出栈两个数值a和b,若a不零,计算c=b/a;将c进栈opand;
//    ch为数字字符：将连续的数字串转换成数值d,将d进栈opand;
// }
// opand栈中唯一的数值即为表达式值


class Express				//求表达式值类
{  string exp;				//存放中缀表达式
   string postexp;			//存放后缀表达式
public:

Express(string str)		//构造函数
{  
    exp=str; 
    postexp="";
}

string getpostexp()		//返回postexp 
{
    return postexp;
}


void Trans()			//将算术表达式exp转换成后缀表达式postexp
{  stack<char> opor;		//定义运算符栈opor
   int i=0;			//i为exp的下标
   char ch,e;
   while (i<exp.length())	//exp表达式未扫描完时循环
   {  
        ch=exp[i];
        if (ch=='(')		//遇到左括号
            opor.push(ch);	//将左括号直接进栈
        else if (ch==')')	//遇到右括号
        {  
            while (!opor.empty() && opor.top()!='(')
            {  
                e=opor.top();	//将栈中'('之前的运算符退栈并存入postexp
                opor.pop();
                postexp+=e;
            }
            opor.pop();		//将(退栈
        }
        else if (ch=='+' || ch=='-')	//遇到加或减号
        {  
            while (!opor.empty() && opor.top()!='(')
            {  
                e=opor.top();		//将栈中(之前的所有运算符退栈
                opor.pop();			//并存入postexp
                postexp+=e;
            }
            opor.push(ch);			//再将'+'或'-'进栈
        }
        else if (ch=='*' || ch=='/')	//遇到'*'或'/'号
        {  
            while (!opor.empty() && opor.top()!='(' && (opor.top()=='*' || opor.top()=='/'))
            {  
                e=opor.top();		//将栈中(之前的所有*或/依次出栈
                opor.pop();			//并存入postexp
            postexp+=e;
            }
            opor.push(ch);			//再将'*'或'/'进栈
        }
        else				//遇到数字字符
        {  
            string d="";
            while (ch>='0' && ch<='9')   	//遇到数字
            {  
                d+=ch;			//提取所有连续的数字字符
                i++;
                if (i<exp.length())	   	//exp没有遍历完时取下一个字符ch
                    ch=exp[i];
                else			   	//exp遍历完毕时退出数字判断
                break;
            }
            i--;			   	//退一个字符，因为遇到数字i一定会加一，后面还会统一加一
            postexp+=d;		   	//将数字串存入postexp
            postexp+="#";		   	//用#标识一个数字串结束
        }
        i++;				//继续处理其他字符
    }
    while (!opor.empty())	//此时exp扫描完毕,栈不空时循环
    {  
        e=opor.top();
        opor.pop();		//将栈中所有运算符退栈并放入postexp
        postexp+=e;
    }
}

double GetValue()			//计算后缀表达式postexp的值
{  stack<double> opand;		//定义运算数栈opand
   double a,b,c,d;
   char ch;
   int i=0;
   while (i<postexp.length())		//postexp字符串未扫描完时循环
   {  
        ch=postexp[i];
        switch (ch)
        {
        case '+':			//遇到+
            a=opand.top(); opand.pop();	//退栈运算数a
            b=opand.top(); opand.pop();	//退栈运算数b 
            c=b+a;			//计算c
            opand.push(c);		//将计算结果进栈
            break;
        case '-':				//遇到-
            a=opand.top(); opand.pop();	//退栈运算数a
            b=opand.top(); opand.pop();	//退栈运算数b 
            c=b-a;				//计算c
            opand.push(c);			//将计算结果进栈
            break;
        case '*':				//遇到*
            a=opand.top(); opand.pop();	//退栈运算数a
            b=opand.top(); opand.pop();	//退栈运算数b 
            c=b*a;				//计算c
            opand.push(c);			//将计算结果进栈
            break;
        case '/':				//遇到/
            a=opand.top(); opand.pop();	//退栈运算数a
            b=opand.top(); opand.pop();	//退栈运算数b 
            c=b/a;				//计算c
            opand.push(c);			//将计算结果进栈
            break;
        default:			//遇到数字字符
            d=0;			//将连续的数字符转换成数值存放到d中
            while (ch>='0' && ch<='9')
            {  
                d=10*d+(ch-'0');
                i++;
                ch=postexp[i];
            }
            opand.push(d);	//将数值d进栈
            break;
        }
        i++;			//继续处理其他字符
   }
   return opand.top();	//栈顶元素即为求值结果
}

};


int main()
{  
    // string str="(56-20)/(4+2)";
    string str="56-20/4+2";
    Express obj(str);
    cout << "中缀表达式: " << str << endl;
    cout << "中缀转换为后缀" << endl;
    obj.Trans();
    cout << "后缀表达式: " << obj.getpostexp() << endl;
    cout << "求后缀表达式值" << endl;
    cout << "求值结果:   " << obj.GetValue() << endl;
    return 0;
}


