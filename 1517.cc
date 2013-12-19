/*
 * =====================================================================================
 *
 *       Filename:  1517.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2013年12月19日 21时21分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wenxian Ni (Hello World~), niwenxianq@qq.com
 *   Organization:  AMS/ICT
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int x):val(x),next(NULL){};
};

LinkNode *initList(int n)
{
   if(n<=0) 
        return NULL;
    LinkNode *root = NULL;
    LinkNode *p, *q;
    int value;
    while(n--)
    {
        cin>>value;
        p = new LinkNode(value);
        if(!root)
        {
            root = p;
            q = root;
            continue; //if not, when n =1, it's a loop;
        }
        q->next = p;
        q = q->next;
    }
    return root;
}

LinkNode *findKthNode(LinkNode *root, int n, int k)
{
    //three cases:
    if(!root)    
        return NULL; 
    if(k>n||k==0)
        return NULL;
    if(n==k)
        return root;

    LinkNode *p,*q;
    int i = 0;
    p = root;
    q = root;
    while(++i!=k)
        q = q->next;
    while(q->next) //q->next
    {
        q = q->next;
        p = p->next;
    }
    return p;
}

int main()
{
    int n,k;
    LinkNode *root;
    LinkNode *p;
    while(cin>>n>>k)
    {
        root = initList(n);
        p = findKthNode(root,n,k);
        if(!p)
        {
            cout<<"NULL"<<endl;
            continue;
        }
        cout<<p->val<<endl;
    }
    return 0;
}
