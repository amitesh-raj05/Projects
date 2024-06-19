
//                                     .....CS PROJECT.....

// This code is for managing mess and hostel related stuffs.
// Its gives a way to take your suggestion , complaints, entries , feedback,etc. about mess and hostel in an efficient way.

//                                   This Project is done by:

// ANURAG ANAND SINGH | ANSHUL BHATNAGAR | GAUTAM KUMAR | AMITESH RAJ | AARADHYA SINGH | ATRI DEWANGAN | BHUMIKA CHAUHAN




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define Max_Input_length 100
#define feedbackFileName "feedback.txt"
#define suggestionsFile "suggestions.txt"
#define complainsFileName "complaints.txt"

char smile = 2;

struct StudentDetails
{
    char Name[50];
    char Username[50];
    char Password[10];
    int RoomNo;
    char MobileNo[10];
    char Newpassword[10];
};

void shift(char a[5][40], char **b)
{
    for (int i = 0; i < 5; i++)
    {
        b[i] = a[i];
    }
}
typedef struct CharL
{
    char arr1[5][40];
} CharL;
char des[5][40] = {"DAYS     ", "Breakfast(7-9am)   ", "Lunch(12-2pm)           ", "Snacks(5:30-6:30pm)", "Dinner(8-10pm)                       "};
char mon[5][40] = {"Monday   ", "Sandwich           ", "Kadhi Pakoda & Chana    ", "Samosa             ", "Aloo Dam,Poori & custard             "};
char tue[5][40] = {"Tuesday  ", "Masala Dosa        ", "Soyabean curry          ", "Bread pakoda       ", "Veg kofta & Gulab jamun              "};
char wed[5][40] = {"Wednesday", "Pasta              ", "Rajma & French fries    ", "Pyaaz kachori      ", "Matar Paneer/chicken & Jalebi        "};
char thu[5][40] = {"Thursday ", "Idli,Vada & Sambhar", "Palak Paneer            ", "Litti chokha       ", "Manchurian & Noodles                 "};
char fri[5][40] = {"Friday   ", "Pav bhaji          ", "Egg curry/Mushroom curry", "French fries       ", "Butter Paneer/chicken                "};
char sat[5][40] = {"Saturday ", "Aloo Paratha       ", "Chhole Bhature          ", "Palak pakoda       ", "Lauki Kofta & Daal Makhani           "};
char sun[5][40] = {"Sunday   ", "Lemon rice         ", "Aloo palak              ", "Aloo chaat         ", "Chicken Biryani/Paneer Lachha Paratha"};
struct CharL *menu1;
void menu()                             //Function for printing the whole menu..
{
    menu1 = (struct CharL *)malloc(sizeof(struct CharL) * 8);
    for (int i = 0; i < 5; i++)          //Code for shifting all the double dimensional arrays defined earlier in menu1
    {
        strcpy(menu1[0].arr1[i], des[i]);       //Copying the contents of des[i] into menu1[0].arr1[i]
    }
    for (int i = 0; i < 5; i++)
    {
        strcpy(menu1[1].arr1[i], mon[i]);       //Copying the contents of mon[i] into menu1[1].arr1[i]
    }
    for (int i = 0; i < 5; i++)
    {
        strcpy(menu1[2].arr1[i], tue[i]);       //Copying the contents of tue[i] into menu1[2].arr1[i]
    }
    for (int i = 0; i < 5; i++)
    {
        strcpy(menu1[3].arr1[i], wed[i]);       //Copying the contents of wed[i] into menu1[3].arr1[i]
    }
    for (int i = 0; i < 5; i++)
    {
        strcpy(menu1[4].arr1[i], thu[i]);       //Copying the contents of thu[i] into menu1[4].arr1[i]
    }
    for (int i = 0; i < 5; i++)
    {
        strcpy(menu1[5].arr1[i], fri[i]);       //Copying the contents of fri[i] into menu1[5].arr1[i]
    }
    for (int i = 0; i < 5; i++)
    {
        strcpy(menu1[6].arr1[i], sat[i]);       //Copying the contents of sat[i] into menu1[6].arr1[i]
    }
    for (int i = 0; i < 5; i++)
    {
        strcpy(menu1[7].arr1[i], sun[i]);       //Copying the contents of sun[i] into menu1[7].arr1[i]
    }
    for (int k = 0; k < 5; k++)
    {
        printf("%s\t\t", menu1[0].arr1[k]);
    }
    printf("\n\n");
    for (int i = 1; i < 8; i++)                 //Code for accessing and printing all the elements of menu1
    {
        for (int k = 0; k < 5; k++)
        {
            printf("%s\t\t", menu1[i].arr1[k]);
        }
        printf("\n");
    }
}
int checkfile(char filename[50], char RollNo[10]) {        //Function for checking and printing the data for a specific roll no.
    FILE *filecheck;                                       //for a given file name
    char line[200];
    filecheck = fopen(filename, "r");            
    if (filecheck == NULL) {
        printf("File not found.\n");
        return 1;
    }

    int found = 0;  

    while (fgets(line, sizeof(line), filecheck)) {          //Reading through each line of the file..
        line[strcspn(line, "\n")] = '\0';  
        
        if (strncmp(line, RollNo, strlen(RollNo)) == 0) {   // Check if the search string is found in the line
            printf("%s\n", line);
            found = 1;
        }
    }

    if (!found) {
        printf("String not found in the file.\n");
    }

    fclose(filecheck);
    return 0;
}


int main()
{

    printf("\n                                    .....CS PROJECT.....\n\nThis code is for managing mess and hostel related stuffs.\nIts gives a way to take your suggestion , complaints, entries , feedback,etc. about mess and hostel in an efficient way.\n\n                            This Project is done by:\n\nANURAG ANAND SINGH | ANSHUL BHATNAGAR | GAUTAM KUMAR | AMITESH RAJ | AARADHYA SINGH | ATRI DEWANGAN | BHUMIKA CHAUHAN\n\n");


    int newEntry = 0;

    FILE *ptr = fopen("StudData.txt", "a+"); // Open file in append mode

    printf("Hello dear, welcome to this program.\n\n");

    char RollNo[50];

    printf("Enter Your Roll No.\n");
    scanf(" %49s", RollNo); // Limit input to 49 characters to avoid buffer overflow

p:
    printf("Are you new to this program? (Y: Yes / N: No)\n");

    char input; // Increase the size to accommodate '\0'

    scanf(" %c", &input); // Limit input to 1 character and add '\0' at the end

    for (;;)
    {
        if (input == 'Y' || input == 'N' || input == 'y' || input == 'n')
        {
            break;
        }

        printf("Invalid input. Please enter Y or N.\n");
        scanf(" %c", &input);
    }

    if (input == 'Y' || input == 'y')
    {
        // The part of code for creating a new account of the user...
        printf("Create Account\n\n");

        char searchStr_1[22];
        strcpy(searchStr_1, RollNo);

        searchStr_1[strcspn(searchStr_1, "\n")] = '\0'; // Remove the newline character

        char line_1[100];

        int found_1 = 0;
        rewind(ptr); // Rewind the file pointer to the beginning

        while (fgets(line_1, sizeof(line_1), ptr) != NULL)
        {                                                  // Read the file line by line
            char *foundStri = strstr(line_1, searchStr_1); // Check if the search string is found in the line

            if (foundStri != NULL && *(foundStri + strlen(searchStr_1)) == ' ')
            {
                found_1 = 1;
                break;
            }
        }

        if (found_1 == 1)
        {
            printf("Account already exists!!\n");
            goto p;
        }

        struct StudentDetails newStudent;
        printf("Enter Your Name:\n");
        while (getchar() != '\n');            // Clear input buffer before reading Name
        scanf("%[^\n]s", newStudent.Name);
        while (getchar() != '\n');           // Clear input buffer after reading Name

        printf("Enter Your Room No.\n");
        scanf("%d", &newStudent.RoomNo);

        printf("Enter Mobile No.\n");
        scanf("%s", newStudent.MobileNo);

        printf("Enter Password (up to 9 characters)\n");
        scanf(" %9s", newStudent.Password);      // Limit input to 9 characters to avoid buffer overflow

        fprintf(ptr, "%s \t\t\t", RollNo);
        fprintf(ptr, "%s", RollNo);
        fprintf(ptr, "%s \t\t\t ", newStudent.Password);
        fprintf(ptr, "%s \t\t\t ", newStudent.Name);
        fprintf(ptr, "%s \t\t\t ", newStudent.MobileNo);
        fprintf(ptr, "%d\n", newStudent.RoomNo);

        newEntry = 1;
        input = 'n';
        printf("Account created successfully.\n\n\n");
    }

    fclose(ptr);            // Close the file before exiting

    if (input == 'N' || input == 'n')
    {
        //Part of code for logging in a existing user by checking login credentials..
        for (;;)
        {

            char newRoll[9];
            char passwordNew[10];
            printf("Enter your login credentials.\n\n");

            printf("Enter your Roll No.\n");

            scanf(" %s", newRoll);

            printf("Enter Password \n");

            scanf(" %s", passwordNew);

            FILE *ptr = fopen("StudData.txt", "r");     //Opening the text file "StudData.txt" having the data for login credentials..
            if (ptr == NULL)
            {
                printf("Failed to open the file.\n");
                return 1;
            }

            char searchStr[22];
            strcpy(searchStr, newRoll);
            strcat(searchStr, passwordNew);

            searchStr[strcspn(searchStr, "\n")] = '\0'; // Remove the newline character

            char line[100];

            int found = 0;

            while (fgets(line, sizeof(line), ptr) != NULL)
            {                                             // Read the file line by line
                char *foundStr = strstr(line, searchStr); // Check if the search string is found in the line

                if (foundStr != NULL && *(foundStr + strlen(searchStr)) == ' ')
                {
                    found = 1;
                    break;
                }
            }
            if (found == 1)
            {

                printf("You are logged in successfully .");

                break;
            }

            if (found == 0)
            {
                printf("Invalid Credential .\nPlease check the username and password and try again!!!");
            }
            fclose(ptr);
        }
    }

    int choice_manage;

start:
    //Giving options to the user and taking the input...
    printf("Choose from following option \n");
    printf("1.) Mess Management System\n");
    printf("2.) Hostel Mangement System\n");
    printf("3.) See Your previously input data\n");
    printf("Enter Input : \n");

    scanf("%d", &choice_manage);

    if (choice_manage == 1)
    {
        //The start of the mess manangement program...
        printf("      #     #  #####  ###   ###             #     #      #      #   #      #       ##    #####   #     #   #####   #   #   #####    \n");
        printf("      ##   ##  #     #     #                ##   ##     # #     ##  #     # #     #  #   #       ##   ##   #       ##  #     #      \n");
        printf("      # # # #  ###    ###   ###             # # # #    #####    # # #    #####    #      ###     # # # #   ###     # # #     #      \n");
        printf("      #  #  #  #         #     #            #  #  #   #     #   #  ##   #     #   #  ##  #       #  #  #   #       #  ##     #      \n");
        printf("      #     #  #####  ###   ###             #     #  #       #  #   #  #       #   ## #  #####   #     #   #####   #   #     #      \n");
        printf("\n\n\t<< Welcome to the Mess Management System >>\n");

        int choice_num, choice_num1, choice_num2, choice_num3, n;
        char string[150];
        char s[3][40];
        FILE *suggestion = fopen(suggestionsFile, "a+");  //Opening the file in append mode for storing suggestions 
        fprintf(suggestion, "%s", RollNo);

        char choice_ = 'Y';
        while (choice_ == 'Y' || choice_ == 'y')
        {
            //Giving options to the user and taking the input...
            printf("\nSelect one of the options by entering one the numbers(Input an integer):\n");
            printf("1.Current Mess Menu\n2.Suggestions for next Menu\n3.Complains\n4.Mess Rebate System\n5.Feedback\nEnter your choice : ");
            scanf("%d", &choice_num);
            if (choice_num == 1)  //Beginning the menu part..
            {
                menu();
            }
            else if (choice_num == 2) //Start of the suggestions part..
            {
                printf("Choose:-\n(The input should be an integer)\n1.Items to be removed\n2.Items to be introduced\nYour choice: ");
                scanf("%d", &choice_num1);
                if (choice_num1 == 1)
                {
                    menu();
                a:
                    printf("\n\nChoose the day(on which that item is served) and the item to be removed:-\n(The input should be an integer)\n"); // 1.Monday  2.Tuesday  3.Wednesday  4.Thursday  5.Friday  6.Saturday  7.Sunday\n
                    for (int i = 1; i < 8; i++)
                    {
                        printf(" %d. %s\t", i, menu1[i].arr1[0]);
                    }
                    printf("\n");
                    scanf("%d", &choice_num2);            //Giving options to the user and taking the input...
                    if (choice_num2 == 1 || choice_num2 == 2 || choice_num2 == 3 || choice_num2 == 4 || choice_num2 == 5 || choice_num2 == 6 || choice_num2 == 7)
                    {
                    }
                    else
                    {
                        printf("Give a proper input !");
                        goto a;         //Going back in the program if the input given by the user is not valid
                    }

                    struct CharL ch;
                b:
                    for (int i = 1; i < 5; i++)
                    {
                        printf(" %d. %s\t", i, menu1[choice_num2].arr1[i]);
                    }
                    printf("\n");
                    scanf("%d", &choice_num3);            //Giving options to the user and taking the input...
                    if (choice_num3 == 1 || choice_num3 == 2 || choice_num3 == 3 || choice_num3 == 4)
                    {
                        fprintf(suggestion, "\tSuggestions of food items to be removed - %s\t%s", menu1[choice_num2].arr1[0], menu1[choice_num2].arr1[choice_num3]);
                        printf("Your suggestion has been recorded!\n");
                    }
                    else
                    {
                        printf("Give a proper input !\n");
                        goto b;                         //Going back in the program if the input given by the user is not valid
                    }
                    fclose(suggestion);
                }
                else if (choice_num1 == 2)
                {
                c:
                    printf("Enter the no. of suggestions you want to give (1<=n<=3) :- ");
                    scanf("%d", &n);
                    if (n == 1 || n == 2 || n == 3)
                    {
                    }
                    else
                    {
                        printf("Give a proper input !\n");
                        goto c;                        //Going back in the program if the input given by the user is not valid
                    }
                    printf("Enter the name of the food item/items that you want to be introduced:-\n(Enter the input in lower cases only)\n");
                    for (int i = 0; i < n; i++)
                    {
                        while (getchar() != '\n');
                        scanf("%[^\n]s", s[i]);
                    }
                    fprintf(suggestion, "\tSuggestions of food item/items be introduced-%s\t", s[0]);
                    for (int i = 1; i < n; i++)
                    {
                        fprintf(suggestion, "\t%s", s[i]);
                    }
                    printf("Your suggestion has been taken successfully !\n");
                    fclose(suggestion);
                }
            }
            else if (choice_num == 3) //Start of the complaints part...
            {

                int choice1 = 0;
                int firstTime = 1;
                char s1[Max_Input_length];

                do
                {
                    if (firstTime)
                    {
                        printf("\nWelcome to our program!\n");
                        firstTime = 0;
                    }
                    //Giving options to the user and taking the input...
                    printf("\nMenu of Complaint System:\n");
                    printf("1. Enter complaints\n");
                    printf("2. Access stored complaints\n");
                    printf("3. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice1);
                    getchar();
                    switch (choice1)
                    {
                    case 1:
                    {
                        int numComplaints;
                        printf("Enter the number of complaints you want to give (1 <= n <= 3): ");
                        scanf("%d", &numComplaints);
                        getchar();
                        printf("Enter the complaint(s) regarding mess:\n");

                        FILE *complainsFile = fopen(complainsFileName, "a+"); //Opening the file in append mode for storing complains 

                        for (int i = 0; i < numComplaints; i++)
                        {
                            fgets(s1, Max_Input_length, stdin);
                            fprintf(complainsFile, "%s \t%s \n", RollNo, s1);
                        }

                        fclose(complainsFile);
                        printf("Thank you! Your complaint(s) have been submitted successfully!\n");
                        break;
                    }
                    case 2:
                    {
                        char line[Max_Input_length];
                        FILE *complainsFile = fopen(complainsFileName, "r");
                        if (complainsFile != NULL)
                        {
                            printf("Stored complaints:\n");
                            while (fgets(line, sizeof(line), complainsFile) != NULL)
                            {
                                printf("%s", line);
                            }
                            fclose(complainsFile);
                        }
                        else
                        {
                            printf("No complaints found!\n");
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("The program ends\n");
                        break;
                    }
                    default:
                    {
                        printf("Invalid choice! Please enter a valid option.\n");
                        break;
                    }
                    }
                } while (choice1 != 3);
            }
            else if (choice_num == 5)
            {
                //The start of code for the feedback part..
                int choice = 0;
                char s2[3][Max_Input_length];

                do
                {
                    //Giving options to the user and taking the input...
                    printf("\nMenu of Feedback System:\n");
                    printf("1. Enter feedback\n");
                    printf("2. Access stored feedback\n");
                    printf("3. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    getchar();

                    switch (choice)
                    {
                    case 1:
                    {
                        int numFeedback;
                        printf("Enter the number of feedback you want to give (1 <= n <= 3): ");
                        scanf("%d", &numFeedback);
                        getchar();
                        printf("Enter the feedback(s) regarding mess:\n");

                        for (int i = 0; i < numFeedback; i++)
                        {
                            scanf("%[^\n]", s2[i]);
                            getchar();
                        }

                        FILE *feedbackFile = fopen(feedbackFileName, "a+");
                        fprintf(feedbackFile, "\n %s\tFeedbacks- %s", RollNo, s2[0]);
                        for (int i = 1; i < numFeedback; i++)
                        {
                            fprintf(feedbackFile, "\t\t %s", s2[i]);
                        }
                        fclose(feedbackFile);
                        printf("Thank you! Your feedback(s) have been submitted successfully!\n");
                        break;
                    }

                    case 2:
                    {
                        char line[Max_Input_length];
                        FILE *feedbackFile = fopen(feedbackFileName, "r");
                        if (feedbackFile != NULL)
                        {
                            printf("Stored feedbacks:\n");
                            while (fgets(line, sizeof(line), feedbackFile) != NULL)
                            {
                                printf("%s\n", line);
                            }
                            fclose(feedbackFile);
                        }
                        else
                        {
                            printf("No feedbacks found!\n");
                        }
                        break;
                    }
                    case 3:
                    {
                        printf("Ending the program\n");
                        break;
                    }
                    default:
                    {
                        printf("Invalid choice! Please enter a valid option.\n");
                        break;
                    }
                    }
                } while (choice != 3);
            }
            else if (choice_num == 4)
            {
                //The start of code for the mess rebate part
                int choice3;
                int r, d1, m1, y1, d2, m2, y2;
                int tot, tot_1=0;
                int M[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

                do
                {
                    //Giving options to the user and taking the input...
                    printf("\nMenu:\n");
                    printf("1. Enter the dates of rebate\n");
                    printf("2. Check rebate amount from file\n");
                    printf("3. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice3);

                    switch (choice3)
                    {
                    case 1:        //Code for taking the dates of rebate from the user 
                    {
                        r = 0;
                    reb:
                        printf("(The maximum number of days that can be rebated is 30 )\nEnter the date(dd mm yy) from which rebate starts: ");
                        scanf("%d %d %d", &d1, &m1, &y1);
                        printf("Enter the date(dd mm yy) on which rebate ends: ");
                        scanf("%d %d %d", &d2, &m2, &y2);
                        if (m1 == m2)               //Calculating amount of days i.e. (no. of days) = r
                        {
                            r = d2 - d1 + 1;
                        }
                        else if (m2 == m1 + 1)
                        {
                            r = d2 + M[m1 - 1] - d1 + 1;
                        }
                        if (r > 30)
                        {
                            printf("Enter the dates considering the given limit of days !");
                        }
                        else if (r == 0)
                        {
                            printf("Enter the dates considering the given limit of days !");
                        }
                        goto reb;                        //Going back in the program if the input given by the user is not valid

                        tot = r * 127.17;
                        tot_1=tot;

                        FILE *Rfile = fopen("rebate.txt", "w");
                        if (Rfile != NULL)
                        {
                            fprintf(Rfile, "\n%s\tRebate is considered from %d-%d-%d to %d-%d-%d\tRebate amount=%d", RollNo, d1, m1, y1, d2, m2, y2, tot);
                            fclose(Rfile);
                            printf("Thank you! Your amount %d will be rebated.\n", tot);
                        }
                        else
                        {
                            printf("Error opening the file for writing.\n");
                        }
                        break;
                    }
                    case 2:
                    {  
                        printf("Your rebate amount is: %d\n", tot);
                        break;
                    }
                    case 3:
                    {
                        printf("Exiting the program.\n");
                        break;
                    }
                    default:
                    {
                        printf("Invalid choice! Please enter a valid option.\n");
                        break;
                    }
                    }
                } while (choice3 != 3);
            }

            printf("\n\nDo you wish to continue(y/n) : ");
            scanf(" %c", &choice_);
            if (choice_ == 'Y' || choice_ == 'y' || choice_ == 'n' || choice_ == 'N')
            {
                if (choice_ == 'n' || choice_ == 'N')
                {
                    printf("\nThank you for visiting the program and giving your precious time\nVisit again later   %c %c", smile, smile);
                    break;
                }
                continue;
            }
            else
            {
                while (1)
                {
                    //Taking a valid input from the user
                    printf("Please enter a valid input !\n");
                    printf("\n\nDo you wish to continue(y/n) : ");
                    scanf(" %c", &choice_);
                    if (choice_ == 'Y' || choice_ == 'y' || choice_ == 'n' || choice_ == 'N')
                    {
                        break;
                    }
                }
                if (choice_ == 'n' || choice_ == 'N')
                {
                    printf("\nThank you for visiting the program and giving your precious time\nVisit again later   %c %c", smile, smile);
                    break;
                }
            }
        }
    }

    //The start of hostel management part...
    if (choice_manage == 2)
    {

        printf("      #  #  ####  ####  #####  #####  #        #     #      #      #   #      #       ##    #####   #     #   #####   #   #   #####    \n");
        printf("      #  #  #  #  #       #    #      #        ##   ##     # #     ##  #     # #     #  #   #       ##   ##   #       ##  #     #      \n");
        printf("      ####  #  #  ####    #    ###    #        # # # #    #####    # # #    #####    #      ###     # # # #   ###     # # #     #      \n");
        printf("      #  #  #  #     #    #    #      #        #  #  #   #     #   #  ##   #     #   #  ##  #       #  #  #   #       #  ##     #      \n");
        printf("      #  #  ####  ####    #    #####  ####     #     #  #       #  #   #  #       #   ## #  #####   #     #   #####   #   #     #      \n");

        printf("\n\n\t<< Welcome to the Hostel Management System >>\n");

        int choose_hostel;

    wapas:
        //Giving options to the user and taking the input...
        printf("Please select following option\n");
        printf("1.)Complaints\n");
        printf("2.)Entries\n");

        scanf("%d", &choose_hostel);

        if (choose_hostel == 1)
        {
            //Start of the code for hostel complains part
            char open;
            int comp;
            char choice_a = 'y';
            FILE *f1, *f2, *f3, *f4, *f5;
            printf("\n\t<< Welcome to the Complains Management System >>\n\n");
        g:
            printf("Press e :For entering complain \nPress v :For viewing complain \n");
            scanf(" %c", &open);
            if (open == 'E' || open == 'e')
            {
                while (choice_a == 'y')
                {
                    //Giving options to the user and taking the input...
                    printf("Please select a category for your complaint:\n");
                    printf("1:Carpentry\n2:Electricity\n3:Plumbing\n4:Technician\n5:Others\n");
                    scanf("%d", &comp);
                    if (comp == 1)
                    {
                        char s1[100];
                        f1 = fopen("Carpentry.txt", "a");           //Opening the file in the append mode
                        printf("Write your complain here:\n");
                        while (getchar() != '\n');
                        scanf("%[^\n]s", s1);                       //Taking the whole line of input from the user
                        while (getchar() != '\n');
                        fprintf(f1, "%s   %s\n", RollNo, s1);
                        fclose(f1);
                    }
                    if (comp == 2)
                    {
                        char s2[100];
                        f2 = fopen("Electricity.txt", "a");           //Opening the file in the append mode
                        printf("Write your complain here:\n");
                        while (getchar() != '\n');
                        scanf("%[^\n]s", s2);                      //Taking the whole line of input from the user
                        while (getchar() != '\n');
                        fprintf(f2, "%s   %s\n", RollNo, s2);
                        fclose(f2);
                    }
                    if (comp == 3)
                    {
                        char s3[100];
                        f3 = fopen("Plumber.txt", "a");           //Opening the file in the append mode
                        printf("Write your complain here:\n");
                        while (getchar() != '\n');
                        scanf("%[^\n]s", s3);                      //Taking the whole line of input from the user
                        while (getchar() != '\n');
                        fprintf(f3, "%s   %s\n", RollNo, s3);
                        fclose(f3);
                    }
                    if (comp == 4)
                    {
                        char s4[100];
                        f4 = fopen("Technical.txt", "a");           //Opening the file in the append mode
                        printf("Write your complain here:\n");
                        while (getchar() != '\n');
                        scanf("%[^\n]s", s4);                      //Taking the whole line of input from the user
                        while (getchar() != '\n');
                        fprintf(f4, "%s   %s\n", RollNo, s4);
                        fclose(f4);
                    }
                    if (comp == 5)
                    {
                        char s5[100];
                        f5 = fopen("Other_complains.txt", "a");           //Opening the file in the append mode
                        printf("Write your complain here:\n");
                        while (getchar() != '\n');
                        scanf("%[^\n]s", s5);                      //Taking the whole line of input from the user
                        while (getchar() != '\n');
                        fprintf(f5, "%s   %s\n", RollNo, s5);
                        fclose(f5);
                    }
                    printf("Do you want to register for any more complaints(y/n):");
                    scanf(" %c", &choice_a);
                }

                if (choice_a == 'n')
                {
                    goto wapas;
                }
            }
            else if (open == 'V')
            {
            }
            else if (open != 'E' && open != 'V')
            {
                printf("Please enter a valid input !\n");
                goto g;
            }
        }

        
        //Start of code of the entries part of hostel management
        if (choose_hostel == 2)
        {

            // Obtain the current time
            time_t currentTime = time(NULL);

            // Convert the time to a string representation
            char *timeString = ctime(&currentTime);

            

            printf("Entries\n\n\n");
            int choice;

            FILE *pttr = fopen("entryData.txt","a+");           //Opening the file in append mode
        acc:

            fprintf(pttr,"%s", RollNo);

            //Giving options to the user and taking the input...
            printf(" 1.) Enter the hostel\n");
            printf(" 2.) Leave the hostel\n");
            printf(" 3.) Use the washing machine\n");
            printf(" 4.) Leave the washing machine\n");
            printf(" 5.) Use the reading room\n");
            printf(" 6.) Leave the reading room\n");
            printf(" 7.) Use the common room\n");
            printf(" 8.) Leave the common room\n");

            printf("Enter your choice: ");

            scanf("%d", &choice);

            if (choice == 1)
            {

                char ehostel[30] = "Hostel Entring Time";

                fprintf(pttr, " %s \t\t\t\t", ehostel);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Entry time recorded successfully\n");
            }

            if (choice == 2)
            {

                char lhostel[30] = "Hostel Leaving Time";

                fprintf(pttr, " %s \t\t\t\t", lhostel);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Exit time recorded successfully\n");
            }
            if (choice == 3)
            {

                char wmach[30] = "Washing maching use time";
                fprintf(pttr, " %s \t\t\t\t", wmach);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Entry time recorded successfully\n");
            }
            if (choice == 4)
            {

                char lwach[30] = "Washing maching leave time";
                fprintf(pttr, " %s \t\t\t\t", lwach);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Exit time recorded successfully\n");
            }
            if (choice == 5)
            {

                char ereading[30] = "Reading room entry time";

                fprintf(pttr, " %s \t\t\t\t", ereading);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Entry time recorded successfully\n");
            }
            if (choice == 6)
            {

                char lreading[30] = "Reading room exit time";
                fprintf(pttr, " %s \t\t\t\t", lreading);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Exit time recorded successfully\n");
            }
            if (choice == 7)
            {

                char ecommon[30] = "Common room entry time";

                fprintf(pttr, " %s \t\t\t\t", ecommon);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Entry time recorded successfully\n");
            }
            if (choice == 8)
            {

                char lcommon[30] = "Common room exit time";
                fprintf(pttr, " %s \t\t\t\t", lcommon);
                fprintf(pttr, " %s ", timeString);          //Appending the time of entry in the file...

                printf("Exit time recorded successfully\n");
            }

            char cont;

            printf("Do you wish to continue(Y/N)\n");

            scanf(" %c", &cont);

            if (cont == 'Y' || cont == 'y')
            {
                goto acc;
            }

            if (cont == 'N' || cont == 'n')
            {
                goto start;
            }
        }
    }

    if(choice_manage==3){
        //Part of code for reading the contents of each file for a given Roll no. and printing it
        printf(" Your suggesstion for mess menu were: \n");
        checkfile("suggestions.txt",RollNo);

        printf("\n\n");


        printf(" Your complaints for mess: \n");
        checkfile("complaints.txt",RollNo);
        printf("\n\n");

        printf(" Your feedback for mess menu were: \n");
        checkfile("feedback.txt",RollNo);
        printf("\n\n");

        printf(" Your rebate in mess was: \n\n");
        checkfile("rebate.txt",RollNo);
        printf("\n\n");

        printf(" Your entry datas in hostel were: \n\n");
        checkfile("entryData.txt",RollNo);

        printf("\n\n");

        printf(" Your complaints against carpentry: \n\n");
        checkfile("Carpentry.txt",RollNo);
        printf("\n\n");

        printf(" Your omplaints against electricity \n\n");
        checkfile("Electricity.txt",RollNo);
        printf("\n\n");

        printf(" Your complaints against plumbing: \n\n");
        checkfile("Plumber.txt",RollNo);
        printf("\n\n");

        printf(" Your complaints against technical assistance: \n\n");
        checkfile("Technical.txt",RollNo);
        printf("\n\n");

        printf(" Your Other complaints were: \n\n");
        checkfile("Other_complains.txt",RollNo);
        printf("\n\n");

        
    }
}