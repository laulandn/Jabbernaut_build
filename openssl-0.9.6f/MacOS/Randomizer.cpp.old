/* Randomizer.cpp */
/* Copyright (C) 2000 idrive.com
 * All rights reserved.
 *
 * This file is free for commercial and non-commercial use as long as
 * the following conditions are aheared to.  The following conditions
 * apply to all code found in this distribution, be it the RC4, RSA,
 * lhash, DES, etc., code; not just the SSL code.  The SSL documentation
 * included with this distribution is covered by the same copyright terms
 * except that the holder is Tim Hudson (tjh@cryptsoft.com).
 * 
 * Copyright remains that of i-drive.com, and as such any Copyright notices in
 * the code are not to be removed.
 * If this package is used in a product, i-drive.com should be given
 * attribution as the author of the parts of the library used.
 * This can be in the form of a textual message at program startup or
 * in documentation (online or textual) provided with the package.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *    "This product includes cryptographic software written by idrive.com"
 * 4. If you include any Windows specific code (or a derivative thereof) from 
 *    the apps directory (application code) you must include an acknowledgement:
 *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
 * 
 * THIS SOFTWARE IS PROVIDED BY I-DRIVE>COM ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * 
 * The licence and distribution terms for any publically available version or
 * derivative of this code cannot be changed.  i.e. this code cannot simply be
 * copied and put under another distribution licence
 * [including the GNU Public Licence.]
 */

/* 
--------- Strong random data generation on a Macintosh (pre - OS X) ----
		
--  GENERAL: We aim to generate unpredictable bits without explicit
	user interaction. A general review of the problem may be found in
	RFC 1750, "Randomness Recommendations for Security", and some more
	discussion, of general and Mac-specific issues has appeared in
	"Using and Creating Cryptographic- Quality Random Numbers" by Jon
	Callas (www.merrymeet.com/jon/usingrandom.html). The data and
	entropy estimates provided below are based on my limited
	experimentation and estimates, rather than by any rigorous study,
	and the entropy estimates tend to be optimistic. They should not be
	considered absolute. Some of the information being collected may be
	correlated in subtle ways. That includes mouse positions, timings,
	and disk size measurements. Some obvious correlations will be
	eliminated by the programmer, but other, weaker ones may remain.
	The reliability of the code depends on such correlations being
	poorly understood, both by us and by potential interceptors. This
	package has been planned to be used with OpenSSL, v. 0.9.5. It
	requires the OpenSSL function RAND_add.
	
--  OTHER WORK: Some source code and other details have been
	published elsewhere, but I haven't found any to be satisfactory for
	the Mac per se:
	
	* The Linux random number generator (by Theodore Ts'o, in
	  drivers/char/random.c), is a carefully designed open-source
	  crypto random number package. It collects data from a variety of
	  sources, including mouse, keyboard and other interrupts. One nice
	  feature is that it explicitly estimates the entropy of the data
	  it collects. Some of its features (e.g. interrupt timing) cannot
	  be reliably exported to the Mac without using undocumented APIs.

	* Truerand by Don P. Mitchell and Matt Blaze uses variations
	  between different timing mechanisms on the same system. This has
	  not been tested on the Mac, but requires preemptive multitasking,
	  and is hardware-dependent, and can't be relied on to work well
	  if only one oscillator is present.
	
	* Cryptlib's RNG for the Mac (RNDMAC.C by Peter Gutmann), gathers
	  a lot of information about the machine and system environment.
	  Unfortunately, much of it is constant from one startup to the
	  next. In other words, the random seed could be the same from one
	  day to the next. Some of the APIs are hardware-dependent, and not
	  all are compatible with Carbon (OS X). Incidentally, the EGD
	  library is based on the UNIX entropy gathering methods in
	  cryptlib, and isn't suitable for MacOS either.
	
	* Mozilla (and perhaps earlier versions of Netscape) uses the time
	  of day (in seconds) and one uninitialized local variable to seed
	  the random number generator. The time of day is known to an
	  outside interceptor (to within the accuracy of the system clock).
	  The uninitialized variable could easily be identical between
	  subsequent launches of an application, if it is reached through
	  the same path.
	
	* OpenSSL provides the function RAND_screen(), by G. van Oosten,
	  which hashes the contents of the screen to generate a seed. This
	  is  not useful for an extension or for an application which
	  launches at startup time, since the screen is likely to look
	  identical from one launch to the next. This method is also
	  rather slow.
	
	* Using variations in disk drive seek times has been proposed
	  (Davis, Ihaka and Fenstermacher, world.std.com/~dtd/; Jakobsson,
	  Shriver, Hillyer and Juels,
	  www.bell-labs.com/user/shriver/random.html). These variations
	  appear to be due to air turbulence inside the disk drive
	  mechanism, and are very strongly unpredictable. Unfortunately
	  this technique is slow, and some implementations of it may be
	  patented (see Shriver's page above.) It of course cannot be
	  used with a RAM disk.

--  TIMING: On the 601 PowerPC the time base register is guaranteed
	to change at least once every 10 addi instructions, i.e. 10 cycles.
	On a 60 MHz machine (slowest PowerPC) this translates to a
	resolution of 1/6 usec. Newer machines seem to be using a 10 cycle
	resolution as well. For 68K Macs, the Microseconds() call may be
	used. See Develop issue 29 on the Apple developer site
	(developer.apple.com/dev/techsupport/develop/issue29/minow.html)
	for
	information on its accuracy and resolution. The code below has been
	tested only on PowerPC based machines.
	
	The time from machine startup to the launch of an application in
	the startup folder sewems to have a variance of about 1.6 msec on a
	new G4 machine with a defragmented and optimized disk, most
	extensions off and no icons on the desktop. This can be reasonably
	taken as a lower bound on the variance. Most of this variation is
	likely due to disk seek time variability. The distribution of
	startup times is probably not entirely even or uncorrelated. This
	needs to be investigated, but I am guessing that it not a major
	problem. Entropy = log2 (1600/0.166) ~= 13 bits on a 60 MHz
	machine,
	~ 16 bits for a 450 MHz machine. User-launched application startup
	times will have a variance of a second or more relative to machine
	startup time. Entropy >~ 22 bits. Machine startup time is available
	with a 1-second resolution. It is predictable to no better a minute
	or two, in the case of people who show up punctually to work at the
	same time and immediately start their computer. Using the scheduled
	startup feature (when available) will cause the machine to start up
	at the same time every day, making the value predictable.
	Entropy >~7 bits, or 0 bits with scheduled startup. The time of day
	is of course known to an outsider and thus has 0 entropy if the
	system clock is regularly calibrated.
	
--  KEY TIMING: A very fast typist (120 wpm) will have a typical
	inter-key timing interval of 100 msec. We can assume a variance of
	no less than 2 msec -- maybe. Do good typists have a constant
	rhythm, like drummers? Since what we measure is not the
	key-generated interrupt but the time at which the key event was
	taken off the event queue, our resolution is roughly the time
	between process switches, at best 1 tick (17 msec). I therefore
	consider this technique questionable and not very useful for
	obtaining high entropy data on the Mac.
	
--  MOUSE POSITION AND TIMING: The high bits of the mouse position
	are far from arbitrary, since the mouse tends to stay in a few
	limited areas of the screen. I am guessing that the position of
	the
	mouse is arbitrary within a 6 pixel square. Since the mouse stays
	still for long periods of time, it should be sampled only after it
	was moved, to avoid correlated data. This gives an entropy of
	log2(6*6) ~= 5 bits per measurement. The time during which the
	mouse
	stays still can vary from zero to, say, 5 seconds (occasionally
	longer). If the still time is measured by sampling the mouse during
	null events, and null events are received once per tick, its
	resolution is 1/60th of a second, giving an entropy of log2 (60*5)
	~= 8 bits per measurement. Since the distribution of still times is
	uneven, this estimate is on the high side. For simplicity and
	compatibility across system versions, the mouse is to be sampled
	explicitly (e.g. in the event loop), rather than in a time manager
	task.
	
--  STARTUP DISK TOTAL FILE SIZE: Varies typically by at least 20k
	from one startup to the next, with 'minimal' computer use. Won't
	vary at all if machine is started again immediately after startup
	(unless virtual memory is on), but any application which uses the
	web and caches information to disk is likely to cause this much
	variation or more. The variation is probably not random, but I
	don't
	know in what way. File sizes tend to be divisible by 4 bytes since
	file format fields are often long-aligned. Entropy > log2 (20000/4)
	~= 12 bits.
	
--  STARTUP DISK FIRST AVAILABLE ALLOCATION BLOCK: As the volume gets
	fragmented this could be anywhere in principle. In a perfectly
	unfragmented volume this will be strongly correlated with the total
	file size on the disk. With more fragmentation comes less
	certainty.
	I took the variation in this value to be 1/8 of the total file size
	on the volume.

--  SYSTEM REQUIREMENTS: The code here should be compatible System
	7.0 through OS X (Carbon), 68K and PowerPC. It has so far only been
	tested on systems 8.6 through 9.0.4.
*/

/*----------------------- Includes -----------------------*/

#include "Randomizer.h"

// Mac OS API
#include <Files.h>
#include <Folders.h>
#include <Events.h>
#include <Processes.h>
#include <Gestalt.h>
#include <Resources.h>
#include <LowMem.h>
#include <Traps.h>
#include <FSM.h>

// Standard C library
#include <stdlib.h>
#include <math.h>

/*---------------------- Function declarations ----------------------*/

// declared in OpenSSL/crypto/rand/rand.h
extern "C" void RAND_add (const void *buf, int num, double entropy);

// Make it global if needed elsewhere
unsigned long GetPPCTimer (bool is601);


/*---------------------------- Constants ----------------------------*/

// Mouse position is entered only if it differs from the last
// one by kMouseResolution pixels.
#define kMouseResolution			6				
#define kMousePositionEntropy		5.16  // log2 (kMouseResolution^2)

// Typical amount of time between mouse moves is 5 seconds -- guess
#define kTypicalMouseIdleTicks		300.0

// about log2 (20000/4), assuming a variation of 20K in total file size
// and long-aligned file formats.
#define kVolumeBytesEntropy			12.0

// Variance > 1 second, uptime in ticks
#define kApplicationUpTimeEntropy	6.0

// Entropy for machine startup time
#define kSysStartupEntropy			7.0


/*------------ Utility function for Pre - System 8.5 ---------------*/

pascal OSErr PBXGetVolInfoSyncGlue(XVolumeParamPtr paramBlock);
#if TARGET_API_MAC_CARBON || !TARGET_RT_MAC_CFM
	// Carbon builds and 68K builds don't need this glue
	#define CallPBXGetVolInfoSync PBXGetVolInfoSync
#else
	static pascal OSErr
				CallPBXGetVolInfoSync(XVolumeParamPtr paramBlock);
#endif


/*----------------------- Function definitions ----------------------*/

CRandomizer::CRandomizer (void)
{
	long	result;
	OSErr	err;
	
	err = Gestalt(gestaltFSAttr, &result);
	mSupportsLargeVolumes =
				(err == noErr)
				&& ((result & (1L << gestaltFSSupports2TBVols)) != 0);
	
	if (Gestalt (gestaltNativeCPUtype, &result) != noErr)
	{
		mIsPowerPC = false;
		mIs601 = false;
	}
	else
	{
		mIs601 = (result == gestaltCPU601);
		mIsPowerPC = (result >= gestaltCPU601);
	}
	
// First mouse will always be recorded
	mLastMouse.h = mLastMouse.v = -10;
	mLastPeriodicTicks = TickCount();
	GetTimeBaseResolution ();
	
// Add initial entropy
	AddTimeSinceMachineStartup ();
	AddAbsoluteSystemStartupTime ();
	AddStartupVolumeInfo ();
	AddFiller ();
}

void CRandomizer::PeriodicAction (void)
{
	AddCurrentMouse ();
	AddNow (0.0);		// Should have a better entropy estimate here
	mLastPeriodicTicks = TickCount();
}

/*------------------------- Private Methods -------------------------*/

void CRandomizer::AddCurrentMouse (void)
{
	Point mouseLoc;
	unsigned long lastCheck;	// Ticks since mouse was last sampled

#if TARGET_API_MAC_CARBON
	GetGlobalMouse (&mouseLoc);
#else
	SInt32 sysVersion;
	::Gestalt(gestaltSystemVersion,&sysVersion);
	if (sysVersion < 0x0850) {
		mouseLoc.v = mouseLoc.h = 0;
	} else {
		mouseLoc = LMGetMouseLocation();
	}
#endif
	
	if (labs (mLastMouse.h - mouseLoc.h) > kMouseResolution/2 &&
		labs (mLastMouse.v - mouseLoc.v) > kMouseResolution/2)
	{
		AddBytes (&mouseLoc, sizeof (mouseLoc), kMousePositionEntropy);
	}
	
	if (mLastMouse.h == mouseLoc.h && mLastMouse.v == mouseLoc.v)
		mMouseStill ++;
	else
	{
		double entropy;
		
// Mouse has moved. Add the number of measurements for which it's been
// still. If the resolution is too coarse, assume the entropy is 0.

		lastCheck = TickCount() - mLastPeriodicTicks;
		if (lastCheck <= 0)
			lastCheck = 1;
		entropy = log2l (kTypicalMouseIdleTicks/(double)lastCheck);
		if (entropy < 0.0)
			entropy = 0.0;
		AddBytes (&mMouseStill, sizeof (mMouseStill), entropy);
		mMouseStill = 0;
	}
	mLastMouse = mouseLoc;
}

void CRandomizer::AddAbsoluteSystemStartupTime (void)
{
	unsigned long	now;		// Time in seconds since 1/1/1904
	GetDateTime (&now);
	now -= TickCount() / 60;	// Time in ticks since machine startup
	AddBytes (&now, sizeof (now), kSysStartupEntropy);
}

void CRandomizer::AddTimeSinceMachineStartup (void)
{
// Uncertainty in app startup time is > 1.5 msec (see discussion).
	AddNow (1.5);
}

void CRandomizer::AddAppRunningTime (void)
{
	ProcessSerialNumber PSN;
	ProcessInfoRec		ProcessInfo;
	
	ProcessInfo.processInfoLength = sizeof (ProcessInfoRec);
	ProcessInfo.processName = nil;
	ProcessInfo.processAppSpec = nil;
	
	GetCurrentProcess (&PSN);
	GetProcessInformation (&PSN, &ProcessInfo);
	
	
// Add the time in ticks that the current process has been active

	AddBytes (&ProcessInfo,
				sizeof (ProcessInfoRec),
				kApplicationUpTimeEntropy);
}

void CRandomizer::AddStartupVolumeInfo (void)
{
	short			vRefNum;
	long			dirID;
	OSErr			err;
			
	FindFolder (kOnSystemDisk,
				kSystemFolderType,
				kDontCreateFolder,
				&vRefNum,
				&dirID);
	
	if (mSupportsLargeVolumes)
	{
		XVolumeParam	pb;
		double			bytesUsed;
		
		pb.ioVRefNum = vRefNum;
		pb.ioCompletion = 0;
		pb.ioNamePtr = 0;
		pb.ioVolIndex = 0;
		err = CallPBXGetVolInfoSync (&pb);
		if (err != noErr)
			return;
			
	// Base the entropy on the amount of space used on the disk and on
	// the next available allocation block. A lot else might be
	// unpredictable, so might as well toss the whole block in. See
	// comments for entropy estimate justifications.

#if UNIVERSAL_INTERFACES_VERSION >= 0x0330
		bytesUsed = pb.ioVTotalBytes - pb.ioVFreeBytes;
#else
		bytesUsed =
		  (pb.ioVTotalBytes.hi - pb.ioVFreeBytes.hi) * 4294967296.0D +
		  (pb.ioVTotalBytes.lo - pb.ioVFreeBytes.lo);
#endif

		AddBytes (&pb, sizeof (pb),
							kVolumeBytesEntropy +
							log2l (bytesUsed/pb.ioVAlBlkSiz) - 3.0);
	}
	else
	{
		double			blocksUsed;

#if PP_Target_Carbon

		XVolumeParam pb;
		pb.ioVRefNum = vRefNum;
		pb.ioCompletion = 0;
		pb.ioNamePtr = 0;
		pb.ioVolIndex = 0;

		err = PBXGetVolInfoSync(&pb);
#else
		ParamBlockRec	pb;
		
		pb.volumeParam.ioVRefNum = vRefNum;
		pb.volumeParam.ioCompletion = 0;
		pb.volumeParam.ioNamePtr = 0;
		pb.volumeParam.ioVolIndex = 0;
		err = PBGetVInfoSync (&pb);
#endif

		if (err != noErr)
			return;
			
	// Base the entropy on the amount of space used on the disk and on
	// the next available allocation block. A lot else might be
	// unpredictable, so might as well toss the whole block in. See
	// comments for entropy estimate justifications.

		blocksUsed =
#if PP_Target_Carbon
			pb.ioVNmAlBlks - pb.ioVFrBlk;
#else
			pb.volumeParam.ioVNmAlBlks  - pb.volumeParam.ioVFrBlk;

#endif			
		AddBytes (&pb, sizeof (pb),
									kVolumeBytesEntropy +
									log2l (blocksUsed) - 3.0);
	}
}

/*
	On a typical startup CRandomizer will come up with about 60 bits
	of good, unpredictable data. Assuming no more input will be
	available, we'll need some more lower-quality data to give OpenSSL
	the 128 bits of entropy it desires. AddFiller adds some relatively
	predictable data into the soup.
*/

void CRandomizer::AddFiller (void)
{
	struct
	{
// Front process serial number
		ProcessSerialNumber psn;
// User-selected highlight color
		RGBColor			hiliteRGBValue;
// Number of active processes
		long				processCount;		
// Processor speed
		long				cpuSpeed;
// Total logical memory (includes virtual memory)
		long				totalMemory;
// OS version
		long				systemVersion;
// Current resource file
		short				resFile;
	} data;
	GetNextProcess ((ProcessSerialNumber*) kNoProcess);
	while (GetNextProcess (&data.psn) == noErr)
		data.processCount++;
	GetFrontProcess (&data.psn);
	LMGetHiliteRGB (&data.hiliteRGBValue);
	Gestalt (gestaltProcClkSpeed, &data.cpuSpeed);
	Gestalt (gestaltLogicalRAMSize, &data.totalMemory);
	Gestalt (gestaltSystemVersion, &data.systemVersion);
	data.resFile = CurResFile ();
	
/*
	Here we pretend to feed the PRNG completely random data. This is of
	course false, as much of the above data is predictable by an
	outsider. At this point we don't have any more randomness to add,
	but with OpenSSL we must have a 128 bit seed before we can start.
	We just add what we can, without a real entropy estimate, and hope
	for the best.
*/
	AddBytes (&data, sizeof(data), 8.0 * sizeof(data));
	AddCurrentMouse ();
	AddNow (1.0);
}

//---------------------------  LOW LEVEL ------------------------------

void CRandomizer::AddBytes (void *data, long size, double entropy)
{
	RAND_add (data, size,
		entropy * 0.125);		// Convert entropy bits to bytes
}

void CRandomizer::AddNow (double millisecondUncertainty)
{
	long time = SysTimer();
	AddBytes (&time, sizeof (time),
		log2l (millisecondUncertainty * mTimebaseTicksPerMillisec));
}

//------------------------- TIMING SUPPORT ---------------------------

void CRandomizer::GetTimeBaseResolution (void)
{	
/*
  PowerPC:
	gestaltProcClkSpeed available on System 7.5.2 and above	
	Only PowerPCs running pre-7.5.2 systems are 60-80 MHz machines,
	so for them we assume the speed is 60 MHz.
	
	If we have the clock speed we can estimate the timebase
	resolution. In the 601 spec this is specified as 10 clock
	cycles. This seems to be true for later machines as well.

  68K VIA-based machines:
    see Develop Magazine no. 29 for details.
*/
#ifdef __powerc
	long speed;
	
	if (Gestalt (gestaltProcClkSpeed, &speed) != noErr)
		mTimebaseTicksPerMillisec =  6000.0D;
	else
		mTimebaseTicksPerMillisec = speed / 1.0e4D;									
#else
	mTimebaseTicksPerMillisec = 783.360D;
#endif
}

// returns the lower 32 bit of the chip timer
unsigned long CRandomizer::SysTimer (void)
{
#ifdef __powerc
	return GetPPCTimer (mIs601);
#else
	UnsignedWide usec;
	Microseconds (&usec);
	return usec.lo;
#endif
}

#ifdef __powerc
/*
	The timebase is available through mfspr on 601, mftb on later
	chips. Motorola recommends that an 601 implementation map mftb to
	mfspr through an exception, but I haven't tested to see if MacOS 
	actually does this. We only sample the lower 32 bits of the timer
	(i.e. a few minutes of resolution).
*/
asm unsigned long GetPPCTimer (register bool is601)
{
	cmplwi	is601, 0	// Check if 601
	bne		_601		// if non-zero goto _601
	mftb  	r3			// Available on 603 and later.
	blr					// return with result in r3
_601:
	mfspr r3, spr5  	// Available on 601 only.
						// blr inserted automatically
}
#endif

/*
	Glue for PBXGetVolInfoSync, taken from Apple's "MoreFiles"
	sample code (v. 1.5) with minor changes.
*/

#if !(TARGET_API_MAC_CARBON || !TARGET_RT_MAC_CFM)

	#if	__WANTPASCALELIMINATION
		#undef	pascal
	#endif	//	__WANTPASCALELIMINATION
	
	pascal OSErr PBXGetVolInfoSyncGlue(XVolumeParamPtr paramBlock)
	{
		enum
		{
			uppFSDispatchProcInfo = kRegisterBased
				 | REGISTER_RESULT_LOCATION(kRegisterD0)
				 | RESULT_SIZE(SIZE_CODE(sizeof(OSErr)))
				 | REGISTER_ROUTINE_PARAMETER(1, kRegisterD0,
				 			SIZE_CODE(sizeof(long)))	// selector
				 | REGISTER_ROUTINE_PARAMETER(2, kRegisterD1,
				 			SIZE_CODE(sizeof(long)))	// trap word
				 | REGISTER_ROUTINE_PARAMETER(3, kRegisterA0,
				 			SIZE_CODE(sizeof(XVolumeParamPtr)))
		};
		
		static UniversalProcPtr	fsDispatchTrapAddress = NULL;
		
		/* Is this the first time we've been called? */
		if ( fsDispatchTrapAddress == NULL )
		{
			/* Yes - Get the trap address of _FSDispatch */
			fsDispatchTrapAddress = NGetTrapAddress(_FSDispatch,
															OSTrap);
		}
		return ( CallOSTrapUniversalProc(fsDispatchTrapAddress,
											uppFSDispatchProcInfo,
											kFSMXGetVolInfo,
											_FSDispatch,
											paramBlock) );
	}
	
/*
	PBXGetVolInfoSync was added to the File Manager in System software
	7.5.2. However, PBXGetVolInfoSync wasn't added to InterfaceLib
	until Mac OS 8.5. This wrapper calls PBXGetVolInfoSync if it is
	found in InterfaceLib; otherwise, it calls PBXGetVolInfoSyncGlue.
	This ensures that your program is calling the latest implementation
	of PBXGetVolInfoSync.
*/
	static pascal OSErr CallPBXGetVolInfoSync(XVolumeParamPtr pb)
	{
		typedef pascal OSErr (*PBXGetVolInfoProcPtr)
											(XVolumeParamPtr pb);
		
		OSErr						result;
		CFragConnectionID			connID;
		static PBXGetVolInfoProcPtr	PBXGetVolInfoSyncPtr = NULL;
		
		//* Is this the first time we've been called? */
		if ( PBXGetVolInfoSyncPtr == NULL )
		{
			/* Yes - Get our connection ID to InterfaceLib */
			result = GetSharedLibrary("\pInterfaceLib",
										kPowerPCCFragArch,
										kLoadCFrag,
										&connID,
										NULL, NULL);
			if ( result == noErr )
			{
				/* See if PBXGetVolInfoSync is in InterfaceLib */
				if ( FindSymbol (connID,
								"\pPBXGetVolInfoSync",
								&(Ptr)PBXGetVolInfoSyncPtr,
								NULL)						!= noErr )
				{
					/* Use glue code if symbol isn't found */
					PBXGetVolInfoSyncPtr = PBXGetVolInfoSyncGlue;
				}
			}
		}
		/* Call PBXGetVolInfoSync if present;
			otherwise, call PBXGetVolInfoSyncGlue */
		return ( (*PBXGetVolInfoSyncPtr)(pb) );
	}

	#if	__WANTPASCALELIMINATION
		#define	pascal	
	#endif	//	__WANTPASCALELIMINATION

#endif	//	TARGET_API_MAC_CARBON || !TARGET_RT_MAC_CFM
