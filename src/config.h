#ifndef GLOG_CONFIG_H
#define GLOG_CONFIG_H

#if defined(__GNUC__)
// GCC or CLANG

/* Define if you have the `dladdr' function */
#define HAVE_DLADDR

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H

/* Define if you have the `backtrace' function in <execinfo.h> */
#define HAVE_EXECINFO_BACKTRACE

/* Define if you have the `backtrace_symbols' function in <execinfo.h> */
#define HAVE_EXECINFO_BACKTRACE_SYMBOLS

/* Define if you have the `fcntl' function */
#define HAVE_FCNTL

/* Define to 1 if you have the <glob.h> header file. */
#define HAVE_GLOB_H

/* Define if you have the 'pread' function */
#define HAVE_PREAD

/* Define to 1 if you have the <pwd.h> header file. */
#define HAVE_PWD_H

/* Define if you have the 'pwrite' function */
#define HAVE_PWRITE

/* Define if you have the 'sigaction' function */
#define HAVE_SIGACTION

/* Define if you have the `sigaltstack' function */
#define HAVE_SIGALTSTACK

/* Define to 1 if you have the <syslog.h> header file. */
#define HAVE_SYSLOG_H

/* Define to 1 if you have the <sys/syscall.h> header file. */
#define HAVE_SYS_SYSCALL_H

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/utsname.h> header file. */
#define HAVE_SYS_UTSNAME_H

/* Define to 1 if you have the <sys/wait.h> header file. */
#define HAVE_SYS_WAIT_H

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* define if localtime_r is available in time.h */
#define HAVE_LOCALTIME_R

/* define if gmtime_r is available in time.h */
#define HAVE_GMTIME_R

/* define if ssize_t is defined */
#define HAVE_SSIZE_T

/* define if mode_t is defined */
#define HAVE_MODE_T

/* define if abi::__cxa_demangle is available in cxxabi.h */
#define HAVE___CXA_DEMANGLE

/* define if __progname is available */
#define HAVE___PROGNAME

#if defined(__linux__)

/* Define to 1 if you have the <syscall.h> header file. */
#define HAVE_SYSCALL_H

/* Define if you have the 'posix_fadvise' function in <fcntl.h> */
#define HAVE_POSIX_FADVISE

/* Define to 1 if you have the <elf.h> header file. */
#define HAVE_ELF_H

/* Define to 1 if you have the <link.h> header file. */
#define HAVE_LINK_H

/* Define to 1 if you have the <ucontext.h> header file. */
#define HAVE_UCONTEXT_H

/* How to access the PC from a struct ucontext */
#define PC_FROM_UCONTEXT uc_mcontext.gregs[REG_RIP]

/* define if program_invocation_short_name is available in cerrno */
#define HAVE_PROGRAM_INVOCATION_SHORT_NAME

#elif defined(__MACH__)

/* define if getprogname is available in cstdlib */
#define HAVE_GETPROGNAME

#else
#error Unknown Platform
#endif

#elif defined(_MSC_VER)
// CLANG-CL or MSVC

/* define if you have dbghelp library */
#define HAVE_DBGHELP

/* define if _chsize_s is available in io.h */
#define HAVE__CHSIZE_S

/* define if __argv is available in cstdlib */
#define HAVE___ARGV

#else
#error Unknown Compiler
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H

/* define if symbolize support is available */
#define HAVE_SYMBOLIZE

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P sizeof(void *)

/* Define if thread-local storage is enabled. */
#define GLOG_THREAD_LOCAL_STORAGE

#endif // GLOG_CONFIG_H
