#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*lchild;
	struct node*rchild;
};
typedef struct node *treeptr;
void insert(treeptr *root,int d)
{
	if((*root)==NULL)
	{
		*root=(treeptr)malloc(sizeof(struct node));
		(*root)->data=d;
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;
		return;
	}
	else if(d>((*root)->data))
	{
		insert(&((*root)->rchild),d);
	}
	else if(d<((*root)->data))
	{
		insert(&((*root)->lchild),d);
	}
	
}
void inorder(treeptr ptr)
{
	if(ptr)
	{
		inorder(ptr->lchild);
		printf("%d\t",ptr->data);
	    inorder(ptr->rchild);
	}
}
void preorder(treeptr ptr)
{
	if(ptr)
	{
		printf("%d\t",ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void postorder(treeptr ptr)
{
	if(ptr)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d\t",ptr->data);
	}
}
int search(treeptr root,int d)
{
	if(root==NULL)
	return 0;
	else if(root->data==d)
	{
	return 1;
	}
	else if(d>((root)->data))
	{
		return search((root)->rchild,d);
	}
	else if(d<((root)->data))
	{
		return search(((root)->lchild),d);
	}
}

void main()
{
	treeptr root;
	root=NULL;
	int ch,data,f;
	while(1)
	{
		printf("\n1)Insert\t2)In Order Traversal\t3)Pre Order Traversal\t4)post Order Traversal\t5)Search\t6)Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter data to be inserted : ");
			scanf("%d",&data); 
			insert(&root,data);
			break;
        case 2:
			inorder(root);
			printf("\n");
			break;
		case 3:
			preorder(root);
			printf("\n");
			break;
		case 4:
			postorder(root);
			printf("\n");
			break;
		case 5:printf("Enter element to be searched in the tree\n");
				scanf("%d",&data);
				f=search(root,data);
				if(f==1)
					printf("Element found\n");
				else
					printf("Element not found\n");
				break;
		case 6:exit(0);
		
		default:printf("Invalid choice\n");
		}
	}
}
		
