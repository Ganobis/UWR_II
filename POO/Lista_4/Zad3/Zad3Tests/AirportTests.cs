using Microsoft.VisualStudio.TestTools.UnitTesting;
using Zad3;
using System;
using System.Collections.Generic;
using System.Text;

namespace Zad3.Tests
{
    [TestClass()]
    public class AirportTests
    {
        [TestMethod()]
        public void Test1()
        {
            Airport airport = new Airport(2);
            Plane plane = airport.Take_Plane();

            Assert.IsNotNull(airport);
            Assert.IsNotNull(plane);
        }
    }
}