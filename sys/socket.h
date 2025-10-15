#pragma once

#include <stddef.h>
#include <stdint.h>

typedef unsigned int socklen_t;
typedef unsigned int sa_family_t;

///@defgroup control_message

struct iovec {
  void *iov_base;
  size_t iov_len;
};

struct msghdr {
  void *msg_name;
  socklen_t msg_namelen;
  struct iovec *msg_iov;
  size_t msg_iovlen;
  void *msg_control;
  size_t msg_controllen;
  int msg_flags;
};

// control message
struct cmsghdr {
  size_t cmsg_len;
  int cmsg_level;
  int cmsg_type;
  unsigned char cmsg_data[];
};

struct cmsghdr *CMSG_FIRSTHDR(struct msghdr *msgh);
struct cmsghdr *CMSG_NXTHDR(struct msghdr *msgh, struct cmsghdr *cmsg);
size_t CMSG_ALIGN(size_t length);
size_t CMSG_SPACE(size_t length);
size_t CMSG_LEN(size_t length);
unsigned char *CMSG_DATA(struct cmsghdr *cmsg);

#define CMSG_FIRSTHDR CMSG_FIRSTHDR
#define CMSG_NXTHDR CMSG_NXTHDR
#define CMSG_ALIGN CMSG_ALIGN
#define CMSG_SPACE CMSG_SPACE
#define CMSG_LEN CMSG_LEN
#define CMSG_DATA CMSG_DATA

///@defgroup socket_address

struct sockaddr {
  sa_family_t sa_family;
  char sa_data[];
};

struct sockaddr_storage {
  sa_family_t ss_family;
};

// internet domain part in <netinet/in.h>