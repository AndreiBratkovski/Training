//
// Primeregbs.js - Andrei Bratkovski
//

//
// Process arguments based on the 1st command line
// argument
//
var maxNumPrimes = process.argv[2];

//
// Declare counter variables
//
var increment = 0;
var lowerBound = 2;
var numPrimes = 0;
var compositeCounter = 0;

//
// Start timer
//
var start = new Date().getTime();

//
// Calculate primes by checking up to the square root of current number being
// checked, until number of primes is the same as the chosen number of max primes
//
while ( numPrimes < maxNumPrimes )
{
  for ( increment = 2; increment <= Math.sqrt(lowerBound); increment++)
  {
    if ( lowerBound % increment == 0 )
      compositeCounter++;
      
    if ( compositeCounter >= 2)
      break;
  }
  if ( compositeCounter < 1 )
  {
      process.stderr.write(lowerBound + " ")
      numPrimes++;
  }
   
  lowerBound++;
  compositeCounter = 0;
}
//
// Calculate end time and calculate
// how long program takes
//
console.log("");
var end = new Date().getTime();
console.log((end-start)/1000);

