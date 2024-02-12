#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <stdio.h>

#include <zephyr/drivers/display.h>
#include <lvgl.h>

LOG_MODULE_REGISTER(display, LOG_LEVEL_DBG);

// You could use zbus instead of this to transmit data from main.c to here.
extern volatile bool do_not_disturb;
extern volatile bool ble_connected;

void display(void *p1, void *p2, void *p3)
{
    const struct device *display_dev;

    display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
    if (!device_is_ready(display_dev))
    {
        LOG_ERR("Device not ready, aborting test");
        return;
    }

    /* Set background color to white */
    static lv_style_t style_screen;
    lv_style_init(&style_screen);
    lv_style_set_bg_color(&style_screen, lv_color_white());
    lv_obj_add_style(lv_scr_act(), &style_screen, 0);

    /* Load Image */
    LV_IMG_DECLARE(nordic_semi);

    lv_obj_t *logo_img = lv_img_create(lv_scr_act());
    lv_img_set_src(logo_img, &nordic_semi);
    lv_obj_align(logo_img, LV_ALIGN_CENTER, 0, 0);
    // lv_img_set_zoom(logo_img, 128); if you want to play with zooms/alignments

    k_msleep(1000);

    /* Load text banners */
    lv_obj_t *title_label = lv_label_create(lv_scr_act());
    lv_label_set_text(title_label, "Nordic Status Sign");
    lv_obj_align(title_label, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_task_handler();

    lv_obj_t *title_status_label = lv_label_create(lv_scr_act());
    lv_label_set_text(title_status_label, "Current Status");
    lv_obj_align(title_status_label, LV_ALIGN_TOP_MID, 0, 90);
    lv_task_handler();

    lv_obj_t *status_label = lv_label_create(lv_scr_act());
    lv_label_set_text(status_label, "N/A");
    lv_obj_align(status_label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *ble_status_label = lv_label_create(lv_scr_act());
    static char ble_label_str[64] = "BLE Status: N/A";
    lv_label_set_text(ble_status_label, ble_label_str);
    lv_obj_align(ble_status_label, LV_ALIGN_BOTTOM_MID, 0, 0);

    /* Main display work below here */
    lv_task_handler();
    display_blanking_off(display_dev);

    while (true)
    {
        LOG_INF("in main display task");
        (do_not_disturb) ? (lv_label_set_text(status_label, "Do Not Disturb")) : (lv_label_set_text(status_label, "Available"));
        (ble_connected) ? (lv_label_set_text(ble_status_label, "BLE: Connected")) : (lv_label_set_text(ble_status_label, "BLE: Disconnected"));
        lv_task_handler();
        k_msleep(1000);
    }
}

K_THREAD_DEFINE(display_id, 8192, display, NULL, NULL, NULL, 7, 0, 0);