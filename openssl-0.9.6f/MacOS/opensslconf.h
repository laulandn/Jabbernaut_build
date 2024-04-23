/* MacOS/opensslconf.h */

#if !(defined(VMS) || defined(__VMS)) /* VMS uses logical names instead */
#if defined(HEADER_CRYPTLIB_H) && !defined(OPENSSLDIR)
#define OPENSSLDIR "/usr/local/ssl"
#endif
#endif

#if defined(HEADER_IDEA_H) && !defined(IDEA_INT)
#define IDEA_INT unsigned int
#endif

#if defined(HEADER_MD2_H) && !defined(MD2_INT)
#define MD2_INT unsigned int
#endif

#if defined(HEADER_RC2_H) && !defined(RC2_INT)
/* I need to put in a mod for the alpha - eay */
#define RC2_INT unsigned int
#endif

#if defined(HEADER_RC4_H)
#if !defined(RC4_INT)
/* using int types make the structure larger but make the code faster
 * on most boxes I have tested - up to %20 faster. */
/*
 * I don't know what does "most" mean, but declaring "int" is a must on:
 * - Intel P6 because partial register stalls are very expensive;
 * - elder Alpha because it lacks byte load/store instructions;
 */
#define RC4_INT unsigned char
#endif
#if !defined(RC4_CHUNK)
/*
 * This enables code handling data aligned at natural CPU word
 * boundary. See crypto/rc4/rc4_enc.c for further details.
 */
#define RC4_CHUNK unsigned long
#endif
#endif

#if defined(HEADER_DES_H) && !defined(DES_LONG)
/* If this is set to 'unsigned int' on a DEC Alpha, this gives about a
 * %20 speed up (longs are 8 bytes, int's are 4). */
#ifndef DES_LONG
#define DES_LONG unsigned long
#endif
#endif

#if defined(HEADER_BN_H) && !defined(CONFIG_HEADER_BN_H)
#define CONFIG_HEADER_BN_H
#if __option(longlong)
#  define BN_LLONG
#else
#  undef BN_LLONG
#endif

/* Should we define BN_DIV2W here? */

/* Only one for the following should be defined */
/* The prime number generation stuff may not work when
 * EIGHT_BIT but I don't care since I've only used this mode
 * for debuging the bignum libraries */
#undef SIXTY_FOUR_BIT_LONG
#undef SIXTY_FOUR_BIT
#define THIRTY_TWO_BIT
#undef SIXTEEN_BIT
#undef EIGHT_BIT
#endif

#if defined(HEADER_RC4_LOCL_H) && !defined(CONFIG_HEADER_RC4_LOCL_H)
#define CONFIG_HEADER_RC4_LOCL_H
/* if this is defined data[i] is used instead of *data, this is a %20
 * speedup on x86 */
 #ifdef __POWERPC__
  #define RC4_INDEX
 #else
  #undef RC4_INDEX
 #endif
#endif

#if defined(HEADER_BF_LOCL_H) && !defined(CONFIG_HEADER_BF_LOCL_H)
#define CONFIG_HEADER_BF_LOCL_H
#ifdef __POWERPC__
  #define BF_PTR
#else
  #undef BF_PTR
#endif
#endif /* HEADER_BF_LOCL_H */

#if defined(HEADER_DES_LOCL_H) && !defined(CONFIG_HEADER_DES_LOCL_H)
#define CONFIG_HEADER_DES_LOCL_H

#ifdef __POWERPC__
 #undef DES_PTR
#endif

#ifndef DES_PTR
 #ifndef __POWERPC__
   #define DES_PTR
 #endif
#endif

/* This helps C compiler generate the correct code for multiple functional
 * units.  It reduces register dependancies at the expense of 2 more
 * registers */
 
#undef DES_RISC1

#ifndef DES_RISC2
#define DES_RISC2
#endif

#if defined(DES_RISC1) && defined(DES_RISC2)
YOU SHOULD NOT HAVE BOTH DES_RISC1 AND DES_RISC2 DEFINED!!!!!
#endif

/* Unroll the inner loop, this sometimes helps, sometimes hinders.
 * Very mucy CPU dependant */
 
/* On a PowerPC this much unrolling is unnecessary. Probably no
unrolling would be even better. Not sure about 68K */

#undef DES_UNROLL

#endif /* HEADER_DES_LOCL_H */

#ifndef __POWERPC__
#define SHA_XARRAY
#endif

