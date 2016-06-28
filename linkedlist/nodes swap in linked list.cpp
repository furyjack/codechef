
#include<iostream>

#include<vector>

using namespace std;

struct node
{
    int content;
    node*next;
};


node* swap(node*head,int key1,int key2)
{
    if(head==NULL)
        return head;



    node*prevf=NULL;
    node*prevs=NULL;

    bool check=false;

    node*first=NULL;
    node*second=NULL;


    if(head->content==key1 or head->content==key2)
    {
        first=head;
        check=true;

    }

    for(node*temp=head;temp->next!=NULL ;temp=temp->next)
    {
        if(temp->next->content==key1)
            {
                if(check==false)
                {
                    check=true;
                    first=temp->next;
                    prevf=temp;
                }
                else
                  {
                    second=temp->next;
                    prevs=temp;
                  }

            }
        if(temp->next->content==key2)
            {

                if(check==false)
                {
                    check=true;
                    first=temp->next;
                    prevf=temp;
                }
                else
                  {
                    second=temp->next;
                    prevs=temp;
                  }



             }


    }



    if(first==NULL or second==NULL or first==second)
        return head;

    if(first->next==second)   //adjacent elements
    {

        if(first==head)
        {

            head=second;
            first->next=second->next;
            second->next=first;



        }
        else
        {

            prevf->next=second;
            first->next=second->next;
            second->next=first;



        }



    }
    else
    {

        if(first==head)
        {


            head=second;
            prevs->next=first;
            node*temp=first->next;
            first->next=second->next;
            second->next=temp;



        }
        else
        {
            prevs->next=first;
            prevf->next=second;
            node*temp=first->next;
            first->next=second->next;
            second->next=temp;





        }



    }

return head;

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






head=swap(head,2,7);


print(head);


    return  0;
}
