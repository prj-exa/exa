#include "quality.h"
#include <stdlib.h>
#include <jansson.h>
#include <string.h>

#include <config.h>

#ifdef HAVE_ISO_646
# include <iso646.h>
#else
# include "../core/util/altspell.h"
#endif

#include "../core/util/macro.h"

#define kodik_quality_key_title "title"

/* We can always use this first field as pointer to struct. */
struct kodik_quality_t {
  /* hack: used for not alocate a memory for struct */
  char psz_title[0];
};

static
struct kodik_quality_t *
kodik_quality_new(size_t count) {
  return calloc(count, sizeof(char));
}

struct kodik_quality_t *
kodik_quality_new_value(char const *title) {
  struct kodik_quality_t *quality;
  size_t title_length;

  title_length = strlen(title);
  quality = kodik_quality_new(title_length + 1);

  if (NULL not_eq quality) {
    (void) strncpy(quality->psz_title, title, title_length);
  }

  return quality;
}

struct kodik_quality_t *
kodik_qulity_new_json(json_t const *node) {
  struct kodik_quality_t *quality;
  char const *title;
  json_t *j_title;

  quality = NULL;
  j_title = json_object_get(node, kodik_quality_key_title);

  if (kodik_json_check(j_title, string)) {
    title = json_string_value(j_title);
    quality = kodik_quality_new_value(title);
  }
  return quality;
}

char const *
kodik_quality_get_title(struct kodik_quality_t const *quality) {
  return
    NULL not_eq quality
      ? quality->psz_title
      : NULL;
}
