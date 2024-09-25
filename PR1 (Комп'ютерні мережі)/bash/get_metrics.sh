#!/bin/bash
netstat -i | awk 'NR==3 {print $4}'
