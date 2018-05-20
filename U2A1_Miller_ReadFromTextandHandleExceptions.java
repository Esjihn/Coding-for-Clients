import java.util.Scanner;
import java.io.FileNotFoundException;


public class U2A1_Miller_ReadFromTextandHandleExceptions {
    public static void main(String args[]) {
		
	// Program distinction console print.
	System.out.println("Miller's Copy");
		
        // "courses.txt" contains information that describes three courses.
        String fn = "courses.txt";

        // syntax for selection which file to read. 
        java.io.File file = new java.io.File("courses.txt");
        
        // try/catch to watch for FileNotFoundException
        try {
            // Introduce Scanner to scan the file assigned above. 
            Scanner input = new Scanner(file); 
            /** Input delimiter to specify boundaries between separate
             *  independent regions in plain text.
             */
            input.useDelimiter(" ");
            
            /* while loop with hasNext() which returns true if scanner has
            *  another token in its input.
            */
            while (input.hasNext()) {
                // String assignments 
                String courseCode = input.next();
                String creditHours = input.next();
                // nextLine here prevents Course title from being split
                String courseTitle = input.nextLine();
                                                 
                System.out.println("Course Code = " + courseCode + " | Credit hours = " + 
                        creditHours + " | Course title =" +
                        courseTitle);    
            }
            
            // Close program after reading file is complete.
            input.close();
            // catch FileNotFoundExceptions.
        } catch(FileNotFoundException ex) {
            System.out.println(
                "This file isn't found:  '" + 
                fn + "'");   
        /** Compiler stated this secondary catch was unnecessary
         *  IOExceptions can only be caught if the compiler predicts
         *  there might be something in the code that throws an IOException
         *  Here, there is none. 
         */    
        //} catch(IOException ex) {
            //System.out.println(
                //"Error reading file '" 
                //+ fn + "'");                  
        }
    }
}

