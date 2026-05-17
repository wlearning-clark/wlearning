// https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html
//

#include <stdio.h>
#include "prt_builtin.h"
int quick10 = 10;

void call() {
    _BASE_FILE_;
    _FILE_;
    _FILE_NAME_;
}
