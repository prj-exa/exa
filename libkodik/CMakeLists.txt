add_library ("kodik" MODULE)

include(CheckIncludeFile)

check_include_file(iso646.h HAVE_ISO_646)

target_sources (kodik
  PRIVATE
    kodik.c
    data/year.c
    data/genre.c
    data/quality.c
    data/country.c
    data/translation.c
    data/translation2.c
    core/util/string.c)

target_sources (kodik
  INTERFACE
    kodik.h
    data/year.h
    data/genre.h
    data/quality.h
    data/country.h
    data/translation.h
    data/translation2.h
    core/util/macro.h
    core/util/string.h)

set_target_properties (kodik
  PROPERTIES
    C_STANDARD 17
    C_EXTENSIONS OFF
    C_STANDARD_REQUIRED ON
    $<$<CMAKE_HOST_WIN32:1>:PREFIX lib>
    C_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON)

target_include_directories (kodik
  PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}")

configure_file (config.h.in config.h @ONLY)
