
public class primeregbs
{
	public static void main(String[] args)
	{
		/////////////////////////////////////////////////////////////////////
		//
		// Error checking
		//
		if (args.length < 1)
		{
			System.err.println("Insufficient argument!");
			System.exit(0);

		}
		long start = System.currentTimeMillis();
		/////////////////////////////////////////////////////////////////////
		//
		// Variable declaration
		//
		int max 	= Integer.parseInt(args[0]);
		char flag 	= 0;
		int factor 	= 0;
		int number 	= 2;
		int qty 	= 0;
		/////////////////////////////////////////////////////////////////////
		//
		// Main algorithm
		//

		/////////////////////////////////////////////////////////////////////
		//
		// Continuously checks until all the qty are print out
		//
		while (qty < max)
		{
			/////////////////////////////////////////////////////////////////
			//
			// Starting from 2 up to the current number, checks to see if
			// there are any factor in the number
			//
			for (factor = 2; factor <= Math.sqrt(number); factor++)
			{
				/////////////////////////////////////////////////////////////
				//
				// Checks to see if there are factors. If the number has
				// a factor other than 1 and itself, flag it as composite
				//
				if (number%factor == 0)
				{
					flag = 1;
					break;
				}
			}
			/////////////////////////////////////////////////////////////////
			//
			//	If the flag wasnt set off, then its a prime so print it out
			//
			if (flag == 0)
			{
				System.err.printf(number + " ");
				qty++;
			}
			number++;
			flag = 0;
		}
		System.err.println();
		long endTime = System.currentTimeMillis();
		float deltaTime = ( endTime -  start);
		System.out.printf("%8.6f\n",deltaTime/1000);
	}
}
