package com.company;

public class Kalendarz {
    public String[] array;
    public Kalendarz(){
        array = new String[2021];
        for (int i = 0; i <= 2020; i++){
            array[i] = "Brak wydarzenia";
        }
    }
    public void Dodaj_Wydarzenie(int start, int end, String name) throws Exception {
        if (start > end)
            throw new Exception("Początek wydarzenia musi być mniejszy niż koniec lub równy!");
        for (int i = start; i <= end; i++){
            if(!array[i].equals("Brak wydarzenia"))
                throw new Exception("Wydarzenie nakłada się na inne wydarzenie!");
        }
        for (int i = start; i <= end; i++){
            array[i] = name;
        }
    }
    public void Usun_Wydarzenie(String name) throws Exception {
        boolean flag = false;
        for (int i = 0; i <= 2020; i++){
            if (array[i].equals(name)) {
                array[i] = "Brak wydarzenia";
                flag = true;
            }
        }
        if (!flag){
            throw new Exception("Podane wydarzenie nie istnieje!");
        }
    }
    public void Modyfikuj_Wyjarzenie(int start, int end, String name) throws Exception{
        boolean flag = false;
        if (start > end)
            throw new Exception("Początek wydarzenia musi być mniejszy niż koniec lub równy!");
        for (int i = 0; i <= 2020; i++){
            if (array[i].equals(name))
            flag = true;
        }
        if (!flag){
            throw new Exception("Podane wydarzenie nie istnieje!");
        }
        for (int i = start; i <= end; i++){
            if(!array[i].equals("Brak wydarzenia") && !array[i].equals(name))
                throw new Exception("Wydarzenie nakłada się na inne wydarzenie!");
        }
        for (int i = 0; i <= 2020; i++){
            if (array[i].equals(name))
                array[i] = "Brak wydarzenia";
        }
        for (int i = start; i <= end; i++){
            array[i] = name;
        }
    }
}
