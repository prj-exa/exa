#include "genre.h"    /* kodik genre */
#include "../core/util/string.h"
#include <jansson.h>  /* json library */
#include <stdlib.h>   /* malloc, calloc, realloc */
#include <string.h>   /* DO NOT USE strdup!!! */

#include <config.h>

#ifdef HAVE_ISO_646
# include <iso646.h>
#else
# include "../core/util/altspell.h"
#endif

#define kodik_genre_invalid_value INT64_MIN
#define kodik_genre_key_title "title"
#define kodik_genre_key_count "count"

struct kodik_genre_t {
  char *psz_title;
  int64_t i_count;
};

static
struct kodik_genre_t *
kodik_genre_new(void) {
  return calloc(1, sizeof(struct kodik_genre_t));
}

struct kodik_genre_t *
kodik_genre_new_value(char const *title, int64_t count) {
  struct kodik_genre_t *genre;
  char *title_copy;

  genre = NULL;
  title_copy = kodik_string_duplicate(title);

  if (NULL not_eq title_copy) {
    genre = kodik_genre_new();
    if (NULL not_eq genre) {
      (*genre) = (kodik_genre_t) {
        .psz_title = title_copy,
        .i_count = count
      };
    } else {
      free(title_copy);
    }
  }

  return genre;
}

struct kodik_genre_t *
kodik_genre_new_json(json_t const *node) {
  kodik_genre_t *genre;
  json_t *j_title;
  json_t *j_count;
  int64_t count;
  char const *title;

  genre = NULL;

  j_title = json_object_get(node, kodik_genre_key_title);
  j_count = json_object_get(node, kodik_genre_key_count);

  if (NULL not_eq j_title
        and json_is_string(j_title)
      and NULL not_eq j_count
        and json_is_integer(j_count)) {
    title = json_string_value(j_title);
    count = json_integer_value(j_count);
    genre = kodik_genre_new_value(title, count);
  }

  return genre;
}

char const *
kodik_genre_get_title(struct kodik_genre_t const *genre) {
  return
    NULL not_eq genre
      ? genre->psz_title
      : NULL;
}

int64_t
kodik_genre_get_count(struct kodik_genre_t const *genre) {
  return
    NULL not_eq genre
      ? genre->i_count
      : kodik_genre_invalid_value;
}

void
kodik_genre_free(kodik_genre_t *genre) {
  free(genre->psz_title);
  free(genre);
}
