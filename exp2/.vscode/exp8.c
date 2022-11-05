// Write a menu driven code to implement Binary Search Tree
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
struct node *FindMin(struct node *);
struct node *deleteElement(struct node *, int);
struct node *searchElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
int totalNodes(struct node *);
int totalLeafNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
int main()
{
    int option, key;
    create_tree(root);
    printf("\n***List Of Operations***");
    printf("\n1. Insertion\n2. Deletion\n3. Searching\n4. Pre-order Traversal\n5. In-order Traversal\n6. Postorder Traversal\n7. Total number of nodes\n8. Total number of leaf nodes\n9. Total number of internal nodes\n10. Find height of the tree\n11. Exit\n");
    do
    {
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &key);
            root = insertElement(root,key);
            break;
        case 2:
            printf("Enter the element to be deleted: ");
            scanf("%d", &key);
            root = deleteElement(root,key);
            break;
        case 3:
            printf("Enter the element to be searched: ");
            scanf("%d", &key);
            root = searchElement(root, key);
            if (root)
                printf("The value %d is found in the tree", key);
            else
                printf("The value %d not found", key);
            break;
        case 4:
            printf("The elements of the tree are : \n");
            preorderTraversal(root);
            break;
        case 5:
            printf("The elements of the tree are : \n");
            inorderTraversal(root);
            break;
        case 6:
            printf("The elements of the tree are : \n");
            postorderTraversal(root);
            break;
        case 7:
            printf("Total no. of nodes = %d", totalNodes(root));
            break;
        case 8:
            printf("Total no. of leaf nodes = %d",
                   totalLeafNodes(root));
            break;
        case 9:
            printf("Total no. of internal nodes = %d",
                   totalInternalNodes(root));
            break;
        case 10:
            printf("The height of the tree = %d", Height(root));
            break;
        case 11:
            printf("\n\tEXIT POINT!");
            break;
        }
    } while (option != 11);
    return 0;
}
void create_tree(struct node *root)
{
    root = NULL;
}
struct node *insertElement(struct node *root,int key)
{
    struct node *ptr,*nodeptr,*parentptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=key;
    ptr->left=NULL;
    ptr->right = NULL;
    if (root == NULL)
    {
        root = ptr;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        parentptr=NULL;
        nodeptr=root;
        while(nodeptr!=NULL)
        {
            parentptr=nodeptr;
            if(key<nodeptr->data)
                nodeptr=nodeptr->left;
            else
                nodeptr=nodeptr->right;
        }
        if(key<parentptr->data)
            parentptr->left=ptr;
        else
            parentptr->right=ptr;
    }
    return root;
}
struct node *FindMin(struct node *root)
{
    while(root->left != NULL)
        root=root->left;
    return root;
}
struct node *deleteElement(struct node *root, int key)
{
    if(root==NULL)
        return root;
    else if(key<root->data)
        root->left=deleteElement(root->left,key); //traversing the left subtree
    else if(key>root->data)
        root->right=deleteElement(root->left,key); //traversing the right subtree
    else //found the element
    {
        //Case1: no child
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        //Case 2: one child
        else if(root->left==NULL){
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        //Case 3: two children
        else{
            struct node *temp=FindMin(root->right);
            root->data=temp->data;
            root->right=deleteElement(root->right,temp->data);
        }
    }
    return root;
}
struct node *searchElement(struct node *root,int key)
{
    if(root==NULL)
    {
        printf("\nThe tree is empty");
    }
    else if(key>root->data)
        return searchElement(root->right,key);
    else if(key<root->data)
        return searchElement(root->left,key);
    else
        return root;
}
void preorderTraversal(struct node *root)
{
    if (root!= NULL)
    {
        printf("%d\t", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void inorderTraversal(struct node *root)
{
    if (root!= NULL)
    {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}
void postorderTraversal(struct node *root)
{
    if (root!= NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t", root->data);
    }
}
int totalNodes(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return (totalNodes(root->left) + totalNodes(root->right) + 1);
}
int totalLeafNodes(struct node *root)
{
    if (root==NULL)
        return 0;
    else if ((root->left == NULL) && (root->right == NULL))
        return 1;
    else
        return (totalLeafNodes(root->left) + totalLeafNodes(root->right));
}
int totalInternalNodes(struct node *root)
{
    if ((root == NULL) || ((root->left == NULL) && (root->right == NULL)))
        return 0;
    else
        return (totalInternalNodes(root->left) + totalInternalNodes(root->right) + 1);
}
int Height(struct node *root)
{
    int leftheight, rightheight;
    if (root == NULL) return 0;
    else
    {
        leftheight = Height(root->left);
        rightheight = Height(root->right);
        if (leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}
