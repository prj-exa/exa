#include "country.h"
#include "../core/util/string.h"
#include <jansson.h>
#include <stdlib.h>
#include <string.h>

#include <config.h>

#ifdef HAVE_ISO_646
# include <iso646.h>
#else
# include "../core/util/altspell.h"
#endif

#define kodik_country_invalid_value INT64_MIN
#define kodik_country_key_title "title"
#define kodik_country_key_count "count"

struct kodik_country_t {
  char *psz_title;
  int64_t i_count;
};

static
kodik_country_t *
kodik_country_new(void) {
  return calloc(1, sizeof(kodik_country_t));
}

kodik_country_t *
kodik_country_new_value(char const *title, int64_t count) {
  kodik_country_t *country;
  char *title_copy;

  country = NULL;
  title_copy = kodik_string_duplicate(title);

  if (NULL not_eq title_copy) {
    country = kodik_country_new();
    if (NULL not_eq country) {
      (*country) = (kodik_country_t) {
        .psz_title = title_copy,
        .i_count = count
      };
    } else {
      free(title_copy);
    }
  }

  return country;
}

kodik_country_t *
kodik_country_new_json(json_t const *node) {
  kodik_country_t *country;
  json_t *j_title;
  json_t *j_count;
  int64_t count;
  char const *title;

  country = NULL;

  j_title = json_object_get(node, kodik_country_key_title);
  j_count = json_object_get(node, kodik_country_key_count);

  if (NULL not_eq j_title
        and json_is_string(j_title)
      and NULL not_eq j_count
        and json_is_integer(j_count)) {
    title = json_string_value(j_title);
    count = json_integer_value(j_count);
    country = kodik_country_new_value(title, count);
  }

  return country;
}

char const *
kodik_country_get_title(kodik_country_t const *country) {
  return
    NULL not_eq country
      ? country->psz_title
      : NULL;
}

int64_t
kodik_country_get_count(kodik_country_t const *country) {
  return
    NULL not_eq country
      ? country->i_count
      : kodik_country_invalid_value;
}

void
kodik_country_free(kodik_country_t *country) {
  free(country->psz_title);
  free(country);
}
