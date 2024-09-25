#!/bin/bash
ip route | grep 'default' | awk '{print $5}'

#показати маршрути
#вивести рядок з 'default'
#відокремити п'яте слово