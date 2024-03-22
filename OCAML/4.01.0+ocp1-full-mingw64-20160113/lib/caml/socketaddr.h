/***********************************************************************/
/*                                                                     */
/*                                OCaml                                */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  All rights reserved.  This file is distributed    */
/*  under the terms of the GNU Library General Public License, with    */
/*  the special exception on linking described in file ../../LICENSE.  */
/*                                                                     */
/***********************************************************************/

#include "misc.h"

union sock_addr_union {
  struct sockaddr s_gen;
  struct sockaddr_in s_inet;
#ifdef HAS_IPV6
  struct sockaddr_in6 s_inet6;
#endif
};

extern union sock_addr_union sock_addr;

#ifdef HAS_SOCKLEN_T
typedef socklen_t socklen_param_type;
#else
typedef int socklen_param_type;
#endif

extern void get_sockaddr (value mladdr,
                          union sock_addr_union * addr /*out*/,
                          socklen_param_type * addr_len /*out*/);
CAMLprim value alloc_sockaddr (union sock_addr_union * addr /*in*/,
                      socklen_param_type addr_len, int close_on_error);
CAMLprim value alloc_inet_addr (struct in_addr * inaddr);
#define GET_INET_ADDR(v) (*((struct in_addr *) (v)))

#ifdef HAS_IPV6
CAMLexport value alloc_inet6_addr (struct in6_addr * inaddr);
#define GET_INET6_ADDR(v) (*((struct in6_addr *) (v)))
#endif

/* Yet another difference between MinGW and MSVC. Since these functions have
different implementations, under Windows, we use an indirection through 
ocp_* functions that are actually implemented in flexdll.c. Since a specific
version of this file is provided on every architecture, it is a good location
for system specific implementations. */ 
#ifdef _WIN32
int WINAPI ocp_getnameinfo (const struct sockaddr *sa,socklen_t salen,char *host,size_t hostlen,char *serv,size_t servlen,int flags);
void WINAPI ocp_freeaddrinfo (struct addrinfo *ai);
int WINAPI ocp_getaddrinfo(const char *nodename,const char *servname,const struct addrinfo *hints,struct addrinfo **res);
#else
#define ocp_getnameinfo getnameinfo
#define ocp_freeaddrinfo freeaddrinfo
#define ocp_getaddrinfo getaddrinfo
#endif
