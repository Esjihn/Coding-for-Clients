
public class U1A1_Miller_InheritOverridetoString {

    public static void main(String[] args) {
        
        /** Per course instruction: the application instantiates three objects
         * from the Course, FlexPathCourse, and GuidedPathCourse and invokes
         * their corresponding toString() methods.
         */
        Course c1 = new Course("TBD", 3, "TBD");
        GuidedPathCourse GPC1 = new GuidedPathCourse("IT2230", 3, "Introduction" +
                " to Database Systems");
        FlexPathCourse FPC1 = new FlexPathCourse("ITFP4789", 3, "Mobile Cloud" +
                " Computing Application Development");
        
        // Title of my program
        System.out.println("Miller's Copy");
        
        // Console print by invoking corresponding toString methods.
        System.out.printf(
                "Java class name = 'Course' Course Code = %s\n",
                (c1).toString());
        System.out.printf(
                "Java class name = 'GuidedPathCourse' Course Code = " +
                "%s\n",
                (GPC1).toString());
        System.out.printf(
                "Java class name = 'FlexPathCourse' Course Code = " +
                "%s\n",
                (FPC1).toString());
    }
} 
