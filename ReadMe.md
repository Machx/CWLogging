#CWLogging
CWLogging is a set of functions that utilize Apples modern loggging asl_log() api's. All of the methods are built around CWLog which takes care of the details of adding STDERR to the file list which log messages are appended to so that they show up in the Xcode console, additionally these api's handle conditionally compiling in logging calls so they show up in the debug builds, but not the release builds. Additionally some API's handle automatically handle prepending the method name and line number to the log message. 

##Usage
You can either use `CWLog`/`CWDebugLog` or the CWLog(Info/Warning/etc) methods. The `CWLog()` and `CWDebugLog()` methods will always call `asl_log()` and append your log message to STDERR. Otherwise you can define the macro `CW_LOG_LEVEL` and utilize the methods such as `CWLogInfo()`,`CWLogWarning`,etc and define the `CW_LOG_LEVEL` macro which will make sure that the log messages will be conditionally compiled (or not) into your code.

You can either include CWLogging.h and CWLogging.m in your source code directly or as a git submodule. 

##Unit Tests
The unit tests are not true unit tests as they violate the [unit test rules](http://www.artima.com/weblogs/viewpost.jsp?thread=126923). As such they are really just to experiment and test the conditional compilation. If you wish to use them you will need to use Specta and Expecta in your project.

##License
CWLogging is licensed under the BSD 2 clause license

```
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
```