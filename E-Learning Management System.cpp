#include <iostream>
#include <vector>
#include <string>

class Course {
public:
    std::string title;
    std::string instructor;

    Course(std::string courseTitle, std::string courseInstructor) 
        : title(courseTitle), instructor(courseInstructor) {}
};

class ELearningSystem {
private:
    std::vector<Course> courses;

public:
    void addCourse(const std::string& title, const std::string& instructor) {
        courses.emplace_back(title, instructor);
        std::cout << "Course '" << title << "' added." << std::endl;
    }

    void showCourses() {
        std::cout << "Available Courses:" << std::endl;
        for (const auto& course : courses) {
            std::cout << "Title: " << course.title << ", Instructor: " << course.instructor << std::endl;
        }
    }
};

int main() {
    ELearningSystem system;
    system.addCourse("C++ Programming", "Dr. Smith");
    system.addCourse("Data Structures", "Prof. Johnson");

    system.showCourses();
    return 0;
}
