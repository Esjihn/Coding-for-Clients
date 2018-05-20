
public class FlexPathCourse extends Course {
    
    /* optionalResources attribute - a string field for the optional resources
    *  for a flexpath course.
    */
    protected String optionalResources;
    /* Parameterized constructor with the three parameters of code, creditHours
    *  and title. The constructor simple assigns the received values to their
    *  corresponding attributes.
    */
    FlexPathCourse(String c, int cH, String t) {
        super(c, cH, t);
    }
    /* An overridden toString() method that returns the name of the Java class
    *  (i.e. FlexPathCourse) and the course code assigned to the class object.
    */
    public String toString() {
        return String.format(getCode());
    }
}

