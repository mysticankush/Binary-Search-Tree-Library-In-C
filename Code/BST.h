struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
};

//Declaration of all the functions used in BST.c file

int search(struct Node *, int);
struct Node *insert(struct Node *, int);
struct Node *getSuccessor(struct Node *);
struct Node *delNode(struct Node *, int);
struct Node *findfloor(struct Node *, int);
struct Node *findceil(struct Node *, int);
void inorder(struct Node *);
void takeinput(struct Node *,int);

