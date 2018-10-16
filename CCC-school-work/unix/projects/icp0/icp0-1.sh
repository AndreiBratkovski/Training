#!/bin/bash
#############################
#
# William Price     - wprice2
# Cody Bonsignore   - cbonsign
# Andrei Bratkovski - abratkov 
# ICP0-1
# 11/2/2017
#
#############################
X=0
Y=0
count=0;
WIDTH=`xwininfo -root | grep Width | cut -d ':' -f2`
let WIDTH="WIDTH/2 - 1"
HEIGHT=`xwininfo -root | grep Height | cut -d ':' -f2`


###############################################################
#Moves mouse pointer to the top left corner of the left screen.
###############################################################
xte 'mousemove 0 0'


###################################################################
#Moves the mouse pointer in a clockwise square around the screen by
#warping the x and y values.
###################################################################
while [ $X -le $WIDTH ] 
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "X=X+4"
done

while [ $Y -le $HEIGHT ]
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "Y=Y+4"
done

while [ $X -gt 0 ]
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "X=X-4"
done

while [ $Y -gt 0 ]
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "Y=Y-4"
done
#########################################################################
#End of first square/beginning of second square that does the same thing.
#########################################################################
while [ $Y -le $HEIGHT ]
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "Y=Y+4"
done
 
while [ $X -le $WIDTH ] 
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "X=X+4"
done

while [ $Y -gt 0 ]
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "Y=Y-4"
done

while [ $X -gt 0 ]
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "X=X-4"
done
############################################################
#End of second square, beginning of arbitrary movementerino.
############################################################

##############################################
#Warps mouse to the middle of the left screen.
##############################################
let WIDTH="WIDTH/2"
while [ $X -le $WIDTH ] 
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "X=X+4"
done
#############################################
#Zig zags down the center of the screen, boi.
#############################################
while [ $Y -le $HEIGHT ]
do
	xwit -root -warp ${X} ${Y}
	sleep 0.005
	let "Y=Y+4"
	if [ $(($count%2)) -eq 0 ]
	then
		let "X=X-25"
	else
		let "X=X+30"
	fi
	let "count=count+1"
done

