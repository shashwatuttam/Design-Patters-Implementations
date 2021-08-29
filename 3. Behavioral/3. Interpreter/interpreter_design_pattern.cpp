#include<bits/stdc++.h>
using namespace std;

// Base interface
class Expression{
public:
    virtual bool interpret(string context) = 0;
};

// Class for variables/terminals i.e. names in this case
// return true is context contains the stored data
class TerminalExpression : public Expression{
    string data;
public:
    TerminalExpression(string s) : data(s){}
    bool interpret(string context)
    {
        return (context.find(data) != string::npos);
    }
};


// Class for non terminal OR, return true if context contains e1 or e2
class OrExpression : public Expression{
    Expression *e1;
    Expression *e2;
public:
    OrExpression(Expression *e1, Expression *e2) : e1(e1), e2(e2) {}

    bool interpret(string context)
    {
        return e1->interpret(context) || e2->interpret(context);
    }
};

// Class for non terminal AND, return true if context contains e1 and e2
class AndExpression : public Expression{
    Expression *e1;
    Expression *e2;
public:
    AndExpression(Expression *e1, Expression *e2) : e1(e1), e2(e2) {}

    bool interpret(string context)
    {
        return e1->interpret(context) && e2->interpret(context);
    }
};

int main()
{
    Expression *term1 = new TerminalExpression("Shashwat");
    Expression *term2 = new TerminalExpression("Meemansak");
    Expression *term3 = new TerminalExpression("Vineet");

    Expression *fromRMS_OR = new OrExpression(term1, term2);
    Expression *fromRMS_AND = new AndExpression(term1, term2);
    cout<< "Is meemansak, or shashwat from RMS ? : " <<fromRMS_OR->interpret("Meemansak, Shashwat") <<"\n";
    cout<< "Are both meemansak and shashwat from RMS ? : " << fromRMS_AND->interpret("Meemansak Shashwat") <<"\n";

    Expression *engineer_OR = new OrExpression(term1, term3);
    Expression *engineer_AND = new AndExpression(term1, term3);
    cout<<"Is any of meemansak or shashwat an engineer? : "<< engineer_OR->interpret("Meemansak, Shashwat") <<"\n";
    cout<<"Are both meemansak and shashwat engineers? : "<< engineer_AND->interpret("Meemansak, Shashwat") <<"\n";

    return 0;
}