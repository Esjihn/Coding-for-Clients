
import java.util.Scanner;
public class U7A1_Miller_NumOfOccurrInSevenInts {
    public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int [] num = new int[7]; // number of int for the total stored numbers in array
    
    int [] count = new int[100]; // max value int for numbers entered
    
   
    int i, temp = 0;
    // assigning int 1 for later use. temp isn't called on until the program runs
    
    System.out.println("Millers's Copy");
    System.out.println("Enter seven numbers: ");
    // Console print out
    
    // Array created with user input
    for(i=0; i < num.length; i++){
        num[i] = input.nextInt();
        // 55 is the last number the user enters which ends the loop
        if(num[i] == 55){
            break;
        }
    }

   
    for(i = 0; i < num.length; i++){
            temp = num[i];
            count[temp]++;
        }// this loops keeps track of the number of times its counted in the array

    for(i=1; i < count.length; i++){

        if(count[i] > 0 && count[i] == 1){
            System.out.print("Number " + i + " occurs "+ count[i] +" time\n");
         }
        else if(count[i] >=2){
            System.out.print("Number " + i + " occurs "+ count[i] +" time's\n");
        }
        /* Console output to user based on the how many times each number
        is counted in the array with proper punctuation
        */

     }
}
}