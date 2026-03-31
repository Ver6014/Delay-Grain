#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4.1/Xcv4.1"
  make -f /Users/victorschulhoff/Desktop/Delay-Grain/Delay\ Grain/v4.1/Xcv4.1/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4.1/Xcv4.1"
  make -f /Users/victorschulhoff/Desktop/Delay-Grain/Delay\ Grain/v4.1/Xcv4.1/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4.1/Xcv4.1"
  make -f /Users/victorschulhoff/Desktop/Delay-Grain/Delay\ Grain/v4.1/Xcv4.1/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4.1/Xcv4.1"
  make -f /Users/victorschulhoff/Desktop/Delay-Grain/Delay\ Grain/v4.1/Xcv4.1/CMakeScripts/ReRunCMake.make
fi

