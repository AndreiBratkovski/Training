#!/usr/bin/perl

use Time::HiRes;


my $start_run = Time::HiRes::gettimeofday();

$input = $ARGV[0];
$testNum = 4;
$divisor = 2;
$primeCount = 2;
$primeCheck = 0;
$root = 0;

printf STDERR '2 3 ';

while ($primeCount < $input){

	$root = sqrt($testNum);

	while ($divisor < $root + 1){
		if (($testNum % $divisor) == 0){
			$primeCheck = 1;
			break;
		}
		$divisor++;
	}

	if ($primeCheck == 0){
		printf STDERR '%d ', $testNum;
		$primeCount++;
	}
	$divisor = 2;
	$testNum++;
	$primeCheck = 0;
	
}

print "\n";

my $end_run = Time::HiRes::gettimeofday();
my $run_time = ($end_run - $start_run) / 1000;
printf("%.3f\n", $end_run - $start_run);


