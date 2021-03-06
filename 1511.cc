/*
 * =====================================================================================
 *
 *       Filename:  1518.cc
 *
 *    Description:   
 *
 *        Version:  1.0
 *        Created:  2013年12月19日 20时29分08秒
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

LinkNode *initList()
{
    LinkNode *root = NULL;
    LinkNode *p, *q;
    int value;
    while(cin>>value&&value!=-1)
    {
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

LinkNode *reverse(LinkNode *root)
{
    if(!root)
        return NULL;
    LinkNode *p, *q, *temp;
    p = root;
    q = root->next;

    while(q)
    {
        temp = q;
        q = q->next;
        temp->next = p;
        p = temp;
    }
    root->next = NULL;
    return p;
}

void printList(LinkNode *root)
{
    while(root)
    {
        cout<<root->val;
        root = root->next;
            cout<<endl;
    }
}

int main()
{
    LinkNode *root,*newRoot;
    root = initList();
    newRoot = reverse(root);
    printList(newRoot);
    return 0;
}
