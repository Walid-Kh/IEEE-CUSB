<h1 align = "center"> Trees part I </h1>
<h2 align = "center"> Introduction </h2> 
heard of trees?, trees have a unique structure of root and branches, and trees in data structure have the same structure as well, the only weird thing about trees in data structures is we somehow had the ingenious idea of representing them upside down.
<h2 align = "center">Some Terminology</h2>
This is a Tree

![Tree.png](pictures/Tree.png)

<h3 align = "center">The difference between trees and linked lists</h3>

As you can see a tree is composed of nodes each of these nodes has a value and pointer/s pointing to another node/s, and we have seen this kind of data structure before mainly in linked lists, but trees differ from linked list because tree represent a hierarchical structures and linked lists represent a linear structure.

![Singly-Linked-List1.png](pictures/Singly-Linked-List1.png)

now to a really boring but important part Terminology
1. Parents : straightforward any node with children, examples of parents in the above tree include {20,30,16,12}
2. The root : the upward most node 
3. Children : any node with a parent this includes every node except the parent
4. Sibling : Nodes with the same parent, an example 20 {30,20(root)}
5. Ancestors : the parents and parent's parent upward to the root
6. Depth : how many nodes have you traveled to get to this node for example I traveled two nodes to get to 90, and 1 to get to 13 and 0 to get the root since I was already at the root
7. Height : the height of 16 is 2 since there is at most two point downward I can travel to
8. Edges : number of pointers currently pointing to existing node and this is a constant = No. of nodes - 1

<h2 align = "center">Types of Trees</h2>
There are several kind of trees each having a different purpose. but in this course we are going to focus on

1. Binary Search Trees
2. AVL Trees
3. N-ary Trees // for an assignment



<h3 align = "center"> Binary Search Trees </h3> 
This kind of tree implies the number two, each node is at most connect to two other nodes, and it follows a rule which is that each node is smaller than every other node on its right and bigger than every other node on its left, this rule makes binary search possible and makes insertion, deletion and getting the successor or the predecessor extremely fast, and to show this let's compare this data structure with array, sorted array, and linked lists. 
<br></br>

|     OP/DS     |  Array   |   sorted Array    | linked list | Binary Search Trees |
|:-------------:|:--------:|:-----------------:|:-----------:|:-------------------:|
| **Searching** | **O(N)** | **O($log(n)$)** |  **O(N)**   | **O($log_2(n)$)\*** |
|  **Adding**   | **O(1)** |     **O(N)**      |  **O(1)**   | **$O(log_2(n))$\*** |
| **Deleting**  | **O(1)** |     **O(N)**      |  **O(1)**   |     **O(H)\****     |  

\* If the tree has a degenerate form then the Big O Notation for every operation is **O(N)**
\** H is the height of the tree 
<br></br>
A binary search Tree can have way more items in the on one side than the other, which make insertion, deletion, and search take way more time, because of this fact we need arose for a balanced tree Where $H(leftSubTree) - H(rightSubTree) \leq 1$  and that this condition is call the balance factor, and A balanced Binary search tree can be called an AVL Tree.
<h2 align = "center"> Shapes of Binary Trees </h2>
To further understand binary trees, we must know their shapes.

 1.	A complete binary tree
	for a binary tree to be complete it must satisfy two conditions 
	- every level is filled except for the last one
	- the nodes on the last level must be located on left most position

 2. A perfect binary tree 
	only one condition 
	- all level must be filled, which means that the No. of Nodes in the shape is $2^N -1$

 3. A full binary tree 
	Only one condition 
	- All nodes must have either no children or two children

 4. A degenerate binary tree 
	- basically a linked list 
	
 <h2 align = "center">Binary search tree Traversal</h2>
 There are two major ways to Traverse a Binary 
 <h3 >Depth-first traversal</h3>
 There can be three way of doing such traversal.
taking this tree as an example

 ![binary-search-tree.png](pictures/binary-search-tree.png)

1. Pre-Order traversal, the order in which this traversal goes is
 root -> left -> node
 the output such traversal is {30,20,16,25,40,35,32,38,50}
 2. In-Order traversal, the order in which this traversal goes is 
left -> root -> node
the output is {16,25,30,32,35,38,40,50} as you can see this is sorted order
this traversal can also be used to represent arithmetic operation 
3. Post-Order traversal, the order in which this traversal goes is 
Left → right → node and the output is {16,25,20,30,32,38,35,40,50} 


 <h3 >Breadth-first Traversal</h3>
 There can be three way of doing such traversal.
 This kind of traversal utilizes a queue, in which the root is first enqueued then we enter a while loop that doesn't stop till the queue is empty, in that while loop we pop a node from the queue and then enqueue its children, this then the desired operation is done then the iteration is finished.
 
 
 <h2 align = "center">Thank you</h2>
