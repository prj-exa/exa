#include "all.h"
#include <stdio.h>
#include <inttypes.h>
#include <jansson.h>
#include <errno.h>
#include <string.h>

json_t * json_load(char const *path)
{
  json_t *root;
  FILE *json;

  json = fopen(path, "rb");
  root = NULL;
  if (NULL != json) {
    rewind(json);
    fseek(json, SEEK_END, 0);
    ftell(json);
    fclose(json);
  } else {
    fprintf(stderr, "Failed to open test data file: %s\n", strerror(errno));
  }
  return root;
}
