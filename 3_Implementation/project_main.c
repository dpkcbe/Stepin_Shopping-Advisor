

/*************************** HEADER FILES ***************************/
#include "masterAccountFunctions.h"
#include "common.h"
#include "credentialFunctions.h"
#include "passwordUsernameFormatChecker.h"
#include <stdlib.h>
/****************************** MACROS ******************************/
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define BUFFER_SIZE (100) /*Common Buffer size for input*/

/***************************** function decration*********************/

void clean_stdin(void); // To clear the input buffer , implementaion is after main function

/*********************** MAIN FUNCTION DEFINITIONS ***********************/

int main()
{
    printf("%s\n", "*********************************************** TextPad Password Maneger ***********************************************");
    while (true)
    {
        if (masterUserAccountExist())
        {
            while (true)
            {
                char username[BUFFER_SIZE]; // for user input
                char password[BUFFER_SIZE]; // for user input
                char input;

                printf("%s\n", "Enter Master Username");
                fgets(username, BUFFER_SIZE, stdin);

                printf("%s\n", "Enter Master password");
                fgets(password, BUFFER_SIZE, stdin);

                if (verifyMasterUserAccount(username, password))
                {
                    break;
                }

                system(CLEAR);
                printf("%s\n", "Master Username or Master  Password is incorrect.");
                printf("%s\n", ">Enter 1 to try again\n>Enter 0 to exit");

                input = getchar();

                if (input == '0')
                {
                    return 0;
                }
                clean_stdin();
            }
            while (true)
            {
                /* code */

                system(CLEAR);
                printf("%s\n", "Enter the index for operation to perform");
                printf("%s\n", "Enter 1 to change Master Username");
                printf("%s\n", "Enter 2 to change Master Password");
                printf("%s\n", "Enter 3 to add New Credential");
                printf("%s\n", "Enter 4 to Search a Credential");
                printf("%s\n", "Enter 5 to Show All Credentials");
                printf("%s\n", "Enter 6 to EXIT");
                char input;

                scanf(" %c", &input);
                switch (input)
                {
                case '1':
                {
                    while (true)
                    {
                        system(CLEAR);
                        char new_username[BUFFER_SIZE];
                        char inside_input;

                        clean_stdin();
                        printf("%s\n", "Enter New Master Username");
                        fgets(new_username, BUFFER_SIZE, stdin);

                        if (usernameFormatCheck(new_username))
                        {
                            modifyMasterUsername(new_username);
                            printf("%s\n", "Username Changed Successfully");
                            break;
                        }

                        printf("%s\n", ">Enter 1 to try again\n>Enter 0 to exit");

                        inside_input = getchar();
                        if (inside_input == '0')
                        {
                            printf("%s", "Exiting the program");
                            return 0;
                        }
                    }
                    break;
                }

                case '2':
                {
                    while (true)
                    {
                        system(CLEAR);
                        char new_password[BUFFER_SIZE];
                        char inside_input;

                        clean_stdin();
                        printf("%s\n", "Enter New Master Password");
                        fgets(new_password, BUFFER_SIZE, stdin);

                        if (passwordFormatCheck(new_password))
                        {
                            modifyMasterPassword(new_password);
                            printf("%s\n", " Password Changed Successfully");
                            break;
                        }

                        printf("%s\n", ">Enter 1 to try again\n>Enter 0 to exit");

                        inside_input = getchar();
                        if (inside_input == '0')
                        {
                            printf("%s", "Exiting the program");
                            return 0;
                        }
                    }
                    break;
                }

                case '3':
                {
                    char new_organisation[BUFFER_SIZE];
                    char new_username[BUFFER_SIZE];
                    char new_password[BUFFER_SIZE];

                    printf("%s\n", "Enter Organisation Name");
                    clean_stdin();
                    fgets(new_organisation, BUFFER_SIZE, stdin);

                    printf("%s\n", "Enter Username");
                    fgets(new_username, BUFFER_SIZE, stdin);

                    printf("%s\n", "Enter Password");
                    fgets(new_password, BUFFER_SIZE, stdin);

                    addNewCredential(new_organisation, new_username, new_password);

                    break;
                }
                case '4':
                {
                    char organisation[BUFFER_SIZE];
                    char username[BUFFER_SIZE];
                    credential temp_credential;

                    clean_stdin();
                    printf("%s\n", "Enter Organisation Name to search");
                    fgets(organisation, BUFFER_SIZE, stdin);

                    printf("%s\n", "Enter Username to search");
                    fgets(username, BUFFER_SIZE, stdin);

                    if (searchCredential(organisation, username, &temp_credential) == FAILURE)
                    {
                        printf("%s\n", "No Such Credential Found");
                        break;
                    }

                    while (true)
                    {
                        char inside_input;
                        printf("%s\n", "********************************************");
                        printf("Organisation -> %s\n", temp_credential.organisationName);
                        printf("Username -> %s\n", temp_credential.username);
                        printf("PASSWORD -> %s\n", temp_credential.password);
                        printf("%s\n", "********************************************");

                        printf("%s\n", "Press 1 to change the Organisation Name");
                        printf("%s\n", "Press 2 to change the Userame");
                        printf("%s\n", "Press 3 to change the Password");
                        printf("%s\n", "Press 0 to exit");

                        inside_input = getchar();

                        if (inside_input == '0')
                        {
                            system(CLEAR);
                            printf("%s\n", "Exiting to main menu");
                            break;
                        }
                        else if (inside_input == '1')
                        {
                            char new_organisation[BUFFER_SIZE];

                            clean_stdin();
                            printf("%s\n", "Enter new organisaion name");
                            fgets(new_organisation, BUFFER_SIZE, stdin);

                            modifyCredentialOrganisation(temp_credential.organisationName, temp_credential.username, new_organisation);
                            strcpy(temp_credential.organisationName, new_organisation);

                            system(CLEAR);
                            printf("%s\n", "***Organisation name changed Successfully");
                        }

                        else if (inside_input == '2')
                        {
                            char new_username[BUFFER_SIZE];

                            clean_stdin();
                            printf("%s\n", "Enter new username");
                            fgets(new_username, BUFFER_SIZE, stdin);

                            modifyCredentialUsername(temp_credential.organisationName, temp_credential.username, new_username);
                            strcpy(temp_credential.username, new_username);

                            system(CLEAR);
                            printf("%s\n", "**Username changed Succcessfully");
                        }

                        else if (inside_input == '3')
                        {
                            char new_password[BUFFER_SIZE];

                            clean_stdin();
                            printf("%s\n", "Enter new organisaion name");
                            fgets(new_password, BUFFER_SIZE, stdin);

                            modifyCredentialPassword(temp_credential.organisationName, temp_credential.username, new_password);
                            strcpy(temp_credential.password, new_password);

                            system(CLEAR);
                            printf("%s\n", "**Password Chnaged Successfully");
                        }

                        else
                        {
                            printf("%s\n", "Invalid Option Please try again");
                            break;
                        }
                    }

                    break;
                }
                case '5':
                    system(CLEAR);
                    showAllCredentials();

                    break;
                case '6':

                    printf("%s\n", "Exiting the program");
                    return 0;
                    break;

                default:
                    system(CLEAR);
                    printf("%s\n\n", "Invalid input, Please try Again");
                    break;
                }
            }
        }
        else // Create new Master Account
        {
            char username[BUFFER_SIZE]; // for new username
            char password[BUFFER_SIZE]; // for new password
            printf("%s\n", "Master Acount Does Not exist");

            while (true) // Until Username format is not correct
            {
                printf("%s\n", "Please Enter New Username");
                //fgets(username, BUFFER_SIZE, stdin);

                fgets(username, BUFFER_SIZE, stdin);

                usernameFormatCheck(username);
                //if format is correct exit the loop
                if (usernameFormatCheck(username))
                {
                    break;
                }
                printf("%s\n", "Please Try Again");
            }

            while (true) // Until Password format is not correct
            {

                printf("%s\n", "Please Enter New password");
                //fgets(password, BUFFER_SIZE, stdin);

                fgets(password, BUFFER_SIZE, stdin);

                system(CLEAR);
                passwordFormatCheck(password);
                //if format is correct exit the loop
                if (passwordFormatCheck(password))
                {
                    break;
                }
                printf("%s\n", "Please Try Again");
            }

            createMasterUserAccount(username, password);
        }
    }
}

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}