# T2-IFC22Template

This is the template implementation for any Tribes 2 C++ modification (that wants to work without TribesNext) that
produces a DLL capable of replacing the game's IFC22.dll which controls force feedback support. LouCypher had
originally implemented TribesNext as a IFC22.dll but did not yield source, so this template code is a reverse
engineering of that combined with Linker's gift code to produce a codebase that is capable of being loaded into
practically any Tribes 2 installation that's running the latest patches.
