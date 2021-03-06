/*
 * Copyright (C) 2004-2008  Michael Richardson <mcr@xelerance.com>
 * Copyright (C) 2004-2009  Paul Wouters <paul@xelerance.com>
 * Copyright (C) 2009 Avesh Agarwal <avagarwa@redhat.com>
 * Copyright (C) 2012-2014  Paul Wouters <paul@libreswan.org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 */

#ifndef _MD5_H_

#include <nss.h>
#include <pk11pub.h>

typedef struct {
	PK11Context* ctx_nss;
} MD5_CTX;

void osMD5Init(MD5_CTX *);
void osMD5Update(MD5_CTX *, const unsigned char *, u_int32_t);
void osMD5Final(unsigned char [16], MD5_CTX *);

#define _MD5_H_
#endif /* _MD5_H_ */
