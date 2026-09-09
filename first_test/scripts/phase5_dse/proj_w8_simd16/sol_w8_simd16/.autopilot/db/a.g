#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /workspace/scripts/phase5_dse/proj_w8_simd16/sol_w8_simd16/.autopilot/db/a.g.bc ${1+"$@"}
