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
#include "args.h"

bool mla_verbose;

int main(int argc, char *const *argv)
{
    int rc = 0;

    struct mla_args args;

    if (mla_parse_args(argc, argv, &args))
    {
        mla_verbose = args.verbose;

        FILE *intro = NULL, *loop_area = NULL, *outro = NULL, *output = NULL;

        if (args.intro)
        {
            intro = fopen(args.intro, "rb");
        }

        loop_area = fopen(args.loop_area, "rb");

        if (args.outro)
        {
            outro = fopen(args.outro, "rb");
        }

        output = fopen(args.output, "wb");

        if ((!args.intro || intro) &&
            loop_area &&
            (!args.outro || outro) &&
            output)
        {
            mla_write_v1_header(args.audio_format, intro, loop_area, NULL, 0, output);
            mla_write_v1_body(intro, loop_area, outro, output);
        }
        else
        {
            fprintf(stderr, "input/output error\n");
            rc = 2;
        }

        if (intro)
        {
            fclose(intro);
        }

        if (loop_area)
        {
            fclose(loop_area);
        }

        if (outro)
        {
            fclose(outro);
        }

        if (output)
        {
            fclose(output);
        }
    }
    else
    {
        mla_print_usage(argc, argv);
        rc = 1;
    }

    return 0;
}
