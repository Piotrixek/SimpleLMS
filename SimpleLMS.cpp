#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Lesson {
public:
    string title;
    string content;

    Lesson(const string& lessonTitle, const string& lessonContent)
        : title(lessonTitle), content(lessonContent) {}
};

class Assignment {
public:
    string title;
    string description;

    Assignment(const string& assignmentTitle, const string& assignmentDescription)
        : title(assignmentTitle), description(assignmentDescription) {}
};

class Course {
public:
    string title;
    vector<Lesson> lessons;
    vector<Assignment> assignments;
    vector<string> enrolledStudents;
    map<string, vector<string>> discussionForum;

    Course(const string& courseTitle)
        : title(courseTitle) {}

    void addLesson(const Lesson& lesson) {
        lessons.push_back(lesson);
    }

    void addAssignment(const Assignment& assignment) {
        assignments.push_back(assignment);
    }

    void enrollStudent(const string& student) {
        enrolledStudents.push_back(student);
        // Automatically subscribe the student to the course's discussion forum
        discussionForum[student] = vector<string>();
    }

    void postToDiscussionForum(const string& username, const string& message) {
        discussionForum[username].push_back(message);
    }
};

class LearningManagementSystem {
private:
    vector<Course> courses;

public:
    void createCourse(const string& courseTitle) {
        courses.push_back(Course(courseTitle));
    }

    void displayCourses() const {
        cout << "Available Courses:" << endl;
        for (const auto& course : courses) {
            cout << "- " << course.title << endl;
        }
    }

    Course* findCourse(const string& courseTitle) {
        for (auto& course : courses) {
            if (course.title == courseTitle) {
                return &course;
            }
        }
        return nullptr;
    }

    void displayCourseDetails(const Course& course) const {
        cout << "Course Title: " << course.title << endl;
        cout << "Lessons:" << endl;
        for (const auto& lesson : course.lessons) {
            cout << "  - " << lesson.title << endl;
        }
        cout << "Assignments:" << endl;
        for (const auto& assignment : course.assignments) {
            cout << "  - " << assignment.title << endl;
        }
    }
};

int main() {
    LearningManagementSystem lms;

    // Create courses
    lms.createCourse("Introduction to Programming");
    lms.createCourse("Web Development Basics");

    // Enroll students
    Course* programmingCourse = lms.findCourse("Introduction to Programming");
    if (programmingCourse) {
        programmingCourse->enrollStudent("Alice");
        programmingCourse->enrollStudent("Bob");
    }

    // Add lessons and assignments
    if (programmingCourse) {
        programmingCourse->addLesson(Lesson("Introduction to C++", "C++ basics and syntax."));
        programmingCourse->addLesson(Lesson("Control Flow", "If statements, loops, and switches."));
        programmingCourse->addAssignment(Assignment("Programming Exercise 1", "Write a simple program."));
        programmingCourse->addAssignment(Assignment("Programming Exercise 2", "Implement a more complex feature."));
    }

    // Display course details
    lms.displayCourseDetails(*programmingCourse);

    // Display available courses
    lms.displayCourses();

    return 0;
}
