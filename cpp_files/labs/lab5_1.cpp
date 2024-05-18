#include <iostream>
using namespace std;
class student {
    string name;
    int age, grade;
    public:
        student(int age, int grade, string name){
            set_name(name);
            set_age(age);
            set_grade(grade);
        }
        void set_name(string name1){
            if (name1.size() == 0){
                name = "NAME";
            }
            else if (name1.size()<3){
                name = "Unknown";
            }
            else{
                name = name1;
            }
        }
        void set_age(int a){
            if (a < 5 || a>20){
                age = 5;
            }
            else{
                age = a;
            }
        }
        
        void set_grade(int g){
            if (g < 0 || g>100){
                grade = 50;
            }
            else{
                grade = g;
            }
        }

        void printStudentDetails(){
            cout << name << " of age " << age << " has grade " << grade << endl ;

        }

        bool isPassed(){
            bool passed = true;
            if (grade < 50)
                passed = false;
            return passed;

        }

        char getGrade (){
            char g = 'F';
            if (grade >= 85){
                g = 'A';
            }
            else if (grade >= 70){
                g = 'B';
            }

            else if (grade >= 50){
                g = 'C';
            }
            return g;
        }
};

int main(){
    student stu1(12,50,"hashir");
    stu1.printStudentDetails();
    cout << stu1.getGrade()<< endl;
    cout << stu1.isPassed() << endl;
    
}