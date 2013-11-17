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

#include "io.h"

void mla_copy_file(FILE *input, FILE *output)
{
    const size_t buf_size = 8192;
    char buf[buf_size];

    size_t bytes_read;

    while ((bytes_read = fread(buf, 1, buf_size, input)) > 0)
    {
        fwrite(buf, 1, bytes_read, output);
    }
}

long mla_file_size(FILE *fp)
{
    long cur_pos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    fseek(fp, cur_pos, SEEK_SET);

    return size;
}
