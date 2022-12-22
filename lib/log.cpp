//
// Created by fisher on 2022/12/22.
//
#include "common.h"
#include <stdarg.h>
#include <syslog.h>


#define MAXLINE  4096

void error(int status,int err,char *fmt, ...) {
    va_list ap;

    va_start(ap,fmt);
    vfprintf(stderr,fmt,ap);
    va_end(ap);
    if (err) {
        fprintf(stderr,"%s (%d)\n"),strerror(err),err)
    }
    if (status) {
        exit(status);
    }
}

static void err_doit(int errnoflag,int level,const char *fmt,va_list ap) {
    int errno_save,n;
    char buf[MAXLINE + 1];

    error_save = errno;

    vsnprintf(buf, MAXLINE, fmt, ap);

    n = strlen(buf);
    if (errnoflag) {
        snprintf(buf + n,MAXLINE - n,"%s",strerror(errno_save));
    }
    strcat(buf,"\n");
    fflush(stdout);
    fputs(buf,stderr);
    fflush(stderr);
}
