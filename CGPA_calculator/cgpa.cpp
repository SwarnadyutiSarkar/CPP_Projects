#include <iostream>
#include <vector>

// Function to convert grade to point
int gradeToPoint(char grade) {
    switch(grade) {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 4;
        case 'E': return 2;
        case 'F': return 0;
        default: return -1; // Invalid grade
    }
}

int main() {
    int numCourses;
    std::cout << "Enter the number of courses: ";
    std::cin >> numCourses;

    std::vector<char> grades(numCourses);
    std::vector<int> credits(numCourses);

    // Input grades and credits for each course
    for (int i = 0; i < numCourses; ++i) {
        std::cout << "Enter grade for course " << i + 1 << " (A/B/C/D/E/F): ";
        std::cin >> grades[i];
        
        std::cout << "Enter credit for course " << i + 1 << ": ";
        std::cin >> credits[i];
    }

    int totalCredits = 0;
    float weightedSum = 0.0;

    // Calculate weighted sum of grades
    for (int i = 0; i < numCourses; ++i) {
        int point = gradeToPoint(grades[i]);
        if (point == -1) {
            std::cout << "Invalid grade entered!" << std::endl;
            return 1;
        }
        weightedSum += point * credits[i];
        totalCredits += credits[i];
    }

    // Calculate CGPA
    float cgpa = weightedSum / totalCredits;

    std::cout << "Your CGPA is: " << cgpa << std::endl;

    return 0;
}
