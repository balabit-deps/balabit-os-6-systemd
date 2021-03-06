#pragma once

/***
  This file is part of systemd.

  Copyright 2014 Daniel Mack

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

typedef struct BusEndpoint BusEndpoint;
typedef struct BusEndpointPolicy BusEndpointPolicy;

#include "bus-policy.h"
#include "hashmap.h"

struct BusEndpointPolicy {
        char *name;
        BusPolicyAccess access;
};

struct BusEndpoint {
        Hashmap *policy_hash;
};

int bus_endpoint_new(BusEndpoint **ep);
void bus_endpoint_free(BusEndpoint *endpoint);

int bus_endpoint_add_policy(BusEndpoint *ep, const char *name, BusPolicyAccess access);

int bus_kernel_set_endpoint_policy(int fd, uid_t uid, BusEndpoint *ep);
