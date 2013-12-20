/*
 * =====================================================================================
 *
 *       Filename:  1512.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年12月20日 23时21分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenxian Ni (Hello World~), niwenxianq@qq.com
 *   Organization:  AMS/ICT
 *
 * =====================================================================================
 */

#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

class myQueue
{
    public:
        void en(int x);
        int  de();
        int  sizeq();
        bool emptyq();

    private:
        stack<int>v1;
        stack<int>v2;
};

int myQueue::sizeq()
{
    return v1.size() + v2.size();
}

bool myQueue::emptyq()
{
    if(sizeq()==0)
        return true;
    return false;
}

void myQueue::en(int x)
{
    v1.push(x);
}

int myQueue::de()
{
    if(sizeq()==0)
        return -1; //the queue is empty
    int front_val;
    if(v1.size()==1)
    {
        front_val = v1.top();
        v1.pop();
        return front_val;
    }
    while(v1.size()!=1)
    {
        front_val = v1.top();
        v2.push(front_val);
        v1.pop();
    }
    front_val = v1.top();
    v1.pop();
    int temp_val;
    while(!v2.empty())
    {
       temp_val = v2.top(); 
       v1.push(temp_val);
       v2.pop();
    }
    return front_val;
}

int main()
{
    int n;
    int val;
    char str[5];
    myQueue qu;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>str;
            if(!strcmp(str,"PUSH"))
            {
                cin>>val;
                qu.en(val);
            }
            if(!strcmp(str,"POP"))
            cout<<qu.de()<<endl;
        }
    }
    return 0;
}
