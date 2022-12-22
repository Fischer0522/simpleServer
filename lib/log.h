//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_LOG_H
#define HTTPSERVER_LOG_H
#include "stdarg.h"

#define LOG_DEBUG_TYPE 0
#define LOG_MSG_TYPE 1
#define LOG_WARN_TYPE 2
#define LOG_ERR_TYPE 3
void fischer_log(int severity,const char *msg);
void fischer_logx(int serverity,const char *errstr,const char *fmt,va_list ap);
void fischer_msgx(const char *fmt,...);
void fischer_debugx(const char *fmt,...);

#define LOG_MSG(msg) fischer_log(LOG_MSG_TYPE,msg)
#define LOG_ERR(msg) fischer_log(LOG_ERR_TYPE,msg)

#endif //HTTPSERVER_LOG_H
