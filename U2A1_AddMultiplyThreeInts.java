import java.util.Scanner;

public class U2A1_AddMultiplyThreeInts {

    
    public static void main(String[] args) {
        
        //Create a Scanner
        Scanner input = new Scanner(System.in);
        
        //Enter the first integer add semicolon
        System.out.print("Enter the first integer: ");
        int firstinteger = input.nextInt();
        
        //Enter the second integer add semicolon
        System.out.print("Enter the second integer: ");
        int secondinteger = input.nextInt();
                
        //Enter the third integer add semicolon
        System.out.print("Enter the third integer: ");
        int thirdinteger = input.nextInt();
               
        //Calculate integers sum and product totals
        int add, multi;
        add=firstinteger+secondinteger+thirdinteger;
        multi=firstinteger*secondinteger*thirdinteger;
        
                
        //Print out "The sum of three integers then =
        System.out.println("The sum of three integers = "+add);
        
        
        //Print out "The product of three integers then = 
        System.out.println("The product of three integers = "+multi);
        
     
    }        
      
}