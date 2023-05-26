#ifndef KODIK_UTIL_MACRO_H
#define KODIK_UTIL_MACRO_H 1

#ifdef __cplusplus
extern "C" {
#endif /* !__cplusplus */

#define kodik_json_check(ptr, type) \
NULL not_eq ptr                     \
  and json_is_##type((ptr))

#define kodik_ret_def_on_null(ptr, field, def)  \
  NULL not_eq (ptr)                             \
    ? ptr->field                                \
    : def

#define kodik_ret_null_on_null(ptr, field)      \
kodik_ret_def_on_null(ptr, field, NULL)

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !KODIK_UTIL_MACRO_H*/
