#ifdef _WIN32
#define MY_EPIC_STRING "you're on a windows bro!"
#elif __APPLE__
#define MY_EPIC_STRING "you're on an apple bro!"
#elif __linux__
#define MY_EPIC_STRING "you're on a linux bro!"
#elif __unix__
#define MY_EPIC_STRING "nice un*x mate"
#elif defined(_POSIX_VERSION)
#define MY_EPIC_STRING "nice posix mate"
#else
#define MY_EPIC_STRING "wtf are you on mate"
#endif
