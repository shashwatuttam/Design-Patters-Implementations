#include<bits/stdc++.h>
using namespace std;

class Employee{
protected:
    int empID, salary;
    string name;
public:
    Employee(int id, string name, int salary) : empID(id), salary(salary), name(name) {}
    int getEmpID() { return empID; }
    string getName() { return name; }

    virtual string getEmployeeDetails(int lvl=1)
    {
        return "Employee: "+ name + "(" + to_string(empID) + ") has salary " + to_string(salary) + " LPA\n";
    }
};

class Engineer : public Employee{
    string primary_language;
public:
    Engineer(int id, string name, int salary, string lang) : Employee(id,name,salary), primary_language(lang) {}

    string getEmployeeDetails(int lvl=1)
    {
        return "Engineer: "+ name + "(" + to_string(empID) + ") has salary " + to_string(salary) + " LPA\n";
    }
};

class HR : public Employee{
    int no_of_emp_handled;
public:
    HR(int id, string name, int salary, int n) : Employee(id,name,salary), no_of_emp_handled(n) {}

    string getEmployeeDetails(int lvl=1)
    {
        return "HR: "+ name + "(" + to_string(empID) + ") has salary " + to_string(salary) + " LPA\n";
    }
};

class EmployeeComposition : public Employee{
    vector<Employee*> emp_list;
public:
    EmployeeComposition(string name) : Employee(0,name,0){}

    string getEmployeeDetails(int lvl=1)
    {
        string res = "Employees in "+ name + " org : \n";
        for(int i=0; i<emp_list.size(); i++)
        {
            for(int j=0; j<lvl; j++)
                res+="   ";
            res += emp_list[i]->getEmployeeDetails(lvl+1);
        }
        return res;
    }

    void add(Employee *e)
    {
        emp_list.push_back(e);
    }

    void remove(int emp_id)
    {
        int i;
        for(i=0; i<emp_list.size(); i++)
        {
            if(emp_list[i]->getEmpID()==emp_id)
                break;
        }
        if(i<emp_list.size())
            emp_list.erase(emp_list.begin()+i);
        else
            cout<<"Employee "<<emp_id<<"to be removed not found!\n";
    }
};

int main()
{
    Employee CEO(1,"Sashi",150);
    Employee ceo_assistant(2,"Priya", 6);
    Engineer e1(3, "Shashwat", 15, "C++");
    Engineer e2(4, "Vineet", 22, "Java");
    HR h1(5, "Kavita", 5, 1);
    HR h2(6, "Savita", 6, 2);

    EmployeeComposition engineer_org("Engineers");
    engineer_org.add(&e1);
    engineer_org.add(&e2);

    EmployeeComposition hr_org("HRs");
    hr_org.add(&h1);
    hr_org.add(&h2);

    EmployeeComposition company_org("Company");
    company_org.add(&CEO);
    company_org.add(&ceo_assistant);
    company_org.add(&engineer_org);
    company_org.add(&hr_org);

    cout<<company_org.getEmployeeDetails();

    return 0;
}