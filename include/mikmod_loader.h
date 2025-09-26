#ifndef mikmod_loader_h
#define mikmod_loader_h

#include <stddef.h>
#include <stdint.h>

extern const uint8_t haiku_s3m_bin[];
extern const uint32_t haiku_s3m_bin_size;

typedef struct _MY_MEMREADER {
	MREADER core;
	const void *buffer;
	size_t len;
	size_t pos;
} MY_MEMREADER;

MREADER *new_mikmod_mem_reader(const void *buffer, size_t len);
void delete_mikmod_mem_reader(MREADER* reader);

#endif
