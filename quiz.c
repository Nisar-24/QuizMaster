#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Q 50
#define MAX_LINE 256
// initializing the structure
typedef struct
{
    char question[MAX_LINE];
    char options[4][MAX_LINE];
    char correct;
} Question;

void trim(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r'))
        str[len - 1] = '\0';
}

void prefix(char *str)
{
    if (strlen(str) < 3)
        return;
    if ((str[0] >= 'a' && str[0] <= 'd') && (str[1] == '.' || str[1] == ')') && str[2] == ' ')
    {
        // Shift string left by 3 characters....

        memmove(str, str + 3, strlen(str + 3) + 1);
    }
}

void load(const char *filename, Question quest[], int *total)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error: The file cannot be open %s\n", filename);
        exit(1);
    }

    *total = 0;
    while (fgets(quest[*total].question, sizeof(quest[*total].question), fp))
    {
        trim(quest[*total].question);
        if (strlen(quest[*total].question) == 0)
            continue; // skip empty lines....

        for (int i = 0; i < 4; i++)
        {
            if (!fgets(quest[*total].options[i], sizeof(quest[*total].options[i]), fp))
            {
                printf("Error: Unexpected error while reading options.\n");
                exit(1);
            }
            trim(quest[*total].options[i]);
            prefix(quest[*total].options[i]);
        }

        char answer[10];
        if (!fgets(answer, sizeof(answer), fp))
        {
            printf("Error: Unexpected error while reading answer.\n");
            exit(1);
        }
        trim(answer);
        if (strlen(answer) != 1 || strchr("abcdABCD", answer[0]) == NULL)
        {
            printf("Error: Not a valid answer '%s' for question %d\n", answer, *total + 1);
            exit(1);
        }
        quest[*total].correct = tolower(answer[0]);
        (*total)++;
        if (*total >= MAX_Q)
            break;
    }

    fclose(fp);
}

char Grade(float percentage)
{
    if (percentage >= 90)
    {
        printf("\nCONGRATS YOU GOT A GRADE WELL DONE...\n");
        return 'A';
    }
    else if (percentage >= 75)
    {
        printf("\n----CONGRATS YOU GOT B GRADE----\n");
        return 'B';
    }
    else if (percentage >= 60)
    {
        printf("\n----YOU GOT C GRADE YOU NEED TO LEARN SMART----\n");
        return 'C';
    }
    else if (percentage >= 40)
    {
        printf("\n----YOU GOT D GRADE YOU NEED TO STUDY HARD----\n");
        return 'D';
    }
    else
    {
        printf("\n----YOU GOT F YOU FAILED TRY AGAIN OR LEARN THE SUBJECTS----\n");
        return 'F';
    }
}

int main()
{
    char input[100];
    char name[50];
    int choice = 0;
    Question q[MAX_Q];
    int total_questions = 0, score = 0;

    printf("Enter your Name: ");
    if (!fgets(name, sizeof(name), stdin))
    {
        printf("Input error.\n");
        return 1;
    }
    trim(name);

    // options displayed for the user to select the subject

    while (1)
    {
        printf("\nPlease Select Course:\n");
        printf("1. Science\n");
        printf("2. Math\n");
        printf("3. Computer Science\n");
        printf("Enter choice: ");

        if (!fgets(input, sizeof(input), stdin))
        {
            printf("Input error Occured.\n");
            return 1;
        }

        choice = atoi(input);
        if (choice >= 1 && choice <= 3)
        {
            break;
        }
        printf("Not a valid choice! Please enter 1, 2 or 3.\n");
    }

    // The question will displayed based on subjects....

    const char *filename;
    const char *courseName;
    if (choice == 1)
    {
        filename = "science.txt";
        courseName = "Science";
        printf("\n----Science Quiz Starts----\n");
    }
    else if (choice == 2)
    {
        filename = "math.txt";
        courseName = "Math";
        printf("\n----Maths Quiz Starts----\n");
    }
    else
    {
        filename = "cs.txt";
        courseName = "Computer Science";
        printf("\n----Computer Science Quiz Starts----\n");
    }

    load(filename, q, &total_questions);

    // quesions pattern

    for (int i = 0; i < total_questions; i++)
    {
        printf("\nQ%d: %s\n", i + 1, q[i].question);
        printf("a. %s\n", q[i].options[0]);
        printf("b. %s\n", q[i].options[1]);
        printf("c. %s\n", q[i].options[2]);
        printf("d. %s\n", q[i].options[3]);

        while (1)
        {
            printf("Your answer (a/b/c/d): ");
            if (!fgets(input, sizeof(input), stdin))
            {
                printf("Input error.\n");
                continue;
            }
            trim(input);
            if (strlen(input) == 1)
            {
                // the choice must be a,b,c or d other character are invalid

                char answer = tolower(input[0]);
                if (answer == 'a' || answer == 'b' || answer == 'c' || answer == 'd')
                {
                    if (answer == q[i].correct)
                    {
                        printf("Correct!\n");
                        score++;
                    }
                    else
                    {
                        printf("Wrong! Correct answer was: %c\n", q[i].correct);
                    }
                    break;
                }
            }
            printf("Not a valid option! Please select a option for these a, b, c, or d.\n");
        }
    }
    // Total Score of user + grades

    float percentage = (score * 100.0f) / total_questions;
    char grade = Grade(percentage);

    printf("\n%s, your score: %d/%d\n", name, score, total_questions);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);

    // updating the result in result page...

    FILE *rfp = fopen("result.txt", "a");
    if (rfp != NULL)
    {
        fprintf(rfp, "Name: %s\n", name);
        fprintf(rfp, "Course: %s\n", courseName);
        fprintf(rfp, "Score: %d/%d\n", score, total_questions);
        fprintf(rfp, "Percentage: %.2f%%\n", percentage);
        fprintf(rfp, "Grade: %c\n", grade);
        fprintf(rfp, "--------------------------\n");
        fclose(rfp);
    }
    else
    {
        printf("Error: Not able to open result.txt for writing.\n");
    }

    return 0;
}
