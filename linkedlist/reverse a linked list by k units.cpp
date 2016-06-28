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



node*k_reverse(node*head,int k)
{
    if(!head or !head->next)
        return head;
    int count;
    node*temp;
    for(count=2,temp=head->next; count<k and temp->next;count++,temp=temp->next);



    if(count==k)
    {
        if(temp->next)
        {
            node*temp1=temp->next;
            temp->next=NULL;
            node*h=reverse_link(head);
            head->next=k_reverse(temp1,k);
            return h;



        }
        else
            return reverse_link(head);

    }
    else
       return reverse_link(head);


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





head=k_reverse(head,3);



print(head);


    return  0;
}
