
#include<iostream>

#include<vector>

using namespace std;

struct node
{
    int content;
    node*next;
};

class wrap
{
public:
    node*head;
    node*tail;
};

wrap* reverse_link_rec(node*head)
{
    if(head==NULL)
        return NULL;

    if(head->next==NULL)
    {
        wrap* r=new wrap;
        r->head=head;
        r->tail=head;
        head->next=NULL;
        return r;
    }


    wrap *Next=reverse_link_rec(head->next);

    wrap * r=new wrap;
    r->head=Next->head;
    Next->tail->next=head;
    Next->tail=Next->tail->next;
    head->next=NULL;
    r->tail=Next->tail;

    return r;



}


node* reverse_link(node*head)
{
    if(!head or !head->next)
        return head;

    node*prev=NULL;
    node*curr=head;
    node*Next=curr->next;

    while(curr)
    {

        curr->next=prev;
        prev=curr;
        curr=Next;
        if(curr)
        Next=curr->next;



    }
    return prev;


}


node* insert_end(node*root,int key)
{
    node*newnode=new node;
    newnode->content=key;
    newnode->next=NULL;
    if(root==NULL)
        return newnode;
    else
    {
        root->next=newnode;

    }
    return newnode;


}

void print(node*head)
{

    while(head!=NULL)
    {
        cout<<head->content<<"->";
        head=head->next;
    }

}

int main()
{

node*head;
node*tail;
head=tail=NULL;

head=tail=insert_end(tail,2);
tail=insert_end(tail,1);
tail=insert_end(tail,6);
tail=insert_end(tail,4);
tail=insert_end(tail,7);






head=reverse_link_rec(head)->head;

head=reverse_link(head);



print(head);


    return  0;
}
