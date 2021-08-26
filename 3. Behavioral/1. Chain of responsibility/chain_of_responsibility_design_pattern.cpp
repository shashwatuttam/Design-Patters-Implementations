#include<bits/stdc++.h>
using namespace std;

// Interface logger
class Logger{
protected:
    int level;
    Logger *next_in_chain;
public:
    static const int LOG_INFO = 1;
    static const int LOG_DEBUG = 2;
    static const int LOG_ERROR = 3;

    void setNextLogger(Logger *next)
    {
        next_in_chain = next;
    }

    void logMessage(int level, string msg)
    {
        if(level >= this->level)
            printLog(msg);
        
        else
            next_in_chain->logMessage(level, msg);
    }

    virtual void printLog(string msg) = 0;
};

class ConsoleLogger : public Logger{
public:
    ConsoleLogger(int lvl) { level = lvl; }
    void printLog(string msg)
    {
        cout<<time(0)<<" : Console : "<<msg<<"\n";
    }
};

class FileLogger : public Logger{
public:
    FileLogger(int lvl) { level = lvl; }
    void printLog(string msg)
    {
        cout<<time(0)<<" : File : "<<msg<<"\n";
    }
};

class ExceptionLogger : public Logger{
public:
    ExceptionLogger(int lvl) { level = lvl; }
    void printLog(string msg)
    {
        cout<<time(0)<<" : Exception : "<<msg<<"\n";
    }
};

Logger* getLoggerChain()
{
    ConsoleLogger *cl = new ConsoleLogger(Logger::LOG_INFO);
    FileLogger *fl = new FileLogger(Logger::LOG_DEBUG);
    ExceptionLogger *el = new ExceptionLogger(Logger::LOG_ERROR);

    //set chain of loggers
    el->setNextLogger(fl);
    fl->setNextLogger(cl);
    return el;
}

int main()
{   
    Logger *logging = getLoggerChain();

    logging->logMessage(1, "Basic info log.");
    logging->logMessage(2, "Wow, what a debug message :)");
    logging->logMessage(3, "Explosion in CPU!!!");

    return 0;
}