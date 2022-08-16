package controller;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

public class ClassProxy implements InvocationHandler {
    Object obj;

    private ClassProxy(Object object){
        obj = object;
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        if (method.getName().startsWith("set")){
            throw new Exception("Access denied");
        }
        return method.invoke(obj, args);
    }

    public static Object newProxy(Object object){
        return java.lang.reflect.Proxy.newProxyInstance(object.getClass().getClassLoader(),
                object.getClass().getInterfaces(), new ClassProxy(object));
    }
}
