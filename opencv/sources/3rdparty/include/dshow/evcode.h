#ifndef _EVCODE_H
#define _EVCODE_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*--- DirectShow Reference - Constants and GUIDs - Event Notification Codes */
#define EC_ACTIVATE 0x0013
#define EC_BUFFERING_DATA 0x0011
#define EC_BUILT 0x0300
#define EC_CLOCK_CHANGED 0x000D
#define EC_CLOCK_UNSET 0x0051
#define EC_CODECAPI_EVENT 0x0057
#define EC_COMPLETE 0x0001
#define EC_DEVICE_LOST 0x001F
#define EC_DISPLAY_CHANGED 0x0016
#define EC_END_OF_SEGMENT 0x001C
#define EC_ERROR_STILLPLAYING 0x0008
#define EC_ERRORABORT 0x0003
#define EC_EXTDEVICE_MODE_CHANGE 0x0031
#define EC_FULLSCREEN_LOST 0x0012
#define EC_GRAPH_CHANGED 0x0050
#define EC_LENGTH_CHANGED 0x001E
#define EC_NEED_RESTART 0x0014
#define EC_NOTIFY_WINDOW 0x0019
#define EC_OLE_EVENT 0x0018
#define EC_OPENING_FILE 0x0010
#define EC_PALETTE_CHANGED 0x0009
#define EC_PAUSED 0x000E
#define EC_PREPROCESS_COMPLETE 0x0056
#define EC_QUALITY_CHANGE 0x000B
#define EC_REPAINT 0x0005
#define EC_SEGMENT_STARTED 0x001D
#define EC_SHUTTING_DOWN 0x000C
#define EC_SNDDEV_IN_ERROR 0x0200
#define EC_SNDDEV_OUT_ERROR 0x0201
#define EC_STARVATION 0x0017
#define EC_STATE_CHANGE 0x0032
#define EC_STEP_COMPLETE 0x0024
#define EC_STREAM_CONTROL_STARTED 0x001B
#define EC_STREAM_CONTROL_STOPPED 0x001A
#define EC_STREAM_ERROR_STILLPLAYING 0x0007
#define EC_STREAM_ERROR_STOPPED 0x0006
#define EC_TIMECODE_AVAILABLE 0x0030
#define EC_UNBUILT 0x0301
#define EC_USERABORT 0x0002
#define EC_VIDEO_SIZE_CHANGED 0x000A
#define EC_VMR_RENDERDEVICE_SET 0x0053
#define EC_VMR_SURFACE_FLIPPED 0x0054
#define EC_VMR_RECONNECTION_FAILED 0x0055
#define EC_WINDOW_DESTROYED 0x0015
#define EC_WMT_EVENT 0x0252
#define EC_WMT_INDEX_EVENT 0x0251
#define EC_USER 0x8000
/*--- DirectShow Reference - DirectShow Structures */
typedef struct {
    HRESULT hrStatus;
    void   *pData;
} AM_WMT_EVENT_DATA;

#ifdef __cplusplus
}
#endif
#endif
