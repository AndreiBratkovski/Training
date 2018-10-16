#!/bin/bash

## ICPO-2 ##
# Cody
# William
# Andrei
#############

###
#Getting window information
###

X=0
Y=0
count=0;
WIDTH=`xwininfo -root | grep Width | cut -d ':' -f2`


HEIGHT=`xwininfo -root | grep Height | cut -d ':' -f2`


start=`echo "${WIDTH} * 0.75" | bc -l`

###
#Opening up mtpaint and preparing
#for squarification
###

xte "mousemove $start, 500"
mtpaint&
sleep 0.5
xte 'mousemove 1055 20'
sleep 0.5
xte 'mouseclick 1'
X=0
Y=195
xwit -root -rwarp ${X} ${Y}
sleep 0.5
xte 'mouseclick 1'
xte 'mousemove 1050 100'
sleep 0.5
xte 'mouseclick 1'
xte 'mousemove 1275 475'
sleep 0.5
xte 'mousedown 1'

######################
# First Square
#
######################
#The squares are made line by line,
#moving in a clockwise pattern
#and then a counterclockwise pattern
#for the second square
###

X=1275
Y=475
while [ $count -lt 100 ]
do
	xwit -root -warp ${X} ${Y}
	let "X=X+4"
	let "count=count+1"
done

###
#By using the xwit tool,
#the script moves the mouse
#in a straight line to draw
#one of the sides of the rectangle
###

let "count=0"
while [ $count -lt 100 ]
do
	xwit -root -warp ${X} ${Y}
	let "Y=Y+4"
	let "count=count+1"
done
let "count=0"
while [ $count -lt 100 ]
do
	xwit -root -warp ${X} ${Y}
	let "X=X-4"
	let "count=count+1"
done
let "count=0"
while [ $count -le 100 ]
do
	xwit -root -warp ${X} ${Y}
	let "Y=Y-4"
	let "count=count+1"
done
sleep 0.5
xte 'mouseup 1'

###
#Dont use rwarp with this
###

###
#Selects a color from the color
#bar on the right hand side of
#the mtpaint window
###

sleep 0.5
X2=1060
Y2=550
xwit -root -warp ${X2} ${Y2}
sleep 0.5
xte 'mouseclick 1'
#####################
##Second Square

let "X=X+20"
let "Y=Y+20"
let "count=0"
xwit -root -warp ${X} ${Y}
xte 'mousedown 1'
while [ $count -lt 80 ]
do
	xwit -root -warp ${X} ${Y}
	let "X=X+4"
	let "count=count+1"
done
let "count=0"
while [ $count -lt 80 ]
do
	xwit -root -warp ${X} ${Y}
	let "Y=Y+4"
	let "count=count+1"
done
let "count=0"
while [ $count -lt 80 ]
do
	xwit -root -warp ${X} ${Y}
	let "X=X-4"
	let "count=count+1"
done
let "count=0"
while [ $count -le 80 ]
do
	xwit -root -warp ${X} ${Y}
	let "Y=Y-4"
	let "count=count+1"
done
sleep 0.5
xte 'mouseup 1'
