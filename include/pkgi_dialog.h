#pragma once

#include <stdint.h>
#include "pkgi_db.h"

#define MDIALOG_OK      0 
#define MDIALOG_YESNO   1 

// Input state structure for dialog handling
typedef struct pkgi_input {
    uint64_t delta;   // Time in microseconds since the last frame
    uint32_t pressed; // Buttons pressed in the last frame
    uint32_t down;    // Buttons currently held down
    uint32_t active;  // Buttons pressed or held for a long duration (10 frames)
} pkgi_input;

// Callback function type for dialogs (int indicates result: OK, Cancel, Yes, No)
typedef void (*pkgi_dialog_callback_t)(int result);

// Initialize the dialog system (must be called before using dialogs)
void pkgi_dialog_init(void);

// Returns non-zero if a dialog is currently open
int pkgi_dialog_is_open(void);

// Returns non-zero if the user canceled the current dialog
int pkgi_dialog_is_cancelled(void);

// Allow or disallow the dialog to be closed by user input
void pkgi_dialog_allow_close(int allow);

// Display a simple message dialog with a title and text
void pkgi_dialog_message(const char* title, const char* text);

// Display an error dialog (typically just text, no title)
void pkgi_dialog_error(const char* text);

// Show detailed information for a database item, e.g., game details
void pkgi_dialog_details(DbItem* item, const char* type);

// Show a dialog with OK and Cancel buttons; callback is triggered with the user's choice
void pkgi_dialog_ok_cancel(const char* title, const char* text, pkgi_dialog_callback_t callback);

// Open a progress dialog with a title, initial text, and starting progress (0.0 to 1.0)
void pkgi_dialog_start_progress(const char* title, const char* text, float progress);

// Update the title of an already open progress dialog
void pkgi_dialog_set_progress_title(const char* title);

// Update the content of a progress dialog:
// - text: main status text
// - extra: additional details (optional)
// - eta: estimated time remaining (optional)
// - progress: current progress (0.0 to 1.0)
void pkgi_dialog_update_progress(
    const char* text,
    const char* extra,
    const char* eta,
    float progress
);
// Close the currently open dialog (if any)
void pkgi_dialog_close(void);

// Process dialog input for the current frame
// - input: structure containing button states and timing
void pkgi_do_dialog(pkgi_input* input);

// Show a modal message dialog with specified type
// - tdialog: type of dialog (MDIALOG_OK or MDIALOG_YESNO)
// - str: message text to display
// Returns: user response (0 for cancel/no, 1 for ok/yes)
int pkgi_msg_dialog(int tdialog, const char* str);
