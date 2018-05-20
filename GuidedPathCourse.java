
public class GuidedPathCourse extends Course {
    
    /* duration attribute - and int field for the duration of the guidedpath
    *  course.
    */
    protected int duration;
    /* requiredResources attribute - an string field for the required resources
    *  for a guidedpath course.
    */
    protected String requiredResources;
    /* Parameterized constructor with the three parameters of code, creditHours
    *  and title. The constructor simple assigns the received values to their
    *  corresponding attributes.
    */
    GuidedPathCourse(String c, int cH, String t) {
        super(c, cH, t);
    }
    /* An overridden toString() method that returns the name of the Java class
    * (i.e. GuidedPathCourse) and the course code assignment to the class object
    */
    public String toString() {
        return String.format(getCode());
    }
}
