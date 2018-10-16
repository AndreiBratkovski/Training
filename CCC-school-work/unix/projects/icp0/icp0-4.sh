#!/bin/bash
###########################
#
# William Price - wprice2 
# Cody Bonsignore - cbonsign
# Andrei Bratkovski - abratkov
# 11/2/2017
#
# ICP0-4 DRAW COOL THINGS
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
#
# Click pencil
#
xte 'mouseclick 1'
xte 'mousemove 1050 100'
sleep 0.5
xte 'mouseclick 1'
#
# Go to white color
#
xte 'mouseclick 1'
xte 'mousemove 1075 310'
sleep 0.5
xte 'mouseclick 1'

xte 'mousemove 1575 575'
sleep 0.5

######################
# Draw our
# First circlerino
#
######################
increment=0
Xoff=1520
Yoff=575
for ((increment=0;increment<2;increment+=1))
do
	
	for ((degree=0;degree<361;degree+=4))
	do
		if [ $degree -eq 4 ]
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
	done
	xte 'mouseup 1'
	let Xoff=Xoff+75

# Debugging x and y statements to see x and y coordinates
#
#	echo "X: $X, Y: $Y"
done

Xoff=1520
Yoff=680
for ((increment=0;increment<2;increment+=1))
do
	
	for ((degree=0;degree<361;degree+=4))
	do
		if [ $degree -eq 4 ]
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
	done
	xte 'mouseup 1'
	let Xoff=Xoff+75

# Debugging x and y statements to see x and y coordinates
#
#	echo "X: $X, Y: $Y"
done

Xoff=1450
Yoff=625
for ((increment=0;increment<2;increment+=1))
do
	
	for ((degree=0;degree<361;degree+=4))
	do
		if [ $degree -eq 4 ]
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
	done
	xte 'mouseup 1'
	let Xoff=Xoff+225

# Debugging x and y statements to see x and y coordinates
#
#	echo "X: $X, Y: $Y"
done


#
# Select 'Fill' option and color for filling circle
#
xte 'mouseup 1'

#
# selecting the pencil
#
xte 'mousemove 1050 100'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1090 150'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1340 150'
xte 'mouseclick 1'
sleep .5
#
# selecting black 
#
xte 'mousemove 1070 200'
xte 'mouseclick 1'
sleep .5
#
# horizontal black line
#
xte 'mousemove 1450 625'
xte 'mousedown 1'
sleep .5
xte 'mousemove 1650 625'
xte 'mouseup 1'

#
# vertical black line
#
xte 'mousemove 1555 575'
xte 'mousedown 1'
sleep .5
xte 'mousemove 1555 675'
xte 'mouseup 1'
#
# filling that sheep up with that white stuff paint ;)
#
xte 'mousemove 1075 310'
sleep 0.5
xte 'mouseclick 1'

xte 'mousemove 1575 575'
sleep 0.5

xte 'mousemove 1110 115'
xte 'mouseclick 1'
sleep .5

xte 'mousemove 1450 625'
xte 'mouseclick 1'
sleep .5
#
# drawing that DANK green grass
#
xte 'mousemove 1050 100'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1075 550'
xte 'mouseclick 1'
sleep .5

xte 'mousemove 1262 800'
xte 'mousedown 1'
xte 'mousemove 1900 800'
xte 'mouseup 1'
sleep .5

xte 'mousemove 1110 115'
xte 'mouseclick 1'
sleep .5

xte 'mousemove 1750 850'
xte 'mouseclick 1'
sleep .5
#
#colouring that wonderfully DANK blue sky
#
xte 'mousemove 1070 910'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1850 600'
xte 'mouseclick 1'
sleep .5
#
# What about a nice traingle sun?
# yellow change dat color
#
xte 'mousemove 1070 615'
sleep .5
xte 'mouseclick 1'
sleep .5

#
# selecting the Ruler for DAT MEME SUN TRIANGLE
#
xte 'mousemove 1145 100'
xte 'mouseclick 1'
sleep .5

xte 'mousemove 1850 500'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1820 560'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1880 560'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1850 500'
xte 'mouseclick 1'
sleep .5
xte 'mousemove 1850 540'
xte 'mouseclick 1'
sleep .5
xte 'mouseclick 3'
sleep .5

#
# change cursor back to small so we can draw a pretty frowny face :(
#
xte 'mousemove 1090 150'
sleep .5
xte 'mouseclick 1'
sleep .5
xte 'mouseclick 1'
sleep .5
#
# Dark blue colored frown
#
xte 'mousemove 1075 777' # lucky number blue == 777
sleep .5
xte 'mouseclick 1'
sleep .5
#
# Move mouse to triangle for frown. Loop draws half circle frown
#
xte 'mousemove 1825 560'
sleep .5
xte 'mousedown 1'
let Xoff=1850
let Yoff=560
	for ((degree=180;degree<361;degree+=4))
	do
		if [ $degree -eq 185 ]
		then
			xte 'mousedown 1'
		fi
		radian=$(echo "${degree}*(3.14/180)" | bc -lq)
		X=$(echo "0.5*c(${radian})"    | bc -lq) 
		X=$(echo "${X}*(180/3.14)" | bc -lq)
		X=$(echo "${X}+${Xoff}"       | bc -lq | cut -d '.' -f1)

		Y=$(echo "0.6*s(${radian})"    | bc -lq)
		Y=$(echo "${Y}*(180/3.14)" | bc -lq)
		Y=$(echo "${Y}+${Yoff}"	   | bc -lq | cut -d '.' -f1)
		xwit -root -warp ${X} ${Y}
	done
	xte 'mousemove 1825 560'
	xte 'mouseup 1'
	#
	# left eye click dot
	#
	sleep .5
	xte 'mousemove 1835 510'
	sleep .5
	xte 'mouseclick 1'

	#
	# right eye click dot
	#
	sleep .5
	xte 'mousemove 1865 510'
	sleep .5
	xte 'mouseclick 1'

exit 0
