add_library (load_data OBJECT load_data.c)

function (kodik_add_test TEST_MAME)
  add_executable (${TEST_MAME}_test ${TEST_MAME}.c)
  target_link_libraries (${TEST_MAME}_test
                          PRIVATE
                            kodik
                            munit
                            load_data
                            jansson::jansson)
  target_include_directories (${TEST_MAME}_test
                              PRIVATE
                                ${PROJECT_SOURCE_DIR}/vendor/munit
                                ${PROJECT_SOURCE_DIR}/libkodik)
  add_test (${TEST_MAME}_test
            ${CMAKE_BINARY_DIR}/bin/${TEST_MAME}_test
            ${CMAKE_CURRENT_LIST_DIR}/input/${TEST_MAME}_data.json)
endfunction (kodik_add_test TEST_MAME)

kodik_add_test (year)
kodik_add_test (genre)
kodik_add_test (quality)
kodik_add_test (country)
kodik_add_test (translation)
kodik_add_test (translation2)
