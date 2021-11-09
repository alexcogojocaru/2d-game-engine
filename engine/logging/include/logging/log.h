#pragma once

#include <stdio.h>

#define __log(tag, format, ...)		printf("[%s] " format "\n", tag, ##__VA_ARGS__)
#define log_info(format, ...)		__log("INFO", format, __VA_ARGS__)
#define log_error(format, ...)		__log("ERROR", format, __VA_ARGS__)
#define log_warning(format, ...)	__log("WARNING", format, __VA_ARGS__)
