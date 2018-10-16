

public class primeregb{
	public static void main(String args[]){
	int numberofprimes = 0;
	int testednumber = 2;
	int test = 0;
//Here I will convert the argument(string) into a int
	try {
	numberofprimes = Integer.parseInt(args[0]);
	}
	catch (NumberFormatException nfe) {
	System.out.println("The argument must be an integer.");
	System.exit(1);
	}
//Error check is right above, it exits if it's not a number.
	double startTime = System.currentTimeMillis();
//Obtaining program start time
	for(int n=0; n<numberofprimes;)
	{
	test=0;
		for(int m=2; m<=testednumber;m++)
		{
		if(m == testednumber)
			{
			n++;
			System.out.printf("%d ", testednumber);
			}
		if(testednumber % m == 0 && testednumber != 2)
			{
			break;
			}
		}
	testednumber++;
	}
// above is the basic loop for checking primes and breaking when it finds its not a prime
System.out.printf("%n");
double endTime = System.currentTimeMillis();
double totalTime = (endTime - startTime);
System.out.println((totalTime)/1000);
return;
	}
}
