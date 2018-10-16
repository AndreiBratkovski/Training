#!/usr/bin/nodejs

function main()
{
	/////////////////////////////////////////////////////////////////////////////////
	//
	// Error checking
	//
	if (process.argv[2] == undefined || process.argv[2] == null)
	{
		console.error("Insufficient argument!");
		process.exit();
	}
	/////////////////////////////////////////////////////////////////////////////////
	//
	// Timing start
	//
	var start = new Date();
	/////////////////////////////////////////////////////////////////////////////////
	//
	// Variable declaration
	//
	var max = process.argv[2];
	var number = 2;
	var flag = 0;
	var qty = 0;
	
	/////////////////////////////////////////////////////////////////////////////////
	//
	// Main algorithm
	//
	while (qty < max)
	{
		for (var factor = 2; factor <= Math.sqrt(number); factor++)
		{
			if (number%factor == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			process.stderr.write(number + " " );
			qty++;
		}
		flag = 0;
		number++;
	}
	console.error();
	/////////////////////////////////////////////////////////////////////////////////
	//
	// Timing end
	//
	var end = new Date();
	/////////////////////////////////////////////////////////////////////////////////
	//
	// Print time
	//
	var time = end.getTime() - start.getTime();
	console.log(time/1000);
}
main();
