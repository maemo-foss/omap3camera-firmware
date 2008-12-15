# Sensor specific code: et8en2
# SMIA stuff: NOKIA + ST Confidential

sub user_warn {
	print STDERR "WARNING: Incomplete register settings\n";
}

sub sensor_max_exp {
	return sensor_height(@_) - 8;
}

sub sensor_pixel_clock {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $vtpixclk_div = ($regs{"0x0300"} << 8) | $regs{"0x0301"};
	my $vtsysclk_div = ($regs{"0x0302"} << 8) | $regs{"0x0303"};
	my $prepll_div = ($regs{"0x0304"} << 8) | $regs{"0x0305"};
	my $pll_mul = ($regs{"0x0306"} << 8) | $regs{"0x0307"};

	if ($vtpixclk_div == 0 || $vtsysclk_div == 0 || \
		$prepll_div == 0 || $pll_mul == 0) { 
		return 0;
	}

	my $pll_op_freq = ($modelist_ext_clock[$modenum] / $prepll_div) * $pll_mul;
	my $vtpixclk = $pll_op_freq / ($vtsysclk_div * $vtpixclk_div);

	return $vtpixclk;
}

sub sensor_opsys_clock {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $opsysclk_div = ($regs{"0x030A"} << 8) | $regs{"0x030B"};
	my $prepll_div = ($regs{"0x0304"} << 8) | $regs{"0x0305"};
	my $pll_mul = ($regs{"0x0306"} << 8) | $regs{"0x0307"};

	if ($opsysclk_div == 0 || $prepll_div == 0 || $pll_mul == 0) { 
		return 0;
	}

	my $pll_op_freq = ($modelist_ext_clock[$modenum] / $prepll_div) * $pll_mul;
	my $opsysclk = $pll_op_freq / $opsysclk_div;

	return $opsysclk;
}

# SMIA mapping
# width			<- vt_line_length_pck    (includes horizontal blanking)
# height		<- vt_frame_length_lines (includes vertical balnking)
# window_origin_x	<- x_addr_start
# window_origin_y	<- y_addr_start
# window_width		<- x_output_size
# window_height		<- y_output_size

sub sensor_width {
	my $regsref = shift @_;
	my %regs = %$regsref;

	return ($regs{"0x0342"} << 8) | $regs{"0x0343"};
}

sub sensor_height {
	my $regsref = shift @_;
	my %regs = %$regsref;

	return ($regs{"0x0340"} << 8) | $regs{"0x0341"};
}

sub sensor_window_origin_x {
	my $regsref = shift @_;
	my %regs = %$regsref;

	return ($regs{"0x0344"} << 8) | $regs{"0x0345"};
}

sub sensor_window_origin_y {
	my $regsref = shift @_;
	my %regs = %$regsref;

	return ($regs{"0x0346"} << 8) | $regs{"0x0347"};
}

sub sensor_window_width {
	my $regsref = shift @_;
	my %regs = %$regsref;

	return ($regs{"0x034C"} << 8) | $regs{"0x034D"};
}

sub sensor_window_height {
	my $regsref = shift @_;
	my %regs = %$regsref;

	return ($regs{"0x034E"} << 8) | $regs{"0x034F"};
}

sub sensor_fps {
	my $spck = sensor_pixel_clock(@_);
	if ($spck == 0) { return undef; }

	my $vt_pix_clk_period_us = (1000 * 1000) / $spck;
	my $vt_line_length_us = sensor_width(@_) * $vt_pix_clk_period_us;
	my $vt_frame_length_us = sensor_height(@_) * $vt_line_length_us;

	return (1000 * 1000) / $vt_frame_length_us;
}

1;
