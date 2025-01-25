#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node*next;
    Node*prev;

    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

class Mystack
{
    public:
    Node*head=NULL;
    Node*tail=NULL;
    int st_sz=0;

    void spush(int val)
    {
        st_sz++;
        Node* newnode=new Node(val);
        // corner casse
        if(tail==NULL)
        {
            head=newnode;
            tail=newnode;
            return;
        }

        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;

    }
    void spop()
    {
        st_sz--;
        Node*deletenode=tail;
       tail= tail->prev;
       delete deletenode;
        if(tail==NULL)
        {
            head=NULL;
            return;
        }
        tail->next=NULL;
 

    }

    int stop()
    {
        return tail->val;
    }

    int ssize()
    {
        return st_sz;
    }
    bool sempty()
    {
        return head==NULL;
    }

};

class Myqueue
{
    public:
    Node*head=NULL;
    Node*tail=NULL;
    int que_sz=0;

    void qu_push(int val)
    {
        que_sz++;
        Node*newnode=new Node(val);
        if(head==NULL)
        {
             head=newnode;
             tail=newnode;
            return;
        }
         tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;




    }

    void que_pop()
    {
        que_sz--;

        Node*deletenode=head;
        head=head->next;
        delete deletenode;
        if(head==NULL)
        {
            tail=NULL;
            return;
        }


        head->prev=NULL;
    }

    int que_front()
    {
        return head->val;
    }
    int que_size()
    {
        return que_sz;
    }
    bool que_empty()
    {
        return head==NULL;
    }


};





int main()
{
    Mystack st;
    Myqueue qu;
     
    int n,m;cin>>n>>m;
    for(int i=0; i<n;i++)
    {
        int val;cin>>val;
        st.spush(val);
    }

    for(int i=0; i<m; i++)
    {
        int val;cin>>val;
        qu.qu_push(val);
    }

    if(st.ssize()!=qu.que_size())
    {
        cout<<"NO";
        return 0;
    }

    while(!st.sempty() && !qu.que_empty())
    {
        if(st.stop()!=qu.que_front())
        {
            cout<<"NO";
            return 0;
        }
        st.spop();
        qu.que_pop();
    }
    cout<<"YES";

 
    
    return 0;
}