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

#include "mla.h"
#include "format.h"
#include "endian.h"
#include "io.h"

#define MLA_FORMAT_MAGIC { 0xF0, 0x9F, 0x99, 0x89 }

struct mla_header
{
    uint8_t magic[4];
    uint8_t version;

    uint16_t header_size;
    uint8_t audio_format;
    uint32_t la_offset;
    uint32_t la_size;

    void *data;

} __attribute__((__packed__));

void mla_write_v1_header(enum mla_audio_format audio_format, FILE *intro, FILE *loop_area, void *data, size_t data_size, FILE *output)
{
    uint16_t header_size = 16 + data_size;
    uint32_t la_offset = 0;
    uint32_t la_size;

    if (intro)
    {
        la_offset = mla_file_size(intro);
    }

    la_size = mla_file_size(loop_area);

    struct mla_header header = {
        .magic = MLA_FORMAT_MAGIC,
        .version = 1,
        .header_size = htobe16(header_size),
        .audio_format = audio_format,
        .la_offset = htobe32(la_offset),
        .la_size = htobe32(la_size),
        .data = data,
    };

    mla_log("writing MLA header (%d bytes).\n", header_size);
    mla_log("loop area offset is %d bytes.\n", la_offset);
    mla_log("loop area size is %d bytes.\n", la_size);

    fwrite(&header, 1, header_size, output);
}

void mla_write_v1_body(FILE *intro, FILE *loop_area, FILE *outro, FILE *output)
{
    mla_log("writing MLA body.\n");

    if (intro)
    {
        long intro_size = mla_file_size(intro);
        mla_log("writing intro segment (%lu bytes).\n", intro_size);
        mla_copy_file(intro, output);
    }

    if (loop_area)
    {
        long la_size = mla_file_size(loop_area);
        mla_log("writing loop area segment (%lu bytes).\n", la_size);
        mla_copy_file(loop_area, output);
    }

    if (outro)
    {
        long outro_size = mla_file_size(outro);
        mla_log("writing outro segment (%lu bytes).\n", outro_size);
        mla_copy_file(outro, output);
    }
}
