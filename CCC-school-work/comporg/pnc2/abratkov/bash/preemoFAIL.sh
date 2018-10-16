#!/usr/bin/env bash

LOWERBOUND=2
NUMPRIMES=0
COMPOSITECOUNTER=0
MAXNUMPRIMES=10

while [ ${NUMPRIMES} -lt ${MAXNUMPRIMES} ]; do
	INCREMENT=2
	sqrtLOW=`bc sqrt(${LOWERBOUND})`
	#printf "%f\n" $sqrtLOW
	while [  "${INCREMENT} < ${sqrtLOW}" | bc -l` ]; do
		if [ $(($LOWERBOUND % $INCREMENT)) -eq 0 ]; then
			let "COMPOSITECOUNTER=COMPOSITECOUNTER+1"
		fi
		
		if [ ${COMPOSITECOUNTER} -ge 2 ]; then
			break
		fi
		let "INCREMENT=INCREMENT+1"
	done
	
	if [ ${COMPOSITECOUNTER} -lt 1 ]; then
		printf "%d " ${LOWERBOUND}
	    let "NUMPRIMES=NUMPRIMES+1"
	fi
	let "LOWERBOUND=LOWERBOUND+1"
	let "COMPOSITECOUNTER=0"
done
