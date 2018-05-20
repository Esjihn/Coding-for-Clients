
public class Course {
    
    // code attribute - a string field to store the course code (e.g. IT4789)
    private String code;
    /* creditHours attribute - an int field to store the credit hours of the
     * course (e.g. 3) 
     */
    private int creditHours;
    /* title attribute - a string field to store the title of the course
     * (e.g. Mobile Cloud Computing Application Development) 
     */
    private String title;
    /* Parameterized constructor with the three parameters of code,
     * creditHours, and title. The constructor simply assigns the received
     * values to their corresponding attributes. 
     */
    Course(String c, int cH, String t) {
        code = c;
        creditHours = cH;
        title = t; 
    }
    
    /* And overridden toString() method that returns the name of the 
     * Java class (i.e. Course) and the course code assigned to the 
     * class object. 
     */
    public String toString() {
        return String.format(getCode());
    } 

    /**
     * @return the code
     */
    public String getCode() {
        return code;
    }

    /**
     * @param code the code to set
     */
    public void setCode(String code) {
        this.code = code;
    }

    /**
     * @return the creditHours
     */
    public int getCreditHours() {
        return creditHours;
    }

    /**
     * @param creditHours the creditHours to set
     */
    public void setCreditHours(int creditHours) {
        this.creditHours = creditHours;
    }

    /**
     * @return the title
     */
    public String getTitle() {
        return title;
    }

    /**
     * @param title the title to set
     */
    public void setTitle(String title) {
        this.title = title;
    }
}
