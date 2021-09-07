#include<stdio.h>
#include<stdlib.h>

// structure to make the Tree 
struct Node
{
  // key will store the data at each node
  int key;
  
  // left pointer is to go in the left subtree for each node 
  struct Node *left;
  
  //right pointer is to go in the right subtree for each node
  struct Node *right;
};

//Function to search node x in BST 
//Time complexity = O(N) , space Complexity = O(H)
int search(struct Node *root, int x){
    
    while(root!=NULL){
        
     // If the value at root is equal to x then it means x is present . So return 1 
     if(root->key==x)
      return 1;
      
     // Is the value at root is smaller than x then it means x is present in right subtree so traverse in right subtree
     
    else if(root->key<x)
      root=root->right;
      
      //If the value at root is greater than x then it means x is present in left subtree so traverse in the left subtree
      
    else
      root=root->left;
      
    }
    
    // If we did'nt find x throughout the loop then it means x is not present in the tree . So return 0
    
    return 0;
}

//Function to insert a new node x in BST
//Time Complexity = O(N) , Space Complexity = O(Height of tree)
struct Node *insert(struct Node *root, int x){
    
    struct Node *temp=malloc(sizeof(struct Node));
    temp->key=x;
    temp->left=NULL;
     temp->right=NULL;
    struct Node *parent=NULL,*curr=root;
    
    while(curr!=NULL){
        
      parent=curr;
      
      //If the current node is greater than x then it means we should insert in the left subtree
      
      if(curr->key>x)
       curr=curr->left;
       
       //If the current node is smaller than x then it means we should insert in the right subtree
       
      else if(curr->key<x)
       curr=curr->right;
       
       //If it is equal then return root as it is already present in the tree
       
      else
       return root;
       
    }
    
    //If parent is null then simply return x or temp as that will be the first node of the tree
    if(parent==NULL)
      return temp;
      
      // If the value at parent is greater than x then it means x will be inserted in the left of parent
      
    if(parent->key>x)
      parent->left=temp;
      
      // If the value at parent is smaller than x then it means x will be inserted in the right of parent
      
    else
      parent->right=temp;
      
    return root;
}

//Function to get successor that is the smallest value which is larger than curr
//Time Complexity = O(Height of tree)

struct Node *getSuccessor(struct Node *curr){
    
    //the successor is the leftmost node of the right subtree for a node curr
    
    //Go in the right subtree
    curr=curr->right;
    
    //find the leftmost node in it
    
    while(curr!=NULL && curr->left!=NULL)
     curr=curr->left;
      return curr;
}

//Function to delete the node from BST
//Time complexity = O(N) , space Complexity = O(H)
struct Node *delNode(struct Node *root, int x){
    
    //if root is NULL then return NULL
    
    if(root==NULL)
     return NULL;
     
     //If value at root is greater than x then it means that x must be in left subtree so do a recursive call in left subtree
     
    if(root->key>x)
     root->left=delNode(root->left,x);
     
     //If value at root is smaller than x then it means that x must be in right subtree so do a recursive call in right subtree
     
    else if(root->key<x)
     root->right=delNode(root->right,x);
     
     //If the value at root is equal to x then we will delete that node x from the tree
     
    else
    {
        
      // If left of root is NULL then simply delete that node and free the root and attach parent of root with root -> right so return root -> right
      
      if(root->left==NULL){
       struct Node *temp=root->right;
       free(root);
       return temp;
        }
        
      // If right is NULL then simply delete that node and free the root and attach parent of root with root -> left so return root -> left
      
      else if(root->right==NULL){
       struct Node *temp=root->left;
       free(root);
       return temp;
      }
      
      // If the node to be deleted has both the childs not NULL then replace that node with the nearest larger value from the tree
      //that is the successor of root node
      
      else{
         struct Node *succ=getSuccessor(root);
         
         //copy the value of successor of the root node to the root node 
         root->key=succ->key;
         
         //call delete function to delete the successor of the root node in the right subtree
         
         root->right=delNode(root->right,succ->key);
         
        }
    }
    return root;
}

//Function to find the floor value of element x in BST
//Time Complexity = O(N) , Space Complexity = O(H)
struct Node *findfloor(struct Node *root, int x){
    
    struct Node *ans = NULL;
    while(root!=NULL){
        
        //if the root value if equal to x then that will be the floor so return it
        
      if(root->key==x)
        return root;
        
        //if the root value if greater than x then do a recursive call in left subtree because we need a smaller value
        
      else if(root->key>x)
        root = root->left;
        
        //If the root value is smaller than x then that can be a floor value so store it and do a recursive call in right subtree because we could get a larger value lesser than or equal to x in it
        
      else{
        ans = root;
        root = root->right;
       }
    }
    return ans;
}

//Function to find ceil of the node x in BST
//Time Complexity = O(N) , Space Complexity = O(H)
struct Node *findceil(struct Node *root, int x){
    
     struct Node *ans=NULL;
    while(root!=NULL){
        
      //if value at root is equal to x then return root
        
      if(root->key==x)
       return root;
       
       //If it is smaller than x then do a recursive call at right subtree because we need a larger value than it 
       
      else if(root->key<x)
       root=root->right;
       
       //else store the answer of the current root because that may be the ceil value and do a recursive call in left subtree because we could a smaller value greater than or equal to x in that
       
      else{
       ans = root;
       root = root->left;
        }
    }
    
    //return the ceil value which is stored in ans
    
    return ans;
}

//Function to print inorder Traversal of the tree

void inorder(struct Node *root){
    
    //Inorder -> left root right
    
    if(root!=NULL){
      inorder(root->left);
      printf("%d ",root->key);
      inorder(root->right);
    }
}

//Function to take input of Tree
void takeinput(struct Node *root,int x)
{
  struct Node *temp=malloc(sizeof(struct Node));
  temp->key=x;
  temp->left=NULL;
  temp->right=NULL;
  
  //Function to insert x in BST
  
  insert(root,x);
}
