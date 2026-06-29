#include "main.h"
#include "UI/ui.h"

#include <cstdio>

namespace {
bool lvgl_initialized = false;
}

extern "C" void init_lvgl_display() {
    if (!lvgl_initialized) {
        lv_init();

        lv_display_t *display = lv_display_get_default();
        if (display == nullptr) {
            display = lv_display_create(480, 240);
            lv_display_set_default(display);
        }

        lvgl_initialized = true;
    }
}

extern "C" {
extern lv_obj_t *ui_LabelXValue;
extern lv_obj_t *ui_LabelYValue;
extern lv_obj_t *ui_LabelThetaValue;
}

namespace {
// Formats a double and pushes it into a label, with a null check.
// decimals defaults to 2 to match your current "%.2f" formatting.
void setLabelDouble(lv_obj_t* label, double value, int decimals = 2) {
    if (label == nullptr) {
        return;
    }
    char buffer[64];
    std::snprintf(buffer, sizeof(buffer), "%.*f", decimals, value);
    lv_label_set_text(label, buffer);
}
}

struct displayval {
    lv_obj_t* label;
    std::function<double()> getValue;
    int decimals;
};

displayval dispval[] = {
    {ui_LabelXValue,     [](){ return chassis.getPose().x; },     2 },
    {ui_LabelYValue,     [](){ return chassis.getPose().y; },     2 },
    {ui_LabelThetaValue, [](){ return chassis.getPose().theta; }, 2 },
};

void update_display() {
    for (displayval& val : dispval) {
        setLabelDouble(val.label, val.getValue(), val.decimals);
    }
}