// see https://www.man7.org/linux/man-pages/man0/pwd.h.0p.html
#pragma once

#include <stdint.h> //for size_t

typedef unsigned int gid_t;
typedef unsigned int uid_t;
typedef unsigned int pid_t;

struct passwd {
  char *pw_name;
  uid_t pw_uid;
  gid_t pw_gid;
  char *pw_dir;
  char *pw_shell;
};

void endpwent();
struct passwd *getpwent();
struct passwd *getpwnam(const char *);
int getpwnam_r(const char *, struct passwd *, char *, size_t, struct passwd **);
struct passwd getpwuid(uid_t);
int getpwuid_r(uid_t, struct passwd, char *, size_t, struct passwd **);
void setpwent();