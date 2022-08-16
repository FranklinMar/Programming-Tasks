package controller;//import java.lang.reflect.Proxy;
import controller.ClassProxy;
import model.CustomAnnotation;
import model.Date;
import model.Notebook;

import java.util.Arrays;
import java.util.Calendar;
import java.lang.reflect.*;
import java.util.LinkedHashMap;
import java.util.Map;

//@Deprecated
public class Main {
    //private static Proxy instance;

    public static void main(String[] args) throws Throwable{
        Calendar birthday = Calendar.getInstance();
        birthday.set(Calendar.HOUR_OF_DAY, 0);
        birthday.set(Calendar.MINUTE, 0);
        birthday.set(Calendar.SECOND, 0);
        birthday.set(Calendar.YEAR, 2002);
        birthday.set(Calendar.MONTH, Calendar.JULY);
        birthday.set(Calendar.DAY_OF_MONTH, 15);
        Notebook nb = new Notebook("Berezniuk Denys Leonidovych", "+380971234567", birthday.getTime());
        Map <Method, Object> map = Task2(nb);
        System.out.println("Task 2\n");
        map.forEach((key, value) -> System.out.println("Method: " + key + "\nResult: " + value));
        System.out.println();
        Task3(nb);
        System.out.println("\nTask4\n");
        try {
            Task4(nb);
        } catch (Exception e){
            System.out.println("Exception caught");
        }
    }
    public static Map<Method, Object> Task2(Object obj) throws IllegalAccessException, InvocationTargetException{
        //System.out.println("Task 2\n");
        Class<?> cls = obj.getClass();
        Map <Method, Object> map = new LinkedHashMap<>();
        for (Method i : cls.getDeclaredMethods()){
            if (i.isAnnotationPresent(CustomAnnotation.class)){
                //System.out.println("Method: " + i.getName() + "\nResult: " + i.invoke(obj));
                map.put(i, i.invoke(obj));
            }
        }
        return map;
    }
    public static void Task3(Object obj){
        System.out.println("Task3\n");
        Class<?> cls = obj.getClass();
        System.out.println(cls);
        for (Method i : cls.getMethods()){
            System.out.println("- " + i.getName());
            System.out.println("\tAnnotations: " + Arrays.toString(i.getAnnotations()));
            System.out.println("\tParameters types: " + Arrays.toString(i.getParameterTypes()));
        }
        System.out.println("\nPackage: " + cls.getPackageName());
        System.out.println("Class: " + cls.getName());
    }
    public static void Task4(Object obj) {// throws Throwable{
        //System.out.println("Task4\n");
        Date instance = (Date) ClassProxy.newProxy(obj);
        System.out.println(instance.getDate());
        //try {
            instance.setDate(null);
        //    System.out.println(instance.getDate());
        //} catch (Exception e){
        //    System.out.println("Exception caught");
        //}
    }
}
