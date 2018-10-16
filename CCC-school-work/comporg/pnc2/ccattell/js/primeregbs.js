/////////////////////////////////////////////////
//					primeregbs.js
//				  Christian Cattell
//
//

var start = new Date().getTime();

var input      = process.argv[2]; 
var testNum    = 4;
var divisor    = 2;
var primeCount = 2;
var primeCheck = 0;
var quo        = 0;
var root       = 0;
var primes     = [];
primes.push(2); // add these numbers to the prime array
primes.push(3);


while (primeCount < input)
{
	root = Math.sqrt(testNum); // same logic as c

	while (divisor <= root)
	{
		quo = testNum % divisor;
		if (quo == 0)
		{
			primeCheck++;
			break;
		}
		divisor++;
	}

	if (primeCheck == 0)
	{
		primeCount++;
		primes.push(testNum);
	}
	primeCheck = 0;
	divisor = 2;
	testNum++;
}

var primeString = primes.toString();
var newchar = ' '								
primeString = primeString.split(',').join(newchar);
console.error(primeString);

var end = new Date().getTime();
var time = (end - start) / 1000;
console.log(time);

//var hrTime = process.hrtime();
//console.log(hrTime[0] * 10 + hrTime[1] / 1000);





