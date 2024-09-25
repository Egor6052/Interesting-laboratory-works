#!/bin/bash
hostname -I | awk '{print $1}'

#показати ім'я та вивести перше слово