#!/bin/bash

##########################################
#
# Andrei Bratkovski - gfo0 - Grading tool
#
##########################################

#
# Print header equals signs
#
printf "==================================================================================\n"

#
# Check if class is listed as an argument.  If it is, use that under the status code instead of
# the default "UNIX 
#
if [ "$#" -gt 0 ]; then
	printf "%-10s" $1
	status "$1" > info.txt
else
	printf "%-10s" "UNIX"
	status unix > info.txt
fi

#
# Print out each project name of the class in the header by iterating over a cut field
#
for project in `sed '/^\PROJECTS/,/^\RANK/!d;//d' info.txt | cut -d ":" -f2`; do
	if [ $project != "bonus" ]
	then
		printf "%-5s" $project
	else
		printf "%-5s" "bns"
	fi
done

#
# Finish printing header , including the user Name
#
printf "prjct+ptcpn+jrnal= result\n"
printf "==================================================================================\n"
printf "%-10s" $USER

#
# Declare counting variables to keep track of grades 
#
myCount=0
totalCount=0
gradeTotal=0
myPointTotal=0
pointTotal=0
projTotal=0

############
#
# PROJECTS
#
############

#
# Iterate through project grades, print out percentages and keep track of point totals for later results
# printing
#
for myNum in `sed '/^\PROJECTS/,/^\RANK/!d;//d' info.txt | cut -d "(" -f2 | cut -d ")" -f1 | cut -d "/" -f1`; do
	let myCount="myCount+1"
	let totalCount=0
	for total in `sed '/^\PROJECTS/,/^\RANK/!d;//d' info.txt | cut -d "(" -f2 | cut -d ")" -f1 | cut -d "/" -f2`; do
		let totalCount="totalCount+1"
		if [ $myCount -eq $totalCount ]
		then
			if [ $total -eq 0 ]
			then
				printf "%-5d" $myNum
				gradeTotal=`echo $gradeTotal+$myNum | bc`
				myPointTotal=`echo $myPointTotal+$myNum | bc`
			else
				grade=`bc <<< "scale = 4; (($myNum / $total) * 100) / 1"`
				let projTotal="projTotal+1"
				gradeTotal=`echo $gradeTotal+$grade | bc`
				myPointTotal=`echo $myPointTotal+$myNum | bc`
				pointTotal=`echo $pointTotal+$total | bc`
				printf "%-5.0f" $grade
			fi
		fi
	done
done

#
# Print out project percentage out of 52 percent points
#
allProjPercent=`bc <<< "scale = 4; ( $myPointTotal / $pointTotal )"`
myProjPercent=`bc <<< "scale = 4; ( $allProjPercent * 52 ) / 1"`
printf "%-2.0f/52" $myProjPercent

###############
#
# PARTICIPATION
#
###############
pointTotal=0
myPointTotal=0
myCount=0

#
# Iterate through the participation grades and calculate point totals including bonuses
# We find the participation grade by checking between headers PARTICIPATION and PROJECTS
#
for myNum in `sed '/^\PARTICIPATION/,/^\PROJECTS/!d;//d' info.txt | cut -d "(" -f2 | cut -d ")" -f1 | cut -d "/" -f1`; do
	let myCount="myCount+1"
	let totalCount=0	
	for total in `sed '/^\PARTICIPATION/,/^\PROJECTS/!d;//d' info.txt | cut -d "(" -f2 | cut -d ")" -f1 | cut -d "/" -f2`; do
		let totalCount="totalCount+1"
		if [ $myCount -eq $totalCount ]
		then
			if [ $total -eq 0 ]
			then
				if [ $myNum -gt 16 ]
				then
					myPointTotal=`echo $myPointTotal+16 | bc`
				else
					myPointTotal=`echo $myPointTotal+$myNum | bc`
				fi
			else
				myPointTotal=`echo $myPointTotal+$myNum | bc`
				pointTotal=`echo $pointTotal+$total | bc`
			fi
		fi
	done
done

#
# Print out the participation percentage out of 13
#
allPartPercent=`bc <<< "scale = 4; ( $myPointTotal / $pointTotal )"`
myPartPercent=`bc <<< "scale = 4; ( $allPartPercent * 13 ) / 1"`
printf "+%-2.0f/13" $myPartPercent

###############
#
# JOURNAL
#
###############
pointTotal=0
myPointTotal=0
myCount=0


#
# iterate over journal grades and points, then add up totals including bonuses
# Check between JOURNAL and PARTICIPATION headers for the specified points
#
for myNum in `sed '/^\JOURNAL/,/^\PARTICIPATION/!d;//d' info.txt | cut -d "(" -f2 | cut -d ")" -f1 | cut -d "/" -f1`; do
	let myCount="myCount+1"
	let totalCount=0	
	for total in `sed '/^\JOURNAL/,/^\PARTICIPATION/!d;//d' info.txt | cut -d "(" -f2 | cut -d ")" -f1 | cut -d "/" -f2`; do
		let totalCount="totalCount+1"
		if [ $myCount -eq $totalCount ]
		then
			if [ $total -eq 0 ]
			then
				if [ $myNum -gt 16 ] 
				then
					myPointTotal=`echo $myPointTotal+16 | bc`
				else
					myPointTotal=`echo $myPointTotal+$myNum | bc`
				fi
			else
				myPointTotal=`echo $myPointTotal+$myNum | bc`
				pointTotal=`echo $pointTotal+$total | bc`
			fi
		fi
	done
done

#
# Print out journal percentage out of 13 percent points
#
allJournPercent=`bc <<< "scale = 4; ( $myPointTotal / $pointTotal )"`
myJournPercent=`bc <<< "scale = 4; ( $allJournPercent * 13 ) / 1"`

printf "+%-2.0f/13" $myJournPercent
printf "= "

#####################
#
# RESULT TOTALS
#
#####################


#
# Print out result out of 100 percent.  Afterwards, check which letter grade the number is underneath and print
# out the letter grade
#
resultPercent=`bc <<< "scale = 4; (( $myJournPercent + $myPartPercent + $myProjPercent ) / 78 ) * 100 / 1"`
printf "%-3.0f/100" $resultPercent

if [ `echo $resultPercent '>=' "100.0" | bc -l` ]; then
	printf " A"
elif [ `echo $resultPercent '>=' "94.0" | bc -l` ]; then
	printf "A-"
elif [ `echo $resultPercent '>=' "88" | bc -l` ]; then
	printf "B+"
elif [ `echo $resultPercent '>=' "82" | bc -l` ]; then
	printf "B"
elif [ `echo $resultPercent '>=' "76" | bc -l` ]; then
	printf "B-"
elif [ `echo $resultPercent '>=' "70" | bc -l` ]; then
	printf "C+"
elif [ `echo $resultPercent '>=' "64" | bc -l` ]; then
	printf "C"
elif [ `echo $resultPercent '>=' "58" | bc -l` ]; then
	printf "D"
else
	printf "F"
fi

#
# Finally, print out last header
#
printf "\n==================================================================================\n"
