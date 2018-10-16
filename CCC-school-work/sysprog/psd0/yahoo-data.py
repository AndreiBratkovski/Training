#!/usr/bin/python
#Input Format is: 
#   "./yahoo-data.py [SYM] (sY) (sM) (sD) (eY) (eM) (eD)"
#   if the YMD sets are not passed as arguments, the user will
#   be prompted for them
import sys
import pandas 
import csv
out=sys.stdout


########
##Symbol Error Checking
##

if(len(sys.argv)<2):
	print("No Sybmbol Given\nTry ./yahoo-data.py [SYM] [Y] [M] [D] [Y] [M] [D]\n")
	exit(0)
else:
	symb=sys.argv[1]
	symb=str(symb)
	
	if(len(symb)!=3):
		print("Improper Symbol Given-- Must be three characters\nTry ./yahoo-data.py [SYM] [Y] [M] [D] [Y] [M] [D]\n")
		exit(0)
 


########
##Start and End Date Setting
##

if(len(sys.argv)>2):
	sY=int(sys.argv[2])
	sM=int(sys.argv[3])
	sD=int(sys.argv[4])

	eY=int(sys.argv[5])
	eM=int(sys.argv[6])
	eD=int(sys.argv[7])
else:
	sY=input("Enter Start Year\n")
	sM=input("Enter Start Month\n")
	sD=input("Enter Start Day\n")

	eY=input("Enter End Year\n")
	eM=input("Enter End Month\n")
	eD=input("Enter End Day\n")

########
##Gets Data and converts to .csv
##
from yahoo_historical import Fetcher
pandas.set_option('display.max_rows', 1000000)
fetched = Fetcher(symb, [sY, sM, sD], [eY, eM, eD])
data=fetched.getHistorical()

#print(data)  #To turn on printing the stock data to STDOUT, uncomment this line 

data.to_csv('stocks_%s_%d_%d-%d_%d.csv' % (symb, sY, sM, eY, eM), index=False)
