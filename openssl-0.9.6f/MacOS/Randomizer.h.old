
/* Randomizer.h */
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
//	Gathers unpredictable system data to be used for generating random bits

#include <MacTypes.h>

class CRandomizer
{
public:
	CRandomizer (void);
	void PeriodicAction (void);
	
private:

// Private calls

	void			AddTimeSinceMachineStartup (void);
	void			AddAbsoluteSystemStartupTime (void);
	void			AddAppRunningTime (void);
	void			AddStartupVolumeInfo (void);
	void			AddFiller (void);

	void			AddCurrentMouse (void);
	void			AddNow (double millisecondUncertainty);
	void			AddBytes (void *data, long size, double entropy);
	
	void			GetTimeBaseResolution (void);
	unsigned long	SysTimer (void);

// System Info	
	bool			mSupportsLargeVolumes;
	bool			mIsPowerPC;
	bool			mIs601;
	
// Time info
	double			mTimebaseTicksPerMillisec;
	unsigned long	mLastPeriodicTicks;
	
// Mouse info
	long			mSamplePeriod;
	Point			mLastMouse;
	long			mMouseStill;
};