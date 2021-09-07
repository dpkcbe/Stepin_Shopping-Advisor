/** 
* @author Deeksha Tripathi(deeksha18799@gmail.com)
* @file passwordUsernameFormatChecker.c
* @brief Definition of functions related to Password format checker
*
*/

/*************************** HEADER FILES ***************************/
#include "passwordUsernameFormatChecker.h"

/*********************** FUNCTION DEFINITIONS ***********************/
bool containSpecialCharacter(const char *str)
{
    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        //checking each character of the string for special character.
        if (str[index] == '!' ||
            str[index] == '@' ||
            str[index] == '#' ||
            str[index] == '$' ||
            str[index] == '%' ||
            str[index] == '^' ||
            str[index] == '&' ||
            str[index] == '*' ||
            str[index] == '(' ||
            str[index] == ')' ||
            str[index] == '-' ||
            str[index] == '{' ||
            str[index] == '}' ||
            str[index] == '[' ||
            str[index] == ']' ||
            str[index] == ':' ||
            str[index] == ';' ||
            str[index] == '\\' ||
            str[index] == '"' ||
            str[index] == '<' ||
            str[index] == '>' ||
            str[index] == '.' ||
            str[index] == '/' ||
            str[index] == '?' ||
            str[index] == '~' ||
            str[index] == '`')
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool containNumber(const char *str)
{

    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        if (isdigit(str[index]))
        {
            flag = true;
            break;
        }
    }

    return flag;
}

bool containLowerCaseLetter(const char *str)
{
    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        if (str[index] >= 'a' && str[index] <= 'z')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool containUpperCaseLetter(const char *str)
{
    bool flag = false;

    for (unsigned int index = 0; index < strlen(str); index++)
    {
        if (str[index] >= 'A' && str[index] <= 'Z')
        {
            flag = true;
            break;
        }
    }
    return flag;
}

bool passwordFormatCheck(const char *password)
{
    bool IsFormatCorrect = true;

    //Passsword length shoud be between 8 and 14
    if (strlen(password) < 8 || strlen(password) > 14)
    {
        printf("-> %s\n", "Password length is not between 8-14 characters.");
        IsFormatCorrect = false;
    }

    //Password should not contain any spaces;
    if (strchr(password, ' ') != NULL)
    {
        printf("-> %s\n", "Password contain Space character. Remove any spaces");
        IsFormatCorrect = false;
    }

    //Password Should contain special Characters
    if (!containSpecialCharacter(password))
    {
        printf("-> %s\n", "Password dose not contain Special Characters. Add at least one Special character");
        IsFormatCorrect = false;
    }

    //password should contain lowercaseletter
    if (!containLowerCaseLetter(password))
    {
        printf("-> %s\n", "Password Does not contain Lower Case Letter. Add at least one Lower Case Letter");
        IsFormatCorrect = false;
    }

    //password should contain uppercase letter
    if (!containUpperCaseLetter(password))
    {
        printf("-> %s\n", "Password Does not contain Upper Case Letter. Add at least one Upper Case Letter");
        IsFormatCorrect = false;
    }

    //password should contain Number
    if (!containNumber(password))
    {
        printf("-> %s\n", "Password Does not contain Number. Add at least one numeric Character");
        IsFormatCorrect = false;
    }
    else
    {
    }

    return IsFormatCorrect;
}

bool usernameFormatCheck(const char *username)
{

    bool IsFormatCorrect = true;
    // username length should be between 4 and 15
    if (strlen(username) < 4 || strlen(username) > 15)
    {
        printf("-> %s\n", "Username length is not between 4-15 characters.");
        IsFormatCorrect = false;
    }

    //username should not contain any spaces
    if (strchr(username, ' ') != NULL)
    {
        printf("-> %s\n", "Username contain Space character");
        IsFormatCorrect = false;
    }

    // username should not contain any special characters
    if (containSpecialCharacter(username))
    {
        printf("-> %s\n", "Username contain Special Characters. ");
        IsFormatCorrect = false;
    }

    return IsFormatCorrect;
}