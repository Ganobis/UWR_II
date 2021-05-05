using System;
using System.Collections.Generic;

namespace Zadanie2
{
    class Program
    {
        public class Context
        {
            private Dictionary<string, bool> _dictionary;
            public Context()
            {
                _dictionary = new Dictionary<string, bool>();
            }
            public bool GetValue(string VariableName)
            {
                if (_dictionary.ContainsKey(VariableName))
                {
                    return _dictionary[VariableName];
                }
                throw new Exception();
            }
            public bool SetValue(string VariableName, bool Value)
            {
                if (_dictionary.ContainsKey(VariableName))
                {
                    _dictionary.Remove(VariableName);
                }
                _dictionary.Add(VariableName, Value);
                return true;
            }
        }
        public abstract class AbstractExpression
        {
            public abstract bool Interpret(Context context);
        }
        public class ConstExpression : AbstractExpression
        {
            private string _string;

            public ConstExpression(string str)
            {
                _string = str;
            }
            public override bool Interpret(Context context)
            {
                return context.GetValue(_string);
            }
        }
        public class BinaryExpression : AbstractExpression
        {
            private AbstractExpression _left;
            private AbstractExpression _right;
            private char _operator;
            public BinaryExpression(char op, AbstractExpression left, AbstractExpression right)
            {
                _operator = op;
                _left = left;
                _right = right;
            }
            public override bool Interpret(Context context)
            {
                if (_operator == '|')
                {
                    return (_left.Interpret(context) || _right.Interpret(context));
                }
                else if (_operator == '&')
                {
                    return (_left.Interpret(context) && _right.Interpret(context));
                }
                throw new Exception();
            }
        }
        public class UnaryExpression : AbstractExpression
        {
            private AbstractExpression _abstractExpression;
            private char _operator;

            public UnaryExpression(char op, AbstractExpression abstractExpression)
            {
                _abstractExpression = abstractExpression;
                _operator = op;
            }

            public override bool Interpret(Context context)
            {
                if(_operator == '!')
                {
                    return !_abstractExpression.Interpret(context);
                }
                throw new Exception();
            }

        }
        static void Main(string[] args)
        {
            // klient
            Context ctx = new Context();
            ctx.SetValue("x", false);
            ctx.SetValue("y", true);
            AbstractExpression exp = new BinaryExpression(
                '&', 
                new ConstExpression("x"),
                new UnaryExpression('!', new ConstExpression("y"))); // jakieś wyrażenie logiczne ze stałymi i zmiennymi
            bool Value = exp.Interpret(ctx);
            Console.WriteLine(Value);
        }
    }
}
