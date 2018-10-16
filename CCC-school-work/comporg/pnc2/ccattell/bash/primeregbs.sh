############primeregbs.sh primeregbs in bash############
#
#!/bin/bash

start=$(date +%s.%N)
input="$1"           ## Get number of primes
primeCount=2
testNum=4

printf "2 3 " 1>&2

while [ $primeCount -lt $input ]
do
	root=`echo "scale=0;sqrt($testNum)" | bc -l` ## Finding the root
	divisor=2	
	while [ $divisor -le $root ]
	do
		remainder=$((testNum % divisor))
		divisor=$((divisor+1))
		if [ $remainder -gt 0 ]
		then
			continue
		else
			break
		fi
		done

	if [ "$remainder" != 0 ]
	then 
		printf "%d " "$testNum"	1>&2
		primeCount=$((primeCount+1))
	fi
	
	testNum=$((testNum+1))
done

printf "\n"

dur=$(echo "$(date +%s.%N) - $start" | bc)
printf "%.4f\n" "$dur"




