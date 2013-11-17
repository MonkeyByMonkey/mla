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

#ifndef __MLA__MLA_H__
#define __MLA__MLA_H__

#include <stdbool.h>
#include <stdio.h>

extern bool mla_verbose;

#define mla_log(fmt, ...) { if (mla_verbose) { fprintf(stderr, fmt, ##__VA_ARGS__); } }

#endif /* __MLA__MLA_H__ */
