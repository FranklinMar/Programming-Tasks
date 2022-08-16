import controller.Main;
import model.Notebook;
import org.junit.jupiter.api.Test;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Calendar;
import java.util.LinkedHashMap;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class MainTests {

    @Test
    void Task2Test() throws NoSuchMethodException, InvocationTargetException, IllegalAccessException {
        Calendar birthday = Calendar.getInstance();
        birthday.set(Calendar.HOUR_OF_DAY, 0);
        birthday.set(Calendar.MINUTE, 0);
        birthday.set(Calendar.SECOND, 0);
        birthday.set(Calendar.YEAR, 2002);
        birthday.set(Calendar.MONTH, Calendar.JULY);
        birthday.set(Calendar.DAY_OF_MONTH, 15);

        Notebook notebook = new Notebook("a", "+380123456789", birthday.getTime());

        Map<Method, Object> map = new LinkedHashMap<>();
        String method1 = "daysRemainingToBirthday";
        map.put(notebook.getClass().getMethod(method1), notebook.getClass().getMethod(method1).invoke(notebook));

        String method2 = "getFullname";
        map.put(notebook.getClass().getMethod(method2), notebook.getClass().getMethod(method2).invoke(notebook));

        assertEquals(map, Main.Task2(notebook));
        assertEquals(new LinkedHashMap<>(), Main.Task2(new Object()));
    }

    @Test
    void Task4Test(){
        Calendar birthday = Calendar.getInstance();
        birthday.set(Calendar.HOUR_OF_DAY, 0);
        birthday.set(Calendar.MINUTE, 0);
        birthday.set(Calendar.SECOND, 0);
        birthday.set(Calendar.YEAR, 2002);
        birthday.set(Calendar.MONTH, Calendar.JULY);
        birthday.set(Calendar.DAY_OF_MONTH, 15);

        Notebook notebook = new Notebook("a", "+380123456789", birthday.getTime());
        assertThrows(Exception.class, () -> Main.Task4(notebook));
    }
}
