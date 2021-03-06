#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG

static const int brackets_len = 3;

// the brackets' code is their position: { and } are 0
// [ and ] are 1
// ( and ) are 2
// NOTE: Opening and closing brackets MUST be at the same position in each
// variable, or the IDs will not work correctly

// when we see those brackets we push on the stack
static const char opening_brackets[] = "{[(";

// when we see those brackets we pop the last one to check if it matches
static const char closing_brackets[] = "}])";

int bracket_push_check(char *s) {
  int len = strlen(s);

#ifdef DEBUG
  printf("Entering with string \"%s\", length %d\n", s, len);
#endif

  if (len == 0) {
#ifdef DEBUG
    printf("String empty, exiting...\n");
#endif
    return EXIT_SUCCESS;
  }

  int brackets_index = 0;

#ifdef DEBUG
  printf("Allocating memory\n");
#endif

  int *brackets_stack = (int *)malloc(len * sizeof(int));

  // loop through each character
  for (int i = 0; i < len; ++i) {
#ifdef DEBUG
    printf("Char %d\n", i);
#endif
    // check for each bracket
    for (int bi = 0; bi < brackets_len; ++bi) {

#ifdef DEBUG
      printf("Checking bracket: %d\n", bi);
#endif
      if (s[i] == opening_brackets[bi]) {
        // the current character is one of the opening brackets
        // save the character 'code' onto the 'stack'
        brackets_stack[brackets_index] = bi;
#ifdef DEBUG
        printf("Adding bracket: %c with id %d\n", s[i], bi);
#endif
        brackets_index++;
        break;
      } else if (s[i] == closing_brackets[bi]) {
        // the current character is one of the closing brackets
        // 'pop' the last character and check if they're compatible
        if (brackets_index == 0) {
#ifdef DEBUG
          printf("Tried closing a bracket, but no bracket was opened\n");
#endif
          return EXIT_FAILURE;
        }
#ifdef DEBUG
        printf("Closing bracket ID: %d, existing bracket ID: %d\n", bi,
               brackets_stack[brackets_index - 1]);
#endif

        if (brackets_stack[brackets_index - 1] != bi) {
#ifdef DEBUG
          printf("Closing bracket not compatible: %c Exiting.\n", s[i]);
#endif
          return EXIT_FAILURE;
        }
#ifdef DEBUG
        printf("Bracket compatible: %c. Continuing...\n", s[i]);
#endif
        brackets_index--;
        break;
      }
    }
  }

  // handle the case where the brackets are never closed
  if (brackets_index != 0) {
#ifdef DEBUG
    printf("Some brackets were not closed\n");
#endif
    return EXIT_FAILURE;
  }
#ifdef DEBUG
  printf("End of input, we didn't find an incompatible bracket so it all must "
         "be correct.\n");
#endif
  return EXIT_SUCCESS;
}