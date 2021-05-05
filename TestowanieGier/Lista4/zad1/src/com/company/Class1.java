package com.company;

import java.util.ArrayList;

public class Class1 {
    public Class1(){};
    public ArrayList<String> method1(ArrayList<String> l, String s) throws Exception
    {
        if (l==null || s== null)
        {
            throw new IllegalArgumentException("któryś z argumentów jest null'em");
        }
        while (l.contains(s))
        {
            l.remove(s);
        }
        return l;
    }
}
