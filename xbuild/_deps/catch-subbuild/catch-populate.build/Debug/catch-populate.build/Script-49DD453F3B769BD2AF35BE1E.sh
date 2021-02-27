#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -P /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/tmp/catch-populate-gitclone.cmake
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-download
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -P /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/tmp/catch-populate-gitclone.cmake
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-download
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -P /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/tmp/catch-populate-gitclone.cmake
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-download
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -P /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/tmp/catch-populate-gitclone.cmake
  /usr/local/Cellar/cmake/3.19.6/bin/cmake -E touch /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/catch-populate-prefix/src/catch-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/catch-populate-download
fi

