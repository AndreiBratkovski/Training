// to compile: javac -J-XX:MaxHeapSize=512M -J-XX:InitialHeapSize=256M -J-XX:CompressedClassSpaceSize=128M -J-XX:MaxMetaspaceSize=128m -J-XX:+UseConcMarkSweepGC -J-XX:MetaspaceSize=64m primeregbs.java
// to run: java -XX:MaxHeapSize=512M -XX:InitialHeapSize=256M -XX:CompressedClassSpaceSize=128M -XX:MaxMetaspaceSize=128m -XX:+UseConcMarkSweepGC -XX:MetaspaceSize=64m primeregbs

//
// Primeregbs.java - Andrei Bratkovski
//

public class primeregbs {
  public static void main(String args[]){
//
// Maximum number of primes are determined by the
// first command line argument
//
int maxNumPrimes = Integer.parseInt(args[0]);

//
// Declare variables
//
int increment;
int lowerBound = 2;
int numPrimes = 0;
int compositeCounter = 0;

//
// Start time is declared using system start time method
//
long start_time = System.currentTimeMillis();

//
// Print out number of primes based on the number of max primes that
// are listed
//
while ( numPrimes < maxNumPrimes )
{
  //
  // Check up to the square root of each number until the max number of
  // primes have been printed
  //
  for ( increment = 2; increment <= Math.sqrt(lowerBound); increment++)
  {
    if ( lowerBound % increment == 0 )
      compositeCounter++;
      
    if ( compositeCounter >= 2)
      break;
  }

  if ( compositeCounter < 1 )
  {
      System.err.print(lowerBound + " ");
      numPrimes += 1;
  } 
  lowerBound++;
  compositeCounter = 0;
}

//
// Calculate and print out the amount of time that has 
// 
//
long end_time = System.currentTimeMillis();
long total_time = end_time - start_time;

System.err.print("\n");
System.out.print(total_time/1000.0);
System.out.print("\n");
}
}
