#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-build
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-configure
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-build
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-configure
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-build
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-configure
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-build
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E echo_append
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-configure
fi

