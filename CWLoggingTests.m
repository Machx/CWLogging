//
//  CWLoggingTests.m
//
//  Created by Colin Wheeler on 6/19/13.
//  Copyright (c) 2013 Colin Wheeler. All rights reserved.
//

#import <asl.h>

#define CW_LOG_LEVEL ASL_LEVEL_DEBUG

#import "CWLoggingTests.h"
#import "CWLogging.h"

SpecBegin(CWLogging)

it(@"should log", ^{
	/**
	 This is here as a means to verify that the function 
	 is working correctly. It is not a true unit test.
	 */
//	CWLog(ASL_LEVEL_DEBUG, @"Log Debug Message");
//	CWLog(ASL_LEVEL_INFO, @"Log Info Message");
//	CWLog(ASL_LEVEL_NOTICE, @"Log Notice Message");
//	CWLog(ASL_LEVEL_WARNING, @"Log Warning Message");
//	CWLog(ASL_LEVEL_ERR, @"Log Error Message");
//	CWLog(ASL_LEVEL_CRIT, @"Log Critical Message");
//	CWLog(ASL_LEVEL_ALERT, @"Log Alert Message");
//	CWLog(ASL_LEVEL_EMERG, @"Log Emergency Message");
//	CWLog(ASL_LEVEL_DEBUG, @"Log Var arg Message %@",@"Hello World!");
//	
//	CWLogEmergency(@"Emergency Message");
//	CWLogAlert(@"Alert Message");
//	CWLogCritical(@"Critical Message");
//	CWLogError(@"Error Message");
//	CWLogWarning(@"Warning Message");
//	CWLogNotice(@"Notice Message");
//	CWLogInfo(@"Info Message");
//	CWLogDebug(@"Debug Message");
//	
//	CWDebugLog(ASL_LEVEL_INFO, @"Hello Info world!");
//	CWDebugLog(ASL_LEVEL_INFO, @"Hello %@",@"World!");
});

SpecEnd
