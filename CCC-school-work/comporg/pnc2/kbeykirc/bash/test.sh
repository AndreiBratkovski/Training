start=$(date +%S%3N)
start2=$(date +%S)

echo $start

x=1

while [ $x -lt 200 ]
do
	((x++))
done

end=$(date +%3N)
end2=$(date +%N)

printf "Start is: %d - %d\n" $start $start2
printf "End is: %d - %d\n" $end $end2
