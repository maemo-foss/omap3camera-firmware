# Sensor specific code: et8ek8

# Usage:
# $modelist_max_exp[$modenum] = sensor_max_exp(\%regs);

sub sensor_max_exp {
	return sensor_height(@_) - 4;
}

sub sensor_pixel_clock {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $ckref_div = $regs{"0x1238"} & 0xf;
	my $ckvar_div = (($regs{"0x1238"} & 0x80) >> 7) | ($regs{"0x1239"} << 1);
	my $vco_div = $regs{"0x123A"} >> 4;
	my $spck_div = $regs{"0x123A"} & 0xf;
	my $mrck_div = $regs{"0x123B"} >> 4;
	my $lvdsck_div = $regs{"0x123B"} & 0xf;

	my $vco = $modelist_ext_clock[$modenum] * $ckvar_div / 3;
	my $ccp2 = $vco / (($lvdsck_div + 1) * ($vco_div + 1));
	my $spck = $vco / (($spck_div + 1) * ($vco_div + 1));
	
	return $spck + 0;
};

sub sensor_width {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $h_count_lo  = $regs{"0x1220"};
	my $h_count_hi  = $regs{"0x1221"} & 0x07;
	my $h_count     = ($h_count_hi<<8) | $h_count_lo;

	return $h_count * 24;
}

sub sensor_height {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $v_count_lo  = $regs{"0x1222"};
	my $v_count_hi  = $regs{"0x1223"} & 0x1F;
	my $v_count     = ($v_count_hi<<8) | $v_count_lo;
	my $moni_mode   = $regs{"0x121B"} & 0x07;
	my $pic_size    = ($regs{"0x121B"} >> 4) & 0x07;

	my $binning;
	$binning = 1/1 if ($moni_mode>=4);
	$binning = 1/(5 - $moni_mode) if ($moni_mode>=1 && $moni_mode<=3);
	$binning = 1/6 if ($moni_mode==0);

	my $cropping;
	$cropping = 1/1 if ($pic_size>=6);
	$cropping = 3/4 if ($pic_size==5);
	$cropping = 2/3 if ($pic_size==4);
	$cropping = 1/2 if ($pic_size==3);
	$cropping = 1/3 if ($pic_size==2);
	$cropping = 1/4 if ($pic_size==1);
	$cropping = 1/6 if ($pic_size==0);

	return $v_count * 24 * $binning * $cropping;
}

sub sensor_fps {
	my $pixels = sensor_width(@_) * sensor_height(@_);
	my $spck = sensor_pixel_clock(@_);

	return $spck / $pixels if ($pixels > 0);
	return undef();
}

1;
