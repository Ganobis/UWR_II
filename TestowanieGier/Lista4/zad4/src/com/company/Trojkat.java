package com.company;

import java.awt.*;

public class Trojkat {
    private static double Dystans(double x1, double y1, double x2, double y2){
        return Math.sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
    }
    public static String Sprawdz_Wieszcholki(Point p1, Point p2, Point p3) throws Exception {
        double b1 = Trojkat.Dystans(p1.x, p1.y, p2.x, p2.y);
        double b2 = Trojkat.Dystans(p2.x, p2.y, p3.x, p3.y);
        double b3 = Trojkat.Dystans(p1.x, p1.y, p3.x, p3.y);
        if (b1 >= (b2 + b3) || b2 >= (b1 + b3) || b3 >= (b2 + b3))
            throw new Exception("Z podoanych punktów nie można stworzyć trójkąta!");
        if (b1 == b2 && b1 == b3)
            return "Równoboczny";
        if (b1 == b2 || b1 == b3 || b2 == b3)
            return "Równoramienny";
        return "Różnoboczny";
    }
}
