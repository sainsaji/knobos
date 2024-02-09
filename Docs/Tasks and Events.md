# Creating Event Handling in Squareline Studio

In Squareline Studio, events can be managed efficiently through proper event handling mechanisms. This guide outlines the steps to create and manage events within the studio environment.

## Setting up Event Handling

To initiate an event within Squareline Studio, utilize the following syntax:


`lv_obj_add_event_cb(ui_BrightnessSlider, brightnessSliderUpdate, LV_EVENT_VALUE_CHANGED, NULL);` 

Ensure to copy and paste this code snippet after `ui_init();` in the `void setup` function as shown below:
`ui_init();
lv_obj_add_event_cb(ui_BrightnessSlider, brightnessSliderUpdate, LV_EVENT_VALUE_CHANGED, NULL);` 

Here's the breakdown of the parameters:

-   `ui_BrightnessSlider`: The object to which the event is registered.
-   `brightnessSliderUpdate`: The function to be executed upon the event trigger.
-   `LV_EVENT_VALUE_CHANGED`: Type of event being handled.
-   `NULL`: Additional data associated with the event (if any).

## Defining Event Handling Function

Define the function `brightnessSliderUpdate` to handle the event:

`void brightnessSliderUpdate(lv_event_t * e) {
    lv_obj_t *target = lv_event_get_target(e);
    xTaskCreate(lvglTask, "LVGL Task", 4096, (void *)target, 1, NULL);
}` 

Here, `lv_event_get_target(e)` retrieves the target widget associated with the event.

## Implementing the Task

Now, implement the task function `lvglTask`:

`static void lvglTask(void *pvParameters) {
    lv_obj_t *target = (lv_obj_t *)pvParameters;
    int value = lv_slider_get_value(target);
    Serial.println("Hello, World!");
    Serial.println(value);
    lv_obj_t * switch_btn = ui_LightSwitch; 
    int buttonState = lv_obj_get_state(switch_btn);
    Serial.println(buttonState);
    lv_obj_clear_state(switch_btn, lv_obj_get_state(switch_btn));
    lv_obj_add_state(switch_btn, LV_STATE_CHECKED);
    
    // Keep LVGL running
    while(1) {
        lv_task_handler();
        delay(5); // Adjust delay as needed
    }
}` 

Ensure that the task includes a `while` loop to continuously handle LVGL tasks.

## Manipulating Widgets

To manipulate widgets based on events, utilize functions such as `lv_slider_get_value()` and `lv_obj_get_state()`. For instance:

`lv_obj_t * switch_btn = ui_LightSwitch;
int buttonState = lv_obj_get_state(switch_btn);
Serial.println(buttonState);

lv_obj_clear_state(switch_btn, lv_obj_get_state(switch_btn));
lv_obj_add_state(switch_btn, LV_STATE_CHECKED);` 

Here, `ui_LightSwitch` represents the generated name from Squareline Studio, providing access to widget properties for manipulation.

By following these steps, effective event handling and widget manipulation can be achieved within Squareline Studio. 🚀