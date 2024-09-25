#!/bin/bash
nmcli -t -f TYPE,DEVICE connection show --active | awk -F: '{print $1}' | head -n 1
