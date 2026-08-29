#include <iostream>
#include <string>

struct Student
{
    std::string  name;
    int score;
};

void printStudents(Student students[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "{\"" << students[i].name << "\", " << students[i].score << "}" << std::endl;;
    }
}

//  Insertion Sort
void insertionSortStable(Student *students, int n)
{
    for (int i = 1; i < n; i++)
    {
        Student temp = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].score > temp.score)
        {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = temp;
    }
}

//  Selection Sort
void selectionSortUnstable(Student students[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (students[j].score < students[minIndex].score)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            Student temp = students[i];
            students[i] = students[minIndex];
            students[minIndex] = temp;
        }
    }
}

void copyStudents(Student source[], Student dest[], int n)
{
    for (int i = 0; i < n; i++)
    {
        dest[i] = source[i];
    }
}

int main()
{
    Student students[] = {
        {"Alice", 3},
        {"Bob", 1},
        {"Chan", 3},
        {"Dara", 2}};
    int n = 4;

    Student temp[4];

    std::cout << "===== TASK 4: Stability Test =====" << std::endl;
    std::cout << "Original order:" << std::endl;
    printStudents(students, n);

    std::cout << "\n--- INSERTION SORT (STABLE) ---" << std::endl;
    copyStudents(students, temp, n);
    std::cout << "Before sorting:" << std::endl;
    printStudents(temp, n);

    insertionSortStable(temp, n);
    std::cout << "\nAfter sorting by score:" << std::endl;;
    printStudents(temp, n);
    std::cout << "\nAlice (score 3) stays before Chan (score 3)" << std::endl;;
    std::cout << "Because insertion sort never swaps equal elements!" << std::endl;;

    std::cout << "\n--- SELECTION SORT (UNSTABLE) ---" << std::endl;;
    copyStudents(students, temp, n);
    std::cout << "Before sorting:" << std::endl;;
    printStudents(temp, n);

    selectionSortUnstable(temp, n);
    std::cout << "\nAfter sorting by score:" << std::endl;;
    printStudents(temp, n);
    std::cout << "\nAlice (score 3) and Chan (score 3) may swap!" << std::endl;;
    std::cout << "Because selection sort swaps elements and can change the order of equals" << std::endl;;

    return 0;
}