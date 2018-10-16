#!/bin/bash
#
# Run this script as follows:
#   ./script 44.1 33 22 3 11 12 23 0 34 2 45 5 1 3.14159 4
#
function process() {
	sleep   "$1"
	echo -n "$1 "
}

for data in $*; do
	process "$data" &
done
wait
echo

exit 0
