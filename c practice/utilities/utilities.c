#include "utilities.h"

// keeping track of memory
int allocated = 0;
int mallocd = 0;
int freed = 0;

void *Malloc(size_t size) {
  allocated += size;
  mallocd++;
  return malloc(size);
}

void Free(void *ptr, size_t size) {
  if (ptr == NULL) {
    printf("Tried to free a NULL pointer");
    return;
  }
  allocated -= size;
  freed++;
  free(ptr);
}

void memcheck() {
  printf("ALLOCATED: %d\n", allocated);
  printf("MALLOCD: %d\n", mallocd);
  printf("FREED: %d\n", freed);
}

void memreset() {
  allocated = 0;
  mallocd = 0;
  freed = 0;
}
