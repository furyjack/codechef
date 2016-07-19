
#include<iostream>


using namespace std;


struct node
{
    int data;
    node*left;
    node*right;
};

struct wrapper
{
    int max;
    int min;
    bool isBst;

};

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

wrapper isbst(node*root)
{
    if(root->left==NULL && root->right==NULL)
    {
        wrapper r;
         r.max=root->data;
         r.min=root->data;
         r.isBst=true;

         return r;
    }

    wrapper self;
    wrapper left;
    wrapper right;

    if(root->left==NULL)
    {
        right=isbst(root->right);
        if(right.isBst==true && right.min>root->data )
        {
            self.isBst=true;
            self.min=root->data;
            self.max=right.max;
        
        }
        else
            self.isBst=false;

        return self;



    }
    else if(root->right==NULL)
    {
        left=isbst(root->left);
        if(left.isBst==true && left.max<root->data)
        {
            self.isBst=true;
            self.min=left.min;
            self.max=root->data;
    
        }
        else
            self.isBst=false;

        return self;


    }

    else

    {
        right=isbst(root->right);
        left=isbst(root->left);

        if(left.isBst==true && right.isBst==true && left.max<root->data && right.min>root->data)
        {
            self.isBst=true;
            self.max=right.max;
            self.min=left.min;

            


        }
        else
            self.isBst=false;

        return self;







    }








    }











int main()
{

     struct node *root = newNode(3);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(4); 

  wrapper ans=isbst(root);
  cout<<ans.isBst;




    cin.get();
}