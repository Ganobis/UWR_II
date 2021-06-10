using System;
using System.Collections;
using System.Reflection;

namespace Zadanie1
{
    public class SimpleContainer
    {
        private Hashtable registerTypes;
        public SimpleContainer()
        {
            Resolver.container = this;
            registerTypes = new Hashtable();
        }
        public void RegisterType<T>(bool Singleton) where T : class
        {
            if (registerTypes.ContainsKey(typeof(T)))
            {
                registerTypes.Remove(typeof(T));
            }
            if (Singleton)
            {
                registerTypes.Add(typeof(T), new SingletonResolve(typeof(T)));
            }
        }
        public void RegisterType<From, To>(bool Singleton) where To : From
        {
            if(registerTypes.ContainsKey(typeof(From)))
            {
                registerTypes.Remove(typeof(From));
            }
            if (Singleton)
            {
                registerTypes.Add(typeof(From), new SingletonResolve(typeof(To)));
            }
            else
            {
                registerTypes.Add(typeof(From), new Resolver(typeof(To)));
            }
        }
        public T Resolve<T>()
        {
            if (registerTypes.ContainsKey(typeof(T)))
            {
                return (T)registerTypes[typeof(T)];
            }
            else
            {
                Console.WriteLine("Unregister type");
                return default(T);
            }
        }

        private class Resolver
        {
            public static SimpleContainer container;
            public Type ToType;
            public Resolver(Type ToType)
            {
                this.ToType = ToType;
            }
            public virtual object Create()
            {
                if (container.registerTypes.ContainsKey(ToType))
                {
                    Resolver nextResolver = container.registerTypes[ToType];
                    if (nextResolver != this)
                    {
                        return nextResolver.Create();
                    }
                    else
                    {
                        return container.Create(ToType);
                    }
                }
                return container.Create(ToType);
            }
        }

        private class SingletonResolve : Resolver
        {
            public SingletonResolve(Type ToType) : base(ToType) { }
            private object _instance;
            private object _lock = new object();
            public override object Create()
            {
                if (_instance == null)
                {
                    lock (_lock)
                    {
                        if (_instance == null)
                        {
                            _instance = base.Create();
                        }
                    }
                }
                return _instance;
            }
        }
    }
}
