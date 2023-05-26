#ifndef KODIK_DATA_COUNTRY_H
#define KODIK_DATA_COUNTRY_H 1

#ifdef __cplusplus
extern "C" {
#endif /* !__cplusplus */

#include <stdint.h>

typedef struct kodik_country_t kodik_country_t;

/**
 * @brief Get title of country object.
 *
 * @return char const*
 */
char const *
kodik_country_get_title( kodik_country_t const * );

/**
 * @brief Get count of country objects.
 *
 * @return int64_t
 */
int64_t
kodik_country_get_count( kodik_country_t const * );

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !KODIK_DATA_COUNTRY_H*/
