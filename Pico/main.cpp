#include "sdk/wasmapi.h"

void init()
{

}

void on_tick()
{
    display.render_text(0,32, "Hallo :)");
    CAPI::framebuffer_set_inverted(CAPI::context_get("fbuf"), true);
}

