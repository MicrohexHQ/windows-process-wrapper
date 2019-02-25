#pragma once

#define SUCCESS (0)
#define FAILURE (-1)

#define WPRINTF_FORMAT _In_z_ _Printf_format_string_ LPCWSTR const
#ifdef __RESHARPER__
#define PRINTF_ATTR(format_index, first_arg_index) [[rscpp::format(printf, format_index, first_arg_index)]]
#else
#define PRINTF_ATTR(format_index, first_arg_index)
#endif

typedef int RESULT;

BOOL errors_init();
BOOL errors_destroy();
int errors_count();
PRINTF_ATTR(1, 2) BOOL error_push(WPRINTF_FORMAT format, ...);
PRINTF_ATTR(2, 3) BOOL system_error_push(const int code, WPRINTF_FORMAT format, ...);
void errors_output_all();
