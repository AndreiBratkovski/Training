import java.text.DecimalFormat;
/////////////////////////////////////////////////////////////
//
// Public class in java, java looks for the main class when
// compliling. Then have the function that is like the same
// as the main function in c.
//
public class primeregbs
{

	public static void main(String[] args)
	{
		/////////////////////////////////////////////////////
		//
		// Declaring the variables.
		//
		int dividend = 2, foundPrimes = 0;
		int flag,maxPrimes, lowerbound = 2;
		double divisorMax,store;
		long start, end,time;
		String tmp;
		
		/////////////////////////////////////////////////////
		//
		// Then check to see if the length is 0, if it is
		// then print out an error and then exit the program
		// Then check to see if the amount of arguments is
		// more than what the program can accept, if it is
		// then print off an error message and exit the
		// program.
		//
		if(args.length == 0)
		{
			System.err.printf("Enter Something valid\n");
			System.exit(0);
		}
		else if(args.length > 1)
		{
			System.err.printf("Too many arguments\n");
			System.exit(1);
		}
		/////////////////////////////////////////////////////
		//
		// Now set a temp variable = to the number that the
		// user specified. Set max primes to the integer that
		// the user input. Then start the calculation timer.
		//
		tmp = args[0];
		maxPrimes = Integer.parseInt(tmp);
		start = System.nanoTime();
		/////////////////////////////////////////////////////
		//
		// This for loops goes until the amount of primes has
		// been found. It increments the lowerbound after 
		// every iteration. After every iteratom set divident
		// = to 2, plag = to 0, then do the calculation to
		// find the divisormax
		//
		for(; foundPrimes < maxPrimes; lowerbound++)
		{
			dividend = 2;
			flag = 0;	
			divisorMax = Math.sqrt(lowerbound);
			/////////////////////////////////////////////////
			//
			// Now have another for loop that goes as many
			// times as the divisorMax. In the loop there
			// is an if statement that checks to see if there
			// are any remainders when dividing. If there
			// is then set a flag = to 1 and break out of the
			// loop. Increase dividend after every loop.
			//
			for(; dividend <= divisorMax;dividend++)
			{
				if(lowerbound % dividend == 0)
				{
					flag = 1;
					break;
				}
			}
			/////////////////////////////////////////////////
			//
			// Now check to see if flag is = to 0, if it is
			// then print out that number because it's prime
			// then increment foundprimes by 1.
			//
			if(flag == 0)
			{
				System.err.printf("%d ", lowerbound);
				foundPrimes++;
			}
		}	
		/////////////////////////////////////////////////////
		//
		// Then we do the final time calculation, print off
		// a new line. Then end the calculation for time.
		// Then take a time variable and get the total time
		// that the program ran for in nano time. Then 
		// divide accordingly to get the correct values. Then
		// make sure that the values are limited by 4 decimal
		// places. Print out a tap then the actual time.
		//
		System.err.printf("\n");
		end = System.nanoTime();
		time = end - start;
		store = time/1000000;	
		store = store/1000;
		DecimalFormat numberFormat = new DecimalFormat("#.####");
		System.out.print("	");
		System.out.println(numberFormat.format(store));
	}
}
