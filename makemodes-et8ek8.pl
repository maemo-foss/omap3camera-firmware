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

sub sensor_pixel_clock {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $ckref_div = ($regs{"0x1238"} & 0xf) + 1;
	my $ckvar_div = (($regs{"0x1238"} & 0x80) >> 7) | ($regs{"0x1239"} << 1);
	my $vco_div = ($regs{"0x123A"} >> 4) + 1;
	my $spck_div = ($regs{"0x123A"} & 0xf) + 1;
	my $mrck_div = ($regs{"0x123B"} >> 4) + 1;
	my $lvdsck_div = ($regs{"0x123B"} & 0xf) + 1;

	return $ckvar_div;
};

1;
