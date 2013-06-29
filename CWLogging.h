/*
//  CWLogging.h
//
//  Created by Colin Wheeler on 6/19/13.
//  Copyright (c) 2013 Colin Wheeler. All rights reserved.
//
 Copyright (c) 2013, Colin Wheeler
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 - Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 
 - Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <Foundation/Foundation.h>
#import <asl.h>

/**
 Log levels made available in the log functions in this header use the ASL Log
 Levels as defined in asl.h.
 
 #define ASL_LEVEL_EMERG   0
 #define ASL_LEVEL_ALERT   1
 #define ASL_LEVEL_CRIT    2
 #define ASL_LEVEL_ERR     3
 #define ASL_LEVEL_WARNING 4
 #define ASL_LEVEL_NOTICE  5
 #define ASL_LEVEL_INFO    6
 #define ASL_LEVEL_DEBUG   7
 
 Emergency (level 0) - The highest priority, usually reserved for catastrophic 
 failures and reboot notices.
 
 Alert (level 1) - A serious failure in a key system.
 
 Critical (level 2) - A failure in a key system.
 
 Error (level 3) - Something has failed.
 
 Warning (level 4) - Something is amiss and might fail if not corrected.
 
 Notice (level 5) - Things of moderate interest to the user or administrator.
 
 Info (level 6) - The lowest priority that you would normally log, and purely 
 informational in nature.
 
 Debug (level 7) - The lowest priority, and normally not logged except for 
 messages from the kernel.
 */

/**
 Replace "DEBUG" with whatever you have defined to specifically mark the your
 development builds vs your release builds.
 
 The log level defined here determines which log calls such as CWLogInfo and
 CWLogNotice, etc actually call CWLog and which ones are just simply don't
 even compile into your code at all. You have the option of changing the levels
 defined here in the header file or simply defining CW_LOG_LEVEL somewhere in
 your code.
 */
#ifndef CW_LOG_LEVEL
	#ifdef DEBUG
		#define CW_LOG_LEVEL ASL_LEVEL_DEBUG
	#else
		#define CW_LOG_LEVEL ASL_LEVEL_NOTICE
	#endif
#endif

/**
 Logs the message passed in with the ASL API's
 
 CWLog utilizes asl_log and sets the output of the logging to STDERR. 
 It also uses ASL's Logging levels to ensure that messages are logged
 appropriately.
 
 @param level the level of the log message, you can use the CWLOG or ASL levels
 @param messageFormat the message to log
 */
void CWLog(int level, NSString *messageFormat, ...);

/**
 Calls CWLog prepending the message string with the current method & line
 
 This is equalent to calling CWLog and passing in format arguments for
 including __PRETTY_FUNCTION__ and __LINE__ in the message format.
 
 @param level One of the predefined ASL log levels as described in asl.h
 @param msgFormat The message to be logged, will be prepended with debug info
 */
#define CWDebugLog(level,msgFormat, ...) \
do { \
	NSString *shellFormat = [NSString stringWithFormat:@"%s L# %i: %@", __PRETTY_FUNCTION__, __LINE__,msgFormat]; \
	CWLog(level,shellFormat,##__VA_ARGS__); \
}while(0)

/**
 Logs a Message with asl_log passing in ASL_LEVEL_EMERG & your message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_EMERG (0) or higher is defined then this method
 is the same as calling asl_log() passing in ASL_LEVEL_INFO for the level.
 However if a sufficient enough level is not defined then this method simply
 is not compiled in your code at all. Thus in development you can use this
 method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_EMERG
	#define CWLogEmergency(msgFormat, ...) CWDebugLog(ASL_LEVEL_EMERG, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogEmergency(...)
#endif

/**
 Logs a Message with asl_log passing in ASL_LEVEL_ALERT & your message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_ALERT (1) or higher is defined then this method
 is the same as calling asl_log() passing in ASL_LEVEL_INFO for the level.
 However if a sufficient enough level is not defined then this method simply
 is not compiled in your code at all. Thus in development you can use this
 method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_ALERT
	#define CWLogAlert(msgFormat, ...) CWDebugLog(ASL_LEVEL_ALERT, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogAlert(...)
#endif

/**
 Logs a Message with asl_log passing in ASL_LEVEL_CRIT & your message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_CRIT (2) or higher is defined then this method
 is the same as calling asl_log() passing in ASL_LEVEL_INFO for the level.
 However if a sufficient enough level is not defined then this method simply
 is not compiled in your code at all. Thus in development you can use this
 method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_CRIT
	#define CWLogCritical(msgFormat, ...) CWDebugLog(ASL_LEVEL_CRIT, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogCritical(...)
#endif

/**
 Logs a Message with asl_log passing in ASL_LEVEL_ERR & your message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_ERR (3) or higher is defined then this method
 is the same as calling asl_log() passing in ASL_LEVEL_INFO for the level.
 However if a sufficient enough level is not defined then this method simply
 is not compiled in your code at all. Thus in development you can use this
 method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_ERR
	#define CWLogError(msgFormat, ...) CWDebugLog(ASL_LEVEL_ERR, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogError(...)
#endif

/**
 Logs a Message with asl_log passing in ASL_LEVEL_WARNING & your message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_WARNING (4) or higher is defined then this 
 method is the same as calling asl_log() passing in ASL_LEVEL_INFO for the 
 level. However if a sufficient enough level is not defined then this method 
 simply is not compiled in your code at all. Thus in development you can use 
 this method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_WARNING
	#define CWLogWarning(msgFormat, ...) CWDebugLog(ASL_LEVEL_WARNING, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogWarning(...)
#endif

/**
 Logs a Message with asl_log passing in ASL_LEVEL_NOTICE for level & the message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_NOTICE (5) or higher is defined then this method
 is the same as calling asl_log() passing in ASL_LEVEL_INFO for the level.
 However if a sufficient enough level is not defined then this method simply
 is not compiled in your code at all. Thus in development you can use this
 method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_NOTICE
	#define CWLogNotice(msgFormat, ...) CWDebugLog(ASL_LEVEL_NOTICE, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogNotice(...)
#endif

/**
 Logs a Message with asl_log passing in ASL_LEVEL_INFO for level & your message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_INFO (6) or higher is defined then this method
 is the same as calling asl_log() passing in ASL_LEVEL_INFO for the level. 
 However if a sufficient enough level is not defined then this method simply
 is not compiled in your code at all. Thus in development you can use this 
 method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_INFO
	#define CWLogInfo(msgFormat, ...) CWDebugLog(ASL_LEVEL_INFO, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogInfo(...)
#endif

/**
 Logs a Message with asl_log passing in ASL_LEVEL_DEBUG for level & your message
 
 If a CW_LOG_LEVEL of ASL_LEVEL_DEBUG (7) or higher is defined then this method
 is the same as calling asl_log() passing in ASL_LEVEL_INFO for the level.
 However if a sufficient enough level is not defined then this method simply
 is not compiled in your code at all. Thus in development you can use this
 method freely and in release builds just change the log level.
 
 @param messageFormat the message to log
 */
#if CW_LOG_LEVEL >= ASL_LEVEL_DEBUG
	#define CWLogDebug(msgFormat, ...) CWDebugLog(ASL_LEVEL_DEBUG, msgFormat, ##__VA_ARGS__)
#else
	#define CWLogDebug(...)
#endif
