Jabbernaut: instant messager client for classic MacOS
===============

An attempt to build from last available source snapshot.  Will attempt to fix bugs and improve stability.  Adding support for m68k Macs.

The version number in the sources is "0.6d1", this may indicate it is the original author's work post-5.5b1, which was the last publicly available binary.

For CodeWarrior Pro 6.

Includes all required dependencies:
+ GUSI (socket and other *nix style functions)
+ MacJLib (for xml parsing)
+ Zoop (application framework)
+ OpenSSL (encyrption and decryption)

MacOS version and requirements unknown....guesses:
+ MacOS 8.5+?
+ Probably not Appearance manager
+ Probably OpenTransport

Includes new work on port for m68k Macs.

+ "Jabbernaut Carb Z2.5.mcp" - for Carbon, unfinished by original author
+ "Jabbernaut PPC.mcp" - builds
+ "Jabbernaut m68k.mcp" - compiles but does not yet link
+ "TOQ.mcp" - original author's special cut down version for "TBN Online", does not build