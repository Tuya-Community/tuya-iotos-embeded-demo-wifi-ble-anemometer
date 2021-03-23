#include "uni_log.h"
#include "tuya_gpio.h"
#include "FreeRTOS.h"
#include "task.h"
#include "uni_thread.h"

#include "app_adc.h"
#include "app_anemometer.h"
#include "tuya_dp_process.h"

USHORT_T anemometer_adc_value;
FLOAT_T anemometer_voltage;
FLOAT_T wind_speed;

VOID_T get_anemometer_value_task(VOID_T)
{
    while(1) {
        get_adc_value(&anemometer_adc_value);

        PR_NOTICE("alcohol_adc_value:%d", anemometer_adc_value);
        anemometer_voltage = (anemometer_adc_value/4096.0) * 2.4;

        wind_speed = (anemometer_voltage * 1000.0) * 0.027;

        anemometer_sensor_state.wind_speed_value = (UINT_T)(wind_speed*100);
        PR_NOTICE("wind_speed:%f", wind_speed);
        PR_NOTICE("wind_speed_value:%d", anemometer_sensor_state.wind_speed_value);
        

        //alcohol_sensor_state.alcohol_value = anemometer_adc_value;
        hw_report_all_dp_status();

        tuya_hal_system_sleep(1000);
    }
}

VOID_T anemometer_sensor_init(VOID_T)
{
    adc_init();

    tuya_hal_thread_create(NULL, "get value", 512 * 4, TRD_PRIO_4, get_anemometer_value_task, NULL);

}
