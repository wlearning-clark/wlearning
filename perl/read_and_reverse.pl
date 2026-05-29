#!/usr/bin/env perl

use strict;
use utf8;
use warnings;

chomp(my @text = <STDIN>);

@text = reverse @text;

print "@text\n";
