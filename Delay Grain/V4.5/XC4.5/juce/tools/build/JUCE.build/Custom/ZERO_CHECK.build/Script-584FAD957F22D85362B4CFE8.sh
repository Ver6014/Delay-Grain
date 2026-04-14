#!/bin/sh
set -e
if test "$CONFIGURATION" = "Custom"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/V4.5/XC4.5/juce/tools"
  make -f /Users/victorschulhoff/Desktop/Delay-Grain/Delay\ Grain/V4.5/XC4.5/juce/tools/CMakeScripts/ReRunCMake.make
fi

