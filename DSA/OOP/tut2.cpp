// Encapsulation: The concept of setting all the data members of a class as private.
// And only allow their access and modification through the specifies member functions,
// So the user has to obey the member functions.
#include<iostream>
#include<string>
#include<list>
#include<algorithm>

using namespace std;

class CollegeStudent{
private:
    string Name;
    int Sem;
    int Year;
    list<string> RegisteredCourses;
public:

    void set_name(string name){
        if(name==Name){
            cout<< "Name stored already.";
        }
        else{
            Name = name;
        }
    }

    void sem_passed(){
        if(++Sem % 2 == 1)
            Year++;
        if(Year >= 5)
            cout<< "Graduated";
    }
    
    void Add_Courses(list<string> RegisteringCourses){
        for(string str: RegisteringCourses)
            RegisteredCourses.push_back(str);
    }

    void Remove_Courses(list<string> rem_courses){
        for(string str: rem_courses)// find(container.begin, container.end, value) performs a linear search
            if(find(RegisteredCourses.begin(), RegisteredCourses.end(), str) != RegisteredCourses.end())
                RegisteredCourses.remove(str);
            else
                cout<< "Course: "<< str<< " is not currently registered"<< endl;
}

    void get_info(){
        cout<< "\nName: "<< Name<< endl;
        if(Year < 5)
            cout<< "Currently in Semester:"<< Sem<< ", Year: "<< Year<< endl;
        else 
            cout<< "Student Graduated"<< endl;
        cout<< "\nThe Registered Courses of the student are: \n";
        for(string str: RegisteredCourses)
            cout<< str<< endl;
          
    }

    CollegeStudent(string name, int semester, list<string> courses){
        Name = name;
        Sem = semester;
        Year = Sem/2;
        RegisteredCourses = courses;

        get_info();
    }

};

int main(){

    CollegeStudent B24CI1044("Piyush", 2, {"ElectromagnetismOptics", "Engineering Mechanics", "Mathematics I"});

    B24CI1044.Add_Courses({"Introduction to Computer Science", "Introduction to Electrical Engineering", "Mathematics II", "Introduction to Bioengineering"});
    B24CI1044.Remove_Courses({"ElectromagnetismOptics", "Engineering Mechanics", "Mathematics I", "Chemistry"});
    B24CI1044.get_info();
}