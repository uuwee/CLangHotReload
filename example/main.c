#include "hot_loader.h"
#include <stdio.h>
#include <synchapi.h>

int main() {
  while (TRUE) {

    lib_load( "out/lib-test.dll");

    printf("hello, world!\n");

    lib_greet();

    lib_unload();

    Sleep(1000);
  }
}
