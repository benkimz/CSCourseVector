#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Course {
  string courseNumber;
  string courseTitle;
  vector<string> prerequisites;
};

void readCoursesFile(string filePath, vector<Course>& courses);

int main() {

  vector<Course> courses;

  string filePath = "sample-courses.txt";

  readCoursesFile(filePath, courses);

  for (const Course& c : courses) {
    cout << c.courseNumber << ": " << c.courseTitle << endl;
    if (!c.prerequisites.empty()) {
      cout << "Prerequisites: ";
      for (const string& p : c.prerequisites) {
        cout << p << " ";
      }
      cout << endl;
    }
  }

  return 0;
}

void readCoursesFile(string filePath, vector<Course>& courses) {
  ifstream coursesFile(filePath);
  if (coursesFile.is_open()) {
    string line;
    while (getline(coursesFile, line)) {
      stringstream ss(line);
      string courseNumber, courseTitle, prerequisite;
      vector<string> prerequisites;

      if (!getline(ss, courseNumber, ',')) {
        cout << "Invalid line: " << line << endl;
        continue;
      }
      if (!getline(ss, courseTitle)) {
        cout << "Invalid line: " << line << endl;
        continue;
      }

      while (getline(ss, prerequisite, ',')) {
        prerequisite.erase(0, prerequisite.find_first_not_of(" "));
        prerequisite.erase(prerequisite.find_last_not_of(" ") + 1);

        bool found = false;
        for (Course& c : courses) {
          if (c.courseNumber == prerequisite) {
            prerequisites.push_back(prerequisite);
            found = true;
            break;
          }
        }
        if (!found) {
          bool isCourseNumber = true;
          for (char& c : prerequisite) {
            if (!isdigit(c)) {
              isCourseNumber = false;
              break;
            }
          }
          if (isCourseNumber) {
            cout << "Invalid prerequisite: " << prerequisite << " in line: " << line << endl;
          }
        }
      }

      courses.push_back({courseNumber, courseTitle, prerequisites});
    }
  } else {
    cout << "Unable to open courses file: " << filePath << endl;
  }
}
