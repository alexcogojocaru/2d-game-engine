#pragma once

#include <stdio.h>

#define __log_engine(tag, format, ...)		printf("[%s] " format "\n", tag, ##__VA_ARGS__)
#define log_info(format, ...)		        __log_engine("INFO", format, __VA_ARGS__)
#define log_error(format, ...)		        __log_engine("ERROR", format, __VA_ARGS__)
#define log_warning(format, ...)	        __log_engine("WARNING", format, __VA_ARGS__)
