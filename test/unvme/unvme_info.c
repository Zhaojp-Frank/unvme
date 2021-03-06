/**
 * Copyright (c) 2015-2016, Micron Technology, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   3. Neither the name of the copyright holder nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * @brief UNVMe device info.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <err.h>

#include "unvme.h"


int main(int argc, char** argv)
{
    const char* prog = strrchr(argv[0], '/');
    prog = prog ? prog + 1 : argv[0];
    if (argc < 2)  {
        warnx("Usage: %s PCINAME", prog);
        exit(1);
    }

    const unvme_ns_t* ns = unvme_open(argv[1]);
    printf("Namespace:               %d (of %d)\n", ns->id, ns->nscount);
    printf("Vendor ID:               %#x\n", ns->vid);
    printf("Model number:            %.40s\n", ns->mn);
    printf("Serial number:           %.20s\n", ns->sn);
    printf("FW revision:             %.8s\n", ns->fr);
    printf("Block count:             %#lx\n", ns->blockcount);
    printf("Page count:              %#lx\n", ns->pagecount);
    printf("Block size:              %d\n", ns->blocksize);
    printf("Page size :              %d\n", ns->pagesize);
    printf("Blocks per page:         %d\n", ns->nbpp);
    printf("Max blocks per IO:       %d\n", ns->maxbpio);
    printf("Default IO queue count:  %d\n", ns->qcount);
    printf("Default IO queue size:   %d\n", ns->qsize);
    printf("Max IO queue count:      %d\n", ns->maxqcount);
    printf("Max IO queue size:       %d\n", ns->maxqsize);
    unvme_close(ns);

    return 0;
}

