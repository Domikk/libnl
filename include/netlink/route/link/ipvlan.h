/*
 * netlink/route/link/ipvlan.h		IPVLAN interface
 *
 *	This library is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation version 2.1
 *	of the License.
 *
 * Copyright (c) 2015 Cong Wang <cwang@twopensource.com>
 */

#ifndef NETLINK_LINK_IPVLAN_H_
#define NETLINK_LINK_IPVLAN_H_

#include <netlink/netlink.h>
#include <netlink/route/link.h>

#ifdef __cplusplus
extern "C" {
#endif

extern struct rtnl_link *rtnl_link_ipvlan_alloc(void);

extern int		rtnl_link_is_ipvlan(struct rtnl_link *);

extern char *		rtnl_link_ipvlan_mode2str(int, char *, size_t);
extern int		rtnl_link_ipvlan_str2mode(const char *);

extern int		rtnl_link_ipvlan_set_mode(struct rtnl_link *,
			                           uint16_t);
extern int		rtnl_link_ipvlan_get_mode(struct rtnl_link *, uint16_t *out_mode);

#ifdef __cplusplus
}
#endif

#endif
