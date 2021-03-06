#pragma once

// fota_client_info holds info that is reported by the LwM2M client.
// Most fields can have arbitrary data but the firmware_version field
// should match the version of a firmware image uploaded to https://api.nbiot.engineering/.
typedef struct {
	char *manufacturer;
	char *model_number;
	char *serial_number;
	char *firmware_version;
} fota_client_info;

// fota_init assumes that the LTE Link Control subsystem is initialized and a connection established.
// It initializes the Firmware-over-the-Air subsystem, starting the LwM2M client which downloads and installs firmware
// updates, rebooting the device as necessary.
// Call this function after you've initialized your application and done any self-tests to confirm that the system is
// functional after an update; otherwise, reboot the device and it will revert to the the previous confirmed image.
int fota_init(fota_client_info client_info);
