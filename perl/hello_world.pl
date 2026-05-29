#!/usr/bin/env perl

use strict;
use warnings;
use diagnostics;
use utf8;

# number and string
print 10 . "\n";
print "one of the\n";
print 3.18e10 . "\n";
print -1.18e-04 . "\n";
my $meal = "hot dog";
print "my breakfast is " . $meal . "\n";
my $what = "bacon";
my $n = 2;
print "clark ate $n rasher of $what.\n";
print "clark ate $n rasher of ${what}.\n";
print "clark ate " . $n . " rasher of" . ${what} .".\n";

print chr(0x6ed0) . "\n";
print ord('$') . "\n";

# if statement
#  compare numerical with ==, !=, >, <, >=, <=
#  compare string with eq, ne, gt, lt, ge, le
if (22 == 10) {
  print "22 equal to 10\n";
} else {
  print "22 does not equal to 10\n";
}

my $is_bigger = 3 > 10;
if (!$is_bigger){
  print "the expression does not bigger than ...\n";
}else {
  print "the expression is bigger than ...\n";
}

# stdin; read a line
my $in = <STDIN>;
if ($in eq "\n")
{
  print "that was just a blank line!\n";
}else{
  print "that line of input was: $in\n";
}


# chomp : used to remove trailing newline from a string
# for example:
# "a text of a line \n" -> chomp() -> "a text of a line "
chomp(my $line = <STDIN>);

my $count = 0;

while ($count < 10)
{
  $count += 2;
  print "count in now $count\n";
}

my $string = "I'm a fence.";
$string .= " they are also calling me a pen.\n";

print $string;

# defined funciton
#
my $next_line = <STDIN>;

if (defined(chomp($next_line)))
{
  print "the input was \"$next_line\"\n";
} else {
  print "no input available!\n"
}

# Array and List
# function qw(): used to quote a list of words separately into a list

# Array
my $addr_snack = ["one", "two"];

print $addr_snack;
print "\n";

my @array = 3..9;

print @array;
print "\n";

push @array, 100;
print @array;
print "\n";

my @other = qw/ 8 1 8 4 /;
push @array, @other;
print @array;
print "\n";

my @array2 = qw# start end push pull all nothing #;
print @array2;
print "\n";

my $a = shift(@array2);
print @array2;
print "\n";
my $b = shift(@array2);
print @array2;
print "\n";
my $c = shift(@array2);
print @array2;
print "\n";

unshift @array2, 10;
print @array2;
print "\n";


# splice arg1, arg2, arg3, arg4
# arg1 is an array that you want to change
# arg2 is the index indicates the start position
# arg3 and arg4 are optional
# arg3 is the specific length that you will be removed
# arg4 is a replacement list that you want to plug in

my @array3 = qw# 1 2 3 4 5#;
my @removed = splice @array3, 1, 2;

print @array3;
print "\n";
print @removed;
print "\n";

# plug element into an array
#
my @array4 = qw# 0 1 2 3 4 5#;
my @removed2 =  splice @array4, 1, 0, qw# sugar #;

print @array4;
print "\n";


my @rocks = qw# flintstone slate rubble #;
print "quartz @rocks limestone\n";

print "the three rocks are: @rocks\n";

# email in perl
#
# my $email = "copyperl@email.com";  # error, because the @email is treat as an array
my $email = "copyperl\@email.com";  # correct
$email = 'copyperl@email.com'; # also correct


# foreach control structure
#

foreach my $snack (qw/ hot-dog banana apple fried-chip coca-cola /) {
    print "One snack is $snack.\n";
}

my @furniture = qw/ door chair sofa television kitchen chaise-longue /;
# change the each item of the array in a loop
foreach my $item (@furniture) {
  $item = "\t$item";
  $item .= "\n";
} 
# print the value that has been changed
# put the tab and newline at the front and after for each item.
print "the furniture are: \n", @furniture;


# default control variable `$_`
#
foreach (qw# 10 3 mice fan #) {
  print "element is $_\n";
}

$_ = "kapibara";
print  ; # output kapibara
print "\n";


# reverse operation

my @number = 3..23;

foreach (@number){
    $_ .= ", ";
}
print @number;
print "\n";
@number = reverse @number;
print "@number";
print "\n";

# sort operator, order by ASCII

my @array5 =  qw# o r m l j u #;
print "@array5";
print "\n";
@array5 = sort @array5;
print "@array5";
print "\n";

my @numbers = 7 .. 21;
print "@numbers\n";
@numbers = sort @numbers;
print "@numbers\n";



# each operator start with v5.12
require v5.12;
@rocks = qw/ bedrock slate rubble granite  /;
while ( (my $index, my  $value) = each @rocks) {
    print "$index, $value\n";
}

# another way to reach the effect of `each`
foreach my $index (0 .. $#rocks) {
  print "$index, $rocks[$index]\n";
}

# Scalar and List Context

print 2 * 3 . "\n";

print 2 x 3 . "\n";  # output 222; repeat 2 with 3 times


my @people = qw# Alice Bob John Charile-Kirk #;

my @sorted = sort @people;  # @people is a list.

print "@sorted\n";

my $number = 12 + @people; # @people is a number
print "$number\n";


my @frea = 6*3; # the one-element list
print "@frea\n";

my @barney = "hello" . ' ' . "world";
print "@barney\n";

my @betty = (); # empty list

my @wilma = undef; # one-element list (undef)

# Scalar Context
# scalar arg1: gives a number of a list
my @array6 = qw# watch mouse screen charge-wire charging-box external-interface #;
print "How many devices do you have?\n";
print "I have @array6 devices!\n";
print "I have ", scalar @array6, " devices!\n"; # gives a number
