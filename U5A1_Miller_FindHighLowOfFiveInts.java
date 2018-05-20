/*
    Design and code a Java console application that
    takes five integer values and produces as output
    the lowest and highest values of these five integer
    values

    3 56 89 602 1 
*/
import java.util.Scanner;
public class U5A1_Miller_FindHighLowOfFiveInts {
    public static void main(String[] args) {
        
        int highest = Integer.MIN_VALUE;
        int lowest = Integer.MAX_VALUE;
        
        
        Scanner input = new Scanner(System.in);
            
            System.out.println("Miller's Copy");
        
            System.out.print("Enter five integers: ");
           
                       
            for(int i = 0; i < 5; i++) {
                int num = input.nextInt();
                if(num > highest) {
                    highest = num;   
                }
                
                if(num < lowest) {
                    lowest = num; 
                }
            }  
            System.out.println("Highest integer is: " + highest);
            System.out.println("Lowest integer is: " + lowest); 
    }
    
}
