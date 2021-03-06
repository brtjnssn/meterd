/*
 * Copyright (c) 2014 Roland van Rijswijk-Deij
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Smart Meter Monitoring Daemon (meterd)
 * Logging
 */

#ifndef _METERD_LOG_H
#define _METERD_LOG_H

#include "config.h"
#include "meterd_types.h"

/* Log levels */
#define METERD_LOG_NONE		0
#define METERD_LOG_ERROR	1
#define METERD_LOG_WARNING	2
#define METERD_LOG_INFO		3
#define METERD_LOG_DEBUG	4

/* Initialise logging */
meterd_rv meterd_init_log(void);

/* Initialise logging at a certain loglevel */
meterd_rv meterd_init_log_at_level(int loglevel);

/* Uninitialise logging */
meterd_rv meterd_uninit_log(void);

/* Log something */
void meterd_log(const int log_at_level, const char* file, const int line, const char* format, ...);

typedef void (*meterd_log_fn)(const int, const char*, const int, const char*, ...);

/* Log directives */
#define ERROR_MSG(...) 		meterd_log(METERD_LOG_ERROR  , __FILE__, __LINE__, __VA_ARGS__);
#define WARNING_MSG(...) 	meterd_log(METERD_LOG_WARNING, __FILE__, __LINE__, __VA_ARGS__);
#define INFO_MSG(...) 		meterd_log(METERD_LOG_INFO   , __FILE__, __LINE__, __VA_ARGS__);
#define DEBUG_MSG(...) 		meterd_log(METERD_LOG_DEBUG  , __FILE__, __LINE__, __VA_ARGS__);

#endif /* !_METERD_LOG_H */

