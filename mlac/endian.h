// -*- mode: c; tab-width: 4; indent-tabs-mode: nil -*-

/**
 * Copyright (c) 2013 Monkey By Monkey
 *
 * This file is part of mla.
 *
 * mla is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mla is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mla. If not, see <http://www.gnu.org/licenses/>.
**/

#ifdef __APPLE__

#include <libkern/OSByteOrder.h>

#define htobe16 OSSwapHostToBigInt16
#define htole16 OSSwapHostToLittleInt16
#define be16toh OSSwapBigToHostInt16
#define le16toh OSSwapLittleToHostInt16

#define htobe32 OSSwapHostToBigInt32
#define htole32 OSSwapHostToLittleInt32
#define be32toh OSSwapBigToHostInt32
#define le32toh OSSwapLittleToHostInt32

#define htobe64 OSSwapHostToBigInt64
#define htole64 OSSwapHostToLittleInt64
#define be64toh OSSwapBigToHostInt64
#define le64toh OSSwapLittleToHostInt64

#define __BYTE_ORDER    BYTE_ORDER
#define __BIG_ENDIAN    BIG_ENDIAN
#define __LITTLE_ENDIAN LITTLE_ENDIAN
#define __PDP_ENDIAN    PDP_ENDIAN

#else
#define __USE_BSD
#include <endian.h>
#endif
