/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package u10a1_ooconsoleregisterforcourse;

/**
 *
 * @author omora
 */
public class Course {

    private String code = "";
    private int creditHour = 0;
    private boolean isRegisterdFor = false;
    
    public Course(String code, int creditHour){
        this.code = code;
        this.creditHour = creditHour;
    }
    
    public void setCode(String code){
        this.code = code;
    }
    
    public String getCode() {
        return this.code;
    }
    
    public void setCrditHour(int creditHour) {
        this.creditHour = creditHour;
    }
    
    public int getCreditHour() {
        return this.creditHour;
    }    
    
    public void setIsRegisteredFor(boolean trueOrFalse){
        this.isRegisterdFor = trueOrFalse;
    }
    
    public boolean getIsRegisteredFor() {
        return this.isRegisterdFor;
    }
        
}

