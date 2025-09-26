#pragma once

#include "pkgi_db.h"

// Load config and return 0 on success, non-zero on failure
int pkgi_load_config(Config* config, char* update_url, size_t buffer_size);

// Save config and return 0 on success, non-zero on failure
int pkgi_save_config(const Config* config, const char* update_url, size_t buffer_size);

const char* pkgi_content_tag(ContentType content);
const char* pkgi_get_user_language();
