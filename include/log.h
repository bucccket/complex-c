#ifndef __libced_log_h_
#define __libced_log_h_

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void _ced_log(FILE *file, const char* fmt, ...);

#define ced_logf(f, ...) _ced_log(f, __VA_ARGS__)
#define ced_log(...) _ced_log(NULL, __VA_ARGS__)

