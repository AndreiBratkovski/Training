#ifndef _PRIME_H
#define _PRIME_H

class prime
{
	public:
			prime(); // constructor
			char primeCheck(int testNum);
			char primePrint(int testNum);
			void setMax(int input);


	private:
			int primeCount;
			int max;

};

#endif
