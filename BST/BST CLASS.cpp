
struct node
{
     int key;
     int count;
    node*left;
    node*right;

};

class BST
{
    public:
    node*root;
    BST()
    {
        root=NULL;
    }

    private:
    node* add_help(node*root,int key)
{
    if(root==NULL)
    {
        node*r=new node;
        r->key=key;
        r->left=r->right=NULL;
        r->count=1;
        return r;


    }

    if(key>root->key)
      root->right=add_help(root->right,key);
    else if(key==root->key)
    {
        root->count+=1;
        return root;
    }
    else
        root->left=add_help(root->left,key);

return root;

}

    public:
        void add(int key)
        {

            root=add_help(this->root,key);


        }

    void static inorder(node*root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->key<<"\n";
    inorder(root->right);


}

    private:

        node* delete_help(node*root,int key)
        {
            if(root==NULL)
                return NULL;
            if(key>root->key)
              root->right=  delete_help(root->right,key);
            else if(key<root->key)
               root->left= delete_help(root->left,key);
            else
            {
                if(root->count>1)
                {
                    root->count--;
                    return root;
                }

                else
                {

                    if(root->right==NULL)
                    {
                        node*temp=root->left;
                        delete root;
                        return temp;

                    }
                    else if(root->left==NULL)
                    {

                        node*temp=root->right;
                        delete root;
                        return temp;

                    }

                    node*temp=minValueNode(root->right);
                    root->key=temp->key;
                    root->count=temp->count;
                    temp->count=1;
                    root->right= delete_help(root->right,temp->key);




                }


            }





        }

    public:
        void Delete(int key)
        {

            root=delete_help(root,key);

        }

node * minValueNode( node* root)
{
    node* current = root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}




};