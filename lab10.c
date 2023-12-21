#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char id[100];
    char fname[100];
    char department[100];
    char dob[100];
    float avg, math, english, programming;
    int rank;
} st[55];

int count; // use to count the total number of student

void inputStudentData();
void studentRanking();
void outputStudentList();
void alphabetSorted();
void avgScoreSorted();

int main()
{
    int choice, choice2;
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
    st[count].rank = 0;

    count++;
}

void studentRanking() // not done
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (st[i].avg < st[j].avg)
            {
                st[i].rank++;
            }
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
        printf("Rank: %d\n", st[i].rank);
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
                char temp[100];
                strcpy(temp, st[i].fname);
                strcpy(st[i].fname, st[j].fname);
                strcpy(st[j].fname, temp);

                strcpy(temp, st[i].id);
                strcpy(st[i].id, st[j].id);
                strcpy(st[j].id, temp);

                strcpy(temp, st[i].department);
                strcpy(st[i].department, st[j].department);
                strcpy(st[j].department, temp);

                strcpy(temp, st[i].dob);
                strcpy(st[i].dob, st[j].dob);
                strcpy(st[j].dob, temp);

                int temp2 = 0;
                temp2 = st[i].math;
                st[i].math = st[j].math;
                st[j].math = temp2;

                temp2 = st[i].english;
                st[i].english = st[j].english;
                st[j].english = temp2;

                temp2 = st[i].programming;
                st[i].programming = st[j].programming;
                st[j].programming = temp2;

                temp2 = st[i].avg;
                st[i].avg = st[j].avg;
                st[j].avg = temp2;

                temp2 = st[i].rank;
                st[i].rank = st[j].rank;
                st[j].rank = temp2;
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
                char temp[100];
                strcpy(temp, st[i].fname);
                strcpy(st[i].fname, st[j].fname);
                strcpy(st[j].fname, temp);

                strcpy(temp, st[i].id);
                strcpy(st[i].id, st[j].id);
                strcpy(st[j].id, temp);

                strcpy(temp, st[i].department);
                strcpy(st[i].department, st[j].department);
                strcpy(st[j].department, temp);

                strcpy(temp, st[i].dob);
                strcpy(st[i].dob, st[j].dob);
                strcpy(st[j].dob, temp);

                int temp2 = 0;
                temp2 = st[i].math;
                st[i].math = st[j].math;
                st[j].math = temp2;

                temp2 = st[i].english;
                st[i].english = st[j].english;
                st[j].english = temp2;

                temp2 = st[i].programming;
                st[i].programming = st[j].programming;
                st[j].programming = temp2;

                temp2 = st[i].avg;
                st[i].avg = st[j].avg;
                st[j].avg = temp2;

                temp2 = st[i].rank;
                st[i].rank = st[j].rank;
                st[j].rank = temp2;
            }
        }
    }
}