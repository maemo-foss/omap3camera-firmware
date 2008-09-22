# Sensor specific code: et8ek8

# Usage:
# $modelist_max_exp[$modenum] = sensor_max_exp(\%regs);

sub sensor_max_exp {
	my $regsref = shift(@_);
	my %regs = %$regsref;
	my $v_count_lo  = $regs{"0x1222"};
	my $v_count_hi  = $regs{"0x1223"} & 0x1F;
	my $moni_mode   = $regs{"0x121B"} & 0x07;
	my $v_count     = ($v_count_hi<<8) | $v_count_lo;
	if ($v_count > 0) {
		return $v_count*24/(5 - $moni_mode) - 4;
	}
}

1;
