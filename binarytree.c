#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void insert(struct Node **, int );
void preOrder(struct Node *);
void inOrder(struct Node *);
void postOrder(struct Node *);


int main()
{
    struct Node *root= 0;
    int num, opt= 1;
    do
    {
        printf("Enter the element:\n");
        scanf("%d", & num);

        // Here we are giving the address of the pointer (&root) rather than simply writing (root) because, 
        // if we write root without &, it will simply means that the root pointer is passed as call by value.
        // So this doesnot make any change in the actual node. Changes will be made only inside the insert() function.
        // So inorder to do CALL BY REFERENCE, we are passing the address of the pointer; ie &root 
        insert(&root, num);
        printf("To continue Enter 1, else Enter 0: ");
        scanf("%d", & opt);
    } 
    while (opt);

    // Here we are simply writing (root) instead of (&root) because, in inorder(), pre order() and postorder() function, we are not making 
    // any changes in the actual arrangement of the struct nodes. We are simply displaying it with temporary arrangement of the nodes, only inside the function
    // Here CALL BY VALUE is being used.
    printf("Preorder: ");
    preOrder(root);
    printf("\nInorder: ");
    inOrder(root);
    printf("\nPostorder: ");
    postOrder(root);
}

// here rt is taken as a double pointer since it points to another pointer called root. 
void insert(struct Node **rt, int x)
{
    // Here, if it was rt == 0 or rt->left etc, it would mean error since the double pointer rt holds the address of the root pointer. But what we 
    // need is the address of the struct node. 
    // rt: has the address of the root pointer 
    // *rt: has the address of root pointer and along with that, the root pointer has the address of struct node 
    // In short, rt points to root pointer, root points to struct node; and *rt directly points to the struct node
   if(*rt == 0)
   {
        *rt = (struct Node *)malloc(sizeof(struct Node));
        (*rt)->data= x;  
        (*rt)->left= 0;
        (*rt)->right= 0;
   }
   else if(x <= (*rt)->data)
   {
        // Here CALL BY REFERENCE is used. This is like the same case as used in main function
        insert(&((*rt)->left), x);
   }
   else
   {
        insert(&((*rt)->right), x);
   }
}

void preOrder(struct Node *rt)
{
    if (rt != 0)
    {
        printf("%d  ", rt->data);
        preOrder(rt->left);
        preOrder(rt->right);
    }
}

void inOrder(struct Node *rt)
{
    if (rt != 0)
    {
        inOrder(rt->left);
        printf("%d  ", rt->data);
        inOrder(rt->right);
    }
}

void postOrder(struct Node *rt)
{
    if (rt != 0)
    {
        postOrder(rt->left);
        postOrder(rt->right);
        printf("%d  ", rt->data);
    }
}