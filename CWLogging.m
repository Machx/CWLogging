/*
//  CWLogging.m
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

#import "CWLogging.h"

void CWLog(int level, NSString *messageFormat, ...) {
	//Add STDERR for ASL Logging
	static dispatch_once_t onceToken;
	dispatch_once(&onceToken, ^{
		asl_add_log_file(NULL, STDERR_FILENO);
	});
	//log message
	va_list args;
	va_start(args, messageFormat);
	NSString *logMessage = [[NSString alloc] initWithFormat:messageFormat arguments:args];
	va_end(args);
	
	//use "%s", ... to avoid clangs warning on non string literals
	asl_log(NULL/*aslclient*/, NULL/*aslmsg*/, level, "%s", [logMessage UTF8String]);
}
