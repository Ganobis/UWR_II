using System;
using System.Collections;
using System.Collections.Generic;

namespace Zad4
{
    class Program
    {
        class ComparisonToComparerAdapter<T> : IComparer
        {
            private readonly Comparison<T> _comparison;
            public ComparisonToComparerAdapter(Comparison<T> comparison)
            {
                _comparison = comparison;
            }

            public int Compare(object x, object y)
            {
                return _comparison((T)x, (T)y);
            }
        }
    }
}
