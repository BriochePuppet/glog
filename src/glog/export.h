
#ifndef GLOG_EXPORT_H
#define GLOG_EXPORT_H

#ifdef GLOG_STATIC_DEFINE
#  define GLOG_EXPORT
#  define GLOG_NO_EXPORT
#else
#  ifndef GLOG_EXPORT
#    ifdef GOOGLE_GLOG_IS_A_DLL
        /* We are building this library */
#      define GLOG_EXPORT 
#    else
        /* We are using this library */
#      define GLOG_EXPORT 
#    endif
#  endif

#  ifndef GLOG_NO_EXPORT
#    define GLOG_NO_EXPORT 
#  endif
#endif

#ifndef GLOG_DEPRECATED
#  if defined(__GNUC__)
// GCC or CLANG
#    define GLOG_DEPRECATED __attribute__((deprecated))
#  elif defined(_MSC_VER)
#    if defined(__clang__)
// CLANG-CL
#        define GLOG_DEPRECATED __attribute__((deprecated))
#    else
// MSVC
#        define GLOG_DEPRECATED __declspec(deprecated)
#    endif
#  else
#    error Unknown Compiler
#  endif
#endif

#ifndef GLOG_DEPRECATED_EXPORT
#  define GLOG_DEPRECATED_EXPORT GLOG_EXPORT GLOG_DEPRECATED
#endif

#ifndef GLOG_DEPRECATED_NO_EXPORT
#  define GLOG_DEPRECATED_NO_EXPORT GLOG_NO_EXPORT GLOG_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef GLOG_NO_DEPRECATED
#    define GLOG_NO_DEPRECATED
#  endif
#endif

#endif /* GLOG_EXPORT_H */
