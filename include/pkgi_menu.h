#pragma once

#include "pkgi_db.h"
#include "pkgi_dialog.h"

// Result codes for menu interactions
typedef enum {
    MenuResultSearch,      // User initiated a search
    MenuResultSearchClear, // User cleared the current search
    MenuResultAccept,      // User confirmed selection
    MenuResultCancel,      // User canceled menu
    MenuResultRefresh,     // User requested a refresh of the menu content
} MenuResult;

// Returns non-zero if the menu is currently open
int pkgi_menu_is_open(void);

// Populate the given Config structure with the current menu configuration
void pkgi_menu_get(Config* config);

// Retrieve the last menu result (one of MenuResult enum values)
MenuResult pkgi_menu_result(void);

// Start the menu
// - search_clear: non-zero to clear existing search input
// - config: pointer to the current configuration to initialize menu state
void pkgi_menu_start(int search_clear, const Config* config);

// Process menu input for the current frame
// - input: pointer to pkgi_input structure with button states and timing
// Returns 0 if no action, non-zero if menu consumed input
int pkgi_do_menu(pkgi_input* input);
