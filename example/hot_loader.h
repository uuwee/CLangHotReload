#ifndef HOT_RELOADER_H
#define HOT_RELOADER_H

#include <stdio.h>
#include <windows.h>

#define X(ret, name, args) typedef ret(*PFN_##name) args;
#include "header.h"
#undef X

static HMODULE dll;
#define X(ret, name, args) static PFN_##name name;
#include "header.h"
#undef X

static int lib_load(const char *dll_path) {
  char temp_path[256];
  sprintf(temp_path, "%s.temp.dll", dll_path);
  CopyFile(dll_path, temp_path, FALSE);

  dll = LoadLibrary(temp_path);
  if (!dll)
    return 0;

#define X(ret, name, args)                                                     \
  name = (PFN_##name)GetProcAddress(dll, #name);                               \
  if (!name)                                                                   \
    return 0;
#include "header.h"
#undef X

  return 1;
}

static void lib_unload() {
  if (dll)
    FreeLibrary(dll);
  dll = NULL;
}

#endif
