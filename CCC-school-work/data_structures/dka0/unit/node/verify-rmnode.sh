#!/bin/bash
#
# verify-rmnode.sh - script to validate node functionality
#
match=0
mismatch=0
total=0

component=$(echo $0 | cut -d'-' -f2 | cut -d'.' -f1)
compath="$(echo $0 | cut -d'/' -f1)/"
if [ -z "${compath}" ]; then
	compath="."
fi

for value in `${compath}/unit-${component} | grep -A1 'you have' | cut -d':' -f2 | tr ' ' '#' | tr '\n' ';' | sed 's/--;/\n/g' | sed 's/##//g' | sed 's/#NULL/NULL/g'`; do
	you_have=$(echo ${value} | cut -d';' -f1 | tr '#' ' ')
	shouldbe=$(echo ${value} | cut -d';' -f2 | tr '#' ' ')

#	echo "--> ${you_have} <--"
#	echo "--> ${shouldbe} <--"

	printf "[test %2d] " "${total}"

	if [ "${you_have}" = "${shouldbe}" ]; then
		echo "MATCH"
		let match=${match}+1
	else
		echo "MISMATCH"
		let mismatch=${mismatch}+1
	fi

	let total=${total}+1
done

echo "Total: ${total}, Matches: ${match}, Mismatches: ${mismatch}"
exit 0
