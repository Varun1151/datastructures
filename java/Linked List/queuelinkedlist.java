import java.util.*;
class node{
	int vertex;
	node link;
}
public class queuelinkedlist{
	static node front=null,rear=null;
	static void insert(int x){
		node temp=new node();
		temp.vertex=x;
		temp.link=null;
		if(rear!=null){
			rear.link=temp;
		}
		rear=temp;
		if(front==null){
			front=temp;
		}
	}
	static int delete(){
		node temp=front;
		int k =  temp.vertex;
		front = temp.link;
		return k;
	}
	static void display(){
		node temp=front;
		for(;temp.link!=null;temp=temp.link){
			System.out.print(temp.vertex+"\t");
		}
		System.out.print(temp.vertex+"\n");
	}
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		while(true){
			System.out.println("\n1)INSERT\t2)DELETE\t3)DISPLAY\t4)EXIT");
			switch(in.nextInt()){
				case 1:	System.out.print("\nEnter element : ");
						insert(in.nextInt());
						break;

				case 2:	if(front==null){
							System.out.println("\nNo elements");
						}
						else{
							System.out.println("\nDeleted element = "+delete());
						}
						break;

				case 3: if(front==null){
							System.out.println("\nNo elements");
						}
						else{
							System.out.print("\nElements are : ");
							display();
						}
						break;

				case 4: System.exit(0);
						break;
			}
		}
	}
}