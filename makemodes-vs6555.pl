# Sensor specific code: vs6555

sub sensor_sensor_width {
	return 648;
}

sub sensor_sensor_height {
	return 488;
}

# FIXME: vs6555 cropping/scaling not yet supported
sub sensor_sensor_window_origin_x {
	return 0;
}

sub sensor_sensor_window_origin_y {
	return 0;
}

sub sensor_sensor_window_width {
	return sensor_sensor_width(@_);
}

sub sensor_sensor_window_height {
	return sensor_sensor_height(@_);
}

sub sensor_max_exp {
	return sensor_height(@_) - 3;
}

sub sensor_pixel_clock {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $pll_multipler    = ($regs{"0x0306"} << 8) | $regs{"0x0307"};
	my $pre_pll_clk_div  = ($regs{"0x0304"} << 8) | $regs{"0x0305"};
	my $vt_sys_clk_div   = ($regs{"0x0302"} << 8) | $regs{"0x0303"};
	my $vt_pix_clk_div   = ($regs{"0x0300"} << 8) | $regs{"0x0301"};

	return undef if (!$pre_pll_clk_div);
	return undef if (!$vt_sys_clk_div);
	return undef if (!$vt_pix_clk_div);

	my $vt_pix_clk_freq = ($modelist_ext_clock[$modenum] * $pll_multipler)
	                      / ($pre_pll_clk_div * $vt_sys_clk_div * $vt_pix_clk_div);
	return $vt_pix_clk_freq;
}

sub sensor_width {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $line_length_pck = ($regs{"0x0342"} << 8) | $regs{"0x0343"};

	return $line_length_pck;
}

sub sensor_height {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $frame_length_lines = ($regs{"0x0340"} << 8) | $regs{"0x0341"};
	return $frame_length_lines;
}

sub sensor_fps {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $line_length_pck    = ($regs{"0x0342"} << 8) | $regs{"0x0343"};
	my $frame_length_lines = ($regs{"0x0340"} << 8) | $regs{"0x0341"};

	return undef if (!$line_length_pck);
	return undef if (!$frame_length_lines);

	my $framerate = sensor_pixel_clock($regsref)
	                / ($line_length_pck * $frame_length_lines);

	return $framerate;
}

1;
