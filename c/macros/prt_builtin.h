#undef prt_builtin
#define prt_builtin

#define STR(x) #x
#define _BASE_FILE_ printf("__BASE_FILE__ %s\n", __BASE_FILE__)
#define _FILE_ printf("__FILE__ %s\n", __FILE__)
#define _FILE_NAME_ printf("__FILE_NAME__ %s\n", __FILE_NAME__)

void call();

