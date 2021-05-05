using System;
using System.IO;

namespace Zadanie1
{

    public interface ILogger
    {
        void Log(string Message);
    }
    public enum LogType { None, Console, File }

    public class ConsoleLogger : ILogger
    {
        public void Log(string Message)
        {
            Console.WriteLine(Message);
        }
    }

    public class NullLogger : ILogger
    {
        public void Log(string Message)
        {

        }
    }

    public class FileLogger : ILogger
    {
        private string _path;

        public FileLogger(string path)
        {
            _path = path;
        }

        public void Log(string Message)
        {
            if (_path == null)
            {
                throw new Exception();
            }
            using (StreamWriter streamWriter = File.AppendText(_path))
            {
                streamWriter.WriteLine(Message);
            }
        }
    }

    public class LoggerFactory
    {
        private static LoggerFactory _instance;
        public ILogger GetLogger(LogType LogType, string Parameters = null)
        {
            if (LogType == LogType.None)
            {
                return new NullLogger();
            }
            else if (LogType == LogType.Console)
            {
                return new ConsoleLogger();
            }
            else if (LogType == LogType.File)
            {
                return new FileLogger(Parameters);
            }

            throw new Exception();
        }
        public static LoggerFactory Instance()
        {
            if(_instance == null)
            {
                return _instance = new LoggerFactory();
            }
            return _instance;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var loggerFactory = LoggerFactory.Instance();
            // klient:
            ILogger logger1 = loggerFactory.GetLogger(LogType.File, "C:\foo.txt");
            logger1.Log("foo bar"); // logowanie do pliku
            ILogger logger2 = loggerFactory.GetLogger(LogType.None);
            logger2.Log("qux"); // brak logowania
        }
    }
}
