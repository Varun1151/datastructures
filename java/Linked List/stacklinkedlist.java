import java.util.*;
class node{
	int vertex;
	node link;
}
public class stacklinkedlist{
	static node top=null;
	static void push(int x){
		node temp=new node();
		temp.vertex=x;
		temp.link=top;
		top=temp;
	}
	static int pop(){
		node temp=top;
		int k =  temp.vertex;
		top = temp.link;
		return k;
	}
	static void display(){
		node temp=top;
		for(;temp.link!=null;temp=temp.link){
			System.out.print(temp.vertex+"\t");
		}
		System.out.print(temp.vertex+"\n");
	}
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		while(true){
			System.out.println("\n1)PUSH\t2)POP\t3)DISPLAY\t4)EXIT");
			switch(in.nextInt()){
				case 1:	System.out.print("\nEnter element : ");
						push(in.nextInt());
						break;

				case 2:	if(top==null){
							System.out.println("\nNo elements");
						}
						else{
							System.out.println("\nDeleted element = "+pop());
						}
						break;

				case 3: if(top==null){
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