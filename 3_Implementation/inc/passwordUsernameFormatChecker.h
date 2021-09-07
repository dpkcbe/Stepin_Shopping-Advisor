/** 
* @author Deeksha Tripathi(deeksha18799@gmail.com)
* @file passwordUsernameFormatChecker.h
* @brief Define the API to check the format of the password and username
*
*/
#ifndef __PASSWORD_USERNAME_FORMAT_CHECKER_H__
#define __PASSWORD_USERNAME_FORMAT_CHECKER_H__

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/**************************** DATA TYPES ****************************/

/*********************** FUNCTION DECLARATIONS **********************/
/**
* @brief check if string contain special characters or not
* @param[in] string
* @return  true if string contains a special character otherwise returns false
*/
bool containSpecialCharacter(const char *str);

/**
* @brief check if string contains number or not
* @param[in] string 
* @return  true if string contains a number otherwise returns false
*/
bool containNumber(const char *str);

/**
* @brief check if string contain lower case letter or not
* @param[in] string 
* @return  true if string contains a lower case otherwise returns false
*/
bool containLowerCaseLetter(const char *str);

/**
* @brief check if string contain upper case letter or not
* @param[in] string
* @return  true if string contains a upper case otherwise returns false
*/
bool containUpperCaseLetter(const char *str);

/**
* @brief Password format checklist basically checks if the password is valid or not based on password policies mention below:
* 1) Password should not contain any space.
* 2) Password should contain at least one digit(0-9).
* 3) Password length should be between 8 to 15 characters.
* 4) Password should contain at least one lowercase letter(a-z).
* 5) Password should contain at least one uppercase letter(A-Z).
* 6) Password should contain at least one special character ( @, #, %, &, !, $, etc….).
* @param[in] string password 
* @return  true if password format is correct
*/
bool passwordFormatCheck(const char *str);

/**
* @brief Username format checklist basically checks if the password is valid or not based on password policies mention below: 
* 1) Username should not contain any space.
* 2) Username length should be between 4 to 15 characters.
* 3) Username should not contain any special character ( @, #, %, &, !, $, etc….).
* @param[in] string username
* @return  true if username format is correct
*/
bool usernameFormatCheck(const char *str);

#endif /* #define __CALCULATOR_OPERATIONS_H__ */