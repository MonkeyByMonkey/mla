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

#include "args.h"
#include "format.h"

#include <getopt.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include <strings.h>

static struct option optspec[] = {
    { "verbose",    no_argument,            0,      'v' },
    { "intro",      required_argument,      0,      'i' },
    { "outro",      required_argument,      0,      'o' },
    { "format",     required_argument,      0,      'f' },
    { 0,            0,                      0,      0   }
};

bool mla_parse_audio_format(const char *format, enum mla_audio_format *result);

bool mla_parse_args(int argc, char *const *argv, struct mla_args *result)
{
    memset(result, 0, sizeof(struct mla_args));

    result->verbose = false;

    char c;

    while ((c = getopt_long(argc, argv, "vi:o:f:p:", optspec, NULL)) != -1)
    {
        switch (c)
        {
            case 'v':
                result->verbose = true;
                break;

            case 'i':
                result->intro = optarg;
                break;

            case 'o':
                result->outro = optarg;
                break;

            case 'f':
                if (!mla_parse_audio_format(optarg, &result->audio_format))
                {
                    return false;
                }
                break;

            case '?':
            default:
                return false;
        }
    }

    if (argc - optind == 2)
    {
        result->loop_area = argv[optind];
        result->output = argv[optind + 1];
    }
    else
    {
        return false;
    }

    return true;
}

bool mla_parse_audio_format(const char *format, enum mla_audio_format *result)
{
    if (strcasecmp("vorbis", format) == 0)
    {
        *result = MLA_AUDIO_FORMAT_OGG_VORBIS;
        return true;
    }
    else if (strcasecmp("flac", format) == 0)
    {
        *result = MLA_AUDIO_FORMAT_FLAC;
        return true;
    }
    else if (strcasecmp("s16le", format) == 0)
    {
        *result = MLA_AUDIO_FORMAT_PCM_S16LE;
        return true;
    }
    else
    {
        return false;
    }
}

void mla_print_usage(int argc, char *const *argv)
{
    struct option *option = optspec;

    fprintf(stderr, "usage: %s: <options> <loop_area> <output>\n\n", basename(argv[0]));

    do
    {
        fprintf(stderr, "    -%c --%s", option->val, option->name);

        if (option->has_arg == required_argument)
        {
            fprintf(stderr, " %s", option->name);
        }
        else if (option->has_arg == optional_argument)
        {
            fprintf(stderr, " [%s]", option->name);
        }

        fprintf(stderr, "\n");

    } while ((++option)->name != NULL);
}
