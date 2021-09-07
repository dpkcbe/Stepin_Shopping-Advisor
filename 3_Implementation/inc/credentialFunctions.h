/** 
* @author Deeksha Tripathi(deeksha18799@gmail.com)
* @file credetnialFunctions.h
* @brief Define the API for User Credential management
*
*/

#ifndef __CREDENTIAL_FUNCTIONS_H__
#define __CREDENTIAL_FUNCTIONS_H__

/*************************** HEADER FILES ***************************/
#include "common.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

/****************************** MACROS ******************************/
#define CREDENTIAL_FILE "credentialFile.dat"

/**************************** DATA TYPES ****************************/
typedef struct
{
    char organisationName[40];
    char username[15];
    char password[16];

} credential;

/*********************** FUNCTION DECLARATIONS **********************/

/**
* @brief To Add new user credentials
* @param[in] string organisation_name
* @param[in] string username
* @param[in] string password
* @return  SUCCESS if Master Username changed successfully otherwise FAILURE
*/
status addNewCredential(const char *organisationName, const char *username, const char *password);

/**
* @brief To delete credential
* @param[in] string organisation_name
* @param[in] string username
* @return  SUCCESS if credential is successfully deleted otherwise FAILURE
*/
status deleteCredential(const char organisationName, const char *username);

/**
* @brief To change Organisation name in  credential
* @param[in] credential pointer to credential data
* @param[in] string new_Organisation_name
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
status modifyCredentialOrganisation(char *organisation, char *username, char *new_Organisation_name);

/**
* @brief To change Username in credentials
* @param[in]  string organisation name
* @param[in] string username
* @param[in] string new_username
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
status modifyCredentialUsername(char *organisation, char *username, char *new_username);

/**
* @brief To password credentials
* @param[in]  string organisation name
* @param[in] string username
* @param[in] string new_password
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
status modifyCredentialPassword(char *organisation, char *username, char *new_password);

/**
* @brief To search credentials
* @param[in] string organisation_name
* @param[in] string username
* @return  SUCCESS if credentials arr found otherwise FAILURE
*/
status searchCredential(const char *organisationName, const char *username, credential *out_credential);

/**
* @brief To print all saved credentials 
* @return  Print all the credentials
*/
status showAllCredentials();

/**
* @brief To delte all credentials at once
* @return  SUCCESS if all the credentials are successfully deleted otherwise FAILURE
*/
status deleteAllCredentials();

/**
* @brief To find if credential exist or not at once
* @param[in] string organisation_name
* @param[in] string username
* @return  true if credential exist in CREDENTIAL_FILE otherwise false
*/
bool credentialExist(const char *organisationName, const char *username);

#endif