// https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "prt_builtin.h"

int main() {
    printf("__FILE__: %s\n", __FILE__);
    printf("__FILE_NAME__: %s\n", __FILE_NAME__);
    printf("__LINE__: %d\n", __LINE__);
    printf("__DATE__: %s\n", __DATE__);
    printf("__TIME__: %s\n", __TIME__);
    printf("__TIMESTAMP__ : %s\n", __TIMESTAMP__);
    printf("__STDC__ : %d\n", __STDC__);
    printf("__STDC_VERSION__ : %d\n", __STDC_VERSION__);
    printf("__GNUC__ : %d\n", __GNUC__);
    printf("__GNUC_MINOR__ : %d\n", __GNUC_MINOR__);
    printf("__GNUC_PATCHLEVEL__ : %d\n", __GNUC_PATCHLEVEL__);
    printf("__BASE_FILE__ : %s\n", __BASE_FILE__);
    printf("__SIZEOF_INT__ : %d\n", __SIZEOF_INT__);
    printf("__SIZEOF_LONG__ : %d\n", __SIZEOF_LONG__);
    printf("__SIZEOF_LONG_LONG_ : %d\n", __SIZEOF_LONG_LONG__);
    printf("__SIZEOF_LONG_DOUBLE__ : %d\n", __SIZEOF_LONG_DOUBLE__);
    printf("__SIZEOF_POINTER__ : %d\n", __SIZEOF_POINTER__);
    printf("__SIZEOF_SIZE_T__ : %d\n", __SIZEOF_SIZE_T__);
    printf("__SIZEOF_WCHAR_T__ : %d\n", __SIZEOF_WCHAR_T__);
    printf("__SIZEOF_WINT_T__ : %d\n", __SIZEOF_WINT_T__);
    printf("__SIZEOF_PTRDIFF_T__ : %d\n", __SIZEOF_PTRDIFF_T__);
    puts("======================================");
    call();
    puts("======================================");

    return (EXIT_SUCCESS);
}
