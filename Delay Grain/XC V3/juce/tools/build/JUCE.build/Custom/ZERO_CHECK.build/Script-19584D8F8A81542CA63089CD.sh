#!/bin/sh
set -e
if test "$CONFIGURATION" = "Custom"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/XC V3/juce/tools"
  make -f /Users/victorschulhoff/Desktop/Delay-Grain/Delay\ Grain/XC\ V3/juce/tools/CMakeScripts/ReRunCMake.make
fi

