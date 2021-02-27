#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/pw/GitHub/phulkan/xbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/pw/GitHub/phulkan/xbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/pw/GitHub/phulkan/xbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/pw/GitHub/phulkan/xbuild
  make -f /Users/pw/GitHub/phulkan/xbuild/CMakeScripts/ReRunCMake.make
fi

