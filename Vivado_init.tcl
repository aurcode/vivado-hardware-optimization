# ==============================================================================
# Vivado Initialization Script (Vivado_init.tcl)
# Fix for Xilinx AR-76960 (Y2K22+ timestamp overflow on core_revision)
# ==============================================================================

if {[info commands ::real_set_property] eq ""} {
    rename ::set_property ::real_set_property
    proc ::set_property {args} {
        set prop [lindex $args 0]
        if {$prop eq "core_revision"} {
            return [uplevel 1 [list ::real_set_property $prop 1 {*}[lrange $args 2 end]]]
        }
        return [uplevel 1 [list ::real_set_property {*}$args]]
    }
}
