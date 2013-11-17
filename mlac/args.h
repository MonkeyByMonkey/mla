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

#ifndef __MLA__ARGS_H__
#define __MLA__ARGS_H__

#include "format.h"
#include <stdbool.h>

struct mla_args
{
    bool verbose;
    const char *intro;
    const char *loop_area;
    const char *outro;
    const char *output;
    enum mla_audio_format audio_format;
};

bool mla_parse_args(int argc, char *const *argv, struct mla_args *result);

void mla_print_usage(int argc, char *const *argv);

#endif /* __MLA__ARGS_H__ */
