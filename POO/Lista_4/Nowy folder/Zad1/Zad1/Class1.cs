using System;

namespace Zad1
{
    public class Singleton
    {
        private static Singleton _instance;
        private static object _lock = new object();

        Singleton() { }

        public static Singleton Instance()
        {
            if(_instance == null)
            {
                lock (_lock)
                {
                    if(_instance == null)
                    {
                        return _instance = new Singleton();
                    }
                }
            }
            return _instance;
        }
    }

    public class ThreadSingleton
    {
        private static ThreadSingleton _instance;

        ThreadSingleton() { }

        public static ThreadSingleton Instance()
        {
            if(_instance == null)
            {
                return _instance = new ThreadSingleton();
            }
            return _instance;
        }
    }

    public class TimeSingleton
    {
        private static object _lock = new object();
        private static TimeSingleton _instance;
        private static DateTime _lastUpdate;

        private static bool IsTime()
        {
            var time = _lastUpdate.AddSeconds(5);
            return DateTime.Now > time;
        }

        TimeSingleton()
        {
            _lastUpdate = DateTime.Now;
        }

        public static TimeSingleton Instance()
        {
            if(_instance == null || IsTime())
            {
                lock (_lock)
                {
                    if(_instance == null || IsTime())
                    {
                        return _instance = new TimeSingleton();
                    }
                }
            }
            return _instance;
        }
    }
}
