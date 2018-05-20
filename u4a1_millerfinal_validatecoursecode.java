import java.util.Scanner;
public class u4a1_millerfinal_validatecoursecode {

   
    public static void main(String[] args) {
        
        
        Scanner input = new Scanner(System.in); //Scanner for input
        String code; // code is a string literal
        boolean valid = true; //boolean valid statement to for code efficiency
        String message = ""; //String messages defined
        
        System.out.print("Enter a course code to validate (e.g. IT 4782): ");
        // First message to use to begin input
        code = input.nextLine();
        
        if (code.length() == 6){
            if (Character.toUpperCase(code.charAt(0)) != 'I') {
                valid = false;
                message += "First character is not an I or a i. \n";
            }
            if (Character.toUpperCase(code.charAt(1)) != 'T') {
                valid = false;
                message += "Second character is not a T or a t. \n";
            }
            if (!Character.isDigit(code.charAt(2))) {
                valid = false;
                message += "Third character is not a digit. \n";
            }
            if (!Character.isDigit(code.charAt(3))) {
                valid = false;
                message += "Fourth character is not a digit. \n";
            }
            if (!Character.isDigit(code.charAt(4))) {
                valid = false;
                message += "Fifth character is not a digit. \n";   
            }
            if (!Character.isDigit(code.charAt(5))) {
                valid = false;
                message += "Sixth chracter is not a digit. \n";    
            } // Program for data crunching user input
        }
        else {
            valid = false;
            message = code + "Insufficient information, error in input. ";
        } /* Message for user error in input which helps speed up process to 
        get user to quickly enter a valid statement
        */
        if (valid) {
            System.out.print(code + " is a valid course code. \n");
        }    // valid course code print out final
        else
            System.out.println(code + " is not a valid course code. \n");
        System.out.print(message);
        }        // invalid course code print out final 
        
     
} //end of code 
    

