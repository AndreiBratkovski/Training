#!/usr/bin/perl

use strict;
use warnings;
use diagnostics;
use Time::HiRes qw( time );

#use feature 'say';
#use feature "switch";

# variables
my $number  = 0;
my $factor  = 0;
my $count   = 0;
my $check   = 0;
my $qty     = 0;
my $sqrt    = 0;

#Error checking
if (!defined $ARGV[0]) # If no argument
{
    print "ERROR: missing quantity!\n";
    exit 1;
}
else
{
    $qty = $ARGV[0];    # set qty to command line argument
    if ($qty < 0)
    {
        print "ERROR: must choose a positive integer!\n";
        exit 2;
    }
}

my $startTime = [Time::HiRes::gettimeofday()];

for ($number = 2; $count < $qty; $number++) #iterate through numbers to check
{
    $check = 1;
    $sqrt = sqrt($number);
    for ($factor = 2; $factor <= $sqrt; $factor++)  #iterate through factors to check numbers against
    {
        if (($number % $factor) == 0)
        {
            $check = 0; # proven to NOT be prime
            last;
        }
    }

    if ($check == 1)    # if check is still true it was Not diproved as a Prime
    {
        print STDERR "$number ";    # print to stderr
        $count++;
    }
}

print "\n";

#my $endTime = [Time::HiRes::gettimeofday()];
my $endTime = Time::HiRes::tv_interval($startTime);
#print STDOUT "$endTime\n";
printf STDOUT ("%8.4lf\n", $endTime);
