#include "IP_config.h"
#include "am_mqtt_info.h"

void vApplicationIPInit( void )
{
    FreeRTOS_IPInit( ucIPAddress,
                     ucNetMask,
                     ucGatewayAddress,
                     ucDNSServerAddress,
                     ucMACAddress );
}

#if ( ipconfigUSE_LLMNR != 0 ) || ( ipconfigUSE_NBNS != 0 ) || ( ipconfigDHCP_REGISTER_HOSTNAME == 1 )

    const char * pcApplicationHostnameHook( void )
    {
        /* This function will be called during the DHCP: the machine will be registered
         * with an IP address plus this name. */
        return IOT_THING_NAME;
    }

#endif