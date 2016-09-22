/*
 * Copyright (c) 2013 by sftp
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted.
 *
 * There's ABSOLUTELY NO WARRANTY, express or implied.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "types.h"
#include "stribog.h"
#include "MainStribog.h"

void print_hash(struct stribog_ctx_t *ctx, char* message)
{
	u8 i;

	for (i = 0; i < (ctx->size ? OUTPUT_SIZE_512 : OUTPUT_SIZE_256); i++)
		snprintf(&message[i], CHAR_MAX,"%x", ctx->h[i] ^ 0xFF);
}

void Gost_34_112012(char* message)
{
	struct stribog_ctx_t ctx;

	init(&ctx, HASH512);
	stribog(&ctx, (u8*)message, sizeof(message));

	print_hash(&ctx, message);
}
