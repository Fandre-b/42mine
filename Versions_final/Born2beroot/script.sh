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
echo "$(uname -o) $(uname -m)"
# • The number of physical processors.
lscpu | grep 'Socket(s):' | awk '{print $NF}'
# • The number of virtual processors.
lscpu | grep 'CPU(s):' | awk '{print $NF}'
# • The current available RAM on your server and its utilization rate as a percentage.
totalmem = $(free -h --si | awk 'NR==2 {print $2}')
percentmem = free --mega | awk 'NR==2 {used=$3; total=$2; print used/total*100}'
# • The current available memory on your server and its utilization rate as a percentage.
df -h --total | sed -n 15p | awk '{print $3}')/$(df -h --total | sed -n 15p | awk '{print $2}')b ($(df -h --total | sed -n 15p | awk '{print $5}')
# • The current utilization rate of your processors as a percentage.
get_cpu_usage() {
  cpu_now=($(grep -w 'cpu' /proc/stat))
  idle_now=${cpu_now[4]}
  total_now=0
  for value in "${cpu_now[@]:1}"; do
    total_now=$((total_now + value))
  done
  echo $idle_now $total_now
}
   #get the first reading
cpu_usage1=($(get_cpu_usage))
   # Sleep for a second
sleep 1
    #get the second reading
cpu_usage2=($(get_cpu_usage))
   # Calculate the difference in idle and total time
idle_diff=$((cpu_usage2[0] - cpu_usage1[0]))
total_diff=$((cpu_usage2[1] - cpu_usage1[1]))
    # Calculate the CPU usage as a percentage
cpu_usage=$((100 * ((total_diff) - (idle_diff)) / (total_diff)))
# • The date and time of the last reboot.
who -b | awk '{print $3, $4}'
# • Whether LVM is active or not.
if [ $(lsblk | grep -c 'LVM') -gt 0 ]; then echo 'yes'; else echo 'no'; fi
lsblk | awk '/LVM/ {count++} END {if (count > 0) print "yes"; else print "no"}'
# • The number of active connections.
cat /proc/net/sockstat | grep TCP | awk '{print $3}'
tail -n 1 /proc/net/tcp | wc -l
# • The number of users using the server.
awk -F':' '{ if ($3 >= 1000) print $1}' /etc/passwd | wc -l
awk -F':' '{ if ($3 >= 1000 && $1 != "nobody") print $1}' /etc/passwd | wc -l
# • The IPv4 address of your server and its MAC (Media Access Control) address.
ip link | awk '/ether/{print $2}'
hostname -I
# • The number of commands executed with the sudo program.
awk '/sudo/'  ~/.bash_history | wc -l



#!/bin/bash

# Get the first line with aggregate of all CPUs
cpu_last=($(grep -w 'cpu' /proc/stat))
idle_last=${cpu_last[4]}
total_last=0
for value in "${cpu_last[@]:1}"; do
  total_last=$((total_last + value))
done

# Sleep for a second
sleep 1

# Get the same line again
cpu_now=($(grep -w 'cpu' /proc/stat))
idle_now=${cpu_now[4]}
total_now=0
for value in "${cpu_now[@]:1}"; do
  total_now=$((total_now + value))
done

# Calculate the difference in idle and total time
idle_diff=$((idle_now - idle_last))
total_diff=$((total_now - total_last))

# Calculate the CPU usage as a percentage
cpu_usage=$((100 * ( (total_diff) - (idle_diff) ) / (total_diff) ))

echo "CPU Usage: $cpu_usage%"