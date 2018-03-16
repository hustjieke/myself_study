#!/bin/sh

function is_pid_exists {
    local pid=$1
    if kill -0 ${pid} > /dev/null 2>&1
    then
        echo 1
    else
        echo 0
    fi
}

shutdown_monitor_then_exit 3 "errmsg"
