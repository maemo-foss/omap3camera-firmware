# Sensor specific code: et8ek8

# Usage:
# $modelist_max_exp[$modenum] = sensor_max_exp(\%regs);

sub sensor_sensor_width {
	return 2592;
}

sub sensor_sensor_height {
	my $regsref = shift @_;
	my %regs = %$regsref;
	my $dummy_data = $regs{"0x125E"} & (1<<5);
	return 1966 if ($dummy_data);
	return 1968 if (!$dummy_data);
}

sub sensor_sensor_window_origin_x {
	my $w = et8ek8_hor_cropping(@_) * sensor_sensor_width(@_);
	return int((sensor_sensor_width(@_) - $w)/2);
}

sub sensor_sensor_window_origin_y {
	my $h = et8ek8_ver_cropping(@_) * sensor_sensor_height(@_);
	return int((sensor_sensor_height(@_) - $h)/2);
}

sub sensor_sensor_window_width {
	return int(et8ek8_hor_cropping(@_) * sensor_sensor_width(@_));
}

sub sensor_sensor_window_height {
	return int(et8ek8_ver_cropping(@_) * sensor_sensor_height(@_));
}

sub sensor_sensor_sensitivity {
	return et8ek8_sensitivity(@_);
}

sub et8ek8_hor_cropping {
	my $regsref = shift @_;
	my %regs = %$regsref;
	my $h_size = ($regs{"0x121D"} >> 4) & 0x07;
	my $cropping;
	$cropping = 1/1 if ($h_size>=6);
	$cropping = 3/4 if ($h_size==5);
	$cropping = 2/3 if ($h_size==4);
	$cropping = 1/2 if ($h_size==3);
	$cropping = 1/3 if ($h_size==2);
	$cropping = 1/4 if ($h_size==1);
	$cropping = 1/6 if ($h_size==0);
	return $cropping;
}

sub et8ek8_hor_scaling {
	my $cropping = et8ek8_hor_cropping(@_);
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $h_intermit  = $regs{"0x121D"} & 0x07;
	my $binning;
	$binning = 1/1 if ($h_intermit>=4);
	$binning = 1/(5 - $h_intermit) if ($h_intermit>=1 && $h_intermit<=3);
	$binning = 1/6 if ($h_intermit==0);

	return $binning * $cropping;
}

sub et8ek8_ver_cropping {
	my $regsref = shift @_;
	my %regs = %$regsref;
	my $pic_size = ($regs{"0x121B"} >> 4) & 0x07;
	my $cropping;
	$cropping = 1/1 if ($pic_size>=6);
	$cropping = 3/4 if ($pic_size==5);
	$cropping = 2/3 if ($pic_size==4);
	$cropping = 1/2 if ($pic_size==3);
	$cropping = 1/3 if ($pic_size==2);
	$cropping = 1/4 if ($pic_size==1);
	$cropping = 1/6 if ($pic_size==0);
	return $cropping;
}

sub et8ek8_ver_scaling {
	my $cropping = et8ek8_ver_cropping(@_);
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $moni_mode   = $regs{"0x121B"} & 0x07;
	my $binning;
	$binning = 1/1 if ($moni_mode>=4);
	$binning = 1/(5 - $moni_mode) if ($moni_mode>=1 && $moni_mode<=3);
	$binning = 1/6 if ($moni_mode==0);

	return $binning * $cropping;
}

sub sensor_max_exp {
	return sensor_height(@_) - 4;
}

sub et8ek8_sensitivity {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $h_intermit  = $regs{"0x121D"} & 0x07;
	my $hor_binning = 1;
	$hor_binning = 1 if ($h_intermit>=4);
	$hor_binning = (5 - $h_intermit) if ($h_intermit>=1 && $h_intermit<=3);
	$hor_binning = 6 if ($h_intermit==0);

	my $moni_mode   = $regs{"0x121B"} & 0x07;
	my $vert_binning = 1;
	$vert_binning = 1 if ($moni_mode>=4);
	$vert_binning = (5 - $moni_mode) if ($moni_mode>=1 && $moni_mode<=3);
	$vert_binning = 6 if ($moni_mode==0);

	return ($hor_binning * $vert_binning) << 16;
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

	my $vco = $modelist_ext_clock[$modenum] * $ckvar_div / ($ckref_div + 1);
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
	my $scaling     = et8ek8_ver_scaling(@_);

	my $regsref = shift @_;
	my %regs = %$regsref;

	my $v_count_lo  = $regs{"0x1222"};
	my $v_count_hi  = $regs{"0x1223"} & 0x1F;
	my $v_count     = ($v_count_hi<<8) | $v_count_lo;

	return $v_count * 24 * $scaling;
}

# Return the size of the visible image area
sub sensor_window_width {
	return 2592 * et8ek8_hor_scaling(@_);
}

sub sensor_window_height {
	return 1968 * et8ek8_ver_scaling(@_);
}

sub sensor_fps {
	my $pixels = sensor_width(@_) * sensor_height(@_);
	my $spck = sensor_pixel_clock(@_);

	return $spck / $pixels if ($pixels > 0);
	return undef();
}

# Return V4L2_PIX_FMT_xxx as a string
sub sensor_pixel_format {
	my $regsref = shift @_;
	my %regs = %$regsref;

	my $ccp_comp_mode = $regs{"0x125D"} & 0x07;

	return "V4L2_PIX_FMT_SGRBG10"      if ($ccp_comp_mode == 0);
	return "V4L2_PIX_FMT_SGRBG12"      if ($ccp_comp_mode == 1);
	return "V4L2_PIX_FMT_SGRBG8"       if ($ccp_comp_mode == 2);
	return "V4L2_PIX_FMT_SGRBG10DPCM8" if ($ccp_comp_mode == 3);
	return "V4L2_PIX_FMT_SGRBG12DPCM8" if ($ccp_comp_mode == 4);
	return "V4L2_PIX_FMT_SGRBG10DPCM6" if ($ccp_comp_mode == 5);
	return "V4L2_PIX_FMT_SGRBG12DPCM6" if ($ccp_comp_mode == 6);

	return undef;
}

1;
