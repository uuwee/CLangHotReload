#ifndef LIB_H
#define LIB_H

#ifdef LIB_EXPORT
#define DECL_SPEC __declspec(dllexport)
#else
#define DECL_SPEC __declspec(dllimport)
#endif

#define X(ret, name, args) DECL_SPEC ret name args;
#include "header.h"
#undef X

#endif
