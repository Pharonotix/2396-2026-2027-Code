#ifndef LVGL_COMPAT_H
#define LVGL_COMPAT_H

/**
 * @file lvgl_compat.h
 * @brief Compatibility layer for LVGL version differences
 * 
 * This header provides a unified API for working with different LVGL versions.
 * It maps deprecated or changed functions to their modern equivalents (LVGL 9.2.2).
 */

#include "liblvgl/lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ===== Display API Compatibility ===== */

/**
 * @brief Get the default display
 * @return Pointer to the default display
 */
static inline lv_display_t * lvgl_get_display(void)
{
    return lv_display_get_default();
}

/**
 * @brief Flush the display buffer
 * @param disp Display pointer
 */
static inline void lvgl_display_flush_ready(lv_display_t * disp)
{
    lv_display_flush_ready(disp);
}

/**
 * @brief Load a screen
 * @param scr Screen object pointer
 */
static inline void lvgl_screen_load(lv_obj_t * scr)
{
    lv_screen_load(scr);
}

/* ===== Type Aliases ===== */

/** Display type - use lv_display_t for 9.2.2 compatibility */
typedef lv_display_t lvgl_display_t;

/* ===== Deprecated Function Mappings (9.2.0 -> 9.2.2) ===== */

/** @deprecated Use lv_display_t instead */
#define lv_disp_t lv_display_t

/** @deprecated Use lv_display_set_theme instead */
#define lv_disp_set_theme(disp, theme) lv_display_set_theme(disp, theme)

/** @deprecated Use lv_screen_load instead */
#define lv_disp_load_scr(scr) lv_screen_load(scr)

/** @deprecated Use lv_display_flush_ready instead */
#define lv_disp_flush_ready(disp) lv_display_flush_ready(disp)

/** @deprecated Use lv_obj_delete instead */
#define lv_obj_del(obj) lv_obj_delete(obj)

/** @deprecated Use lv_malloc/lv_free directly - already compatible */
/* lv_malloc and lv_free are compatible across versions */

/* ===== Common Widget API Compatibility ===== */

/** @deprecated lv_obj_t type is stable across versions */
/* lv_obj_t - no change needed */

/** @deprecated lv_event_t type is stable across versions */
/* lv_event_t - no change needed */

/* ===== Object Property API Compatibility ===== */

/** @deprecated These functions are compatible across versions */
/* lv_obj_add_event_cb - no change needed */
/* lv_obj_send_event - no change needed */
/* lv_event_get_code - no change needed */
/* lv_event_get_user_data - no change needed */
/* lv_event_get_param - no change needed */

/* ===== SquareLine UI Compatibility ===== */

/**
 * @brief Initialize LVGL theme with standard colors
 * @param disp Display pointer
 * @param color_primary Primary palette color
 * @param color_secondary Secondary palette color
 * @return Theme pointer
 */
static inline lv_theme_t * lvgl_theme_init(lv_display_t * disp, lv_color_t color_primary, lv_color_t color_secondary)
{
    return lv_theme_default_init(disp, color_primary, color_secondary, false, LV_FONT_DEFAULT);
}

/**
 * @brief Set theme for display
 * @param disp Display pointer
 * @param theme Theme pointer
 */
static inline void lvgl_set_theme(lv_display_t * disp, lv_theme_t * theme)
{
    lv_display_set_theme(disp, theme);
}

#ifdef __cplusplus
}
#endif

#endif // LVGL_COMPAT_H

#ifndef LVGL_DRIVER_H
#define LVGL_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

void init_lvgl_display();

#ifdef __cplusplus
}
#endif

#endif
