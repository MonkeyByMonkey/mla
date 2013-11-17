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

#ifndef __MLA__FORMAT_H__
#define __MLA__FORMAT_H__

#include <stdint.h>
#include <stdio.h>

enum mla_audio_format
{
    MLA_AUDIO_FORMAT_UNSPECIFIED,
    MLA_AUDIO_FORMAT_OGG_VORBIS,
    MLA_AUDIO_FORMAT_FLAC,
    MLA_AUDIO_FORMAT_PCM_S16LE
};

void mla_write_v1_header(enum mla_audio_format audio_format, FILE *intro, FILE *loop_area, void *data, size_t data_size, FILE *output);
void mla_write_v1_body(FILE *intro, FILE *loop_area, FILE *outro, FILE *output);

#endif /* __MLA__FORMAT_H__ */
