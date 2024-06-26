#
# SSLeay/crypto/dsa/Makefile
#

DIR=	dsa
TOP=	../..
CC=	cc
INCLUDES= -I.. -I../../include
CFLAG=-g
INSTALL_PREFIX=
OPENSSLDIR=     /usr/local/ssl
INSTALLTOP=/usr/local/ssl
MAKE=		make -f Makefile.ssl
MAKEDEPEND=	$(TOP)/util/domd $(TOP)
MAKEFILE=	Makefile.ssl
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=dsatest.c
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC= dsa_gen.c dsa_key.c dsa_lib.c dsa_asn1.c dsa_vrf.c dsa_sign.c \
	dsa_err.c dsa_ossl.c
LIBOBJ= dsa_gen.o dsa_key.o dsa_lib.o dsa_asn1.o dsa_vrf.o dsa_sign.o \
	dsa_err.o dsa_ossl.o

SRC= $(LIBSRC)

EXHEADER= dsa.h
HEADER=	$(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	@echo You may get an error following this line.  Please ignore.
	- $(RANLIB) $(LIB)
	@touch lib

files:
	$(PERL) $(TOP)/util/files.pl Makefile.ssl >> $(TOP)/MINFO

links:
	@$(TOP)/util/point.sh Makefile.ssl Makefile
	@$(PERL) $(TOP)/util/mklink.pl ../../include/openssl $(EXHEADER)
	@$(PERL) $(TOP)/util/mklink.pl ../../test $(TEST)
	@$(PERL) $(TOP)/util/mklink.pl ../../apps $(APPS)

install:
	@for i in $(EXHEADER) ; \
	do  \
	(cp $$i $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i; \
	chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i ); \
	done;

tags:
	ctags $(SRC)

tests:

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff

depend:
	$(MAKEDEPEND) $(INCLUDES) $(DEPFLAG) $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.o */*.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

dsa_asn1.o: ../../include/openssl/asn1.h ../../include/openssl/asn1_mac.h
dsa_asn1.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
dsa_asn1.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
dsa_asn1.o: ../../include/openssl/dh.h ../../include/openssl/dsa.h
dsa_asn1.o: ../../include/openssl/e_os.h ../../include/openssl/e_os2.h
dsa_asn1.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
dsa_asn1.o: ../../include/openssl/opensslconf.h
dsa_asn1.o: ../../include/openssl/opensslv.h ../../include/openssl/safestack.h
dsa_asn1.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
dsa_asn1.o: ../cryptlib.h
dsa_err.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
dsa_err.o: ../../include/openssl/crypto.h ../../include/openssl/dh.h
dsa_err.o: ../../include/openssl/dsa.h ../../include/openssl/err.h
dsa_err.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
dsa_err.o: ../../include/openssl/opensslv.h ../../include/openssl/safestack.h
dsa_err.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
dsa_gen.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
dsa_gen.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
dsa_gen.o: ../../include/openssl/dh.h ../../include/openssl/dsa.h
dsa_gen.o: ../../include/openssl/e_os.h ../../include/openssl/e_os2.h
dsa_gen.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
dsa_gen.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
dsa_gen.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
dsa_gen.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
dsa_gen.o: ../../include/openssl/symhacks.h ../cryptlib.h
dsa_key.o: ../../include/openssl/bio.h ../../include/openssl/bn.h
dsa_key.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
dsa_key.o: ../../include/openssl/dh.h ../../include/openssl/dsa.h
dsa_key.o: ../../include/openssl/e_os.h ../../include/openssl/e_os2.h
dsa_key.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
dsa_key.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
dsa_key.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
dsa_key.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
dsa_key.o: ../../include/openssl/symhacks.h ../cryptlib.h
dsa_lib.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
dsa_lib.o: ../../include/openssl/blowfish.h ../../include/openssl/bn.h
dsa_lib.o: ../../include/openssl/buffer.h ../../include/openssl/cast.h
dsa_lib.o: ../../include/openssl/crypto.h ../../include/openssl/des.h
dsa_lib.o: ../../include/openssl/dh.h ../../include/openssl/dsa.h
dsa_lib.o: ../../include/openssl/e_os.h ../../include/openssl/e_os2.h
dsa_lib.o: ../../include/openssl/engine.h ../../include/openssl/err.h
dsa_lib.o: ../../include/openssl/evp.h ../../include/openssl/idea.h
dsa_lib.o: ../../include/openssl/lhash.h ../../include/openssl/md2.h
dsa_lib.o: ../../include/openssl/md4.h ../../include/openssl/md5.h
dsa_lib.o: ../../include/openssl/mdc2.h ../../include/openssl/obj_mac.h
dsa_lib.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
dsa_lib.o: ../../include/openssl/opensslv.h ../../include/openssl/rand.h
dsa_lib.o: ../../include/openssl/rc2.h ../../include/openssl/rc4.h
dsa_lib.o: ../../include/openssl/rc5.h ../../include/openssl/ripemd.h
dsa_lib.o: ../../include/openssl/rsa.h ../../include/openssl/safestack.h
dsa_lib.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
dsa_lib.o: ../../include/openssl/symhacks.h ../cryptlib.h
dsa_ossl.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
dsa_ossl.o: ../../include/openssl/blowfish.h ../../include/openssl/bn.h
dsa_ossl.o: ../../include/openssl/buffer.h ../../include/openssl/cast.h
dsa_ossl.o: ../../include/openssl/crypto.h ../../include/openssl/des.h
dsa_ossl.o: ../../include/openssl/dh.h ../../include/openssl/dsa.h
dsa_ossl.o: ../../include/openssl/e_os.h ../../include/openssl/e_os2.h
dsa_ossl.o: ../../include/openssl/engine.h ../../include/openssl/err.h
dsa_ossl.o: ../../include/openssl/evp.h ../../include/openssl/idea.h
dsa_ossl.o: ../../include/openssl/lhash.h ../../include/openssl/md2.h
dsa_ossl.o: ../../include/openssl/md4.h ../../include/openssl/md5.h
dsa_ossl.o: ../../include/openssl/mdc2.h ../../include/openssl/obj_mac.h
dsa_ossl.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
dsa_ossl.o: ../../include/openssl/opensslv.h ../../include/openssl/rand.h
dsa_ossl.o: ../../include/openssl/rc2.h ../../include/openssl/rc4.h
dsa_ossl.o: ../../include/openssl/rc5.h ../../include/openssl/ripemd.h
dsa_ossl.o: ../../include/openssl/rsa.h ../../include/openssl/safestack.h
dsa_ossl.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
dsa_ossl.o: ../../include/openssl/symhacks.h ../cryptlib.h
dsa_sign.o: ../../include/openssl/asn1.h ../../include/openssl/bio.h
dsa_sign.o: ../../include/openssl/blowfish.h ../../include/openssl/bn.h
dsa_sign.o: ../../include/openssl/buffer.h ../../include/openssl/cast.h
dsa_sign.o: ../../include/openssl/crypto.h ../../include/openssl/des.h
dsa_sign.o: ../../include/openssl/dh.h ../../include/openssl/dsa.h
dsa_sign.o: ../../include/openssl/e_os.h ../../include/openssl/e_os2.h
dsa_sign.o: ../../include/openssl/engine.h ../../include/openssl/err.h
dsa_sign.o: ../../include/openssl/evp.h ../../include/openssl/idea.h
dsa_sign.o: ../../include/openssl/lhash.h ../../include/openssl/md2.h
dsa_sign.o: ../../include/openssl/md4.h ../../include/openssl/md5.h
dsa_sign.o: ../../include/openssl/mdc2.h ../../include/openssl/obj_mac.h
dsa_sign.o: ../../include/openssl/objects.h ../../include/openssl/opensslconf.h
dsa_sign.o: ../../include/openssl/opensslv.h ../../include/openssl/rand.h
dsa_sign.o: ../../include/openssl/rc2.h ../../include/openssl/rc4.h
dsa_sign.o: ../../include/openssl/rc5.h ../../include/openssl/ripemd.h
dsa_sign.o: ../../include/openssl/rsa.h ../../include/openssl/safestack.h
dsa_sign.o: ../../include/openssl/sha.h ../../include/openssl/stack.h
dsa_sign.o: ../../include/openssl/symhacks.h ../cryptlib.h
dsa_vrf.o: ../../include/openssl/asn1.h ../../include/openssl/asn1_mac.h
dsa_vrf.o: ../../include/openssl/bio.h ../../include/openssl/blowfish.h
dsa_vrf.o: ../../include/openssl/bn.h ../../include/openssl/buffer.h
dsa_vrf.o: ../../include/openssl/cast.h ../../include/openssl/crypto.h
dsa_vrf.o: ../../include/openssl/des.h ../../include/openssl/dh.h
dsa_vrf.o: ../../include/openssl/dsa.h ../../include/openssl/e_os.h
dsa_vrf.o: ../../include/openssl/e_os2.h ../../include/openssl/engine.h
dsa_vrf.o: ../../include/openssl/err.h ../../include/openssl/evp.h
dsa_vrf.o: ../../include/openssl/idea.h ../../include/openssl/lhash.h
dsa_vrf.o: ../../include/openssl/md2.h ../../include/openssl/md4.h
dsa_vrf.o: ../../include/openssl/md5.h ../../include/openssl/mdc2.h
dsa_vrf.o: ../../include/openssl/obj_mac.h ../../include/openssl/objects.h
dsa_vrf.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
dsa_vrf.o: ../../include/openssl/rand.h ../../include/openssl/rc2.h
dsa_vrf.o: ../../include/openssl/rc4.h ../../include/openssl/rc5.h
dsa_vrf.o: ../../include/openssl/ripemd.h ../../include/openssl/rsa.h
dsa_vrf.o: ../../include/openssl/safestack.h ../../include/openssl/sha.h
dsa_vrf.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
dsa_vrf.o: ../cryptlib.h
