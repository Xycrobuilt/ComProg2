#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void mainScreen();
void studentNameSort();

//Main Function
int main()
{
    mainScreen();
    int letterChoice;
    scanf("%d", letterChoice);
    if (letterChoice = "A") {
        studentNameSort();
    }
    return 0;
}

//For Printing the Mainscreen
void mainScreen()
{

system("COLOR 03");
printf(" ___________________________________________________________ \n");
printf("|                                                           | \n");
printf("|                 CLASSROOM MANAGEMENT SYSTEM               | \n");
printf("|___________________________________________________________| \n");
printf("|         Select the corresponding letter of Choice         | \n");
printf("|                                                           | \n");
printf("|                (A) Grade Recording System                 | \n");
printf("|                (B) Student Name Sorting                   | \n");
printf("|                (C) Random Group Formation                 | \n");
printf("|                (D) Group File Creation                    | \n");
printf("|                (E) Random Student Selection               | \n");
printf("|                (F) Performance Evaluation                 | \n");
printf("|___________________________________________________________|\n");
printf("             ENTER LETTER HERE: ");



    return 0;
}

//For Sorting Student Names inside Text File
void studentNameSort()
{
    system("cls");
    system("COLOR 06");
    FILE *csvFile = fopen("studentNames.txt", "r");
    if (csvFile == NULL) {
        perror("Your File is Corrupted");
        return;
    }

    char lines[100][200];
    int count = 0;

    char line[200];
    while (fgets(line, sizeof(line), csvFile)) {
        int lineLength = strlen(line);
        if (lineLength > 0 && line[lineLength - 1] == '\n') {
            line[lineLength - 1] = '\0';
        }
        strcpy(lines[count], line);
        count++;
    }

    fclose(csvFile);

    // Sort the lines in alphabetical order
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char temp[200];
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

    // Create a new text file for sorted names
    FILE *sortedFile = fopen("sortedNames.txt", "w");
    if (sortedFile == NULL) {
        perror("Unable to create the sorted file");
        return;
    }

    // Write the sorted names to the new file
    for (int i = 0; i < count; i++) {
        fprintf(sortedFile, "%s\n", lines[i]);
    }

    fclose(sortedFile);
    fopen("sortedNames.txt", "r");
}


