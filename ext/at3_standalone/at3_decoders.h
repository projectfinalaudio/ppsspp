#pragma once

#include <cstdint>

// The full external API for the standalone Atrac3/3+ decoder.

struct ATRAC3Context;
struct ATRAC3PContext;

ATRAC3Context *atrac3_alloc(int channels, int block_align, const uint8_t *extra_data, int extra_data_size);
void atrac3_free(ATRAC3Context *ctx);
int atrac3_decode_frame(ATRAC3Context *ctx, float *out_data[2], int *nb_samples, int *got_frame_ptr, const uint8_t *buf, int buf_size);

ATRAC3PContext *atrac3p_alloc(int channels, int block_align);
void atrac3p_free(ATRAC3PContext *ctx);
int atrac3p_decode_frame(ATRAC3PContext *ctx, float *out_data[2], int *nb_samples, int *got_frame_ptr, const uint8_t *buf, int buf_size);
