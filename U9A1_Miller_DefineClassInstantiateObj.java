public class U9A1_Miller_DefineClassInstantiateObj {

    public static void main(String[] args) {
        
        Course[] course = new Course[7];
        course[0] = new Course(1, "IT1006", 6);
        course[1] = new Course(2, "IT4782", 3);
        course[2] = new Course(3, "IT4789", 3);
        course[3] = new Course(4, "IT4079", 6);
        course[4] = new Course(5, "IT2230", 3);
        course[5] = new Course(6, "IT3345", 3);
        course[6] = new Course(7, "IT2249", 6);
        
        System.out.println("Miller's Copy");
        
        System.out.println("course Objects each has a code (e.g. IT 1006) "
                + "and credit hours (e.g. 6)");
        
        System.out.println("The number inside the [] is the display order number.");
        System.out.println("The number inside the () is the credit hours for the " +
                "course.\n");
        
 
        int itemNumber = 1; // item counter
        for (Course cs : course) {
               
        System.out.println( "[" + itemNumber++ + "] " + cs.getCode() + " (" +
                           cs.getcreditHours() + ")" );
        }
    }
    
}
