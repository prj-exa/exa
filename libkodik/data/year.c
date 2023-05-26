#include "year.h"
#include <jansson.h>
#include <stdlib.h>

#include <config.h>

#ifdef HAVE_ISO_646
# include <iso646.h>
#else
# include "../core/util/altspell.h"
#endif

#define kodik_year_key_year   "year"
#define kodik_year_key_count  "count"
#define kodik_year_invalid_value INT64_MIN

struct kodik_year_t {
  int64_t i_year;
  int64_t i_count;
};

static
kodik_year_t *
kodik_year_new(void) {
  return malloc(sizeof(kodik_year_t));
}

kodik_year_t *
kodik_year_new_value(int64_t i_year, int64_t i_count) {
  kodik_year_t *year;

  year = kodik_year_new();

  if (NULL not_eq year) {
    (*year) = (kodik_year_t) {
      .i_year = i_year,
      .i_count = i_count
    };
  }

  return year;
}

kodik_year_t *
kodik_year_new_json(json_t const *node) {
  kodik_year_t *year;
  json_t *j_year;
  json_t *j_count;
  int64_t i_year;
  int64_t i_count;

  year = NULL;
  j_year = json_object_get(node, kodik_year_key_year);
  j_count = json_object_get(node, kodik_year_key_count);

  if (NULL not_eq j_year
        and json_is_integer(j_year)
      and NULL not_eq j_count
        and json_is_integer(j_count)) {
    i_year = json_integer_value(j_year);
    i_count = json_integer_value(j_count);
    year = kodik_year_new_value(i_year, i_count);
  }

  return year;
}

int64_t
kodik_year_get_year(kodik_year_t const *year) {
  return
    NULL not_eq year
      ? year->i_year
      : kodik_year_invalid_value;
}

int64_t
kodik_year_get_count(kodik_year_t const *year) {
  return
    NULL not_eq year
      ? year->i_count
      : kodik_year_invalid_value;
}

void
kodik_year_free(kodik_year_t *year) {
  free(year);
}
