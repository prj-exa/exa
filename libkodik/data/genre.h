#ifndef KODIK_DATA_GENRE_H
#define KODIK_DATA_GENRE_H 1

#ifdef __cplusplus
extern "C" {
#endif /* !__cplusplus */

#include <stdint.h>

/**
 * @brief opaque struct with data of genre.
 *
 */
typedef struct kodik_genre_t kodik_genre_t;

/**
 * @brief Get the title of object genre.
 *
 * @return char const *
 */
char const *
kodik_genre_get_title( kodik_genre_t const * );

/**
 * @brief Get the count of materials associated with this genre object.
 *
 * @return int64_t count of materials. INT64_MIN on.
 */
int64_t
kodik_genre_get_count( kodik_genre_t const *);

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !KODIK_DATA_GENRE_H*/
