package model;

import java.util.Calendar;

public class Notebook implements Date {
    private String fullname;
    private String phone;
    private java.util.Date date;

    public Notebook(){}

    public Notebook(String fullname, String phone, java.util.Date date){
        //this.fullname = fullname;
        setFullname(fullname);
        //this.phone = phone;
        setPhone(phone);
        //this.date = date;
        setDate(date);
    }

    @CustomAnnotation
    public String getFullname(){
        return fullname;
    }

    public void setFullname(String fullname){
        //String REGEX = "([a-zA-Zа-яА-Я ])+";
        if (fullname != null && !fullname.matches("([a-zA-Zа-яА-Я ])+")){
            throw new IllegalArgumentException("Illegal symbols in string: '" + fullname + "'");
        }
        this.fullname = fullname;
    }

    public String getPhone(){
        return phone;
    }

    public void setPhone(String phone){
        //String REGEX_PHONE = "\\+[0-9]{12}";
        // "/^\\+\\d{12}$/"
        if (phone != null && !phone.matches("\\+[0-9]{12}")){
            throw new IllegalArgumentException("Illegal symbols in string: '" + phone + "'");
        }
        this.phone = phone;
    }

    @Override
    public java.util.Date getDate(){
        return date;
    }

    @Override
    public void setDate(java.util.Date date){
//        Calendar today = Calendar.getInstance();
//        if (date.getTime() > today.getTime().getTime()){
//            throw new IllegalArgumentException("Date surpasses current UTC time.");
//        }
        if (date != null && date.getTime() > System.currentTimeMillis()){
            throw new IllegalArgumentException("Date surpasses current UTC time.");
        }
        this.date = date;
    }

    @CustomAnnotation
    public int daysRemainingToBirthday() {
        Calendar today = Calendar.getInstance();
        java.util.Date day = today.getTime();
        return daysDiffToBirthday(day);
    }

    public int daysDiffToBirthday(java.util.Date day){
        Calendar today = Calendar.getInstance();
        today.setTime(day);
        today.set(Calendar.HOUR_OF_DAY, 0);
        today.set(Calendar.MINUTE, 0);
        today.set(Calendar.SECOND, 0);
        int year = today.get(Calendar.YEAR);

        Calendar birthday = Calendar.getInstance();
        birthday.setTime(this.getDate());
        today.set(Calendar.HOUR_OF_DAY, 0);
        today.set(Calendar.MINUTE, 0);
        today.set(Calendar.SECOND, 0);
        birthday.set(Calendar.YEAR, year);
        if (day.getTime() >= birthday.getTime().getTime()){
            birthday.set(Calendar.YEAR, year + 1);
        }

        long time = birthday.getTime().getTime() - day.getTime();
        return (int) (time / (3600000 * 24));
    }

    @Override
    public String toString(){
        Calendar birth = Calendar.getInstance();
        birth.setTime(getDate());
        return "Fullname: " + fullname + "; Phone: " + phone + "; Birth date: " + birth.get(Calendar.DAY_OF_MONTH) +
                "-" + (birth.get(Calendar.MONTH) + 1) + "-" + birth.get(Calendar.YEAR);
    }

    @Override
    public int hashCode(){
        return fullname.hashCode() + phone.hashCode() + date.hashCode();
    }

    @Override
    public boolean equals(Object object){
        if (!(object instanceof Notebook)){
            return false;
        }
        if (object == this){
            return true;
        }
        return fullname.equals(((Notebook) object).getFullname()) && phone.equals(((Notebook) object).getPhone()) &&
                date.equals(((Notebook) object).getDate());
    }

}
