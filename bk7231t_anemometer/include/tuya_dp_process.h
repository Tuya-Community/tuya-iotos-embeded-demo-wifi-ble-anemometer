#ifndef __TUYA_DP_PROCESS_H__
#define __TUYA_DP_PROCESS_H__

#include "tuya_cloud_com_defs.h"
#include "tuya_cloud_types.h"

/* DP define */
typedef UINT8_T ANEMOMETER_SENSOR_DP_T;
#define DP_ID_WIND_SPEED 101

typedef struct  {
    ANEMOMETER_SENSOR_DP_T dp_id_wind_speed;

    UINT_T wind_speed_value;
}ANEMOMETER_SENSOR_STATE;

extern ANEMOMETER_SENSOR_STATE anemometer_sensor_state;

VOID_T hw_report_all_dp_status(VOID_T);
VOID_T deal_dp_proc(IN CONST TY_OBJ_DP_S *root);

#endif /* __TUYA_DP_PROCESS */