# Sensor specific code: tcm8330md

# Use vs6555 for most things--it's sufficiently similar
do "makemodes-vs6555.pl" or die("invalid makemodes-vs6555.pl\n");

sub sensor_window_height {
       return 488 - 2;
}
