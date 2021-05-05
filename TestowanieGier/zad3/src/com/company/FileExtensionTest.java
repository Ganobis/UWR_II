package com.company;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;

class FileExtensionTest{
    @Test
    @ExtendWith(FileExtension.class)
    void test(@FileExtension.File(path= "C:\\Users\\kasia\\OneDrive\\Dokumenty\\GitHub\\UWR_II\\TestowanieGier\\zad3\\src\\com\\company\\test.txt") String content)
    {
        assertEquals(content, "test1");
    }
}
