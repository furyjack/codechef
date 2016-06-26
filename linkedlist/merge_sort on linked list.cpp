
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

struct node
{
    int content;
    node*next;
};

node* find_mid(node*head)
{
    node*fast=head;
    node*super_fast=head;

    while( super_fast->next!=NULL and super_fast->next->next!=NULL )
    {

        super_fast=super_fast->next->next;
        fast=fast->next;


    }

    return fast;

}

node* merge(node*head1,node*head2)
{
    node*list=NULL;
    node*temp=NULL;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;

    if(head1->content>=head2->content)
       {
           list=head1;
           head1=head1->next;
       }
    else
    {
        list=head2;
        head2=head2->next;
    }

    temp=list;

    while(head1!=NULL and head2!=NULL)
    {

        if(head1->content>=head2->content)
        {
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
            temp->next=NULL;
        }
        else
        {
            temp->next=head1;
            temp=temp->next;
            head1=head1->next;
            temp->next=NULL;

        }



    }

    if(head1==NULL)
        temp->next=head2;
    else
        temp->next=head1;


    return list;


}


node* find_tail(node*head)
{

    node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    return temp;


}

node* merge_sort(node*head,node*tail)
{
    if(head==tail)
        return head;

    node*mid=find_mid(head);
    node*temp=mid->next;
    mid->next=NULL;
    node*list1=merge_sort(head,mid);
    node*list2=merge_sort(temp,tail);

   return merge(list1,list2);


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



head=merge_sort(head,tail);

print(head);


    return  0;
}
