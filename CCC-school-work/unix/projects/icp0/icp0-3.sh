#!/bin/bash
###########################
#
# William Price - wprice2 
# Cody Bonsignore - cbonsign
# Andrei Bratkovski - abratkov
# 11/2/2017
# ICPO-3
# allyourbasearebelongtous
############################

#
# Initialize X and Y coordinates
#
X=0
Y=0
count=0

#
# Find height and width of screen with xwinfo
#
WIDTH=`xwininfo -root | grep Width | cut -d ':' -f2`
HEIGHT=`xwininfo -root | grep Height | cut -d ':' -f2`

#
# Set starting mouse pointer
#
start=`echo "${WIDTH}*0.75" | bc -l`

#######################
# debugging statement
# printf "%f\n" ${start}
#######################
#
# Open mtpaint and maximize it
#
xte "mousemove $start, 500"
pkill mtpaint 
mtpaint&
sleep 0.5
xte 'mousemove 1055 20'
sleep 0.5
xte 'mouseclick 1'

#
# using xwit and xte, setup initial X and Y mouse
# pointers
#
X=0
Y=195
xwit -root -rwarp ${X} ${Y}
sleep 0.5
xte 'mouseclick 1'
xte 'mousemove 1050 100'
sleep 0.5
xte 'mouseclick 1'
xte 'mousemove 1575 575'
sleep 0.5

######################
# Draw our
# First circlerino
#
######################
Xoff=1575
Yoff=575
for ((degree=0;degree<361;degree+=1))
do
	if [ $degree -eq 1 ]
	then
		xte 'mousedown 1'
	fi
	radian=$(echo "${degree}*(3.14/180)" | bc -lq)
	X=$(echo "c(${radian})"    | bc -lq) 
	X=$(echo "${X}*(180/3.14)" | bc -lq)
	X=$(echo "${X}+${Xoff}"       | bc -lq | cut -d '.' -f1)

	Y=$(echo "s(${radian})"    | bc -lq)
	Y=$(echo "${Y}*(180/3.14)" | bc -lq)
	Y=$(echo "${Y}+${Yoff}"	   | bc -lq | cut -d '.' -f1)
	xwit -root -warp ${X} ${Y}

# Debugging x and y statements to see x and y coordinates
#
#	echo "X: $X, Y: $Y"
done

#
# Select 'Fill' option and color for filling circle
#
xte 'mouseup 1'

xte 'mousemove 1105 100'
xte 'mouseclick 1'
sleep 0.5

xte 'mousemove 1060 890'
xte 'mouseclick 1'
sleep 0.5

xwit -root -warp 1575 ${Y}
xte 'mouseclick 1'

exit 0
