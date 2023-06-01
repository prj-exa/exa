#include <munit.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <data/country.h>
#include "all.h"

extern
json_t *
json_load(char const *);

json_t *
json_parse(json_t const *root) {
  json_t *array = json_object_get(root, "results");
  return
    json_is_array(array)
      ? array
      : NULL;
}

MunitSuite const test_suite = {

};

KODIK_TEST_MAIN()
