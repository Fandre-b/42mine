#!/bin/bash

wall -n"
_________________________________________________________________________
# Architecture	:	$(uname -a)
_________________________________________________________________________
# CPU physical	:	$(nproc)
_________________________________________________________________________
# vCPU		:	$(cat /proc/cpuinfo | grep processor | wc -l)
_________________________________________________________________________
# RAM usage	:	$(free -m | sed -n 2p | awk '{print $3 }')/$(free -m | sed -n 2p | awk '{print $2 }')MB ($(free -m | awk 'NR == 2 {printf $3/$2*100}')%)
_________________________________________________________________________
# Disk usage	:	$(df -h --total | sed -n 15p | awk '{print $3}')/$(df -h --total | sed -n 15p | awk '{print $2}')b ($(df -h --total | sed -n 15p | awk '{print $5}'))
_________________________________________________________________________
# CPU load	:	$(grep 'cpu' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage "%"}')
_________________________________________________________________________
# Last boot	:	$(who -b | awk '{print $3}') $(who -b | awk '{print $4}')
_________________________________________________________________________
$(if [ $(lsblk | grep LVM | wc -l) -gt 0 ]; then echo "# LVM use	:	yes"; else echo "# LVM use	:	no"; fi)
_________________________________________________________________________
# Connexions TCP:	$(cat /proc/net/sockstat | grep TCP | awk '{print $3}') ESTABLISHED
_________________________________________________________________________
# User log	:	$(who | wc -l)
_________________________________________________________________________
# Network IP	:	$(hostname -I) ($(ip link | grep "link/ether" | awk '{print $2}')
_________________________________________________________________________
# Sudo		:	$(grep -a sudo /var/log/auth.log | grep -a COMMAND= | wc -l) cmd executed
_________________________________________________________________________"


# Finally, you have to create a simple script called monitoring.sh. It must be devel-
# oped in bash.
# At server startup, the script will display some information (listed below) on all ter-
# minals every 10 minutes (take a look at wall). The banner is optional. No error must
# be visible.
# Your script must always be able to display the following information:
# • The architecture of your operating system and its kernel version.
# • The number of physical processors.
# • The number of virtual processors.
# • The current available RAM on your server and its utilization rate as a percentage.
# • The current available memory on your server and its utilization rate as a percentage.
# • The current utilization rate of your processors as a percentage.
# • The date and time of the last reboot.
# • Whether LVM is active or not.
# • The number of active connections.
# • The number of users using the server.
# • The IPv4 address of your server and its MAC (Media Access Control) address.
# • The number of commands executed with the sudo program.