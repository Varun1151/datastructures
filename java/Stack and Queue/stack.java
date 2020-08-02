import java.util.*;

public class stack{
	static int top=-1,stac[]=new int[20];
	static void push(int x){
		stac[++top]=x;
	}
	static int pop(){
		return stac[top--];
	}
	static void display(){
		int temp=top;
		for(;temp>0;temp--){
			System.out.print(stac[temp]+"\t");
		}
		System.out.print(stac[temp]+"\n");
	}
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		while(true){
			System.out.println("\n1)PUSH\t2)POP\t3)DISPLAY\t4)EXIT");
			switch(in.nextInt()){
				case 1:	System.out.print("\nEnter element : ");
						push(in.nextInt());
						break;

				case 2:	if(top==-1){
							System.out.println("\nNo elements");
						}
						else{
							System.out.println("\nDeleted element = "+pop());
						}
						break;

				case 3: if(top==-1){
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