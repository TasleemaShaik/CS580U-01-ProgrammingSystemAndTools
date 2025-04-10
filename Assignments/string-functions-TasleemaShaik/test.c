#include "functions.h"
#include "solutions.h"
#include "randstr.h"
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *strs[10] = {
  "Binghamton",
  "Bing\0hamton",
  "DETERMINISM",
  "powerlessly",
  "censorious",
  "BADC0FFEE0ddf00d",
  "concurrently",
  "abaft",
  "lexicon truculent wherewithal zenith",
  "down-and-out"
};

char *sstrs[10] = {
  "Bing",
  "bing",
  "TERM",
  "ss",
  "io",
  "",
  "rent",
  "abaft",
  "lent",
  "-and-"
};

char *padded[10] = {
  "danger LARVA takeoff\0",
  "    AMBIENCE peril romanian    ",
  "\f\nCLIP gnostic radon\n\f",
  "\tportent MONITOR tumid\v",
  "licence stencil LAD\r\n",
  "internet\0 misdeed TECTA       ",
  "\t\t\tbuggy chaos ULULATE",
  " lip KETTLE emblem ",
  "    MIDST gardenia lay",
  "\t    \tSENTINEL paint mutter\n"
};

/* The suite initialization function.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite(void) {
  // Initialize random integer for tests
  srand(time(NULL)); 

  return 0;
}

/* The suite cleanup function.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite(void) {
  return 0;
}

void testNO_STRING_H(void){
  FILE *fp;
  char word[1024];
  char ch;
  bool has_string_h = false;

  /*  open for reading */
  fp = fopen("functions.c", "r");
  if (!fp) {
    CU_FAIL_FATAL("Couldn't open functions.c!");
  }

  do {
    ch = fscanf(fp, "%s", word);
    if (strcmp(word, "<string.h>") == 0) {
      has_string_h = true;
      break;
    }
  } while (ch != EOF);
  fclose(fp);

  if (has_string_h) {
    CU_FAIL("Included <string.h>");
  }
  else{
    CU_PASS("Didn't include <string.h>");
  }
}

void testMYSTRLEN(void) {
  for (size_t i = 0; i < 10; ++i) {
    CU_ASSERT_EQUAL(mystrlen(strs[i]), _mystrlen(strs[i]));
  }

  for (size_t i = 10; i < 20; ++i) {
    char *word = randstr();
    CU_ASSERT_EQUAL(mystrlen(word), _mystrlen(word));
    free(word);
  }
}

void testMYSTRCMP(void) {
  for (int i = 0; i < 10; ++i) {
    CU_ASSERT_EQUAL(mystrcmp(strs[i],sstrs[i]),_mystrcmp(strs[i],sstrs[i]));
  }

  for (int i = 10; i < 20; ++i){
    char *word = randstr();
    char *sword = randsubstr(word);
    
    CU_ASSERT_EQUAL(mystrcmp(word,sword),_mystrcmp(word,sword));
    
    free(word);
    free(sword);
  }
}

void testMYSTRSTR(void) {
  for (int i = 0; i < 10; ++i) {
    CU_ASSERT_EQUAL(mystrstr(strs[i],sstrs[i]),_mystrstr(strs[i],sstrs[i]));
  }

  for (int i = 10; i < 20; ++i){
    char *word = randstr();
    char *sword = randsubstr(word);
    char *notsword = randstr();
    
    if (rand() % 2) {
      CU_ASSERT_PTR_EQUAL(mystrstr(word,sword),_mystrstr(word,sword));
    } else {
      CU_ASSERT_PTR_EQUAL(mystrstr(word,notsword),_mystrstr(word,notsword));
    }
    
    free(word);
    free(sword);
    free(notsword);
  }
}

void testMYSTRSTRIP(void) {
  for (int i = 0; i < 10; ++i)
  {
    char *actual = mystrstrip(strs[i]);
    char *expected = _mystrstrip(strs[i]);

    if (!actual || !expected){
      CU_ASSERT_PTR_NOT_NULL_FATAL(actual);
      CU_ASSERT_PTR_NOT_NULL_FATAL(expected);
    } else
      CU_ASSERT_STRING_EQUAL(actual,expected);

    free(actual);
    free(expected);
  }

  for (int i = 10; i < 20; ++i)
  {
    char *actual = mystrstrip(padded[i-10]);
    char *expected = _mystrstrip(padded[i-10]);
    
    CU_ASSERT_STRING_EQUAL(actual,expected);

    free(actual);
    free(expected);
  }
}

void testANYALL(void){
  char *strs[10] = {
  "Binghamton",
  "Bing\x04\0hamton",
  "DETERMINISM",
  "powerlessly",
  "censorious",
  "BADC0FFEE0ddf00d",
  "concurrently",
  "abaft",
  "lexicon truculent wherewithal zenith",
  "down-and-out"
};
  CU_ASSERT_TRUE(all(strs[0], mystrlen(strs[0]), sizeof(char), &myisalnum));
  CU_ASSERT_FALSE(all(strs[1], mystrlen(strs[1]), sizeof(char), &myiscntrl));
  CU_ASSERT_FALSE(all(strs[2], mystrlen(strs[2]), sizeof(char), &myisdigit));
  CU_ASSERT_TRUE(all(strs[3], mystrlen(strs[3]), sizeof(char), &myislower));
  CU_ASSERT_TRUE(all(strs[4], mystrlen(strs[4]), sizeof(char), &myisprint));
  CU_ASSERT_TRUE(all(strs[5], mystrlen(strs[5]), sizeof(char), &myisxdigit));
  CU_ASSERT_TRUE(all(strs[6], mystrlen(strs[6]), sizeof(char), &myisalpha));
  CU_ASSERT_FALSE(all(strs[7], mystrlen(strs[7]), sizeof(char), &myisupper));
  CU_ASSERT_FALSE(all(strs[8], mystrlen(strs[8]), sizeof(char), &myisspace));
  CU_ASSERT_FALSE(all(strs[9], mystrlen(strs[9]), sizeof(char), &myispunct));

  CU_ASSERT_TRUE(any(strs[0], mystrlen(strs[0]), sizeof(char), &myisalnum));
  CU_ASSERT_TRUE(any(strs[1], mystrlen(strs[1]), sizeof(char), &myiscntrl));
  CU_ASSERT_FALSE(any(strs[2], mystrlen(strs[2]), sizeof(char), &myisdigit));
  CU_ASSERT_TRUE(any(strs[3], mystrlen(strs[3]), sizeof(char), &myislower));
  CU_ASSERT_TRUE(any(strs[4], mystrlen(strs[4]), sizeof(char), &myisprint));
  CU_ASSERT_TRUE(any(strs[5], mystrlen(strs[5]), sizeof(char), &myisxdigit));
  CU_ASSERT_TRUE(any(strs[6], mystrlen(strs[6]), sizeof(char), &myisalpha));
  CU_ASSERT_FALSE(any(strs[7], mystrlen(strs[7]), sizeof(char), &myisupper));
  CU_ASSERT_TRUE(any(strs[8], mystrlen(strs[8]), sizeof(char), &myisspace));
  CU_ASSERT_TRUE(any(strs[9], mystrlen(strs[9]), sizeof(char), &myispunct));
}

int main(int argc, char *argv[]) {
  /* parse command line options */
  for (size_t i = 1; i < argc; i++) {
    CU_basic_set_mode(CU_BRM_NORMAL);
    if (strcmp(argv[i], "--quiet") == 0 || 
        strcmp(argv[i], "--silent") == 0 ||
        strcmp(argv[i], "-q") == 0)
      CU_basic_set_mode(CU_BRM_SILENT);
    else if (strcmp(argv[i], "--verbose") == 0 || 
             strcmp(argv[i], "-v") == 0)
      CU_basic_set_mode(CU_BRM_VERBOSE);
    else{;}
  }

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* add a suite to the registry */
  CU_pSuite pSuite = NULL;
  pSuite = CU_add_suite("String Function Suite", init_suite, clean_suite);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  if ((NULL == CU_add_test(pSuite, "testing for included headers", testNO_STRING_H)) ||
      (NULL == CU_add_test(pSuite, "test of mystrlen", testMYSTRLEN)) ||
      (NULL == CU_add_test(pSuite, "test of mystrcmp", testMYSTRCMP)) ||
      (NULL == CU_add_test(pSuite, "test of mystrstr", testMYSTRSTR)) ||
      (NULL == CU_add_test(pSuite, "test of strstrip", testMYSTRSTRIP)) ||
      (NULL == CU_add_test(pSuite, "test of any and all", testANYALL))) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}