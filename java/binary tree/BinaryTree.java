import java.util.Scanner;
class BinaryTree 
{ 
    // Root of Binary Tree 
    Node root; 
    BinaryTree(int key) 
    { 
        root = new Node(key); 
    } 
  
    BinaryTree() 
    { 
        root = null; 
    } 
    
     /* Given a binary tree, print its nodes according to the 
      "bottom-up" postorder traversal. */
    void printPostorder(Node node) 
    { 
        if (node == null) 
            return; 
  
        printPostorder(node.left); 
        printPostorder(node.right); 
        System.out.print(node.key + " "); 
    } 
  
    /* Given a binary tree, print its nodes in inorder*/
    void printInorder(Node node) 
    { 
        if (node == null) 
            return; 
  
        printInorder(node.left); 
        System.out.print(node.key + " "); 
        printInorder(node.right); 
    } 
  
    /* Given a binary tree, print its nodes in preorder*/
    void printPreorder(Node node) 
    { 
        if (node == null) 
            return; 
  
        System.out.print(node.key + " "); 
        printPreorder(node.left); 
        printPreorder(node.right); 
    } 
    public static void main(String[] args) 
    { 
        Scanner in = new Scanner(System.in);
        BinaryTree tree = new BinaryTree(); 
        tree.root = new Node(1); 
        tree.root.left = new Node(2); 
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4); 
        System.out.println("\n1)Inorder\n2)Preorder\n3)Postorder");
        switch(in.nextInt()){
          case 1:
            tree.printInorder(tree.root);break;
          case 2:
            tree.printPreorder(tree.root);break;
          case 3:
            tree.printPostorder(tree.root);break;
          default:
            System.out.println("Wrong Choice");
        }
        System.out.println();
    } 
} 