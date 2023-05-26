#ifndef KODIK_DATA_TRANSLATION2_H
#define KODIK_DATA_TRANSLATION2_H 1

#ifdef __cplusplus
extern "C" {
#endif /* !__cplusplus */

#include <stdint.h>

typedef struct kodik_translation2_t kodik_translation2_t;

int64_t
kodik_translation2_get_id( kodik_translation2_t const * );

char const *
kodik_translation2_get_title( kodik_translation2_t const * );

int64_t
kodik_translation2_get_count( kodik_translation2_t const * );

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !KODIK_DATA_TRANSLATION2_H*/
