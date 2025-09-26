#pragma once

#include <stdint.h>
#include "pkgi_db.h"

// Size of a RAP file in bytes
#define PKGI_RAP_SIZE 16

// Download a database item (game, DLC, etc.)
// - item: pointer to the database entry
// - background_dl: non-zero to perform download in the background
// Returns 0 on success, non-zero on failure
int pkgi_download(const DbItem* item, const int background_dl);

// Download the icon associated with a given content ID
// - content: content ID string (e.g., "NPWR12345")
// Returns 0 on success, non-zero on failure
int pkgi_download_icon(const char* content);

// Download a file from a URL into memory buffer
// - url: remote file URL
// - buf_size: pointer to store size of allocated buffer
// Returns pointer to allocated buffer containing downloaded data (must be freed with pkgi_free), or NULL on failure
char* pkgi_http_download_buffer(const char* url, uint32_t* buf_size);

// Convert a RAP file to a RIF file
// - rap: pointer to 16-byte RAP data
// - content_id: target content ID
// - exdata_path: path to save generated RIF
// Returns 0 on success, non-zero on failure
int rap2rif(const uint8_t* rap, const char* content_id, const char* exdata_path);
