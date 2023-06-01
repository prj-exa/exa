#include <munit.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>
#include <data/quality.h>
#include "all.h"

extern
json_t *
json_load(char const *);

MunitSuite const test_suite = {

};

KODIK_TEST_MAIN()
