#include<stdio.h>
#include<stdlib.h>

struct node{
  int vertex;
  struct node* link;
};
typedef struct node *ptr;
ptr graph[20]={NULL};
int visited[20]={0};
int queue[20],front=0,rear=0;
void addq(int k)
{
	queue[rear++]=k;
}

int deleteq()
{
  return queue[front++];
}

int queueempty()
{
	if(front==rear)
		return 1;
	return 0;
}

void bfs(int v){
  ptr w;
  printf(" %d",v);
  visited[v]=1;
  addq(v);
  while(!queueempty()){
    v=deleteq();
    for(w=graph[v];w;w=w->link){
      if(!visited[w->vertex]){
        printf(" %d",w->vertex);
        addq(w->vertex);
        visited[w->vertex]=1;
      }
    }
  }
}

void main(){
  printf("Enter no. of vertices\n");
  int i,n,k;
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
      else{
        t=graph[i];
        while(t->link!=NULL)
        t=t->link;
        t->link=tmp;
      }
      scanf("%d",&k);
    }
  }

  printf("Print vertex(index) from which to perform bfs ");
  scanf("%d",&k);
  bfs(k);
  printf("\n");
}
