/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u3a1_debugfixifstmts;

import java.util.Scanner;

/**
 *
 * @author omora
 */
public class U3A1_DebugFixIFStmts {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        System.out.println("Teacher's Copy");
                
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter three integers: ");
        int firstChoice = input.nextInt();
        int secondChoice = input.nextInt();
        int thirdChoice = input.nextInt();
    
        if (firstChoice == 0)
            System.out.println("State of choices: \n" +
                    "no choices made yet");
        else if (secondChoice == 0) // 1)change if to else if. 
            System.out.println("State of choices: \n" +
                    "user made first choice (" + firstChoice + ")\n" +
                    "number of choices = 1");
        else if (thirdChoice == 0) // 2) added another = for logical 'equal'
            System.out.println("State of choices: \n" +
                    "user made first choice (" + firstChoice + ")\n" +
                    "user made second choice (" + secondChoice + ")\n" +
                    "number of choices = 2");
        else // 3) if-else two way needs to end with an else statement. 
            System.out.println("State of choices: \n" +
                    "user made first choice (" + firstChoice + ")\n" +
                    "user made second choice (" + secondChoice + ")\n" +
                    "user made third choice (" + thirdChoice + ")\n" +
                    "number of choices = 3"); // 4) added a semi colon 
    
    }
}
