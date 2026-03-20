#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4"
  "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/juce/tools/extras/Build/juceaide/juceaide_artefacts/Custom/juceaide" pkginfo AU "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/DelayGrain_artefacts/JuceLibraryCode/DelayGrain_AU/PkgInfo"
fi
if test "$CONFIGURATION" = "Release"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4"
  "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/juce/tools/extras/Build/juceaide/juceaide_artefacts/Custom/juceaide" pkginfo AU "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/DelayGrain_artefacts/JuceLibraryCode/DelayGrain_AU/PkgInfo"
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4"
  "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/juce/tools/extras/Build/juceaide/juceaide_artefacts/Custom/juceaide" pkginfo AU "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/DelayGrain_artefacts/JuceLibraryCode/DelayGrain_AU/PkgInfo"
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4"
  "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/juce/tools/extras/Build/juceaide/juceaide_artefacts/Custom/juceaide" pkginfo AU "/Users/victorschulhoff/Desktop/Delay-Grain/Delay Grain/v4/DelayGrain_artefacts/JuceLibraryCode/DelayGrain_AU/PkgInfo"
fi

