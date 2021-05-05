package com.company;

import org.junit.jupiter.api.DynamicTest;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestFactory;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import java.awt.*;
import java.util.Arrays;
import java.util.Collection;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.DynamicTest.dynamicTest;

class TrojkatTest {

    @ParameterizedTest
    @ValueSource(ints = {2, 3, 90})
    void sprawdz_Wieszcholki(int x) throws Exception {
        assertEquals("Różnoboczny", Trojkat.Sprawdz_Wieszcholki(new Point(x, 0), new Point(0, 0), new Point(7, 1)));
    }

    @ParameterizedTest
    @ValueSource(ints = {1, -1})
    void sprawdz_Wieszcholki2(int y) throws Exception {
        assertEquals("Równoramienny", Trojkat.Sprawdz_Wieszcholki(new Point(0, y), new Point(0, 0), new Point(1, 0)));
    }

    @ParameterizedTest
    @ValueSource(ints = {1, -1})
    void sprawdz_Wieszcholki3(int x) throws Exception {
        assertEquals("Różnoboczny", Trojkat.Sprawdz_Wieszcholki(new Point(x, 1), new Point(0, 1), new Point(1, 3)));
    }

    @Test
    void sprawdz_Wieszcholki_Exception() throws Exception{
        Exception exception = assertThrows(Exception.class, () -> {
            Trojkat.Sprawdz_Wieszcholki(new Point(-0, 0), new Point(0, 0), new Point(-0, -0));
        });
        assertEquals("Z podoanych punktów nie można stworzyć trójkąta!", exception.getMessage());
    }

    @TestFactory
    Collection<DynamicTest> simpleDynamicTestExample() throws Exception{
        return Arrays.asList(
                dynamicTest("Test różnoboczny", () -> assertEquals("Różnoboczny", Trojkat.Sprawdz_Wieszcholki(new Point(1, 0), new Point(0, 0), new Point(7, 1)))),
                dynamicTest("Test równoramienny", () -> assertEquals("Równoramienny", Trojkat.Sprawdz_Wieszcholki(new Point(1, 0), new Point(0, 0), new Point(1, 1)))),
                dynamicTest("Test równoboczny", () -> assertEquals("Różnoboczny", Trojkat.Sprawdz_Wieszcholki(new Point(-1, 1), new Point(0, 1), new Point(1, 3)))),
                dynamicTest("Test wyjątku", () -> assertEquals("Z podoanych punktów nie można stworzyć trójkąta!",     assertThrows(Exception.class, () -> {
                    Trojkat.Sprawdz_Wieszcholki(new Point(-0, 0), new Point(0, 0), new Point(-0, -0));
                }).getMessage()))
        );
    }
}