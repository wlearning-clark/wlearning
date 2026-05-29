#!/usr/bin/env perl

use v5.28;
use strict;
use warnings;
use utf8;

say "hello";

# involke subroutine with ampersand
&marine;
&marine;
&marine;

my $n;
sub marine () {
  $n += 1;
  print "hello, sailor number $n \n";
}

# define a priviate variable using my
my $fan = 10;
my $bot = 20;

sub sum_of_fan_and_bot {
  print "Hello, you are calling the sum_of_fan_and_bot subroutine.\n";
  $fan + $bot;  # this is the return value
  print "Hi, I'm returning a value now.\n";
}

# involke a subroutine without ampersand, only the subroutine defined in early
marine;
marine;
marine;

my $box = &sum_of_fan_and_bot;
print "\$box is $box.\n";

my $bigbox = 2 * &sum_of_fan_and_bot;
print "\$bigbox is $bigbox.\n";


my ($first, $last) = qw# 10 22 #;
my $larger = &larger_of_two_value($first, $last);
say "\$larger is: " . $larger;
sub larger_of_two_value {
  # define the priviate and  persistante variable
  if( $first > $last )
  {
    $first;
  }else{
    $last;
  }
}

# Arguments
# $_ is a control variable
sub max {
  if ($_[0] > $_[1])
  {
    $_[0];
  }else {
    $_[1];
  }
}

my $maxnum = max(1, 9);
say "\$maxnum is: $maxnum";

$maxnum = max(1, -2, 5);  # ignore the 3rd argument
say "\$maxnum is: $maxnum";


# @_ is an array of parameters
sub max2 {
  my ($m, $n) = @_;
  if ($m > $n)
  {
    $m;
  }else {
    $n;
  }
}

$maxnum = max2(10, 31);
say "\$maxnum is $maxnum";
$maxnum = max2(-10, 1, 9);  # ignore the 3rd argument
say "\$maxnum is $maxnum";


# variable length

sub max3 {
  if (@_ != 2) {
    say "WARNING! &max3 should get exactily two arguments!"
  }
  if($_[0] < $_[1]){
    $_[1];
  }else{
    $_[0];
  }
}

$maxnum = max3(-1, 7, -9);  # ignore the 3rd argument
say "\$maxnum is $maxnum";

# better max subroutine

my $maximum = &max5(2, 99, 10, -52, 8);
say "\$maximum is $maximum";
sub max5{
    my ($max_so_far) = shift @_;
    foreach (@_){
      if($_ > $max_so_far){
        $max_so_far = $_;
      }
    }
    $max_so_far;
}

$maximum = max5(my @numbers);
say $maximum;
