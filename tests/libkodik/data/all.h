#ifndef KODIK_TEST_ALL_H
#define KODIK_TEST_ALL_H 1

#ifdef __cplusplus
extern "C" {
#endif /* !__cplusplus */

#define KODIK_TEST_MAIN()                                         \
int                                                               \
main(int argc, char *argv[]) {                                    \
  int status;                                                     \
  size_t i;                                                       \
  for (i = 0; i < argc; i++) {                                    \
    (void) fprintf(stderr, "Arg#%" PRIu64 " = %s\n", i, argv[i]); \
  }                                                               \
  if (argc > 1) {                                                 \
    json_t *root = json_load(argv[1]);                            \
    if (NULL != root) {                                           \
      status = munit_suite_main(&test_suite, root, argc, argv);   \
    }                                                             \
  } else {                                                        \
    status = 1;                                                   \
    (void) fprintf (stderr, "Invalid arguments count\n");         \
  }                                                               \
  return status;                                                  \
}


#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !KODIK_TEST_ALL_H*/
