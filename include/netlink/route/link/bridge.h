/*
 * netlink/route/link/bridge.h		Bridge
 *
 *	This library is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU Lesser General Public
 *	License as published by the Free Software Foundation version 2.1
 *	of the License.
 *
 * Copyright (c) 2013 Thomas Graf <tgraf@suug.ch>
 */

#ifndef NETLINK_LINK_BRIDGE_H_
#define NETLINK_LINK_BRIDGE_H_

#include <netlink/netlink.h>
#include <netlink/route/link.h>

#ifdef __cplusplus
extern "C" {
#endif

/* maximum vlan id */
#define VLAN_N_VID		4096

#define BITS_PER_BYTE		8
#define BITS_PER_LONG		(BITS_PER_BYTE * sizeof(unsigned long))
#define DIV_ROUND_UP(n,d)	(((n) + (d) - 1) / (d))
#define BITS_TO_LONGS(nr)	DIV_ROUND_UP(nr, BITS_PER_LONG)
#define BR_VLAN_BITMAP_LEN	BITS_TO_LONGS(VLAN_N_VID)

struct bridge_vlan
{
	uint16_t                pvid;
	unsigned long           vlan_bitmap[BR_VLAN_BITMAP_LEN];
	unsigned long           untagged_bitmap[BR_VLAN_BITMAP_LEN];
};

/**
 * Bridge flags
 * @ingroup bridge
 */
enum rtnl_link_bridge_flags {
	RTNL_BRIDGE_HAIRPIN_MODE	= 0x0001,
	RTNL_BRIDGE_BPDU_GUARD		= 0x0002,
	RTNL_BRIDGE_ROOT_BLOCK		= 0x0004,
	RTNL_BRIDGE_FAST_LEAVE		= 0x0008,
};

extern struct rtnl_link *rtnl_link_bridge_alloc(void);

extern int	rtnl_link_is_bridge(struct rtnl_link *);
extern int	rtnl_link_bridge_has_ext_info(struct rtnl_link *);

extern int	rtnl_link_bridge_set_port_state(struct rtnl_link *, uint8_t );
extern int	rtnl_link_bridge_get_port_state(struct rtnl_link *);

extern int	rtnl_link_bridge_set_priority(struct rtnl_link *, uint16_t);
extern int	rtnl_link_bridge_get_priority(struct rtnl_link *);

extern int	rtnl_link_bridge_set_cost(struct rtnl_link *, uint32_t);
extern int	rtnl_link_bridge_get_cost(struct rtnl_link *, uint32_t *);

extern int	rtnl_link_bridge_unset_flags(struct rtnl_link *, unsigned int);
extern int	rtnl_link_bridge_set_flags(struct rtnl_link *, unsigned int);
extern int	rtnl_link_bridge_get_flags(struct rtnl_link *);

extern char * rtnl_link_bridge_flags2str(int, char *, size_t);
extern int	rtnl_link_bridge_str2flags(const char *);

extern int	rtnl_link_bridge_add(struct nl_sock *sk, const char *name);

extern int	rtnl_link_bridge_pvid(struct rtnl_link *link);
extern int	rtnl_link_bridge_has_vlan(struct rtnl_link *link);

extern struct bridge_vlan *rtnl_bridge_get_port_vlan(struct rtnl_link *link);
#ifdef __cplusplus
}
#endif

#endif

