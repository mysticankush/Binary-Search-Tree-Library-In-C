# Library for Binary Search Tree (BST)
## The goal of Binary Search Tree is to Implement :-
- Inserting a new element in a BST
- Deleting an element in BST
- Search an element in BST
- Finding Floor of an element x in BST i.e. Greatest value which is smaller than or equal to x
- Finding Ceil of an element x in BST i.e. Smallest value which is greater than or equal to x 
## Description
### What is Binary Search Tree?
It is a data structure in which left subtree of a node contains only nodes with keys lesser than the node's key
and right subtree of a node contains only nodes with keys greater than the node's keys and both left and right subtree should also be a Binary Search Tree
### Sample Binary Search Tree :-
![Sample BST](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
## Applications :
 - It is used to maintain the sorted stream of data
 - It is used to implement Doubly Ended Priority Queue
 - It is used to count smaller or greater elements of some elements in a stream
 - It is used to find Floor , Ceil , Greater , Smaller value of some element in a stream
 ##  Designs and Specifications :- 
 ### The Project contains two files :-
- One is "BST.h" which contains implementation of the data structure Binary Search Tree .
- The other is "main.c" file which contains driver function to use "BST.h" . "#include BST.h" is used to use BST data structure in "main.c".
#### About BST.h file
In this file , all the functions like Insert an element , Delete an element , Search an element , find floor of an element , find ceil of an element are created
| Function Name | Description |
| :--: | :-- |
|insert() | It inserts an  element in BST such that BST is balanced after insertion|
|delete() | It deletes an element in BST such that BST is balanced after deletion|
|search(x) | It searches an element x in BST and return true if present else return false|
|floor(x) | It finds the floor of element x in BST|
|ceil(x) | It finds the ceil of element x in BST|
