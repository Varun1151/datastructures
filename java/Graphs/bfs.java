import java.util.*;

class bfs
{
        static int visited[]=new int[20],queue[];
        static node g[]=new node[20];
        static int n;
        static Scanner sc=new Scanner(System.in);
        static int typeofgraph;
        static void insert(int vi,int vj)
        {
                node temp,trav;
                temp=new node();
                temp.vertex=vj;
                temp.link=null;
                if(g[vi]==null)
                {
                        g[vi]=temp;
                }
                else
                {
                        for(trav=g[vi];trav.link!=null;trav=trav.link);
                        trav.link=temp;
                }
        }
        static void showlist(){
            for(int i=0;i<20;i++){
                if(g[i]!=null){
                    System.out.print(i+"-->");
                    node temp=g[i];
                    while(temp.link!=null){
                        System.out.print(temp.vertex+"-->");
                        temp=temp.link;
                    }
                    System.out.println(temp.vertex);
                }
            }
        }
        static void creategraph()
        {
                int i,vi,vj,vw,n;
                System.out.println("Enter type of graph\n1)Directed graph\n2)Undirected Graph");
                typeofgraph=sc.nextInt();
                if(typeofgraph!=1&&typeofgraph!=2){
                	System.exit(0);
                }
                System.out.println("\nEnter number of vertices: ");
                n=sc.nextInt();
                queue=new int[n];//Allocating memory for queue
                for(i=0;i<n;i++)
                {
                        g[i]=null;
                }
                System.out.println("Enter Number of edges: ");
                n=sc.nextInt();
                System.out.println("Enter edges in numerical or alphabetical order of vertices and one edge only once");
                System.out.println("Enter list of edges (a,b): ");
                for(i=0;i<n;i++)
                {
                        
                        vi=sc.nextInt();
                        vj=sc.nextInt();
                        if(typeofgraph==1){
                        	insert(vi,vj);
                        }
                        else{
                        	insert(vi,vj);
                        	insert(vj,vi);
                        }
                }
        }
        static void bfsorder(int v)
        {
                node t;
                int r=0,f=0;//Rear and front of queue
                System.out.print(v+"\t");
                visited[v]=1;
                queue[r++]=v;
                while(r!=f)//while queue is not empty
                {
                    v=queue[f++];
                    for(t=g[v];t!=null;t=t.link)
                    {   
                        if(visited[t.vertex]==0)//if vertex is not visited
                        {
                                visited[t.vertex]=1;
                                queue[r++]=t.vertex;
                                System.out.print(t.vertex+"\t");       
                        }
                    }
                }
        }
        public static void main(String args[])
        {
                int i;
                creategraph();
                System.out.println("\nAdjacency list\n");
                showlist();
                System.out.print("\nEnter Source vertex");
                bfsorder(sc.nextInt());
                System.out.println();

        }

}