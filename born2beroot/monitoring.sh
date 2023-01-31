#Print the number of commands executed with the sudo program
arc=$(uname -a)

#Print the architecture of your operating system and its kernel version

pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
#print the number of virtual processors
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)

#Print the current available RAM on your server and its utilization rate as a percentage
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

#Print the current available memory on your server and its utilization rate as a percentage
fdisk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')

#Print the current utilization rate of your processors as a percentage
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')

#Print he date and time of the last reboot
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

#Print whether LVM is active or not
lvmt=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)

#Print the number of active connections
ctcp=$(netstat -n | grep ESTABLISHED | wc -l)

#Print the number of users using the server
ulog=$(users | wc -w)

#Print the IPv4 address of your server and its MAC (Media Access Control) address
ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')

#Print the number of commands executed with the sudo program
cmds=$(grep sudo /var/log/auth.log -a | wc -l)
wall "  #Architecture: $arc
        #CPU physical: $pcpu
        #vCPU: $vcpu
        #Memory Usage: $uram/${fram}MB ($pram%)
        #Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
        #CPU load: $cpul
        #Last boot: $lb
        #LVM use: $lvmu
        #Connexions TCP: $ctcp ESTABLISHED
        #User log: $ulog
        #Network: IP $ip ($mac)
        #Sudo: $cmds cmd"

