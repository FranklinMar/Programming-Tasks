import controller.Main;
import model.Notebook;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.*;
import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.*;

class NotebookTests {

    @ParameterizedTest
    @MethodSource("constructorTestCases")
    void constructorTests(String fullName, String phone, Date date){
        assertThrows(IllegalArgumentException.class, () -> {
            Notebook notebook = new Notebook(fullName, phone, date);
        });
    }

    @Test
    void daysRemainingToBirthdayTests() {
        Calendar birthday = Calendar.getInstance();
        birthday.set(Calendar.HOUR_OF_DAY, 0);
        birthday.set(Calendar.MINUTE, 0);
        birthday.set(Calendar.SECOND, 0);
        birthday.set(Calendar.YEAR, 2002);
        birthday.set(Calendar.MONTH, Calendar.JULY);
        birthday.set(Calendar.DAY_OF_MONTH, 15);

        Notebook notebook = new Notebook("a", "+380123456789", birthday.getTime());

        birthday.set(Calendar.YEAR, Calendar.getInstance().get(Calendar.YEAR));
        Calendar today = Calendar.getInstance();
        today.set(Calendar.HOUR_OF_DAY, 0);
        today.set(Calendar.MINUTE, 0);
        today.set(Calendar.SECOND, 0);
        java.util.Date day = today.getTime();
        int year = today.get(Calendar.YEAR);


        if (day.getTime() > birthday.getTime().getTime()){
            birthday.set(Calendar.YEAR, year + 1);
        }
        long time = birthday.getTime().getTime() - day.getTime();
        assertEquals((int) (time / (3600000 * 24)), notebook.daysRemainingToBirthday());
    }

    //@org.junit.jupiter.api.Test
    @ParameterizedTest
    @MethodSource("testCasesDaysDifference")
    void daysDiffToBirthday(java.util.Date day, java.util.Date birthday, int dayDifference) {
        Notebook notebook = new Notebook("a", "+380123456789", birthday);
        assertEquals(dayDifference, notebook.daysDiffToBirthday(day));
    }

    @Test
    void equalsTest() {
        Calendar birthday = Calendar.getInstance();
        birthday.set(Calendar.HOUR_OF_DAY, 0);
        birthday.set(Calendar.MINUTE, 0);
        birthday.set(Calendar.SECOND, 0);
        birthday.set(Calendar.YEAR, 2002);
        birthday.set(Calendar.MONTH, Calendar.JULY);
        birthday.set(Calendar.DAY_OF_MONTH, 15);

        Notebook notebook1 = new Notebook("a", "+380123456789", birthday.getTime());

        Notebook notebook2 = new Notebook("a", "+800331235467", birthday.getTime());

        assertTrue(notebook1.equals(notebook1));
        assertFalse(notebook1.equals(null));
        assertFalse(notebook1.equals(new Object()));
        assertFalse(notebook1.equals(notebook2));

        notebook2.setPhone("+380123456789");
        notebook2.setFullname(null);

        assertFalse(notebook1.equals(notebook2));

        notebook2.setFullname("a");
        assertTrue(notebook1.equals(notebook2));
    }

    public static Stream<Arguments> constructorTestCases(){
        List<Arguments> testCases = new ArrayList<>();

        String goodFullname = "Denys Berenzniuk", badFullname = "He1100!! M4h nAme, is V4n91aRus15";
        String goodPhone = "+380123456789", badPhone = "8 800 555 3535";
        Calendar goodDay = Calendar.getInstance(), badDay = Calendar.getInstance();
        goodDay.set(Calendar.YEAR, 2017);
        goodDay.set(Calendar.MONTH, Calendar.AUGUST);
        goodDay.set(Calendar.DAY_OF_MONTH, 7);

        badDay.set(Calendar.YEAR, 2099);
        badDay.set(Calendar.MONTH, Calendar.JANUARY);
        badDay.set(Calendar.DAY_OF_MONTH, 25);

        String[] fullnames = {goodFullname, badFullname},
                phones = {goodPhone, badPhone};
        Calendar[] days = {goodDay, badDay};

        for (int i = 0; i < fullnames.length; i++){
            for (int j = 0; j < phones.length; j++){
                for (int k = 0; k < days.length; k++){
                    if (i != 0 || j != 0 || k != 0) {
                        testCases.add(Arguments.arguments(fullnames[i], phones[j], days[k].getTime()));
                    }
                }
            }
        }
        //testCases.add(Arguments.arguments(day.getTime(), day.getTime(), 171));

        //Stream<Arguments> testCases = Stream.of(Arguments.arguments("1", "1"),
        //        Arguments.arguments("2", "2"),
        //        Arguments.arguments("5", "120"));

        return testCases.stream();
    }

    public static Stream<Arguments> testCasesDaysDifference(){
        List<Arguments> testCases = new ArrayList<>();
        Calendar day = Calendar.getInstance();
        day.set(Calendar.YEAR, 2017);
        day.set(Calendar.MONTH, Calendar.AUGUST);
        day.set(Calendar.DAY_OF_MONTH, 7);

        Calendar birthday = Calendar.getInstance();
        birthday.set(Calendar.YEAR, 2014);
        birthday.set(Calendar.MONTH, Calendar.JANUARY);
        birthday.set(Calendar.DAY_OF_MONTH, 25);

        testCases.add(Arguments.arguments(day.getTime(), birthday.getTime(), 171));

        day = Calendar.getInstance();
        day.set(Calendar.YEAR, 2021);
        day.set(Calendar.MONTH, Calendar.DECEMBER);
        day.set(Calendar.DAY_OF_MONTH, 1);

        birthday = Calendar.getInstance();
        birthday.set(Calendar.YEAR, 2021);
        birthday.set(Calendar.MONTH, Calendar.DECEMBER);
        birthday.set(Calendar.DAY_OF_MONTH, 1);

        testCases.add(Arguments.arguments(day.getTime(), birthday.getTime(), 365));
        //Stream<Arguments> testCases = Stream.of(Arguments.arguments("1", "1"),
        //        Arguments.arguments("2", "2"),
        //        Arguments.arguments("5", "120"));

        day = Calendar.getInstance();
        day.set(Calendar.YEAR, 2021);
        day.set(Calendar.MONTH, Calendar.DECEMBER);
        day.set(Calendar.DAY_OF_MONTH, 1);

        birthday = Calendar.getInstance();
        birthday.set(Calendar.YEAR, 2021);
        birthday.set(Calendar.MONTH, Calendar.DECEMBER);
        birthday.set(Calendar.DAY_OF_MONTH, 2);

        testCases.add(Arguments.arguments(day.getTime(), birthday.getTime(), 1));

        day = Calendar.getInstance();
        day.set(Calendar.YEAR, 2021);
        day.set(Calendar.MONTH, Calendar.DECEMBER);
        day.set(Calendar.DAY_OF_MONTH, 2);

        birthday = Calendar.getInstance();
        birthday.set(Calendar.YEAR, 2021);
        birthday.set(Calendar.MONTH, Calendar.DECEMBER);
        birthday.set(Calendar.DAY_OF_MONTH, 1);

        testCases.add(Arguments.arguments(day.getTime(), birthday.getTime(), 364));

        return testCases.stream();
    }
}