#include "unity.h"
#include "passwordUsernameFormatChecker.h"
#include "masterAccountFunctions.h"
#include "credentialFunctions.h"
#define PROJECT_NAME "TextPad"

/* Prototypes for all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/
void test_containSpecialCharacter(void);
void test_containNumber(void);
void test_containLowerCaseLetter(void);
void test_containUpperCaseLetter(void);
void test_passwordFormatCheck(void);
void test_usernameFormatCheck(void);

/********************************
 * Filename -> masterAccountFunctions.c
*/
void test_userAccountExist(void);
void test_createMasteUserAccount(void);
void test_verifyMasterUserAccount(void);
void test_deleteMasterUserAccount(void);
void test_modifyMasterUsername(void);
void test_modifyMasterPassword(void);

/********************************
 * Filename -> credentialFunctions.c
*/
void test_addNewCredential(void);
void test_showAllCredentials(void);
void test_deleteAllCredentials(void);
void test_searchCredential(void);
void test_credentialExist(void);
void test_modifyCredentialUsername(void);
void test_modifyCredentialOrganisation(void);
void test_modifyCredentialPassword(void);
/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown() {}

/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */

  /********************************
 * Filename -> passwordUsernameFormatChecker.c
 */
  RUN_TEST(test_containSpecialCharacter);
  RUN_TEST(test_containNumber);
  RUN_TEST(test_containLowerCaseLetter);
  RUN_TEST(test_containUpperCaseLetter);
  RUN_TEST(test_passwordFormatCheck);
  RUN_TEST(test_usernameFormatCheck);

  /********************************
 * Filename -> masterAccountFunctions.c
*/
  RUN_TEST(test_userAccountExist);
  RUN_TEST(test_createMasteUserAccount);
  RUN_TEST(test_verifyMasterUserAccount);
  RUN_TEST(test_deleteMasterUserAccount);
  RUN_TEST(test_modifyMasterUsername);
  RUN_TEST(test_modifyMasterPassword);

  /********************************
 * Filename -> credentialFunctions.c
*/
  RUN_TEST(test_addNewCredential);
  RUN_TEST(test_showAllCredentials);
  RUN_TEST(test_deleteAllCredentials);
  RUN_TEST(test_searchCredential);
  RUN_TEST(test_credentialExist);
  RUN_TEST(test_modifyCredentialUsername);
  RUN_TEST(test_modifyCredentialOrganisation);
  RUN_TEST(test_modifyCredentialPassword);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */

/********************************
 * Filename -> passwordUsernameFormatChecker.c
*/
void test_containSpecialCharacter(void)
{
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankit$kumar"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("ankitkumar#"));
  TEST_ASSERT_EQUAL(true, containSpecialCharacter("@ankit$kumar*"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("ankitkumars d"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
  TEST_ASSERT_EQUAL(false, containSpecialCharacter("asdfsad"));
}

void test_containNumber(void)
{
  TEST_ASSERT_EQUAL(true, containNumber("ankit23kumar"));
  TEST_ASSERT_EQUAL(true, containNumber("ankitkumar23"));
  TEST_ASSERT_EQUAL(true, containNumber("12ankitkumar"));
  TEST_ASSERT_EQUAL(false, containNumber("ankitkumar"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FS23D$#$@!#!@"));
}

void test_containLowerCaseLetter()
{
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("andaskjds"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("ANKITUMAr"));
  TEST_ASSERT_EQUAL(true, containLowerCaseLetter("aNKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(false, containLowerCaseLetter("####$!@$!$!$#$@!#!@"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$er#$@!#!@"));
}

void test_containUpperCaseLetter()
{
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ANKITKUMAR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("ankitkumaR"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("Ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("ankitkumar"));
  TEST_ASSERT_EQUAL(false, containUpperCaseLetter("####$!@$!$!$#$@!#!@"));
  TEST_ASSERT_EQUAL(true, containUpperCaseLetter("####$!@$!$!FSD$#$@!#!@"));
}

void test_passwordFormatCheck(void)
{
  TEST_ASSERT_EQUAL(true, passwordFormatCheck("@nkitKumar123"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("nk"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("asdfasdfsdafasdfasdfaf"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("@nkitKumar"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("ankit$umar123"));
  TEST_ASSERT_EQUAL(false, passwordFormatCheck("@NKITKUMAR123"));
}

void test_usernameFormatCheck()
{
  TEST_ASSERT_EQUAL(true, usernameFormatCheck("ankit123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@nkitKumar123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("nk"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("asdfasdfsdafasdfasdfaf"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@nkitKumar"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("ankit$umar123"));
  TEST_ASSERT_EQUAL(false, usernameFormatCheck("@NKITKUMAR123"));
}

/********************************
 * Filename -> masterAccountFunctions.c
*/
void test_userAccountExist(void)
{
  deleteMasterUserAccount();
  TEST_ASSERT_EQUAL(false, masterUserAccountExist());

  createMasterUserAccount("AnkitKumar", "Ankit123");
  TEST_ASSERT_EQUAL(true, masterUserAccountExist());
}

void test_createMasteUserAccount(void)
{
  TEST_ASSERT_EQUAL(SUCCESS, createMasterUserAccount("AnkitKumar", "Ankit123"));
  TEST_ASSERT_EQUAL(NULL_PTR, createMasterUserAccount(NULL, NULL));
}

void test_verifyMasterUserAccount(void)
{
  createMasterUserAccount("AnkitKumar", "Ankit123");
  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("AnkitKumar", "Ankit123"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnshulKumar", "Ankit12334"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar", "Ankit123232312"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar2323", "Ankit123"));

  createMasterUserAccount("RandomUSERNMAE@#@$!@#", "RandomPassword@#$#@");

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("RandomUSERNMAE@#@$!@#", "RandomPassword@#$#@"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnshulKumar", "Ankit12334"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar", "Ankit123232312"));
  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("AnkitKumar2323", "Ankit123"));
}

void test_deleteMasterUserAccount(void)
{
  createMasterUserAccount("Ankit123", "Ankit123");
  TEST_ASSERT_EQUAL(SUCCESS, deleteMasterUserAccount());

  TEST_ASSERT_EQUAL(FAILURE, deleteMasterUserAccount());
}

void test_modifyMasterPassword(void)
{
  createMasterUserAccount("old_username", "old_password");

  TEST_ASSERT_EQUAL(SUCCESS, modifyMasterPassword("new_password"));

  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("old_username", "old_password"));

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("old_username", "new_password"));
}

void test_modifyMasterUsername(void)
{
  createMasterUserAccount("old_username", "old_password");

  TEST_ASSERT_EQUAL(SUCCESS, modifyMasterUsername("new_username"));

  TEST_ASSERT_EQUAL(false, verifyMasterUserAccount("old_username", "old_password"));

  TEST_ASSERT_EQUAL(true, verifyMasterUserAccount("new_username", "old_password"));
}

/********************************
 * Filename -> credentialFunctions.c
*/

void test_addNewCredential(void)
{
  TEST_ASSERT_EQUAL(SUCCESS, addNewCredential("facebook", "Ankit", "ankit123"));
  TEST_ASSERT_EQUAL(SUCCESS, addNewCredential("twitter", "Ankit", "ankit123"));
  TEST_ASSERT_EQUAL(FAILURE, addNewCredential("facebook", "Ankit", "ankit123"));
  TEST_ASSERT_EQUAL(NULL_PTR, addNewCredential(NULL, "Ankit", "ankit123"));
  TEST_ASSERT_EQUAL(EMPTY_STRING, addNewCredential("", "", "ankit123"));
  TEST_ASSERT_EQUAL(NULL_PTR, addNewCredential("as", "Ankit", NULL));

  deleteAllCredentials();
}
void test_showAllCredentials(void)
{
  addNewCredential("facebook", "Ankit", "ankit123");
  addNewCredential("twitter", "Ankit", "ankit123");
  TEST_ASSERT_EQUAL(SUCCESS, showAllCredentials());
  deleteAllCredentials();

  TEST_ASSERT_EQUAL(FAILURE, showAllCredentials());

  deleteAllCredentials();
}

void test_deleteAllCredentials(void)
{
  addNewCredential("facebook", "Ankit", "ankit123");
  TEST_ASSERT_EQUAL(SUCCESS, deleteAllCredentials());
  TEST_ASSERT_EQUAL(FAILURE, deleteAllCredentials());
}

void test_searchCredential(void)
{
  credential temp_credential;
  addNewCredential("facebook", "Ankit", "ankit123");
  addNewCredential("twitter", "Ankit", "ankit123");
  addNewCredential("Random Organisation", "Ankit Kumar", "@nkit123");

  searchCredential("twitter", "Ankit", &temp_credential);

  TEST_ASSERT_EQUAL_CHAR_ARRAY("twitter", temp_credential.organisationName, strlen(temp_credential.organisationName));

  TEST_ASSERT_EQUAL_CHAR_ARRAY("Ankit", temp_credential.username, strlen(temp_credential.username));

  TEST_ASSERT_EQUAL_CHAR_ARRAY("ankit123", temp_credential.password, strlen(temp_credential.password));

  TEST_ASSERT_EQUAL(SUCCESS, searchCredential("twitter", "Ankit", &temp_credential));
  TEST_ASSERT_EQUAL(SUCCESS, searchCredential("Random Organisation", "Ankit Kumar", &temp_credential));
  TEST_ASSERT_EQUAL(FAILURE, searchCredential("twitter", "Ankit Kumar", &temp_credential));
  TEST_ASSERT_EQUAL(FAILURE, searchCredential("DontKnow", "Ankit Kumar", &temp_credential));

  TEST_ASSERT_EQUAL(NULL_PTR, searchCredential(NULL, "Ankit Kumar", &temp_credential));
  TEST_ASSERT_EQUAL(EMPTY_STRING, searchCredential("", "Ankit Kumar", &temp_credential));
  TEST_ASSERT_EQUAL(NULL_PTR, searchCredential("Ankit Kumar", NULL, &temp_credential));
  TEST_ASSERT_EQUAL(EMPTY_STRING, searchCredential("Ankit Kumar", "", &temp_credential));

  // creeating empty file
  FILE *test_file = fopen(CREDENTIAL_FILE, "w");
  fclose(test_file);

  TEST_ASSERT_EQUAL(FAILURE, searchCredential("DontKnow", "Ankit Kumar", &temp_credential));

  deleteAllCredentials();

  TEST_ASSERT_EQUAL(FAILURE, searchCredential("DontKnow", "Ankit Kumar", &temp_credential));
}

void test_credentialExist(void)
{
  addNewCredential("twitter", "Ankit", "ankit123");
  addNewCredential("Random Organisation", "Ankit Kumar", "@nkit123");

  TEST_ASSERT_EQUAL(true, credentialExist("twitter", "Ankit"));
  TEST_ASSERT_EQUAL(true, credentialExist("Random Organisation", "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("twitter", "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("DontKnow", "Ankit Kumar"));

  TEST_ASSERT_EQUAL(false, credentialExist(NULL, "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("", "Ankit Kumar"));
  TEST_ASSERT_EQUAL(false, credentialExist("Ankit Kumar", NULL));
  TEST_ASSERT_EQUAL(false, credentialExist("Ankit Kumar", ""));

  // creeating empty file
  FILE *test_file = fopen(CREDENTIAL_FILE, "w");
  fclose(test_file);

  TEST_ASSERT_EQUAL(false, credentialExist("DontKnow", "Ankit Kumar"));

  deleteAllCredentials();
  TEST_ASSERT_EQUAL(false, credentialExist("DontKnow", "Ankit Kumar"));
}

void test_modifyCredentialUsername(void)
{
  addNewCredential("1_facebook", "Ankit", "ankit123");
  addNewCredential("2_twitter", "Ankit", "ankit123");
  addNewCredential("3_facebook", "Ankit", "ankit123");
  addNewCredential("4_twitter", "Ankit", "ankit123");
  addNewCredential("5_facebook", "Ankit", "ankit123");
  addNewCredential("6_twitter", "Ankit", "ankit123");
  addNewCredential("7_facebook", "Ankit", "ankit123");
  addNewCredential("8_facebook", "Ankit", "ankit123");
  addNewCredential("9_twitter", "Ankit", "ankit123");
  addNewCredential("10_facebook", "Ankit", "ankit123");
  addNewCredential("11_twitter", "Ankit", "ankit123");
  addNewCredential("12_facebook", "Ankit", "ankit123");
  addNewCredential("13_twitter", "Ankit", "ankit123");
  addNewCredential("14_facebook", "Ankit", "ankit123");
  addNewCredential("15_twitter", "Ankit", "ankit123");

  TEST_ASSERT_EQUAL(SUCCESS, modifyCredentialUsername("1_facebook", "Ankit", "New_username"));

  modifyCredentialUsername("8_facebook", "Ankit", "New_username");

  TEST_ASSERT_EQUAL(true, credentialExist("8_facebook", "New_username"));

  TEST_ASSERT_EQUAL(false, credentialExist("8_facebook", "Ankit"));

  deleteAllCredentials();
}
void test_modifyCredentialOrganisation(void)
{
  addNewCredential("1_facebook", "Ankit", "ankit123");
  addNewCredential("2_twitter", "Ankit", "ankit123");
  addNewCredential("3_facebook", "Ankit", "ankit123");
  addNewCredential("4_twitter", "Ankit", "ankit123");
  addNewCredential("5_facebook", "Ankit", "ankit123");
  addNewCredential("6_twitter", "Ankit", "ankit123");
  addNewCredential("7_facebook", "Ankit", "ankit123");
  addNewCredential("8_facebook", "Ankit", "ankit123");
  addNewCredential("9_twitter", "Ankit", "ankit123");
  addNewCredential("10_facebook", "Ankit", "ankit123");
  addNewCredential("11_twitter", "Ankit", "ankit123");
  addNewCredential("12_facebook", "Ankit", "ankit123");
  addNewCredential("13_twitter", "Ankit", "ankit123");
  addNewCredential("14_facebook", "Ankit", "ankit123");
  addNewCredential("15_twitter", "Ankit", "ankit123");

  TEST_ASSERT_EQUAL(SUCCESS, modifyCredentialUsername("1_facebook", "Ankit", "New_username"));

  modifyCredentialUsername("8_facebook", "Ankit", "New_username");

  TEST_ASSERT_EQUAL(true, credentialExist("8_facebook", "New_username"));

  TEST_ASSERT_EQUAL(false, credentialExist("8_facebook", "Ankit"));
  deleteAllCredentials();
}
void test_modifyCredentialPassword(void)
{
  addNewCredential("1_facebook", "Ankit", "ankit123");
  addNewCredential("2_twitter", "Ankit", "ankit123");
  addNewCredential("3_facebook", "Ankit", "ankit123");
  addNewCredential("4_twitter", "Ankit", "ankit123");
  addNewCredential("5_facebook", "Ankit", "ankit123");
  addNewCredential("6_twitter", "Ankit", "ankit123");
  addNewCredential("7_facebook", "Ankit", "ankit123");
  addNewCredential("8_facebook", "Ankit", "ankit123");
  addNewCredential("9_twitter", "Ankit", "ankit123");
  addNewCredential("10_facebook", "Ankit", "ankit123");
  addNewCredential("11_twitter", "Ankit", "ankit123");
  addNewCredential("12_facebook", "Ankit", "ankit123");
  addNewCredential("13_twitter", "Ankit", "ankit123");
  addNewCredential("14_facebook", "Ankit", "ankit123");
  addNewCredential("15_twitter", "Ankit", "ankit123");

  credential cred;

  TEST_ASSERT_EQUAL(SUCCESS, modifyCredentialPassword("1_facebook", "Ankit", "New_Password"));

  modifyCredentialPassword("8_facebook", "Ankit", "New_Password");
  searchCredential("8_facebook", "Ankit", &cred);

  TEST_ASSERT_EQUAL_CHAR_ARRAY("New_Password", cred.password, strlen(cred.password));

  deleteAllCredentials();
}