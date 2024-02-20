"physical id" /proc/cpuinfo | wc -l
cat /proc/cpuinfo | grep 'cpu cores'
cat /proc/cpuinfo | grep 'cpu cores' | wc -l | awk '{printf "ola gay %10s\n", $1}'

 lscpu | egrep 'Socket\(s\)|Core\(s\) per socket'
 /proc/cpuinfo grep "cpu cores"
 lscpu | grep 'Core(s) per socket' | awk '{print $NF}'



 lscpu | egrep 'Socket\(s\)|Core\(s\) per socket' | awk '{print $1, $2, $3, $4}'
 lscpu | egrep 'Socket\(s\)|Core\(s\) per socket' | awk '{printf "%-20s %-10s\n", $1, $2}'

 RAM
 free -h | awk '{printf "%-20s %-10s\n", $1, $2}'
free --mega | awk '$1 == "Mem:" {printf("%%used%10.2f\n"), $3/$2*100}'
free --mega | grep "Mem" | awk '{printf("%%used%10.2f\n"), $3/$2*100}'     

free --mega | awk '{used=$3; total=$2; if (NR==1) {percent = "Used perc."} else if (used+0 > 1) {percent = sprintf("%.2f%%", used/total*100)} else {percent = 0"%"}; printf "%-10s %-10s %s\n", $1, $2, percent}'


id -Gn $FT_USER | tr ' ' ','| tr -d '\n'
find . -type f -name "*.sh" -execdir basename {} \; | sed 's/\.sh$//'
find . -type f -o -type d | wc -l
ifconfig | grep ether | awk '{print $2}'
ls -l | awk 'NR%2==1'

'{print "prefix_"$0}'
'{print $0"suffix"}'

# LAST BOOT
who -b

#id of vmstat
vmstat | awk 'NR==1 {for (i=1; i<=NF; i++) if ($i=="id") col=i} NR==3 {print $col}'
awk '{counter++; print $0} END {print "Number of lines: " counter}' filename
lsblk | awk '/LVM/ {print "yes"; exit} END {print "no"}'
lsblk | awk '/LVM/ {print "Found LVM " ++count}'