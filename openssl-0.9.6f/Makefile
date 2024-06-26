### Generated automatically from Makefile.org by Configure.

##
## Makefile for OpenSSL
##

VERSION=0.9.6f
MAJOR=0
MINOR=9.6
SHLIB_VERSION_NUMBER=0.9.6
SHLIB_VERSION_HISTORY=
SHLIB_MAJOR=0
SHLIB_MINOR=9.6
SHLIB_EXT=
PLATFORM=dist
OPTIONS=
CONFIGURE_ARGS=dist
SHLIB_TARGET=

# INSTALL_PREFIX is for package builders so that they can configure
# for, say, /usr/ and yet have everything installed to /tmp/somedir/usr/.
# Normally it is left empty.
INSTALL_PREFIX=
INSTALLTOP=/usr/local/ssl

# Do not edit this manually. Use Configure --openssldir=DIR do change this!
OPENSSLDIR=/usr/local/ssl

# RSAref  - Define if we are to link with RSAref.
# NO_IDEA - Define to build without the IDEA algorithm
# NO_RC4  - Define to build without the RC4 algorithm
# NO_RC2  - Define to build without the RC2 algorithm
# THREADS - Define when building with threads, you will probably also need any
#           system defines as well, i.e. _REENTERANT for Solaris 2.[34]
# TERMIO  - Define the termio terminal subsystem, needed if sgtty is missing.
# TERMIOS - Define the termios terminal subsystem, Silicon Graphics.
# LONGCRYPT - Define to use HPUX 10.x's long password modification to crypt(3).
# DEVRANDOM - Give this the value of the 'random device' if your OS supports
#           one.  32 bytes will be read from this when the random
#           number generator is initalised.
# SSL_FORBID_ENULL - define if you want the server to be not able to use the
#           NULL encryption ciphers.
#
# LOCK_DEBUG - turns on lots of lock debug output :-)
# REF_CHECK - turn on some xyz_free() assertions.
# REF_PRINT - prints some stuff on structure free.
# CRYPTO_MDEBUG - turns on my 'memory leak' detecting stuff
# MFUNC - Make all Malloc/Free/Realloc calls call
#       CRYPTO_malloc/CRYPTO_free/CRYPTO_realloc which can be setup to
#       call application defined callbacks via CRYPTO_set_mem_functions()
# MD5_ASM needs to be defined to use the x86 assembler for MD5
# SHA1_ASM needs to be defined to use the x86 assembler for SHA1
# RMD160_ASM needs to be defined to use the x86 assembler for RIPEMD160
# Do not define B_ENDIAN or L_ENDIAN if 'unsigned long' == 8.  It must
# equal 4.
# PKCS1_CHECK - pkcs1 tests.

CC= cc
#CFLAG= -DL_ENDIAN -DTERMIO -O3 -fomit-frame-pointer -m486 -Wall -Wuninitialized -DSHA1_ASM -DMD5_ASM -DRMD160_ASM
CFLAG= -O
DEPFLAG= 
PEX_LIBS= 
EX_LIBS= 
EXE_EXT= 
AR=ar r
RANLIB= /usr/bin/ranlib
PERL= /usr/local/bin/perl
TAR= tar
TARFLAGS= --no-recursion

# Set BN_ASM to bn_asm.o if you want to use the C version
BN_ASM= bn_asm.o
#BN_ASM= bn_asm.o
#BN_ASM= asm/bn86-elf.o	# elf, linux-elf
#BN_ASM= asm/bn86-sol.o # solaris
#BN_ASM= asm/bn86-out.o # a.out, FreeBSD
#BN_ASM= asm/bn86bsdi.o # bsdi
#BN_ASM= asm/alpha.o    # DEC Alpha
#BN_ASM= asm/pa-risc2.o # HP-UX PA-RISC
#BN_ASM= asm/r3000.o    # SGI MIPS cpu
#BN_ASM= asm/sparc.o    # Sun solaris/SunOS
#BN_ASM= asm/bn-win32.o # Windows 95/NT
#BN_ASM= asm/x86w16.o   # 16 bit code for Windows 3.1/DOS
#BN_ASM= asm/x86w32.o   # 32 bit code for Windows 3.1

# For x86 assembler: Set PROCESSOR to 386 if you want to support
# the 80386.
PROCESSOR= 

# Set DES_ENC to des_enc.o if you want to use the C version
#There are 4 x86 assember options.
DES_ENC= des_enc.o fcrypt_b.o
#DES_ENC= des_enc.o fcrypt_b.o          # C
#DES_ENC= asm/dx86-elf.o asm/yx86-elf.o # elf
#DES_ENC= asm/dx86-sol.o asm/yx86-sol.o # solaris
#DES_ENC= asm/dx86-out.o asm/yx86-out.o # a.out, FreeBSD
#DES_ENC= asm/dx86bsdi.o asm/yx86bsdi.o # bsdi

# Set BF_ENC to bf_enc.o if you want to use the C version
#There are 4 x86 assember options.
BF_ENC= bf_enc.o
#BF_ENC= bf_enc.o
#BF_ENC= asm/bx86-elf.o # elf
#BF_ENC= asm/bx86-sol.o # solaris
#BF_ENC= asm/bx86-out.o # a.out, FreeBSD
#BF_ENC= asm/bx86bsdi.o # bsdi

# Set CAST_ENC to c_enc.o if you want to use the C version
#There are 4 x86 assember options.
CAST_ENC= c_enc.o
#CAST_ENC= c_enc.o
#CAST_ENC= asm/cx86-elf.o # elf
#CAST_ENC= asm/cx86-sol.o # solaris
#CAST_ENC= asm/cx86-out.o # a.out, FreeBSD
#CAST_ENC= asm/cx86bsdi.o # bsdi

# Set RC4_ENC to rc4_enc.o if you want to use the C version
#There are 4 x86 assember options.
RC4_ENC= rc4_enc.o
#RC4_ENC= rc4_enc.o
#RC4_ENC= asm/rx86-elf.o # elf
#RC4_ENC= asm/rx86-sol.o # solaris
#RC4_ENC= asm/rx86-out.o # a.out, FreeBSD
#RC4_ENC= asm/rx86bsdi.o # bsdi

# Set RC5_ENC to rc5_enc.o if you want to use the C version
#There are 4 x86 assember options.
RC5_ENC= rc5_enc.o
#RC5_ENC= rc5_enc.o
#RC5_ENC= asm/r586-elf.o # elf
#RC5_ENC= asm/r586-sol.o # solaris
#RC5_ENC= asm/r586-out.o # a.out, FreeBSD
#RC5_ENC= asm/r586bsdi.o # bsdi

# Also need MD5_ASM defined
MD5_ASM_OBJ= 
#MD5_ASM_OBJ= asm/mx86-elf.o        # elf
#MD5_ASM_OBJ= asm/mx86-sol.o        # solaris
#MD5_ASM_OBJ= asm/mx86-out.o        # a.out, FreeBSD
#MD5_ASM_OBJ= asm/mx86bsdi.o        # bsdi

# Also need SHA1_ASM defined
SHA1_ASM_OBJ= 
#SHA1_ASM_OBJ= asm/sx86-elf.o       # elf
#SHA1_ASM_OBJ= asm/sx86-sol.o       # solaris
#SHA1_ASM_OBJ= asm/sx86-out.o       # a.out, FreeBSD
#SHA1_ASM_OBJ= asm/sx86bsdi.o       # bsdi

# Also need RMD160_ASM defined
RMD160_ASM_OBJ= 
#RMD160_ASM_OBJ= asm/rm86-elf.o       # elf
#RMD160_ASM_OBJ= asm/rm86-sol.o       # solaris
#RMD160_ASM_OBJ= asm/rm86-out.o       # a.out, FreeBSD
#RMD160_ASM_OBJ= asm/rm86bsdi.o       # bsdi

# When we're prepared to use shared libraries in the programs we link here
# we might set SHLIB_MARK to '$(SHARED_LIBS)'.
SHLIB_MARK=

DIRS=   crypto ssl rsaref $(SHLIB_MARK) apps test tools
SHLIBDIRS= crypto ssl

# dirs in crypto to build
SDIRS=  \
	md2 md4 md5 sha mdc2 hmac ripemd \
	des rc2 rc4 rc5 idea bf cast \
	bn rsa dsa dh dso engine \
	buffer bio stack lhash rand err objects \
	evp asn1 pem x509 x509v3 conf txt_db pkcs7 pkcs12 comp

MAKEFILE= Makefile.ssl
MAKE=     make -f Makefile.ssl

MANDIR=$(OPENSSLDIR)/man
MAN1=1
MAN3=3
SHELL=/bin/sh

TOP=    .
ONEDIRS=out tmp
EDIRS=  times doc bugs util include certs ms shlib mt demos perl sf dep VMS
WDIRS=  windows
LIBS=   libcrypto.a libssl.a
SHARED_CRYPTO=libcrypto$(SHLIB_EXT)
SHARED_SSL=libssl$(SHLIB_EXT)
SHARED_LIBS=
SHARED_LIBS_LINK_EXTS=
SHARED_LDFLAGS=

GENERAL=        Makefile
BASENAME=       openssl
NAME=           $(BASENAME)-$(VERSION)
TARFILE=        $(NAME).tar
WTARFILE=       $(NAME)-win.tar
EXHEADER=       e_os.h e_os2.h
HEADER=         e_os.h

# When we're prepared to use shared libraries in the programs we link here
# we might remove 'clean-shared' from the targets to perform at this stage

all: clean-shared Makefile.ssl sub_all

sub_all:
	@for i in $(DIRS); \
	do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making all in $$i..." && \
		$(MAKE) CC='${CC}' PLATFORM='${PLATFORM}' CFLAG='${CFLAG}' SDIRS='$(SDIRS)' INSTALLTOP='${INSTALLTOP}' PEX_LIBS='${PEX_LIBS}' EX_LIBS='${EX_LIBS}' BN_ASM='${BN_ASM}' DES_ENC='${DES_ENC}' BF_ENC='${BF_ENC}' CAST_ENC='${CAST_ENC}' RC4_ENC='${RC4_ENC}' RC5_ENC='${RC5_ENC}' SHA1_ASM_OBJ='${SHA1_ASM_OBJ}' MD5_ASM_OBJ='${MD5_ASM_OBJ}' RMD160_ASM_OBJ='${RMD160_ASM_OBJ}' AR='${AR}' PROCESSOR='${PROCESSOR}' PERL='${PERL}' RANLIB='${RANLIB}' EXE_EXT='${EXE_EXT}' all ) || exit 1; \
	else \
		$(MAKE) $$i; \
	fi; \
	done; \
	if echo "$(DIRS)" | \
	    egrep '(^| )(crypto|ssl)( |$$)' > /dev/null 2>&1 && \
	   [ -n "$(SHARED_LIBS)" ]; then \
		$(MAKE) $(SHARED_LIBS); \
	fi

libcrypto$(SHLIB_EXT): libcrypto.a
	@if [ "$(SHLIB_TARGET)" != "" ]; then \
		$(MAKE) SHLIBDIRS=crypto build-shared; \
	else \
		echo "There's no support for shared libraries on this platform" >&2; \
	fi
libssl$(SHLIB_EXT): libcrypto$(SHLIB_EXT) libssl.a
	@if [ "$(SHLIB_TARGET)" != "" ]; then \
		$(MAKE) SHLIBDIRS=ssl SHLIBDEPS='-lcrypto' build-shared; \
	else \
		echo "There's no support for shared libraries on this platform" >&2; \
	fi

clean-shared:
	@for i in $(SHLIBDIRS); do \
		if [ -n "$(SHARED_LIBS_LINK_EXTS)" ]; then \
			tmp="$(SHARED_LIBS_LINK_EXTS)"; \
			for j in $${tmp:-x}; do \
				( set -x; rm -f lib$$i$$j ); \
			done; \
		fi; \
		( set -x; rm -f lib$$i$(SHLIB_EXT) ); \
		if [ "$(PLATFORM)" = "Cygwin" ]; then \
			( set -x; rm -f cyg$$i$(SHLIB_EXT) lib$$i$(SHLIB_EXT).a ); \
		fi; \
	done

link-shared:
	@if [ -n "$(SHARED_LIBS_LINK_EXTS)" ]; then \
		tmp="$(SHARED_LIBS_LINK_EXTS)"; \
		for i in $(SHLIBDIRS); do \
			prev=lib$$i$(SHLIB_EXT); \
			for j in $${tmp:-x}; do \
				( set -x; \
				rm -f lib$$i$$j; ln -s $$prev lib$$i$$j ); \
				prev=lib$$i$$j; \
			done; \
		done; \
	fi

build-shared: clean-shared do_$(SHLIB_TARGET) link-shared

do_bsd-gcc-shared: do_gnu-shared
do_linux-shared: do_gnu-shared
do_gnu-shared:
	libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
	( set -x; ${CC} ${SHARED_LDFLAGS} \
		-shared -o lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		-Wl,-soname=lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		-Wl,-Bsymbolic \
		-Wl,--whole-archive lib$$i.a \
		-Wl,--no-whole-archive $$libs ${EX_LIBS} -lc ) || exit 1; \
	libs="$$libs -l$$i"; \
	done

DETECT_GNU_LD=${CC} -v 2>&1 | grep '^gcc' >/dev/null 2>&1 && \
	collect2=`gcc -print-prog-name=collect2 2>&1` && \
	[ -n "$$collect2" ] && \
	my_ld=`$$collect2 --help 2>&1 | grep Usage: | sed 's/^Usage: *\([^ ][^ ]*\).*/\1/'` && \
	[ -n "$$my_ld" ] && \
	$$my_ld -v 2>&1 | grep 'GNU ld' >/dev/null 2>&1

# For Darwin AKA Mac OS/X (dyld)
do_darwin-shared: 
	libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
	( set -x ; ${CC} --verbose -dynamiclib -o lib$$i${SHLIB_EXT} \
		lib$$i.a $$libs -all_load -current_version ${SHLIB_MAJOR}.${SHLIB_MINOR} \
		-compatibility_version ${SHLIB_MAJOR}.`echo ${SHLIB_MINOR} | cut -d. -f1` \
		-install_name ${INSTALLTOP}/lib/lib$$i${SHLIB_EXT} ) || exit 1; \
	libs="$$libs -l`basename $$i${SHLIB_EXT} .dylib`"; \
	echo "" ; \
	done

do_cygwin-shared:
	libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
	( set -x; ${CC}  -shared -o cyg$$i.dll \
		-Wl,-Bsymbolic \
		-Wl,--whole-archive lib$$i.a \
		-Wl,--out-implib,lib$$i.dll.a \
		-Wl,--no-whole-archive $$libs ) || exit 1; \
	libs="$$libs -l$$i"; \
	done

# This assumes that GNU utilities are *not* used
do_alpha-osf1-shared:
	if ${DETECT_GNU_LD}; then \
		$(MAKE) do_gnu-shared; \
	else \
		libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
		( set -x; ${CC} ${SHARED_LDFLAGS} \
			-shared -o lib$$i.so \
			-set_version "${SHLIB_VERSION_HISTORY}${SHLIB_VERSION_NUMBER}" \
			-all lib$$i.a -none $$libs ${EX_LIBS} -lc ) || exit 1; \
		libs="$$libs -l$$i"; \
		done; \
	fi

# This assumes that GNU utilities are *not* used
# The difference between alpha-osf1-shared and tru64-shared is the `-msym'
# option passed to the linker.
do_tru64-shared:
	if ${DETECT_GNU_LD}; then \
		$(MAKE) do_gnu-shared; \
	else \
		libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
		( set -x; ${CC} ${SHARED_LDFLAGS} \
			-shared -msym -o lib$$i.so \
			-set_version "${SHLIB_VERSION_HISTORY}${SHLIB_VERSION_NUMBER}" \
			-all lib$$i.a -none $$libs ${EX_LIBS} -lc ) || exit 1; \
		libs="$$libs -l$$i"; \
		done; \
	fi

# This assumes that GNU utilities are *not* used
# The difference between tru64-shared and tru64-shared-rpath is the
# -rpath ${INSTALLTOP}/lib passed to the linker.
do_tru64-shared-rpath:
	if ${DETECT_GNU_LD}; then \
		$(MAKE) do_gnu-shared; \
	else \
		libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
		( set -x; ${CC} ${SHARED_LDFLAGS} \
			-shared -msym -o lib$$i.so \
			-rpath  ${INSTALLTOP}/lib \
			-set_version "${SHLIB_VERSION_HISTORY}${SHLIB_VERSION_NUMBER}" \
			-all lib$$i.a -none $$libs ${EX_LIBS} -lc ) || exit 1; \
		libs="$$libs -l$$i"; \
		done; \
	fi


# This assumes that GNU utilities are *not* used
do_solaris-shared:
	if ${DETECT_GNU_LD}; then \
		$(MAKE) do_gnu-shared; \
	else \
		libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
		( PATH=/usr/ccs/bin:$$PATH ; export PATH; \
		  set -x; ${CC} ${SHARED_LDFLAGS} \
			-G -o lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			-h lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			-z allextract lib$$i.a $$libs ${EX_LIBS} -lc ) || exit 1; \
		libs="$$libs -l$$i"; \
		done; \
	fi

# OpenServer 5 native compilers used
do_svr3-shared:
	if ${DETECT_GNU_LD}; then \
		$(MAKE) do_gnu-shared; \
	else \
		libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
		( PATH=/usr/ccs/bin:$$PATH ; export PATH; \
		  find . -name "*.o" -print > allobjs ; \
		  OBJS= ; export OBJS ; \
		  for obj in `ar t lib$$i.a` ; do \
		    OBJS="$${OBJS} `grep $$obj allobjs`" ; \
		  done ; \
		  set -x; ${CC}  -G -o lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			-h lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			$${OBJS} $$libs ${EX_LIBS} ) || exit 1; \
		libs="$$libs -l$$i"; \
		done; \
	fi

# UnixWare 7 and OpenUNIX 8 native compilers used
do_svr5-shared:
	if ${DETECT_GNU_LD}; then \
		$(MAKE) do_gnu-shared; \
	else \
		libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
		( PATH=/usr/ccs/bin:$$PATH ; export PATH; \
		  find . -name "*.o" -print > allobjs ; \
		  OBJS= ; export OBJS ; \
		  for obj in `ar t lib$$i.a` ; do \
		    OBJS="$${OBJS} `grep $$obj allobjs`" ; \
		  done ; \
		  set -x; ${CC} ${SHARED_LDFLAGS} \
			-G -o lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			-h lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			$${OBJS} $$libs ${EX_LIBS} ) || exit 1; \
		libs="$$libs -l$$i"; \
		done; \
	fi

# This assumes that GNU utilities are *not* used
do_irix-shared:
	if ${DETECT_GNU_LD}; then \
		$(MAKE) do_gnu-shared; \
	else \
		libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
		( set -x; ${CC} ${SHARED_LDFLAGS} \
			-shared -o lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			-Wl,-soname,lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
			-all lib$$i.a $$libs ${EX_LIBS} -lc) || exit 1; \
		libs="$$libs -l$$i"; \
		done; \
	fi

# This assumes that GNU utilities are *not* used
do_hpux-shared:
	libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
	( set -x; /usr/ccs/bin/ld ${SHARED_LDFLAGS} \
		+vnocompatwarnings \
		-b -z -o lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		+h lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		-Fl lib$$i.a $$libs ${EX_LIBS} -lc ) || exit 1; \
	chmod a=rx lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR} ; \
	libs="$$libs -L. -l$$i"; \
	done

# This assumes that GNU utilities are *not* used
do_hpux64-shared:
	libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
	( set -x; /usr/ccs/bin/ld ${SHARED_LDFLAGS} \
		-b -z -o lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		+h lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		+forceload lib$$i.a $$libs ${EX_LIBS} -lc ) || exit 1; \
	chmod a=rx lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR} ; \
	libs="$$libs -L. -l$$i"; \
	done

# The following method is said to work on all platforms.  Tests will
# determine if that's how it's gong to be used.
# This assumes that for all but GNU systems, GNU utilities are *not* used.
# ALLSYMSFLAGS would be:
#  GNU systems: --whole-archive
#  Tru64 Unix:  -all
#  Solaris:     -z allextract
#  Irix:        -all
#  HP/UX-32bit: -Fl
#  HP/UX-64bit: +forceload
#  AIX:		-bnogc
# SHAREDFLAGS would be:
#  GNU systems: -shared -Wl,-soname=lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR}
#  Tru64 Unix:  -shared \
#		-set_version "${SHLIB_VERSION_HISTORY}${SHLIB_VERSION_NUMBER}"
#  Solaris:     -G -h lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR}
#  Irix:        -shared -Wl,-soname,lib$$i.so.${SHLIB_MAJOR}.${SHLIB_MINOR}
#  HP/UX-32bit: +vnocompatwarnings -b -z +s \
#		+h lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR}
#  HP/UX-64bit: -b -z +h lib$$i.sl.${SHLIB_MAJOR}.${SHLIB_MINOR}
#  AIX:		-G -bE:lib$$i.exp -bM:SRE
# SHAREDCMD would be:
#  GNU systems: $(CC)
#  Tru64 Unix:  $(CC)
#  Solaris:     $(CC)
#  Irix:        $(CC)
#  HP/UX-32bit: /usr/ccs/bin/ld
#  HP/UX-64bit: /usr/ccs/bin/ld
#  AIX:		$(CC)
ALLSYMSFLAG=-bnogc
SHAREDFLAGS=${SHARED_LDFLAGS} -G -bE:lib$$i.exp -bM:SRE
SHAREDCMD=$(CC)
do_aix-shared:
	libs='-L. ${SHLIBDEPS}'; for i in ${SHLIBDIRS}; do \
	( set -x; \
	  ld -r -o $$i.o $(ALLSYMSFLAG) lib$$i.a && \
	  ( nm -Pg lib$$i.o | grep ' [BD] ' | cut -f1 -d' ' > lib$$i.exp; \
	    $(SHAREDCMD) $(SHAREDFLAG) -o lib$$i.so lib$$i.o \
		$$libs ${EX_LIBS} ) ) \
	|| exit 1; \
	libs="$$libs -l$$i"; \
	done

Makefile.ssl: Makefile.org
	@echo "Makefile.ssl is older than Makefile.org."
	@echo "Reconfigure the source tree (via './config' or 'perl Configure'), please."
	@false

libclean:
	rm -f *.a */lib */*/lib

clean:
	rm -f shlib/*.o *.o core a.out fluff *.map rehash.time testlog make.log cctest cctest.c
	@for i in $(DIRS) ;\
	do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making clean in $$i..." && \
		$(MAKE) SDIRS='${SDIRS}' clean ) || exit 1; \
		rm -f $(LIBS); \
	fi; \
	done;
	rm -f *.a *.o speed.* *.map *.so .pure core
	rm -f $(TARFILE)
	@for i in $(ONEDIRS) ;\
	do \
	rm -fr $$i/*; \
	done

makefile.one: files
	$(PERL) util/mk1mf.pl >makefile.one; \
	sh util/do_ms.sh

files:
	$(PERL) $(TOP)/util/files.pl Makefile.ssl > $(TOP)/MINFO
	@for i in $(DIRS) ;\
	do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making 'files' in $$i..." && \
		$(MAKE) SDIRS='${SDIRS}' PERL='${PERL}' files ) || exit 1; \
	fi; \
	done;

links:
	@$(TOP)/util/point.sh Makefile.ssl Makefile
	@$(PERL) $(TOP)/util/mkdir-p.pl include/openssl
	@$(PERL) $(TOP)/util/mklink.pl include/openssl $(EXHEADER)
	@for i in $(DIRS); do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making links in $$i..." && \
		$(MAKE) CC='${CC}' PLATFORM='${PLATFORM}' CFLAG='${CFLAG}' SDIRS='$(SDIRS)' INSTALLTOP='${INSTALLTOP}' PEX_LIBS='${PEX_LIBS}' EX_LIBS='${EX_LIBS}' BN_ASM='${BN_ASM}' DES_ENC='${DES_ENC}' BF_ENC='${BF_ENC}' CAST_ENC='${CAST_ENC}' RC4_ENC='${RC4_ENC}' RC5_ENC='${RC5_ENC}' SHA1_ASM_OBJ='${SHA1_ASM_OBJ}' MD5_ASM_OBJ='${MD5_ASM_OBJ}' RMD160_ASM_OBJ='${RMD160_ASM_OBJ}' AR='${AR}' PERL='${PERL}' links ) || exit 1; \
	fi; \
	done;

dclean:
	rm -f *.bak
	@for i in $(DIRS) ;\
	do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making dclean in $$i..." && \
		$(MAKE) SDIRS='${SDIRS}' PERL='${PERL}' dclean ) || exit 1; \
	fi; \
	done;

rehash: rehash.time
rehash.time: certs
	@(OPENSSL="`pwd`/apps/openssl"; export OPENSSL; $(PERL) tools/c_rehash certs)
	touch rehash.time

test:   tests

tests: rehash
	@(cd test && echo "testing..." && \
	$(MAKE) CC='${CC}' PLATFORM='${PLATFORM}' CFLAG='${CFLAG}' SDIRS='$(SDIRS)' INSTALLTOP='${INSTALLTOP}' PEX_LIBS='${PEX_LIBS}' EX_LIBS='${EX_LIBS}' BN_ASM='${BN_ASM}' DES_ENC='${DES_ENC}' BF_ENC='${BF_ENC}' CAST_ENC='${CAST_ENC}' RC4_ENC='${RC4_ENC}' RC5_ENC='${RC5_ENC}' SHA1_ASM_OBJ='${SHA1_ASM_OBJ}' MD5_ASM_OBJ='${MD5_ASM_OBJ}' RMD160_ASM_OBJ='${RMD160_ASM_OBJ}' AR='${AR}' PROCESSOR='${PROCESSOR}' PERL='${PERL}' RANLIB='${RANLIB}' TESTS='${TESTS}' EXE_EXT='${EXE_EXT}' SHARED_LIBS='${SHARED_LIBS}' SHLIB_EXT='${SHLIB_EXT}' SHLIB_TARGET='${SHLIB_TARGET}' OPENSSL_DEBUG_MEMORY=on tests );
	@apps/openssl version -a

report:
	@$(PERL) util/selftest.pl

depend:
	@for i in $(DIRS) ;\
	do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making dependencies $$i..." && \
		$(MAKE) SDIRS='${SDIRS}' DEPFLAG='${DEPFLAG}' PERL='${PERL}' depend ) || exit 1; \
	fi; \
	done;

lint:
	@for i in $(DIRS) ;\
	do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making lint $$i..." && \
		$(MAKE) SDIRS='${SDIRS}' lint ) || exit 1; \
	fi; \
	done;

tags:
	@for i in $(DIRS) ;\
	do \
	if [ -d "$$i" ]; then \
		(cd $$i && echo "making tags $$i..." && \
		$(MAKE) SDIRS='${SDIRS}' tags ) || exit 1; \
	fi; \
	done;

errors:
	$(PERL) util/mkerr.pl -recurse -write

stacks:
	$(PERL) util/mkstack.pl -write

util/libeay.num::
	$(PERL) util/mkdef.pl crypto update

util/ssleay.num::
	$(PERL) util/mkdef.pl ssl update

crypto/objects/obj_dat.h: crypto/objects/obj_mac.h crypto/objects/obj_dat.pl
	$(PERL) crypto/objects/obj_dat.pl crypto/objects/obj_mac.h crypto/objects/obj_dat.h
crypto/objects/obj_mac.h: crypto/objects/objects.pl crypto/objects/objects.txt 
	$(PERL) crypto/objects/objects.pl crypto/objects/objects.txt crypto/objects/obj_mac.num crypto/objects/obj_mac.h

TABLE: Configure
	(echo 'Output of `Configure TABLE'"':"; \
	$(PERL) Configure TABLE) > TABLE

update: depend errors stacks util/libeay.num util/ssleay.num crypto/objects/obj_dat.h TABLE

# Build distribution tar-file. As the list of files returned by "find" is
# pretty long, on several platforms a "too many arguments" error or similar
# would occur. Therefore the list of files is temporarily stored into a file
# and read directly, requiring GNU-Tar. Call "make TAR=gtar dist" if the normal
# tar does not support the --files-from option.
tar:
	find * \! -path CVS/\* \! -path \*/CVS/\* \! -name CVS \! -name .cvsignore \! -name STATUS \! -name TABLE | sort > ../$(TARFILE).list; \
	$(TAR) $(TARFLAGS) --files-from ../$(TARFILE).list -cvf - | \
	tardy --user_number=0  --user_name=openssl \
	      --group_number=0 --group_name=openssl \
	      --prefix=openssl-$(VERSION) - |\
	gzip --best >../$(TARFILE).gz; \
	rm -f ../$(TARFILE).list; \
	ls -l ../$(TARFILE).gz

dist:   
	$(PERL) Configure dist
	@$(MAKE) dist_pem_h
	@$(MAKE) SDIRS='${SDIRS}' clean
	@$(MAKE) TAR='${TAR}' TARFLAGS='${TARFLAGS}' tar

dist_pem_h:
	(cd crypto/pem; $(MAKE) CC='${CC}' SDIRS='${SDIRS}' CFLAG='${CFLAG}' pem.h; $(MAKE) clean)

install: all install_docs
	@$(PERL) $(TOP)/util/mkdir-p.pl $(INSTALL_PREFIX)$(INSTALLTOP)/bin \
		$(INSTALL_PREFIX)$(INSTALLTOP)/lib \
		$(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl \
		$(INSTALL_PREFIX)$(OPENSSLDIR)/misc \
		$(INSTALL_PREFIX)$(OPENSSLDIR)/certs \
		$(INSTALL_PREFIX)$(OPENSSLDIR)/private \
		$(INSTALL_PREFIX)$(OPENSSLDIR)/lib
	@for i in $(EXHEADER) ;\
	do \
	(cp $$i $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i; \
	chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i ); \
	done;
	@for i in $(DIRS) ;\
	do \
	if [ -d "$$i" ]; then \
		(cd $$i; echo "installing $$i..."; \
		$(MAKE) CC='${CC}' CFLAG='${CFLAG}' INSTALL_PREFIX='${INSTALL_PREFIX}' INSTALLTOP='${INSTALLTOP}' OPENSSLDIR='${OPENSSLDIR}' EX_LIBS='${EX_LIBS}' SDIRS='${SDIRS}' RANLIB='${RANLIB}' EXE_EXT='${EXE_EXT}' install ); \
	fi; \
	done
	@for i in $(LIBS) ;\
	do \
		if [ -f "$$i" ]; then \
		(       echo installing $$i; \
			cp $$i $(INSTALL_PREFIX)$(INSTALLTOP)/lib; \
			$(RANLIB) $(INSTALL_PREFIX)$(INSTALLTOP)/lib/$$i; \
			chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/lib/$$i ); \
		fi; \
	done
	@if [ -n "$(SHARED_LIBS)" ]; then \
		tmp="$(SHARED_LIBS)"; \
		for i in $${tmp:-x}; \
		do \
			if [ -f "$$i" -o -f "$$i.a" ]; then \
			(       echo installing $$i; \
				if [ "$(PLATFORM)" != "Cygwin" ]; then \
					cp $$i $(INSTALL_PREFIX)$(INSTALLTOP)/lib; \
					chmod 555 $(INSTALL_PREFIX)$(INSTALLTOP)/lib/$$i; \
				else \
					c=`echo $$i | sed 's/^lib/cyg/'`; \
					cp $$c $(INSTALL_PREFIX)$(INSTALLTOP)/bin/$$c; \
					chmod 755 $(INSTALL_PREFIX)$(INSTALLTOP)/bin/$$c; \
					cp $$i.a $(INSTALL_PREFIX)$(INSTALLTOP)/lib/$$i.a; \
					chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/lib/$$i.a; \
				fi ); \
			fi; \
		done; \
		(	here="`pwd`"; \
			cd $(INSTALL_PREFIX)$(INSTALLTOP)/lib; \
			$(MAKE) -f $$here/Makefile link-shared ); \
	fi

install_docs:
	@$(PERL) $(TOP)/util/mkdir-p.pl \
		$(INSTALL_PREFIX)$(MANDIR)/man1 \
		$(INSTALL_PREFIX)$(MANDIR)/man3 \
		$(INSTALL_PREFIX)$(MANDIR)/man5 \
		$(INSTALL_PREFIX)$(MANDIR)/man7
	@pod2man=`cd ../../util; ./pod2mantest ignore`; \
	for i in doc/apps/*.pod; do \
		fn=`basename $$i .pod`; \
		if [ "$$fn" = "config" ]; then sec=5; else sec=1; fi; \
		echo "installing man$$sec/`basename $$i .pod`.$$sec"; \
		(cd `$(PERL) util/dirname.pl $$i`; \
		sh -c "$(PERL) $$pod2man \
			--section=$$sec --center=OpenSSL \
			--release=$(VERSION) `basename $$i`") \
			>  $(INSTALL_PREFIX)$(MANDIR)/man$$sec/`basename $$i .pod`.$$sec; \
	done; \
	@for i in doc/crypto/*.pod doc/ssl/*.pod; do \
		fn=`basename $$i .pod`; \
		if [ "$$fn" = "des_modes" ]; then sec=7; else sec=3; fi; \
		echo "installing man$$sec/`basename $$i .pod`.$$sec"; \
		(cd `$(PERL) util/dirname.pl $$i`; \
		sh -c "$(PERL) $$pod2man \
			--section=$$sec --center=OpenSSL \
			--release=$(VERSION) `basename $$i`") \
			>  $(INSTALL_PREFIX)$(MANDIR)/man$$sec/`basename $$i .pod`.$$sec; \
	done

# DO NOT DELETE THIS LINE -- make depend depends on it.
