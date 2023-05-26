#ifndef KODIK_DATA_TRANSLATION_H
#define KODIK_DATA_TRANSLATION_H 1

#ifdef __cplusplus
extern "C" {
#endif /* !__cplusplus */

#include <stdint.h>

enum kodik_translation_type_e {
  kodik_translation_type_voice      = 0x0,
  kodik_translation_type_subtitles  = 0x1,
  kodik_translation_type_unknown    = 0xffffffffffffffff
};

typedef struct kodik_translation_t kodik_translation_t;

char const *
kodik_translation_get_title( kodik_translation_t const * );

int64_t
kodik_translation_get_id( kodik_translation_t const * );

enum kodik_translation_type_e
kodik_translation_get_type( kodik_translation_t const * );

char const *
kodik_translation_get_type_string( kodik_translation_t const * );

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !KODIK_DATA_TRANSLATION_H*/
