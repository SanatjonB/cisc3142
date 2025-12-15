#include <string>
#include <vector>
#include <iostream>

class Student {
    private:
    std::string name;
    int id;
    double grade;

    public:
    Student(std::string name,int id,double grade):
    name(name), id(id),grade(grade){
        std::cout <<"Student "<< name<< "made"<<std::endl;
    };

    std::string getName()const {return name;};
    int getId()const {return id;};
    double getGrade()const {return grade;};
        // name = name;
        // id=id;
        // grade=grade;
    // ~Student(){
    //         std::cout<< "Student Object "<< name<< "destroyed"<<std::endl;
    // }
    // std::vector<Student> studentDatabase;

    // void addStudent(std::string name,int id,double grade){
    //     studentDatabase.push_back(Student(name,id,grade));
    // };
    // void displayStudents(){
    //     for(auto it = studentDatabase.begin(); it !=studentDatabase.end(); it++){
    //         const Student& s = *it;
    //         std::cout<<"Name: "<<s.name<<" Id: "<<s.id<<" Grade: "<<s.grade<<std::endl;
    //     }
    // };
    // void findStudent(int id){
    //     for(auto it = studentDatabase.begin();it != studentDatabase.end(); it++){
    //         const Student& s = *it;
    //         if(s.id==id){
    //             std::cout<<"Student Name "<<s.name<<" ID "<<s.id<< " Grade "<<s.grade<<std::endl; 
    //             return;
    //         }
    //     }
    //     std::cout<<"Student not found"<<std::endl;
    // }

};

void addStudent(std::vector<Student>& database ){
        std::string name;
        int id;
        double grade;
        std::cout<<"Enter Name "<<std::endl;
        std::cin>>name;

        std::cout<<"Enter Id "<<std::endl;
        std::cin>>id;

        std::cout<<"Enter Grade"<<std::endl;
        std::cin>>grade;

        database.push_back(Student(name,id,grade));
    };

void findStudent(const std::vector<Student>& database,int id){
        for(auto it=database.begin(); it !=database.end(); it++){
            if(it->getId()==id){
                std::cout<< "Name: " << it->getName()<< " ID: " << it->getId()<< " Grade: " << it->getGrade() << std::endl;// copied from the display all x
                return;
            }
        };
        std::cout<<"Student not found"<<std::endl;
    };



    void displayStudents(const std::vector<Student>& database){
        if(database.empty()){
            std::cout<<"Database is empty"<<std::endl;
            return;
        }
        for(auto it = database.begin(); it!= database.end(); it++){
            std::cout<< "Name: " << it->getName()<< " ID: " << it->getId()<< " Grade: " << it->getGrade() << std::endl;
        }
    };



int main(){
    std::vector<Student> studentDataBase;
    char choice;

    while(true){
        std::cout << "A  Add a new student to the database"<<std::endl;
        std::cout << "D  Display all students in the database"<<std::endl;
        std::cout << "F  Find a student by ID"<<std::endl;
        std::cout << "Q  Exit the program"<<std::endl;
        std::cin >> choice;

        switch(choice){
            case 'A':
            case 'a': {
                addStudent(studentDataBase);
                break;
            }
            case 'D':
            case 'd':
                displayStudents(studentDataBase);
                break;

            case 'F':
            case 'f': {
                int id;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                findStudent(studentDataBase,id);
                break;
            }

            case 'Q':
            case 'q':
                std::cout << "Exiting program"<<std::endl;
                return 0;

            default:
                std::cout << "Invalid option"<<std::endl;
        }
    }

    return 0;
}
