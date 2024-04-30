Jabbernaut: instant messager client for classic MacOS
===============

An attempt to build from last available source snapshot.  Will attempt to fix bugs and improve stability.  Added support for m68k Macs.  Fixed Carbon and TOQ, which now build.

The version number in the sources is "0.6d1", this may indicate it is the original author's work post-0.5.5b1, which was the last publicly available binary.

For CodeWarrior Pro 6.

Includes all required dependencies:
+ GUSI (socket and other *nix style functions)
+ "GUSI2-for-MacPython" a Carbon version of GUSI
+ MacJLib (for xml parsing)
+ Zoop (application framework)
+ OpenSSL (encyrption and decryption)

MacOS version and requirements unknown....guesses:
+ MacOS 7.5+
+ Probably not Appearance manager
+ Probably OpenTransport
+ Sound (Yes, it will fail on Sheepshaver, etc, if sound is not configured)

Includes new work on port for m68k Macs, Carbon and fixing TOQ version.

NOTE: Printing is currently disabled in Carbon build due to limitations of Universal Interfaces shipped with CW6.

CodeWarrior project files:

+ "Jabbernaut PPC.mcp" - builds
+ "Jabbernaut m68k.mcp" - builds
+ "Jabbernaut Carb Z2.5.mcp" - for Carbon, unfinished by original author

+ "TOQ.mcp" - original author's special cut down version for "TBN Online".
+ "TOQ m68k.mcp" - m68k version of above.