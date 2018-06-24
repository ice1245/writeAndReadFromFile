#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

using namespace std;

struct Employee{
 string  name;
 int     age;
 string  company;
 double  weight;
 bool    paid;
 string paymentDate; //Will be nil until employee is paid 
}; 

//Printing Employee to console 
ostream& operator << (ostream& output, const Employee& emp){
 output <<"Employee Information: "<<endl
        <<"Name: "<< emp.name << endl
        <<"Age: "<< emp.age <<endl
        <<"Company: "<<emp.company<<endl
        <<"Weight: "<<emp.weight<<endl
        <<"Paid: "<<emp.paid<<endl
        <<"PayDate: "<<emp.paymentDate<<endl
        <<"========================="<<endl;
 return output;
}

//Employee input from istringstream
istream& operator >> (istream& input, Employee& emp) {
  input >> emp.name >> emp.age >> emp.company >> emp.weight;
}

// PayEmployees 
void processEmployees(vector<Employee>& employees, const function<void(Employee&)>& pay,  const function<void(Employee&)>& writeToFile){
     for (Employee emp: employees) {
         pay(emp);
         writeToFile(emp);
     }
}


int main(){
    vector<Employee> employees;
string  Inputfilename = "payroll/assets/employees.txt";
    //string Inputfilename = "/home/godfreys/Documents/Development/docker/c++/github/writeAndReadFromFile/payroll/data/employees.txt";
    string processedEmployees = "processedEmployees.txt";

    ifstream in(Inputfilename.c_str());
    if(!in){
        cerr << "Cannot open the file " <<Inputfilename<<endl;
        return -1;
    }
    string line;
    Employee emp;
    while(getline(in, line))
    {
        if(line.size() > 0){
            istringstream iss (line);
            iss >> emp;
            emp.paid = false;
            employees.push_back(emp);
        }
    }

    // Printing to console
    for (Employee emp: employees)
        cout << emp;
   
    // Preparing ofstream for writting employees to file
    ofstream out;
    out.open(processedEmployees);
    if(!out){
        cerr << "Cannot open the file" <<processedEmployees<<endl;
    }    
    
    //functions to process the Employee
    auto payEmployee = [](Employee& emp)-> Employee{emp.paid = true; return emp;};
    auto writeEmployeeToFile = [&](Employee& emp) {out << emp;};

    //Processing the employing using helper lambda functions above 
    processEmployees(employees,payEmployee, writeEmployeeToFile); 

    return 0;
}







