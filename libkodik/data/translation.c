#include "translation.h"
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

#define ktts "subtitles"
#define kttv "voice"
#define max(a,b) ((a) > (b) ? (a) : (b))
#define kttl max(sizeof(ktts), sizeof(kttv))

#define kodik_translation_key_id    ("id")
#define kodik_translation_key_type  ("type")
#define kodik_translation_key_title ("title")
#define kodik_translation_invalid_value INT64_MIN

struct kodik_translation_t {
  char *psz_title;
  int64_t i_id;
  char array_type[kttl];
};

static
kodik_translation_t *
kodik_translation_new(void) {
  return calloc(1, sizeof(kodik_translation_t));
}

kodik_translation_t *
kodik_translation_new_value(char const *title, char const *type, int64_t id) {
  kodik_translation_t *translation;
  char *title_copy;

  translation = NULL;
  title_copy = kodik_string_duplicate(title);

  if (NULL not_eq title_copy) {
    translation = kodik_translation_new();
    if (NULL not_eq translation) {
      (*translation) = (kodik_translation_t) {
        .psz_title = title_copy,
        .i_id = id,
        0
      };
      (void) strncpy(translation->array_type, type, strlen(type));
    } else {
      free(title_copy);
    }
  }

  return translation;
}

kodik_translation_t *
kodik_translation_new_json(json_t const *node) {
  kodik_translation_t *translation;
  json_t *j_title;
  json_t *j_id;
  json_t *j_type;
  char const *title;
  char const *type;
  int64_t id;

  j_title = json_object_get(node, kodik_translation_key_title);
  j_type = json_object_get(node, kodik_translation_key_type);
  j_id = json_object_get(node, kodik_translation_key_id);

  if (kodik_json_check(j_title, string)
      and kodik_json_check(j_type, string)
      and kodik_json_check(j_id, integer)) {
    title = json_string_value(j_title);
    type  = json_string_value(j_type);
    id = json_integer_value(j_id);
    translation = kodik_translation_new_value(title, type, id);
  }

  return translation;
}

char const *
kodik_translation_get_title(kodik_translation_t const *translation) {
  return
    NULL not_eq translation
      ? translation->psz_title
      : NULL;
}

int64_t
kodik_translation_get_id(kodik_translation_t const *translation) {
  return
    NULL not_eq translation
      ? translation->i_id
      : kodik_translation_invalid_value;
}

enum kodik_translation_type_e
kodik_translation_get_type(kodik_translation_t const *translation) {
  int state;
  enum kodik_translation_type_e status
    = kodik_translation_type_unknown;

  state = strcmp(kttv, translation->array_type);

  if (0 not_eq state) {
    state = strcmp(ktts, translation->array_type);
    if (0 == state) {
      status = kodik_translation_type_subtitles;
    }
  }else {
    status = kodik_translation_type_voice;
  }

  return status;
}

char const *
kodik_translation_get_type_string(kodik_translation_t const *translation) {
  return
    NULL not_eq translation
      ? &translation->array_type[0]
      : NULL;
}
