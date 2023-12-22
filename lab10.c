#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char id[100];
    char fname[100];
    char department[100];
    char dob[100];
    float avg, math, english, programming;
    char rank[100];
} st[55];

int count; // use to count the total number of student

void inputStudentData();
void studentRanking();
void outputStudentList();
void alphabetSorted();
void avgScoreSorted();
void searchStudentName();
void searchStudentId();
void editStudentInfo();
void deleteStudent();

int main()
{
    struct Student *st = NULL;
    int choice, choice2, choice3;
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
            studentRanking();
            break;
        case 2:
            outputStudentList();
            break;
        case 3:

            printf("Enter your choice(1-Alphabet Sorted  2- Score Decreasing Sorted): ");
            scanf("%d", &choice2);

            switch (choice2)
            {
            case 1:
                alphabetSorted();
                break;
            case 2:
                avgScoreSorted();
                break;
            }

            break;
        case 4:
            printf("Enter your choice(1-Finding via name  2-Finding via ID): ");
            scanf("%d", &choice3);

            switch (choice3)
            {
            case 1:
                searchStudentName();
                break;
            case 2:
                searchStudentId();
                break;
            }
            break;
        case 5:
            editStudentInfo();
            studentRanking();
            break;
        case 6:
            deleteStudent();

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
    scanf("%f %f %f", &st[count].math, &st[count].english, &st[count].programming);
    printf("Score Information Added\n");

    st[count].avg = (st[count].math + st[count].english + st[count].programming) / 3;

    count++;
}

void studentRanking() // not done
{
    for (int i = 0; i < count; i++)
    {
        if (st[i].avg > 90)
        {
            strcpy(st[i].rank, "A+");
        }
        else if (st[i].avg > 80)
        {
            strcpy(st[i].rank, "A");
        }
        else if (st[i].avg > 70)
        {
            strcpy(st[i].rank, "B+");
        }
        else if (st[i].avg > 60)
        {
            strcpy(st[i].rank, "B");
        }
        else if (st[i].avg > 50)
        {
            strcpy(st[i].rank, "B-");
        }
        else if (st[i].avg > 40)
        {
            strcpy(st[i].rank, "D");
        }
        else if (st[i].avg > 0 && st[i].avg < 40)
        {
            strcpy(st[i].rank, "F");
        }
    }
}

void outputStudentList()
{
    for (int i = 0; i < count; i++)
    {
        printf("ID: %s\n", st[i].id);
        printf("Full Name: %s\n", st[i].fname);
        printf("Date of Birth: %s\n", st[i].dob);
        printf("Department: %s\n", st[i].department);
        printf("Score:\nMath: %f\nEnglish: %f\nProgramming: %f\n", st[i].math, st[i].english, st[i].programming);
        printf("Average score: %f\n", st[i].avg);
        printf("Rank: %s\n", st[i].rank);
        printf("\n");
    }
    printf("\n");
}

void alphabetSorted()
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(st[i].fname, st[j].fname) > 0)
            {
                struct Student temp = st[j];
                st[j] = st[i];
                st[i] = temp;
            }
        }
    }
}

void avgScoreSorted()
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (st[i].avg < st[j].avg)
            {
                struct Student temp = st[j];
                st[j] = st[i];
                st[i] = temp;
            }
        }
    }
}

void searchStudentName()
{
    if (count == 0)
    {
        printf("No students in the list.\n");
        return;
    }
    char searchName[50];
    printf("\nEnter the name of the student to search: ");
    scanf(" %[^\n]s", searchName);

    for (int i = 0; i < count; ++i)
    {
        if (strcmp(st[i].fname, searchName) == 0)
        {
            printf("Student found:\n");
            printf("ID: %s\n", st[i].id);
            printf("Full Name: %s\n", st[i].fname);
            printf("Date of Birth: %s\n", st[i].dob);
            printf("Department: %s\n", st[i].department);
            printf("Score:\nMath: %f\nEnglish: %f\nProgramming: %f\n", st[i].math, st[i].english, st[i].programming);
            printf("Average score: %f\n", st[i].avg);
            printf("Rank: %s\n", st[i].rank);
            printf("\n");
            return;
        }
    }
    printf("Student not found with the name: %s\n", searchName);
}

void searchStudentId()
{
    if (count == 0)
    {
        printf("No students in the list.\n");
        return;
    }
    char searchId[50];
    printf("\nEnter the ID of the student to search: ");
    scanf("%s", searchId);

    for (int i = 0; i < count; ++i)
    {
        if (strcmp(st[i].id, searchId) == 0)
        {
            printf("Student found:\n");
            printf("ID: %s\n", st[i].id);
            printf("Full Name: %s\n", st[i].fname);
            printf("Date of Birth: %s\n", st[i].dob);
            printf("Department: %s\n", st[i].department);
            printf("Score:\nMath: %f\nEnglish: %f\nProgramming: %f\n", st[i].math, st[i].english, st[i].programming);
            printf("Average score: %f\n", st[i].avg);
            printf("Rank: %s\n", st[i].rank);
            printf("\n");
            return;
        }
    }
    printf("Student not found with the ID: %s\n", searchId);
}

void editStudentInfo()
{
    if (count == 0)
    {
        printf("No students in the list.\n");
        return;
    }

    char editId[50];
    printf("\nEnter the ID of the student to edit: ");
    scanf("%s", &editId);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(st[i].id, editId) == 0)
        {
            printf("Enter new details for student %s:\n", editId);

            printf("Enter the ID: ");
            scanf("%s", &st[i].id);
            getchar();
            printf("ID Information Added\n");

            printf("\nEnter the full name of student: ");
            scanf("%[^\n]", &st[i].fname);
            getchar();
            printf("Name Information Added\n");

            printf("\nEnter the date of birth: ");
            scanf("%s", &st[i].dob);
            printf("Date of Birth Information Added\n");

            printf("\nEnter your department: ");
            scanf("%s", &st[i].department);
            printf("Department Information Added\n");

            printf("\nEnter your scores (Math English Programming): ");
            scanf("%f %f %f", &st[i].math, &st[i].english, &st[i].programming);
            printf("Score Information Added\n");

            st[i].avg = (st[i].math + st[i].english + st[i].programming) / 3;

            printf("Data for student %s updated successfully.\n", editId);
            return;
        }
    }

    printf("Student not found with ID: %s\n", editId);
}

void deleteStudent()
{
    if (count == 0)
    {
        printf("No students in the list.\n");
        return;
    }

    char removeId[50];
    printf("\nEnter the ID of the student to delete: ");
    scanf("%s", &removeId);
    printf("%s", removeId);

    int removeIndex = -1;
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(st[i].id, removeId) == 0)
        {
            removeIndex = i;
            break;
        }
    }

    if (removeIndex != -1)
    {
        // Shift elements to fill the gap
        for (int i = removeIndex; i < count - 1; ++i)
        {
            st[i] = st[i + 1];
        }

        count -= 1;

        printf("Student with ID %s removed successfully.\n", removeId);
    }
    else
    {
        printf("Student not found with ID: %s\n", removeId);
    }
}