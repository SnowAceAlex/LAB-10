#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student
{
    int ID;
    char fullName[50];
    char dob[15];
    char department[30];
    float math, english, programming, average;
    int rank;
};

// Function prototypes
void inputData(struct Student *students, int *numStudents);
void outputStudentList(struct Student *students, int numStudents);
void sortStudentList(struct Student *students, int numStudents);
void searchStudent(struct Student *students, int numStudents);
void editStudentInfo(struct Student *students, int numStudents);
void removeStudent(struct Student *students, int *numStudents);
void exportDataToFile(struct Student *students, int numStudents);
void importDataFromFile(struct Student **students, int *numStudents);

int main()
{
    struct Student *students = NULL;
    int numStudents = 0;
    int option;

    do
    {
        printf("\nStudent Management\n");
        printf("1. Input data\n");
        printf("2. Output student list\n");
        printf("3. Sort student list\n");
        printf("4. Search student\n");
        printf("5. Edit student info\n");
        printf("6. Remove student from list\n");
        printf("7. Export data to file (optional)\n");
        printf("8. Import data from file (optional)\n");
        printf("0. Exit program\n");
        printf("Your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            inputData(students, &numStudents);
            break;
        case 2:
            outputStudentList(students, numStudents);
            break;
        case 3:
            sortStudentList(students, numStudents);
            break;
        case 4:
            searchStudent(students, numStudents);
            break;
        case 5:
            editStudentInfo(students, numStudents);
            break;
        case 6:
            removeStudent(students, &numStudents);
            break;
        case 7:
            exportDataToFile(students, numStudents);
            break;
        case 8:
            importDataFromFile(&students, &numStudents);
            break;
        case 0:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 0);

    // Free allocated memory before exiting
    free(students);

    return 0;
}

void inputData(struct Student *students, int *numStudents)
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for new students
    students = (struct Student *)realloc(students, (*numStudents + n) * sizeof(struct Student));

    for (int i = *numStudents; i < *numStudents + n; ++i)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        students[i].ID = i + 1;

        printf("Full Name: ");
        scanf(" %[^\n]s", students[i].fullName);

        printf("Date of Birth: ");
        scanf(" %[^\n]s", students[i].dob);

        printf("Department: ");
        scanf(" %[^\n]s", students[i].department);

        printf("Math score: ");
        scanf("%f", &students[i].math);

        printf("English score: ");
        scanf("%f", &students[i].english);

        printf("Programming score: ");
        scanf("%f", &students[i].programming);

        // Calculate average and rank
        students[i].average = (students[i].math + students[i].english + students[i].programming) / 3.0;
        students[i].rank = 0; // Initialize rank (can be updated later)

        printf("Data for student %d entered successfully.\n", i + 1);
    }

    *numStudents += n;
}

void outputStudentList(struct Student *students, int numStudents)
{
    if (numStudents == 0)
    {
        printf("No students in the list.\n");
        return;
    }

    printf("\nStudent List:\n");
    printf("ID\tFull Name\t\t\tDOB\t\tDepartment\tMath\tEnglish\tProgramming\tAverage\tRank\n");
    for (int i = 0; i < numStudents; ++i)
    {
        printf("%d\t%-25s\t%s\t%-15s\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n", students[i].ID, students[i].fullName,
               students[i].dob, students[i].department, students[i].math, students[i].english,
               students[i].programming, students[i].average, students[i].rank);
    }
}

// Function to compare students for sorting
int compareStudents(const void *a, const void *b)
{
    return strcmp(((struct Student *)a)->fullName, ((struct Student *)b)->fullName);
}

void sortStudentList(struct Student *students, int numStudents)
{
    if (numStudents == 0)
    {
        printf("No students in the list.\n");
        return;
    }

    int sortOption;
    printf("\nSort Options:\n");
    printf("1. Sort in alphabetical order of student name\n");
    printf("2. Sort in decreasing order of Average\n");
    printf("Enter sort option: ");
    scanf("%d", &sortOption);

    switch (sortOption)
    {
    case 1:
        qsort(students, numStudents, sizeof(struct Student), compareStudents);
        printf("Student list sorted in alphabetical order of student name.\n");
        break;
    case 2:
        // Implement sorting by Average (you can use qsort or any other sorting algorithm)
        // For simplicity, let's use bubble sort here
        for (int i = 0; i < numStudents - 1; ++i)
        {
            for (int j = 0; j < numStudents - i - 1; ++j)
            {
                if (students[j].average < students[j + 1].average)
                {
                    // Swap students
                    struct Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        printf("Student list sorted in decreasing order of Average.\n");
        break;
    default:
        printf("Invalid sort option.\n");
    }
}

void searchStudent(struct Student *students, int numStudents)
{
    if (numStudents == 0)
    {
        printf("No students in the list.\n");
        return;
    }

    char searchName[50];
    printf("\nEnter the name of the student to search: ");
    scanf(" %[^\n]s", searchName);

    // Linear search for simplicity
    for (int i = 0; i < numStudents; ++i)
    {
        if (strcmp(students[i].fullName, searchName) == 0)
        {
            printf("Student found:\n");
            printf("ID\tFull Name\t\t\tDOB\t\tDepartment\tMath\tEnglish\tProgramming\tAverage\tRank\n");
            printf("%d\t%-25s\t%s\t%-15s\t%.2f\t%.2f\t%.2f\t%.2f\t%d\n", students[i].ID, students[i].fullName,
                   students[i].dob, students[i].department, students[i].math, students[i].english,
                   students[i].programming, students[i].average, students[i].rank);
            return;
        }
    }

    printf("Student not found with the name: %s\n", searchName);
}

void editStudentInfo(struct Student *students, int numStudents)
{
    if (numStudents == 0)
    {
        printf("No students in the list.\n");
        return;
    }

    int editID;
    printf("\nEnter the ID of the student to edit: ");
    scanf("%d", &editID);

    for (int i = 0; i < numStudents; ++i)
    {
        if (students[i].ID == editID)
        {
            printf("Enter new details for student %d:\n", editID);

            printf("Full Name: ");
            scanf(" %[^\n]s", students[i].fullName);

            printf("Date of Birth: ");
            scanf(" %[^\n]s", students[i].dob);

            printf("Department: ");
            scanf(" %[^\n]s", students[i].department);

            printf("Math score: ");
            scanf("%f", &students[i].math);

            printf("English score: ");
            scanf("%f", &students[i].english);

            printf("Programming score: ");
            scanf("%f", &students[i].programming);

            // Recalculate average and rank
            students[i].average = (students[i].math + students[i].english + students[i].programming) / 3.0;
            // Rank may need to be updated based on the new average
            // You can implement a function to re-calculate ranks if needed

            printf("Data for student %d updated successfully.\n", editID);
            return;
        }
    }

    printf("Student not found with ID: %d\n", editID);
}

void removeStudent(struct Student *students, int *numStudents)
{
    if (*numStudents == 0)
    {
        printf("No students in the list.\n");
        return;
    }

    int removeID;
    printf("\nEnter the ID of the student to remove: ");
    scanf("%d", &removeID);

    int removeIndex = -1;
    for (int i = 0; i < *numStudents; ++i)
    {
        if (students[i].ID == removeID)
        {
            removeIndex = i;
            break;
        }
    }

    if (removeIndex != -1)
    {
        // Shift elements to fill the gap
        for (int i = removeIndex; i < *numStudents - 1; ++i)
        {
            students[i] = students[i + 1];
        }

        // Resize the array to remove the last element
        students = (struct Student *)realloc(students, (*numStudents - 1) * sizeof(struct Student));

        *numStudents -= 1;

        printf("Student with ID %d removed successfully.\n", removeID);
    }
    else
    {
        printf("Student not found with ID: %d\n", removeID);
    }
}

void exportDataToFile(struct Student *students, int numStudents)
{
    // Implement exporting data to a file (optional)
    // You can use file I/O functions (e.g., fopen, fprintf, fclose)
}

void importDataFromFile(struct Student **students, int *numStudents)
{
    // Implement importing data from a file (optional)
    // You can use file I/O functions (e.g., fopen, fscanf, fclose)
    // Make sure to free the existing memory before reading new data
}
