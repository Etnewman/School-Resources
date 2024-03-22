#!/bin/bash
read_hosts () {
hosts=`cat $1`
count=1
for host in hosts; do
	hosts_array[$count]=$host
	((count+=1))
done
}
pick_host () {
countVar=1
for host in $hosts; do
	echo "$countVar) $host"
	((countVar+=1))
done
echo "Select a host 1 - $countVar"
read which_host
if [$which_host -lt 0];then
	echo "Bad choice: Between 1 - $countVar"
	exit 1
fi
if [$which_host -gt $countVar];then
	echo "Bad choice: Between 1  - $countVar"
	exit 1
fi
}
doneVar=0
host=$host_array[$which_host]
while [ $doneVar == 0 ]; do
	echo "(P) for ping"
	echo "(N) for nslookup"
	echo "(Q) for quit"
	echo "Select one from the above: "
	read cmd
	read_hosts $@
	case $cmd in
		P|p)
			pick_host "$hosts"
			echo "ping -c 1 $host"
			ping -c l $host
			;;
		N|n)
			pick_host "$hosts"
			echo "nslookup $host"
			nslookup $host
			;;
		Q|q)
			doneVar=1;
			echo "Goodbye!"
			;;
		*)
			echo "Bad choice: Choose from P,N or Q"
			;;
	esac
done
