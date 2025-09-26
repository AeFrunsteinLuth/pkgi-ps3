#pragma once

#include "pkgi_utils.h"

// PolarSSL / mbedTLS headers for hashing
#include <polarssl/sha1.h>   // Only include if SHA1 is used elsewhere
#include <polarssl/sha256.h> // For SHA-256 hashing functions

// Standard SHA-256 digest size (in bytes)
#define SHA256_DIGEST_SIZE 32
