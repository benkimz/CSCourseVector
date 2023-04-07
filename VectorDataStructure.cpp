#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Course {
  string courseNumber;
  string courseTitle;
  vector<string> prerequisites;
};

int main() {
  vector<Course> courses = {
    {"CS101", "Introduction to Computer Science", {}},
    {"CS201", "Data Structures and Algorithms", {"CS101"}},
    {"CS301", "Operating Systems", {"CS201"}},
    {"CS401", "Artificial Intelligence", {"CS201", "CS301"}}
  };

  // Accessing individual course information
  cout << "Course 1 Number: " << courses[0].courseNumber << endl;
  cout << "Course 2 Title: " << courses[1].courseTitle << endl;
  cout << "Course 4 Prerequisites: ";
  for (string preReq : courses[3].prerequisites) {
    cout << preReq << " ";
  }
  
  cout << endl;

  return 0;
}
