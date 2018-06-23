#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Employee{
 string  name;
 int     age;
 string  company;
 double  weight;
 friend ostream& operator << (ostream& output, const Employee& emp);
 friend istream& operator >> (istream& input, Employee& emp);
}; 


int main(){
    //antoinette.name = "Antoinette";
    //antoinette.age = 27;
    //antoinette.company = "SNG";
    //antoinette.weight =  3.4; 

    vector<Employee> employees;


    ifstream is("employees.txt");
    string name, company;
    int age;
    double weight;

    while(is >> name >> age >> company >> weight)
    {
        Employee antoinette;
        antoinette.name = name;
        antoinette.age = age;
        antoinette.company = company;
        antoinette.weight =  weight;
        employees.push_back(antoinette);
    }


    for(Employee emp: employees)
       cout << emp;

    //Employee antoinette;
    //cout << "Enter employee info" <<endl;
    //cin >> antoinette;
    //cout << antoinette;
    return 0;
}

ostream& operator << (ostream& output, const Employee& emp){
 output <<"Employee Information "<<endl
        <<"Name: "<< emp.name << endl
        <<"Age: "<< emp.age <<endl
        <<"Company: "<<emp.company<<endl
        <<"Weight: "<<emp.weight<<endl;
 return output;
}

istream& operator >> (istream& input, Employee& emp) {
  cout << "Employee name: ";
  input >> emp.name;
  cout << "Employee age: ";
  input >> emp.age;
  cout << "Employee Company: ";
  input >> emp.company;
  cout <<"Employee weight: ";
  input >> emp.weight;
}

