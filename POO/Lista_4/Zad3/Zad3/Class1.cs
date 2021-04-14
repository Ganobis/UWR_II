using System;
using System.Collections.Generic;

namespace Zad3
{
    public class Plane
    {
        public void GetModel()
        {
            Console.WriteLine("Boeing 747");
        }
    }
    public class Airport
    {
        private int _capacity;
        private List<Plane> _ready = new List<Plane>();
        private List<Plane> _take = new List<Plane>();

        public Airport(int capacity)
        {
            _capacity = capacity;
            Plane newPlane = new Plane();
            _ready.Add(newPlane);
        }

        public Plane Take_Plane()
        {
            if(_ready.Count >= _capacity)
            {
                Console.WriteLine("Nie można zabrać więcej samolotów!");
                return null;
            }
            Plane plane = _ready[0];
            _ready.Remove(plane);
            _take.Add(plane);
            Console.WriteLine("Zabrano samolot!");
            return plane;
        }

        public void Realase_Plane(Plane plane)
        {
            if (!_take.Contains(plane))
            {
                Console.WriteLine("Ten samolot nie startował z tego lotniska!");
                return;
            }
            _take.Remove(plane);
            _ready.Add(plane);
            Console.WriteLine("Samolot wrócił!");
        }
    }
}
