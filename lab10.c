#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char id[100];
    char fname[100];
    char department[100];
    char dob[100];
    int math, english, programming;
    float avg;
    int rank;
} st[55];

int count; // use to count the total number of student

void inputStudentData();
void outputStudentList();

int main()
{
    int choice;
    do
    {
        printf("====\n");
        printf("1. Input data\n");
        printf("2. Ouput student list\n");
        printf("3. Sort student list\n");
        printf("4. Search student list\n");
        printf("5. Edit student info\n");
        printf("6. Remove student from list\n");
        printf("7. Export data to file\n");
        printf("8. Import data from file\n");
        printf("0. Exit program\n");
        printf("====\n");

        printf("Your option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputStudentData();
            break;
        case 2:
            outputStudentList();
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }

    } while (choice != 0);

    return 0;
}

void inputStudentData()
{

    printf("Add the Students Details\n");
    printf("-------------------------\n");

    printf("Enter the ID: ");
    scanf("%s", &st[count].id);
    getchar();
    printf("ID Information Added\n");

    printf("\nEnter the full name of student: ");
    scanf("%[^\n]", &st[count].fname);
    getchar();
    printf("Name Information Added\n");

    printf("\nEnter the date of birth: ");
    scanf("%s", &st[count].dob);
    printf("Date of Birth Information Added\n");

    printf("\nEnter your department: ");
    scanf("%s", &st[count].department);
    printf("Department Information Added\n");

    printf("\nEnter your scores (Math English Programming): ");
    scanf("%d %d %d", &st[count].math, &st[count].english, &st[count].programming);
    printf("Score Information Added\n");

    count++;
}

void outputStudentList()
{
    for (int i = 0; i < count; i++)
    {
        printf("No. %d\n", i + 1);
        printf("ID: %s\n", st[i].id);
        printf("Full Name: %s\n", st[i].fname);
        printf("Date of Birth: %s\n", st[i].dob);
        printf("Department: %s\n", st[i].department);
        printf("Score:\nMath: %d\nEnglish: %d\nProgramming: %d\n", st[i].math, st[i].english, st[i].programming);
        printf("\n");
    }
    printf("\n");
}