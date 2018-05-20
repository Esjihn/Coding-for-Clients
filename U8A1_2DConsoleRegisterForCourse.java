/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u8a1_2dconsoleregisterforcourse;

import java.util.Scanner;

/**
 *
 * @author omora
 */
public class U8A1_2DConsoleRegisterForCourse {

    /**
     * @param args the command line arguments1
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        System.out.println("Miller's Copy");
                
        Scanner input = new Scanner(System.in);
        
        // courses 2d array hold course code and their credit hours
        String[][] courses = {
            {"IT1006", "IT4782", "IT4789", "IT4079", "IT2230", "IT3345", "IT2249"},
            {"6", "3", "3", "6", "3", "3", "6"}
        };
        
        // validChoices 2d array holds valid number choices (as strings) selected by user
        // and their corresponding courses
        //e.g  String[][] choices = { {"5", "IT2230"}, {"1", "IT1006"}, {"6", "IT3345"} };
        String[][] validChoices = {
            {"", ""},
            {"", ""},
            {"", ""}
        };
        
        int choice;
        int totalCredit = 0;
        String yesOrNo = "";

        
        do {

            choice = getChoice(courses, input);
            
            switch (ValidateChoice(choice, validChoices, totalCredit, courses)) {
                case -1:
                    System.out.println("**Invalid** - Your selection of " + 
                            choice + " is not a recognized course.");
                    break;
                case -2:
                    System.out.println("**Invalid** - You have already registered for this " +
                            courses[0][choice-1] + " course.");
                    break;
                case -3:
                    System.out.println("**Invalid** - You can not register for more than 9 credit hours.");
                    break;
                case 0:
                    System.out.println("Registration Confirmed for course " +
                            courses[0][choice-1] );
                    totalCredit += Integer.parseInt(courses[1][choice-1]);
                    if (validChoices[0][0].equals("")) {
                            validChoices[0][0] = Integer.toString(choice);
                            validChoices[0][1] = courses[0][choice-1];
                    } else if (validChoices[1][0].equals("")) {
                        validChoices[1][0] = Integer.toString(choice);
                        validChoices[1][1] = courses[0][choice-1]; 
                    } else if (validChoices[2][0].equals("")) {
                        validChoices[2][0] = Integer.toString(choice);
                        validChoices[2][1] = courses[0][choice-1];            
                    }
                    break;
            }

            WriteCurrentRegistration(validChoices, totalCredit);
            
            System.out.print("\nDo you want to try again? (Y|N)? : ");
            
            yesOrNo = input.next().toUpperCase();
            
        } while (yesOrNo.equals("Y"));

        System.out.println("Thank you for registering with us");
        
    }

    //This method prints out the selection menu to the user in the form of
    //[selection number]Course Code (Course Credit Hours)
    //from the courses array one per line 
    //and then prompts the use to make a number selection
    public static int getChoice(String[][] courses, Scanner input) {
        /*followed getChoice from the courses do while statement
        down to the getChoice method and added the second array
        */
        System.out.println("Please type the number inside the [] to register for a course");
        System.out.println("The number inside the () is the credit hours for the course");
        for(int i = 0; i < courses[0].length; i++ ) 
            System.out.println("[" + (i+1) + "]" + courses[0][i] + "(" + courses[1][i] + ")");
        System.out.print("Enter your choice : ");
        return (input.nextInt());
    }

    
 
    //This method validates the user menu selection
    //against the given registration business rules
    //it returns the following code based on the validation result
    // -1 = invalid, unrecognized menu selection
    // -2 = invalid, alredy registered for the course
    // -3 = invalid, No more than 9 credit hours allowed
    // 0 = menu selection is valid
    public static int ValidateChoice(int choice, String[][] validChoices, int totalCredit, String[][] courses) {
        String choiceAsString = Integer.toString(choice);
        if (choice < 1 || choice > 7)
            return -1;
        else if (choiceAsString.equals(validChoices[0][0])
                || choiceAsString.equals(validChoices[1][0]) 
                /* added the correct array [1][0] which enables the array to search
                duplicate entry course choices. 
                */
                || choiceAsString.equals(validChoices[2][0])) 
            return -2;
        else if ( totalCredit + Integer.parseInt(courses[1][choice-1]) > 9)
            return -3;
        return 0;
    }
    
    
    //This method prints the current list of registered courses thus far
    //from the courses array separated by , and enclosed inside { }
    //It also prints the total credit registered for thus far
    public static void WriteCurrentRegistration(String[][] validChoices, int totalCredit) {

        if (validChoices[0][0].equals(""))
            System.out.println("Current course registration:  { none } " );     
        else if (validChoices[1][0].equals(""))
            System.out.println("Current course registration: { " + validChoices[0][1] + " }" );
        // changed to array to [0][1]
        else if (validChoices[2][0].equals(""))
            System.out.println("Current course registration: { " + validChoices[0][1] + 
                    ", " + validChoices[1][1] + " }");
        else
            System.out.println("Current course registration: { " + validChoices[0][1] + 
                    ", " + validChoices[1][1] + ", " + validChoices[2][1] + " }");
        System.out.println("Current registration total credit = " + totalCredit);
    }
    
}
