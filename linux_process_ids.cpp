
#include <cstdio>
#include <unistd.h>
#include <cstdlib>

void die(const char *argv0) {
  fprintf(stderr, "%s\n", argv0);
  exit(127);
}

void getState() {
  uid_t ruid, euid, suid;
  if (getresuid(&ruid, &euid, &suid)) die("getresuid failed");
  printf("\nActual state:\n");
  printf("  Effective user id (RUID): %d\n", euid);
  printf("  Real user id      (EUID): %d\n", ruid);
  printf("  Saved user id     (SUID): %d\n", suid);
}

uid_t getsuid() {
  uid_t ruid, euid, suid;
  if (getresuid(&ruid, &euid, &suid)) die("getresuid failed");
  return suid;
}

int main() {

  printf("Hello from executable!\n\n\n");
  getState();

  printf("\n--> Executing: 'setuid(geteuid())'\n");
  if (setuid(geteuid())) die("setuid(geteuid()) failed");
  getState();  //Nothing changes

  printf("\n--> Executing: 'setuid(getuid()'\n");
  if (setuid(getuid())) die("setuid(getuid() failed");
  getState(); //non-permanently droping owner permissions

  printf("\n--> Executing: 'setuid(getsuid()'\n");
  if (setuid(getsuid())) die("setuid(getsuid() failed");
  getState(); // re-acquiring owner permissions - back to the original state


  return 0;
}