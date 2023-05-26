#include "translation2.h"
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

#include "../core/util/macro.h"

#define kodik_translation2_key_title  ("title")
#define kodik_translation2_key_count  ("count")
#define kodik_translation2_key_id     ("id")
#define kodik_translation2_invalid_value INT64_MIN

struct kodik_translation2_t {
  char *psz_title;
  int64_t i_count;
  int64_t i_id;
};

static
kodik_translation2_t *
kodik_translation2_new(void) {
  return calloc(1, sizeof(kodik_translation2_t));
}

kodik_translation2_t *
kodik_translation2_new_value(char const *title, int64_t count, int64_t id) {
  kodik_translation2_t *res;
  char *title_copy;

  res = NULL;
  title_copy = kodik_string_duplicate(title);

  if (NULL not_eq title_copy) {
    res = kodik_translation2_new();
    if (NULL not_eq res) {
      (*res) = (kodik_translation2_t) {
        .psz_title = title_copy,
        .i_count = count,
        .i_id = id
      };
    } else {
      free(title_copy);
    }
  }

  return res;
}

kodik_translation2_t *
kodik_translation2_new_json(json_t const *node) {
  kodik_translation2_t *res;
  json_t *j_title;
  json_t *j_count;
  json_t *j_id;
  char const *title;
  int64_t id;
  int64_t count;

  res = NULL;
  j_title = json_object_get(node, kodik_translation2_key_title);
  j_count = json_object_get(node, kodik_translation2_key_count);
  j_id = json_object_get(node, kodik_translation2_key_id);

  if (kodik_json_check(j_title, string)
      and kodik_json_check(j_count, integer)
      and kodik_json_check(j_id, integer)) {
    title = json_string_value(j_title);
    count = json_integer_value(j_count);
    id = json_integer_value(j_id);
    res = kodik_translation2_new_value(title, count, id);
  }

  return res;
}

int64_t
kodik_translation2_get_id(kodik_translation2_t const *o) {
  return
    kodik_ret_def_on_null(o, i_id, kodik_translation2_invalid_value);
}

char const *
kodik_translation2_get_title(kodik_translation2_t const *o) {
  return
    kodik_ret_null_on_null(o, psz_title);
}

int64_t
kodik_translation2_get_count(kodik_translation2_t const *o) {
  return
    kodik_ret_def_on_null(o, i_count, kodik_translation2_invalid_value);
}

void
kodik_translation2_free(kodik_translation2_t *o) {
  free(o->psz_title);
  free(o);
}
