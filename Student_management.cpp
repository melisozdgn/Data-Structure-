#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Student {  
  public:
    // Constructor to initialize student with random id and class number
    Student() {
      //ID randomly between 1000 and 3999
      this->id = 1000 * (1 + rand() % 3) + rand() % 999;
      //// randomly between 1000 and 3999
      this->studentClass = 1 + rand() % 4;
    }

    int getId() const {
      return id;
    }

    int getStudentClass() const {
      return studentClass;
    }

    // Overload 
    friend ostream& operator<<(ostream& os, const Student& student) {
      os << setw(5) << student.getId() << " - Class: " << setw(2) << std::right << student.getStudentClass();
      // Allows the use of chained operators
      return os;
    }

  private:
    int id;
    int studentClass; 
};
// Define a function that takes an array of Student objects and prints this array to the screen
void printArray(Student** arr, int numStudent) {
  cout << setw(8) << std::left << "Index" << " Student Info" << endl;
  for(int i = 0; i < numStudent; i++) {
    cout << setw(8) << std::left << "array[" << i << "] " << *arr[i] << endl;
  }
}

int main() {
  int numStudent = 10;
  Student** studentList = new Student*[numStudent];

  for (int i = 0; i < numStudent; i++) {
    studentList[i] = new Student();
  }

  printArray(studentList, numStudent);

  
  for (int i = 0; i < numStudent; i++) {
    //prevents memory leak
    delete studentList[i];
  }
  delete[] studentList;

  return 0;
}
