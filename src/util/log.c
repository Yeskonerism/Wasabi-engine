#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "util/log.h"

void log_info(const char* fmt, ...) {
	va_list arg_ptr;
	char message[1024];

	va_start(arg_ptr, fmt);
	vsnprintf(message, sizeof(message), fmt, arg_ptr);
	va_end(arg_ptr);

	fprintf(stdout, "%s", message);
}

void log_error(const char* fmt, ...) {
	va_list arg_ptr;
	char message[1024];

	va_start(arg_ptr, fmt);
	vsnprintf(message, sizeof(message), fmt, arg_ptr);
	va_end(arg_ptr);

	fprintf(stderr, "[ERROR] %s", message);
}