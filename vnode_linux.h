/*
 * Copyright (C) 2003, 2007 IBM Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA
 *
 * Author: IBM Corporation
 * This module is part of the IBM (R) Rational (R) ClearCase (R)
 * Multi-version file system (MVFS).
 * For support, please visit http://www.ibm.com/software/support
 */

#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)
#include <linux/autoconf.h>
#else
#include <linux/config.h>
#if CONFIG_MODVERSIONS == 1
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0)
#define MODVERSIONS
#include <linux/modversions.h>
#else
#include <linux/autoconf.h>
#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0) */
#endif /* CONFIG_MODVERSIONS == 1 */
#endif /* LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18) */

#include <linux/module.h>

/* common Linux headers */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0)
#include <linux/locks.h>        /* Contents are scattered in 2.6 */
#else
#include <linux/mount.h>        /* Was included by <linux/dcache.h> */
#include <linux/pagemap.h>      /* Was included by <linux/locks.h> */
#include <linux/namei.h>        /* Has stuff that was in <linux/fs.h> e.g. LAST_NORM */
#endif
#include <linux/vmalloc.h>
#include <linux/sched.h>
#include <linux/file.h>
#include <linux/poll.h>
#include <linux/smp_lock.h>
#include <linux/ctype.h>        /* For isdigit and toupper. */
#include <asm/bitops.h>
#include <asm/page.h>
#include <asm/system.h>
#include <linux/list.h>
#include <linux/dcache.h>
#include <linux/dirent.h>
#include <linux/fs.h>
#include <linux/in.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0)
#include <linux/locks.h>
#endif
#include <linux/quotaops.h>
#include <linux/sched.h>
#include <linux/time.h>
#include <linux/uio.h>
#include <linux/sunrpc/auth.h>
#include <linux/sunrpc/clnt.h>
#include <linux/sunrpc/xprt.h>
#include <linux/wait.h>
#include <asm/param.h>
#include <asm/processor.h>
#include <asm/semaphore.h>

/* common adapter headers */
#include "mvfs_mdki.h"
#include "mvfs_vnode.h"
#include "mvfs_linux_only.h"
/* $Id: 8a06027c.66c511dc.9bbb.00:01:83:09:5e:0d $ */