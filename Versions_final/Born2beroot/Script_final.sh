#!/bin/bash

# Function to handle errors
handle_error() {
    echo "Script failed at line $1"
    exit 1
}

# Set the error handler
trap 'handle_error $LINENO' ERR


# Script to display system info
wall -n"
_________________________________________________________________________
Architecture: $(uname -m)
kernel version: $(uname -r)
_________________________________________________________________________
Physical processors: $(lscpu | grep 'Socket(s):' | awk '{print $NF}')
Virtual processors: $(lscpu | grep 'CPU(s):' | awk '{print $NF}')
_________________________________________________________________________
RAM: $(free --mega | awk 'NR==2 {used=$3; total=$2; print used/total*100}')% of $(free -h --si | awk 'NR==2 {print $2}'))
####mpstat 1 1 | awk '/Average/ {print 100 - $NF}'
Cpu: $(top -bn2 -d0.05 | grep "Cpu(s)" | awk 'NR == 2 {print 100 - $8}')%
_________________________________________________________________________
Last reboot: $(who -b | awk '{print $3,$4}')
_________________________________________________________________________
####LVM: $(lsblk | grep "lvm" | wc -l) LVM physical volume(s)
LVM: $(lsblk | awk '/LVM/ {count++} END {if (count > 0) print "yes"; else print "no"}')
_________________________________________________________________________
####Active connections: $(ss -s | awk '/TCP:/ {print $2}') ESTABLISHED
Active connections: $(ss -s | awk '/TCP:/ {con=$2} END {print (con > 0 ? con " Connections" : "No connections")}')
_________________________________________________________________________
Users logged: $(who | awk '{print $1}'| sort -u | wc -l)
_________________________________________________________________________
#####ip addr | awk '/eth0/ {getline; getline; print $2}'
IPv4 address: $(hostname -I)
#####ip link | awk '/ether/ {print $2}'
MAC address: $(ip link | awk '/eth0/ {getline; print $2}')
_________________________________________________________________________
Number of Sudo Commands: $(cat /var/log/sudo/sudo.log | grep -c COMMAND)
_________________________________________________________________________"