package com.company;
import org.junit.jupiter.api.Test;
import java.util.ArrayList;
import static org.junit.jupiter.api.Assertions.*;


class Class1Test {
    private  Class1 c1= new Class1();

    @Test
    public void testNullS()
    {
        ArrayList<String> list=new ArrayList<String>();
        list.add("abcdef");

        Exception exception = assertThrows(Exception.class, () -> {
            c1.method1(list,null);
        });
    }

    @Test
    public void testNullList()
    {

        String s="abcdef";
        Exception exception = assertThrows(Exception.class, () -> {
            c1.method1(null,s);
        });
    }

    @Test
    public void testBothNull()
    {
        Exception exception = assertThrows(Exception.class, () -> {
            c1.method1(null,null);
        });
    }
    @Test
    public void testRemoveOneString() throws Exception {
        ArrayList<String> list=new ArrayList<String>();
        list.add("abcdef");
        list.add("bcdefg");
        list.add("cdefgh");
        list.add("defghi");
        list.add("efghij");
        String s="cdefgh";

        ArrayList<String> listRes=new ArrayList<String>();
        listRes.add("abcdef");
        listRes.add("bcdefg");
        listRes.add("defghi");
        listRes.add("efghij");

        assertEquals(c1.method1(list,s),listRes);
    }
    @Test
    public void testNoRemove() throws Exception {
        ArrayList<String> list=new ArrayList<String>();
        list.add("abcdef");
        list.add("bcdefg");
        list.add("cdefgh");
        list.add("defghi");
        list.add("efghij");
        String s="cdefghasf";

        ArrayList<String> listRes=new ArrayList<String>();
        listRes.add("abcdef");
        listRes.add("bcdefg");
        listRes.add("cdefgh");
        listRes.add("defghi");
        listRes.add("efghij");
        assertEquals(c1.method1(list,s),listRes);
    }
    @Test
    public void testRemoveMany() throws Exception {
        ArrayList<String> list=new ArrayList<String>();
        list.add("abcdef");
        list.add("bcdefg");
        list.add("bcdefg");
        list.add("bcdefg");
        list.add("bcdefg");
        list.add("cdefgh");
        list.add("defghi");
        list.add("efghij");
        String s="bcdefg";

        ArrayList<String> listRes=new ArrayList<String>();
        listRes.add("abcdef");
        listRes.add("cdefgh");
        listRes.add("defghi");
        listRes.add("efghij");
        assertEquals(c1.method1(list,s),listRes);
    }
    @Test
    public void testNullInList() throws Exception {
        ArrayList<String> list=new ArrayList<String>();
        list.add("abcdef");
        list.add("bcdefg");
        list.add("cdefgh");
        list.add("defghi");
        list.add(null);
        list.add("efghij");
        String s="cdefghasf";

        ArrayList<String> listRes=new ArrayList<String>();
        listRes.add("abcdef");
        listRes.add("bcdefg");
        listRes.add("cdefgh");
        listRes.add("defghi");
        listRes.add(null);
        listRes.add("efghij");
        assertEquals(c1.method1(list,s),listRes);
    }
    @Test
    public void testNullInListRemove() throws Exception {
        ArrayList<String> list=new ArrayList<String>();
        list.add("abcdef");
        list.add("bcdefg");
        list.add("cdefgh");
        list.add("defghi");
        list.add(null);
        list.add("efghij");
        String s="cdefgh";

        ArrayList<String> listRes=new ArrayList<String>();
        listRes.add("abcdef");
        listRes.add("bcdefg");
        listRes.add("defghi");
        listRes.add(null);
        listRes.add("efghij");
        assertEquals(c1.method1(list,s),listRes);
    }


}