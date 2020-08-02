import java.util.*;

public class queue{
	static int front=0,rear=0,qu[]=new int[20];
	static void insert(int x){
		qu[rear++]=x;
	}
	static int delete(){
		return qu[front++];
	}
	static void display(){
		int temp=front;
		for(;temp!=rear-1;temp++){
			System.out.print(qu[temp]+"\t");
		}
		System.out.print(qu[temp]+"\n");
	}
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		while(true){
			System.out.println("\n1)INSERT\t2)DELETE\t3)DISPLAY\t4)EXIT");
			switch(in.nextInt()){
				case 1:	System.out.print("\nEnter element : ");
						insert(in.nextInt());
						break;

				case 2:	if(front==rear){
							System.out.println("\nNo elements");
						}
						else{
							System.out.println("\nDeleted element = "+delete());
						}
						break;

				case 3: if(front==rear){
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