#include<iostream>
#include<queue>
using namespace std;
struct node
{   int data;
    struct node *left,*right;
};

struct node *find_ele(struct node *root,int val);//SEARCHING
struct node *find_min(struct node *root);//FINDING MINIMUM
struct node *insert_BST(struct node *root,int val);//INSERTION BST
struct node *D_BST(struct node *root,int val);//DELETION BST
void inorder_BST(struct node *root);//INORDER
void preorder_BST(struct node *root);//PREORDER
void postorder_BST(struct node *root);//POSTORDER
void levelorder_BST(struct node *root);// LEVEL ORDER
int FINDhieght(struct node *root);//HIEGHT OF TREE



int main()
{   struct node *root=NULL;
    root=insert_BST(root,5);
    insert_BST(root,10);
    insert_BST(root,7);
    insert_BST(root,15);
    insert_BST(root,8);
    insert_BST(root,6);
    insert_BST(root,3);
    insert_BST(root,12);
    cout<<"INORDER";
    inorder_BST(root);
    cout<<"\nLEVELORDER";
    levelorder_BST(root);
    cout<<"\nHIEGHT OF BST:\t"<<FINDhieght(root);
    cout<<"\nMINIMUM ELEMENT\t"<<find_min(root->right)->data;
    D_BST(root,7);
    cout<<"\nINORDER";
    inorder_BST(root);
    cout<<"\nLEVELORDER";
    levelorder_BST(root);
    return 0;
}


struct node *find_ele(struct node *root,int val)
{   if(root==NULL)
    {   return root;    }
    else if(root->data > val)
    {   return find_ele(root->left,val);
    }
    else if(root->data < val)
    {   return find_ele(root->right,val);
    }
    return root;
}

struct node *find_min(struct node*root)
{   if(root==NULL)
    {   return NULL;   }
    else if(root->left == NULL)
    {   return root;    }
    else
        return find_min(root->left);
}

struct node *insert_BST(struct node *root,int val)
{   if(root==NULL)
    {   root= new (struct node);
        /*if(root==NULL)
        {   cout<<"Memory Full-";
            return;
        }*/
        root->data=val;
        root->left=root->right=NULL;

    }
    else
    {   if(val < root->data)
        {   root->left=insert_BST(root->left,val);    }
        else if(val > root->data)
        {   root->right=insert_BST(root->right,val);  }
    }
    return root;
}


struct node *D_BST(struct node *root,int val)
{
    struct node *temp;
    if(root==NULL)
    {   cout<<"\nElement Not in Tree";
        return root;
    }
    else if(val < root->data)
    {   root->left=D_BST(root->left,val);
    }
    else if(val > root->data)
    {   root->right=D_BST(root->right,val);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            delete root;
            return temp;
        }
        else{temp=find_min(root->right);
        root->data=temp->data;
        root->right=D_BST(root->right,temp->data);
        }
        }
	return root;

}


void inorder_BST(struct node *root)
{   if(root!=NULL)
    {   inorder_BST(root->left);
        cout<<" "<<root->data;
        inorder_BST(root->right);
    }
}


void preorder_BST(struct node *root)
{   if(root!=NULL)
    {   cout<<" "<<root->data;
        preorder_BST(root->left);
        preorder_BST(root->right);
    }
}


void postorder_BST(struct node *root)
{   if(root!=NULL)
    {   postorder_BST(root->left);
        postorder_BST(root->right);
        cout<<" "<<root->data;
    }
}

void levelorder_BST(struct node *root)
{   queue <struct node *> Q;
    Q.push(root);
    struct node *temp,*k;
    while(!Q.empty())
    {   temp=Q.front();
        cout<<" "<<temp->data<<" ";
        k=Q.back();
        Q.pop();
        if((temp->left)!=NULL)
        {   Q.push(temp->left);
        }
        if((temp->right)!=NULL)
        {   Q.push(temp->right);
        }

    }
}


int FINDhieght(struct node *root)
{   if(root == NULL)
    {   return -1;
    }
    int LH=FINDhieght(root->left);
    int RH=FINDhieght(root->right);
    if(LH>RH)
        return LH+1;
    else
        return RH+1;
}
