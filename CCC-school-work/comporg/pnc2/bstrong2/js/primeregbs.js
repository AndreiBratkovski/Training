/////////////////////////////////////////////////////////
//
// So here we are with another program yet another 
// primeregbs :D. Alright so first thing is first and
// it's needed to check to see if there are enough 
// arguments, if not then print an error to the user.
// Also give an error if the user inputs anthing less
// than or = to 0.
//
if(process.argv.length < 3)
	process.stderr.write("Invalid amount of arguments\n");
else if(process.argv[2] <= 0)
	process.stderr.write("Don't you want to see primes?\n");
/////////////////////////////////////////////////////////
//
// Next it's time to declare all of the used variables.
// Make max = to the number of primes the user wants
// displayed.
//
var divisor, lowerbound = 2, max,maxFound = 0, flag;
var square,start, end, time, secondsS, secondsE,secondsT;
max = process.argv[2];
/////////////////////////////////////////////////////////
//
// This is to start displaying the time. So it was a big
// issue to display the time xD. So i get the mill and
// seconds seperatly because if the mill exceeded 1000
// then the number would reset.
//
// Then it's time to start the while loop, which tbh
// it's the same condition that I used in the C program.
// To keep looping until the amount of primes has 
// been found.
//
start = new Date().getMilliseconds();
secondsS = new Date().getSeconds();
while(maxFound < max)
{
	/////////////////////////////////////////////////////
	//
	// Now for inside the loop. Set divisor to 2 at the
	// start of every iteration, set flag to 0 and find
	// the squareroot of the number being tested. Then
	// have a while loop to to go as many times as the
	// square root, inside the loop have an if checking
	// for a remainder, if a number with no remainder
	// is found then set off flag and end loop.
	//
	divisor = 2;
	flag = 0;
	square = Math.sqrt(lowerbound);
	while(divisor <= square)
	{
		if(lowerbound % divisor == 0)
		{
			flag = 1;
			break;
		}
		divisor++;
	}
	/////////////////////////////////////////////////////
	//
	// Have an if to check the flag(if the number is 
	// prime) then write to stderr the number. increment
	// values as needed(explained it many times already
	// xD).
	//
	if(flag == 0)
	{
		process.stderr.write(lowerbound + " ");
		maxFound++;	
	}
	lowerbound++;
}
/////////////////////////////////////////////////////////
//
// Now that all of the processing is done time to cut
// the timers. Set a var time = to the end time - the
// start time. Then do the same thing for the seconds
// time. (In class you said that you used Date().getTime()
// I don't know how you got arround the milliseconds thing)
//
// Next take the milliseconds time and divide it so it
// is in 4 decimal places. Then add the total amount of
// seconds the program ran for. Print that value.
//
end = new Date().getMilliseconds();
secondsE = new Date().getSeconds();
time = end - start;
secondsT = secondsE - secondsS;

time /= 10000;
time += (secondsT);
console.log("\n	" + (time));
