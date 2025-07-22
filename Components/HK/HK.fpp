module HK {
    @ Housekeeping component
    active component HK {

        @ Commands
        async command LOAD_CONFIG(
            configFile: string size 64 @< Name of the configuration file to load
        )

        @ Example telemetry counter
        telemetry voltage1: F32
        telemetry current1: F32
        telemetry mcuTemp: F32

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

        @ Example port: receiving calls from the rate group
        sync input port run: Svc.Sched

        @ Parameter
        param SAMPLE_INTERVAL: U32 @< Interval at which to sample telemetry data

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}