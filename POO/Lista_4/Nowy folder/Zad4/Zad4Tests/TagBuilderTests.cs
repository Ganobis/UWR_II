using Microsoft.VisualStudio.TestTools.UnitTesting;
using Zad4;
using System;
using System.Collections.Generic;
using System.Text;

namespace Zad4.Tests
{
    [TestClass()]
    public class TagBuilderTests
    {
        [TestMethod()]
        public void TagBuilderTest()
        {
            TagBuilder tag0 = new TagBuilder();
            TagBuilder tagparent = new TagBuilder("Rodzic", tag0);
            TagBuilder tag = new TagBuilder("TagTest", tagparent);
            Console.WriteLine(tag.ToString());
            Assert.IsNotNull(tag);
        }
        [TestMethod()]
        public void TagBuilderTest2()
        {
            string str = "<TagTest><parent parentproperty1='true' parentproperty2='5'><child1 childproperty1='c'>childbody</child1><child2 childproperty2='c'>childbody</child2></parent><script>$.scriptbody();</script></TagTest>";
            TagBuilder tag0 = new TagBuilder();
            TagBuilder tagparent = new TagBuilder("Rodzic", tag0);
            TagBuilder tag = new TagBuilder("TagTest", tagparent);
            var script =
            tag.StartTag("parent")
                 .AddAttribute("parentproperty1", "true")
                 .AddAttribute("parentproperty2", "5")
                     .StartTag("child1")
                     .AddAttribute("childproperty1", "c")
                     .AddContent("childbody")
                     .EndTag()
                     .StartTag("child2")
                     .AddAttribute("childproperty2", "c")
                     .AddContent("childbody")
                     .EndTag()
                 .EndTag()
                 .StartTag("script")
                 .AddContent("$.scriptbody();")
                 .EndTag();
            Assert.AreEqual(str, tag.ToString());
        }
    }
}
