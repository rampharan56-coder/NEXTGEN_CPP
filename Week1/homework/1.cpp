#include <iostream>
#include <string>

struct Teacher
{
    std::string name;
};

struct Student
{
    std::string name;
    int id;
};

struct Course
{
    Teacher *teacher;
    Student *students[25];
    int studentCount;

    Course() : teacher(nullptr), studentCount(0)
    {
        for (int i = 0; i < 25; i++)
        {
            students[i] = nullptr;
        }
    }
};

void addTeacher(Course *course, Teacher *teacher)
{
    course->teacher = teacher;
}

bool addStudent(Course *course, Student *student)
{
    if (course->studentCount >= 25)
    {
        std::cout << "No more room!" << std::endl;
        return false;
    }
    course->students[course->studentCount] = student;
    course->studentCount++;
    return true;
}

void displayCourse(Course *course)
{
    if (course->teacher != nullptr)
    {
        std::cout << "Teacher: " << course->teacher->name << std::endl;
    }
    else
    {
        std::cout << "Teacher: (not assigned)" << std::endl;
    }
    std::cout << "Students: " << course->studentCount << "/25" << std::endl;

    for (int i = 0; i < course->studentCount; i++)
    {
        std::cout << " - " << course->students[i]->name
                  << " (id: " << course->students[i]->id << ")" << std::endl;
    }
}
int main()
{

    Teacher t1 = {"Mr. Ronan"};
    Teacher t2 = {"Mr. Rith"};
    Student s1, s2, s3;
    s1 = {"Alice", 1};
    s2 = {"Bob", 2};
    s3 = {"Chalie", 3};

    Course Computer_Science;
    addTeacher(&Computer_Science, &t1);
    addStudent(&Computer_Science, &s1);
    addStudent(&Computer_Science, &s2);
    addStudent(&Computer_Science, &s3);

    Course algebra;
    addTeacher(&algebra, &t2);
    addStudent(&algebra, &s1);
    addStudent(&algebra, &s2);
    addStudent(&algebra, &s3);

    displayCourse(&Computer_Science);
    displayCourse(&algebra);

    return 0;
}