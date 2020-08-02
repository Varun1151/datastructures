//DFS (deph first search) for a binary tree

#include<stdio.h>
#include<stdlib.h>


struct node{
  int vertex;
  struct node*link;
};
typedef struct node *ptr;
//array of 20 node pointers
ptr graph[20]={NULL};

//to distinguish between visited and unvisited nodes
int visited[20]={0};

//performing dfs
void dfs(int v){
  ptr w;
  //to note that the entered vertex has now been visited
  visited[v]=1;
  printf(" %d",v);
  // searching for unvisited nodes among adjacent vertices of that node
  for(w=graph[v];w;w=w->link){
    if(!(visited[w->vertex]))
    dfs(w->vertex);
  }
}

void main(){
  printf("Enter no. of vertices\n");
  int n,k,i;
  ptr t;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
	printf("Enter adjacent vertices of %d th node in parent first child next order,Enter -999 to stop\n",i+1);
    scanf("%d",&k);
    while(k!=-999)
    {
    ptr tmp=(ptr)malloc(sizeof(struct node));
    tmp->vertex=k;
    tmp->link=NULL;
      //if it is the first adjacent node being inserted
    if(!graph[i])
    graph[i]=tmp;
    //for 2nd node onwards
    else
	{
        t=graph[i];
        while(t->link!=NULL)
        t=t->link;
        t->link=tmp;
    }
      scanf("%d",&k);
    }
  }

  printf("Print vertex from which to perform dfs ");
  scanf("%d",&k);
  dfs(k);
  printf("\n");
}
