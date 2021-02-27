#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/_deps/catch-subbuild/CMakeScripts/ReRunCMake.make
fi

