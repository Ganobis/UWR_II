using System;
using System.Collections.Generic;

namespace Zad2
{
    public interface IShape
    {
        public int GetArea();
    }

    public interface IShapeFactoryWorker
    {
        bool AcceptsParametres(string parametr);
        IShape Create(params object[] parametr);
    }

    public class Square : IShape
    {
        private int _side;

        public Square(int side)
        {
            _side = side;
        }

        public int GetArea()
        {
            return _side * _side;
        }
    }

    public class Triangle : IShape
    {
        private int _a, _b, _c;

        public Triangle(int a, int b, int c)
        {
            _a = a;
            _b = b;
            _c = c;
        }
        public int GetArea()
        {
            int p = (_a + _b + _c) / 3;
            return (int)Math.Sqrt(p * (p - _a) * (p - _b) * (p - _c));
        }
    }

    public class SquareShapeWorker : IShapeFactoryWorker
    {
        public bool AcceptsParametres(string parametr)
        {
            return parametr == "Square";
        }

        public IShape Create(params object[] parametr)
        {
            return new Square((int)parametr[0]);
        }
    }

    public class TriangleShapeWorker : IShapeFactoryWorker
    {
        public bool AcceptsParametres(string parametr)
        {
            return parametr == "Triangle";
        }

        public IShape Create(params object[] parametr)
        {
            return new Triangle((int)parametr[0], (int)parametr[1], (int)parametr[2]);
        }
    }

    public class ShapeFactory
    {
        private List<IShapeFactoryWorker> workers = new List<IShapeFactoryWorker>();

        public void RegisterWorker(IShapeFactoryWorker worker)
        {
            workers.Add(worker);
        }
        public IShape CreateShape(string ShapeName, params object[] parameters)
        {
            foreach (var worker in workers)
            {
                if (worker.AcceptsParametres(ShapeName))
                    return worker.Create(parameters);
            }

            if (ShapeName == "Square")
            {
                return new Square((int)parameters[0]);
            }
            else if (ShapeName == "Triangle")
            {
                return new Triangle((int)parameters[0], (int)parameters[1], (int)parameters[2]);
            }
            throw new ArgumentNullException();
        }
    }
}