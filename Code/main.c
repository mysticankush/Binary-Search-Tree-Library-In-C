#include <stdio.h>
#include<stdlib.h>

//Declaration of all the functions is done in BST.h file
//Implementation of all the functions is done in BST.c file

#include "BST.h"
int main()
{
        struct Node *root=malloc(sizeof(struct Node));
        
        int flg=0;
        
        //taking input
        
        while(1)
        {
          int x;
          scanf("%d",&x);
          if(x==-1)
           break;
           
           //If it is the first value then make it as a root node
           
           if(flg==0)
           {
               root->key=x;
               root->left=NULL;
               root->right=NULL;
               flg=1;
               continue;
           }
           //else insert x in the current tree with non NULL root
          takeinput(root,x);
        }
        
        //print Inorder traversal of Binary Search Tree 
        
        inorder(root);
        printf("\n");
        
        printf("Print node to search in the tree :- \n");
        int s;
        scanf("%d",&s);
        
        //Check whether node s is present in the Tree or not
        
        if(search(root,s))
          printf("Found %d\n",s);
        else
          printf("Not Found %d\n",s);
        
        printf("Print node to find its ceil value :- ");
        int c;
        scanf("%d",&c);
        
        //Find ceil of c i.e. smallest value which is greater than or equal to c
        
        printf("Ceil of %d: ",c);
        
        struct Node *ceilroot = findceil(root,c);
        
        //If no ceil value is found then print -1 else print the ceil value
        
        if(ceilroot==NULL)
        {
          printf("-1\n");
        }
        else
          printf("%d\n",(ceilroot->key));
          
        printf("Print node to find its floor value :- ");
        
        int f;
        scanf("%d",&f);
        
        //Find floor of f i.e. largest value which is smaller than or eqaul to f
        
        printf("Floor of %d: ",f);
        
        struct Node *floorroot = findfloor(root,f);
        
        //If no floor value is found then print -1 else print the floor value 
        
        if(floorroot==NULL)
        {
          printf("-1\n");
        }
        else
          printf("%d\n",(floorroot->key));
        
        printf("Print node to delete :- ");
        
        int d;
        scanf("%d",&d);
        
        //Check whether node d is present in the tree or not
        
        //If it is present then delete it
        
        if(search(root,d)){
          root=delNode(root,d);
          printf("Deleted %d\n",d);
          
        }
        else
          printf("Node is not present in the tree\n");
          
        inorder(root);
        printf("\n");
        
        //Search node d in the tree after deleting it
        
        if(search(root,d))
         printf("Found %d\n",d);
        else
         printf("Not Found %d\n",d);
        
        printf("Print node to insert in the tree :- ");
        int i;
        scanf("%d",&i);
        
        //Insert node i in the tree 
          
        root=insert(root,i);
        printf("Inserted %d\n",i);
        
        inorder(root);
        printf("\n");
        
        //Check whether node i is present in the tree or not after insertion
        
        if(search(root,i))
          printf("Found %d\n",i);
        else
          printf("Not Found %d\n",i);
}
