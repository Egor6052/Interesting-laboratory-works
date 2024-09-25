#!/bin/bash
ip route | grep 'default' | awk '{print $3}'

#показати маршрути
#вивести рядок з 'default'
#відокремити третье слово