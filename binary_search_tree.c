//Program to create BST and perform Preorder,Inorder, and Postorder Traversing.

#include<stdio.h>
struct node
{
    int info;
    struct node *left, *right;
};
struct node *root=NULL;
void Create();
void Preorder(struct node *);
void Inorder(struct node *);
void Postorder(struct node *);
int main()
{
    int ch;
    do
    {
        printf("\n\nMENU");
        printf("\n1 Create\n2 Preorder \n3 Inorder\n4 Postorder");
        printf("\n5 Exit\nEnter your choice ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            Create();
            break;
        case 2:
            printf("\nPreorder is \n");
            Preorder(root);



            break;
        case 3:
            printf("\nInorder is \n");
            Inorder(root);
            break;
        case 4:
            printf("\nPostorder is \n");
            Postorder(root);
            break;
        case 5:
            break;
        default:
            printf("\nInvalid choice ");
        }
    }
    while(ch!=5);
    return 0;
} // end of main
void Create()
{
    int item;
    struct node *n, *t, *p;
    char ch;
    do
    {
        printf("\n\nEnter the number ");
        scanf("%d",&item);
//find parent node of item
        p=NULL;
        t=root;
        while(t!=NULL)
        {
            p=t;
            if(item<t->info)
                t=t->left;
            else
                t=t->right;

        }
//create a new node
        n = (struct node *) malloc(sizeof(struct node));
        n->info=item;
        n->left=NULL;
        n->right=NULL;
//insert new node
        if(root==NULL) //if root is null then new node is the root
            root=n;
        else if(item<p->info) //if item is smaller then set in left of parent
            p->left=n;
        else
            p->right=n; //if item is greater then set in right of parent
        printf("%d is inserted in BST\n",item);
        printf("\nAdd Another(y/n)");
        ch=getche();
    }
    while(ch=='y' || ch=='Y');
} // end of Create
void Preorder(struct node *t)
{
    if(t!=NULL)
    {
        printf("\t %d ",t->info);
        Preorder(t->left);
        Preorder(t->right);
    }
}

void Postorder(struct node *t)
{
    if(t!=NULL)
    {
        Postorder(t->left);
        Postorder(t->right);
        printf("\t %d ",t->info);
    }
}
void Inorder(struct node *t)
{
    if(t!=NULL)
    {
        Inorder(t->left);
        printf("\t %d ",t->info);
        Inorder(t->right);
    }
}
