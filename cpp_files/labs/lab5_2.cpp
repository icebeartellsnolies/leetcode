#include <iostream>
using namespace std;

class course{
    string  courseName;
    int courseCode, credits;

    public:
        course(string courseName, int courseCode, int credits){
            set_name(courseName);
            set_code(courseCode);
            set_credits(credits);
        }

        void set_name(string c_name){
            if (c_name.size() == 0){
                courseName = "COURSE";
            }
            else{
                courseName = c_name;
            }
        }
        void set_code(int c_code){
            if (c_code < 0){
                courseCode = 0;
            }
            else{
                courseCode = c_code;
            }
        }

        void set_credits(int cred){
            if (cred < 1 || cred > 3){
                credits = 1;
            }
            else{
                credits = cred;
            }
        }
        void printCourseDetails(){
            cout << "course name: " << courseName << " course code: " << courseCode << " credits: " << credits << endl;
        }
        bool isGreater(const course &another_course){
            if (credits > another_course.credits){
                return true;
            }
            else{
                return false;
            }
        }
}; 

int main(){
    course c1("PF", 01,2);
    c1.printCourseDetails();
    course c2("oop", 55, 3);
    cout <<c1.isGreater(c2) << endl ;
}