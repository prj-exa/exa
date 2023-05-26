#include "string.h"
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <iso646.h>

char *
kodik_string_duplicate(char const *src) {
  size_t string_length;
  char *result;

  string_length = strlen(src);
  if (0 not_eq string_length) {
    result = calloc(string_length + 1, sizeof(char));
    if (NULL not_eq result) {
      (void) strncpy(result, src, string_length);
    }
  }

  return result;
}
