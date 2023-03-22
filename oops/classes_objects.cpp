#include <iostream>
using namespace std;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee
{
    private:
        string Company;
        int Age;
    // protected:
        string Name;

    public:
        string getName(){
            return Name;
        }
        void setName(string name){
            Name = name;
        }
        void IntroduceYourself()
        {
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
        }
        Employee(string name, string company, int age)
        {
            Name = name;
            Company = company;
            Age = age;
        }
        void AskForPromotion(){
            if(Age >30)
                cout <<Name  << " u r promoted"<<endl;
            else 
                cout <<Name << " no promotion for u"<<endl;       
        }
        virtual void work(){
            cout << Name <<" is checking emails..."<<endl;
        }
};

class Developer:public Employee{
    public:
        string favLang;
        Developer(string name, string company, int age,string favLang)
        :Employee(name,company,age){
            favLang=favLang;
        };
        void fixBug(){
            cout << getName() << " - fixed the bug" <<endl;
        }  
        // polymorphism
        void work(){
            cout << getName() <<" is writting code in " <<favLang <<endl;
        }
};

int main()
{
    Employee emp1 = Employee("jaswanth", "google", 20);
    Employee emp2 = Employee("john", "amazon", 35);

    // emp1.AskForPromotion();
    // emp2.AskForPromotion();

    Developer d = Developer("jaswanth", "google", 20,"c++");
    d.AskForPromotion();
    d.fixBug();
    Employee* e1 = &d;
    e1->work();
    // emp1.setName("jas");
    // emp1.IntroduceYourself();


    // emp1.Name = "jaswanth";
    // emp1.Company = "Google";
    // emp1.Age = 20;
}