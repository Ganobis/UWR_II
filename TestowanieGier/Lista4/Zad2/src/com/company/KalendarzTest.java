package com.company;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class KalendarzTest {
    Kalendarz kalendarz = new Kalendarz();

    @Test
    void dodaj_Wydarzenie_1() throws Exception {
        kalendarz.Dodaj_Wydarzenie(0, 33, "Test");
        kalendarz.Dodaj_Wydarzenie(35, 473, "Test2");
        assertEquals(kalendarz.array[0], "Test");
        for (int i = 35; i <= 473; i++) {
            assertEquals(kalendarz.array[i], "Test2");
        }
    }

    @Test
    void dodaj_Wydarzenie_Exception1() throws Exception{
        Exception exception = assertThrows(Exception.class, () -> {
            kalendarz.Dodaj_Wydarzenie(54, 1, "Test");
        });
        assertEquals("Początek wydarzenia musi być mniejszy niż koniec lub równy!", exception.getMessage());
    }

    @Test
    void dodaj_Wydarzenie_Exception2() throws Exception{
        kalendarz.Dodaj_Wydarzenie(0, 33, "Test");
        Exception exception = assertThrows(Exception.class, () -> {
            kalendarz.Dodaj_Wydarzenie(2, 4, "Test");
        });
        assertEquals("Wydarzenie nakłada się na inne wydarzenie!", exception.getMessage());
    }

    @Test
    void usun_Wydarzenie_1() throws Exception{
        kalendarz.Dodaj_Wydarzenie(0, 33, "Test");
        kalendarz.Dodaj_Wydarzenie(35, 473, "Test2");
        kalendarz.Dodaj_Wydarzenie(34, 34, "Test3");
        assertEquals(kalendarz.array[34], "Test3");
        kalendarz.Usun_Wydarzenie("Test3");
        assertEquals(kalendarz.array[34], "Brak wydarzenia");
    }

    @Test
    void usun_Wydarzenie_Exception() throws Exception{
        Exception exception = assertThrows(Exception.class, () -> {
            kalendarz.Usun_Wydarzenie( "Test");
        });
        assertEquals("Podane wydarzenie nie istnieje!", exception.getMessage());
    }

    @Test
    void modyfikuj_Wyjarzenie() throws Exception {
        kalendarz.Dodaj_Wydarzenie(0, 2020, "Test");
        for (int i = 0; i <= 2020; i++){
            assertEquals(kalendarz.array[i], "Test");
        }
        kalendarz.Modyfikuj_Wyjarzenie(10, 2000, "Test");
        for (int i = 0; i <= 2020; i++){
            if (i >= 10 && i <= 2000)
                assertEquals(kalendarz.array[i], "Test");
            else
                assertEquals(kalendarz.array[i], "Brak wydarzenia");
        }
    }

    @Test
    void modyfikuj_Wydarzenie_Exception1() throws Exception {
        kalendarz.Dodaj_Wydarzenie(0, 2020, "Test");
        Exception exception = assertThrows(Exception.class, () -> {
            kalendarz.Modyfikuj_Wyjarzenie( 4, 2, "Test");
        });
        assertEquals("Początek wydarzenia musi być mniejszy niż koniec lub równy!", exception.getMessage());
    }

    @Test
    void modyfikuj_Wydarzenie_Exception2() throws Exception {
        Exception exception = assertThrows(Exception.class, () -> {
            kalendarz.Modyfikuj_Wyjarzenie( 1, 2, "Test");
        });
        assertEquals("Podane wydarzenie nie istnieje!", exception.getMessage());
    }

    @Test
    void modyfikuj_Wydarzenie_Exception3() throws Exception {
        kalendarz.Dodaj_Wydarzenie(0, 1000, "Test");
        kalendarz.Dodaj_Wydarzenie(2000, 2001, "Test2");
        Exception exception = assertThrows(Exception.class, () -> {
            kalendarz.Modyfikuj_Wyjarzenie( 1, 200, "Test2");
        });
        assertEquals("Wydarzenie nakłada się na inne wydarzenie!", exception.getMessage());
    }
}