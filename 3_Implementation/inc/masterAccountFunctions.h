/** 
* @author Deeksha Tripathi(deeksha18799@gmail.com)
* @file masterAccountFunctions.h
* @brief Define the API for master user account management
*
*/

#ifndef __MASTER_ACCOUNT_FUNCTIONS_H__
#define __MASTER_ACCOUNT_FUNCTIONS_H__

/*************************** HEADER FILES ***************************/
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "common.h"
#include "passwordUsernameFormatChecker.h"
#include "credentialFunctions.h"
#include "sha256.h"

/****************************** MACROS ******************************/
#define USER_FILE "MasterUserData.dat"

/*********************** FUNCTION DECLARATIONS **********************/

/**
* @brief create a new Mater User Account
* @param[in] string username
* @param[in] string password
* @return  SUCCESS if Master User Account created successfully
*/
status createMasterUserAccount(const char *username, const char *password);

/**
* @brief create a new Mater User Account
* @return  SUCCESS if Master User Account deleted successfully
*/
status deleteMasterUserAccount();

/**
* @brief To change Master user name
* @param[in] string new_username
* @return  SUCCESS if Master Username changed successfully
*/
status modifyMasterUsername(const char *new_username);

/**
* @brief To change Master password
* @param[in] string new_password
* @return  SUCCESS if Master Password changed successfully
*/
status modifyMasterPassword(const char *new_password);

/**
* @brief match enterd password and username with existing master user credentials
* @param[in] string username
* @param[in] string password
* @return  true if credential entered are correct
*/
bool verifyMasterUserAccount(const char *username, const char *password);

/**
* @brief check if master user account exist.
* @return  true if master account exist otherwise false.
*  
*/
bool masterUserAccountExist();

#endif /* #define __MASTER_ACCOUNT_FUNCTIONS_H__*/