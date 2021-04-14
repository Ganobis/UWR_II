using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Zad2.Tests
{
    public class Diamond : IShape
    {
        private int _a, _h;

        public Diamond(int a, int h)
        {
            _a = a;
            _h = h;
        }
        public int GetArea()
        {
            return _a * _h;
        }
    }

    public class DiamondShapeWorker : IShapeFactoryWorker
    {
        public bool AcceptsParametres(string parametr)
        {
            return parametr == "Diamond";
        }

        public IShape Create(params object[] parametr)
        {
            return new Diamond((int)parametr[0], (int)parametr[1]);
        }
    }

    [TestClass()]
    public class ShapeFactoryTests
    {
        [TestMethod()]
        public void RegisterWorkerTest()
        {
            var factory = new ShapeFactory();
            factory.RegisterWorker(new DiamondShapeWorker());
            IShape shapeFactoryWorker = factory.CreateShape("Diamond", 6, 3);
            IShape shapeFactoryWorker2 = factory.CreateShape("Triangle", 2, 3, 5);
            Assert.IsNotNull(shapeFactoryWorker);
            Assert.IsNotNull(shapeFactoryWorker2);
        }

        [TestMethod()]
        public void RegisterWorkerTest2()
        {
            var factory = new ShapeFactory();
            factory.RegisterWorker(new DiamondShapeWorker());
            IShape shapeFactoryWorker = factory.CreateShape("Square", 6);
            IShape shapeFactoryWorker2 = factory.CreateShape("Square", 5);
            Assert.IsNotNull(shapeFactoryWorker);
            Assert.IsNotNull(shapeFactoryWorker2);
            Assert.AreEqual(shapeFactoryWorker.GetArea(), 36);
            Assert.AreEqual(shapeFactoryWorker2.GetArea(), 25);
        }
    }
}