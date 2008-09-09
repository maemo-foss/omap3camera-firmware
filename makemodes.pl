#!/usr/bin/env perl

use Getopt::Std;

(my $sec,my $min,my $hour,my $mday,my $mon,my $year,my $wday,my $yday,my $isdst) = gmtime(time);
my $name = "smia_meta_reglist";
my $version = sprintf("%04d-%02d-%02d", $year+1900, $mon, $mday);
my %options=();
getopts("n:v:h",\%options);
my $inifile = $ARGV[0];
die "Need input filename\n" if !$inifile;
if (defined $options{h}) {
	print("Copyright (C) 2008 Nokia, author Tuukka Toivonen <tuukka.o.toivonen@nokia.com>\n");
	print("Convert Scooby settings to SMIA sensor firmware format.\n");
	print("Usage: makemodes.pl [-n name] [-v version string] <inputfile.ini>\n");
	exit(0);
}
if (defined $options{n}) { $name = $options{n}; }
if (defined $options{v}) { $version = $options{n}; }

$extclk = 9600000;
@modelist_width = ();
@modelist_height = ();
@modelist_window_origin_x = ();
@modelist_window_origin_y = ();
@modelist_window_width = ();
@modelist_window_height = ();
@modelist_pixel_clock = ();
@modelist_ext_clock = ();
@modelist_tpf_numerator = ();
@modelist_tpf_denominator = ();
@modelist_max_exp = ();
@modelist_max_gain = ();
@modelist_pixel_format = ();
@modelist_type = ();
@modelist_bayer = ();
@modelist_blacklvl = ();
@modelist_satlvl = ();

sub flush {
	if ($m != 0) {
		print("		{ SMIA_REG_TERM, 0, 0}\n" .
		      "	}\n" .
		      "};\n");
		$m = 0;
	}
}

sub generate_modelist {
	my $pass = shift(@_);
	my $modenum = 0;
	my $incomment = 0;	# 0=no any comment yet, 1=some comments done, 2=currently in comment
	$m = 0;

	open(my $fh, "<", $inifile) or die("can not open input file\n");
	while (<$fh>) {
		$_ =~ s/\r//;
		chomp;
		if (length($_) <= 0) { next; }
		my @a = split(/[\t ]+/);
		my $o = $_;
		$o =~ s/\*\//##/g;
		$o =~ s/;//g;
		if (substr($_,0,1) eq "#") {
			if ($incomment==2) {
				$o =~ s/^#/ \*/;
			} else {
				if ($pass!=1 && $incomment==0) { next; }
				if ($pass==1 && $incomment==1 && $modenum>0) { next; }
				$incomment = 2;
				$o =~ s/^#/\/\*/;
			}
		} else {
			if ($incomment==2) {
				$incomment = 1;
				print(" */\n");
			};
		}
		$o =~ s/#.*$//;
		/^ / && do {
			if ($pass!=2) { next; }
			my $c = substr($o,9);
			$o = "		{ SMIA_REG_8BIT, 0x$a[1], 0x$a[2] },";
			if (length($c)>0) {
				$o .= "	/* " . $c . " */";
			}
		};
		/^S/ && do {
			$modenum++;
			flush() if ($pass==2);
			$m = 1;
			my $l = substr($o,2);
			my $c = $l;
			$c =~ tr/\(\)@[A-Z]\/\.-/___[a-z]___/;
			if ($pass==1) {
				$modelist_width[$modenum] = 0;
				$modelist_height[$modenum] = 0;
				$modelist_window_origin_x[$modenum] = 0;
				$modelist_window_origin_y[$modenum] = 0;
				$modelist_window_width[$modenum] = 0;
				$modelist_window_height[$modenum] = 0;
				$modelist_pixel_clock[$modenum] = 0;
				$modelist_ext_clock[$modenum] = 0;
				$modelist_tpf_numerator[$modenum] = 0;
				$modelist_tpf_denominator[$modenum] = 0;
				$modelist_max_exp[$modenum] = 0;
				$modelist_max_gain[$modenum] = 0;
				$modelist_pixel_format[$modenum] = $modelist_pixel_format[0];
				if ($modelist_pixel_format[0]) {
					$modelist_pixel_format[$modenum] = $modelist_pixel_format[0];
				}
				$modelist_type[$modenum] = "SMIA_REGLIST_MODE";
				$modelist_bayer[$modenum] = 0;
				$modelist_blacklvl[$modenum] = 0;
				$modelist_satlvl[$modenum] = 0;
				next;
			}
			if ($pass==2) {
				if (!$modelist_width[$modenum]) {
					$modelist_width[$modenum] = $l;
					if (!($modelist_width[$modenum] =~ s/^.*_([0-9]+)x[0-9]+_.*$/$1/)) {
						$modelist_width[$modenum] = "0";
					}
				}
				if (!$modelist_height[$modenum]) {
					$modelist_height[$modenum] = $l;
					if (!($modelist_height[$modenum] =~ s/^.*_[0-9]+x([0-9]+)_.*$/$1/)) {
						$modelist_height[$modenum] = "0";
					}
				}
				if (!$modelist_tpf_numerator[$modenum]) {
					$modelist_tpf_numerator[$modenum] = 100;
					$modelist_tpf_denominator[$modenum] = $l;
					$modelist_tpf_denominator[$modenum] =~ s/^.*_([0-9\.]+)fps.*$/$1/;
					$modelist_tpf_denominator[$modenum] *= 100;
					if (($modelist_tpf_denominator[$modenum] % 100) == 0) {
						$modelist_tpf_numerator[$modenum] /= 100;
						$modelist_tpf_denominator[$modenum] /= 100;
					}
				}
				if ($l =~ /DPCM10/i) {
					$modelist_pixel_format[$modenum] = "V4L2_PIX_FMT_SGRBG10DPCM8";
				}
				if (!$modelist_pixel_format[$modenum]) {
					$modelist_pixel_format[$modenum] = "V4L2_PIX_FMT_SGRBG10";
				}
				if ($l =~ /powerdown/) {
					$modelist_type[$modenum] = "SMIA_REGLIST_STANDBY";
				}
				if ($l =~ /poweron/) {
					$modelist_type[$modenum] = "SMIA_REGLIST_POWERON";
				}
				$o = "\n";
				$o .= "/* " . $l . " */\n";
				$o .= "static struct smia_reglist $c = {	/* $modenum */\n";
				$o .= "	.type = $modelist_type[$modenum],\n";
				$o .= "	.mode = {\n" .
				      "		.width = $modelist_width[$modenum],\n" .
				      "		.height = $modelist_height[$modenum],\n" .
				      "		.window_origin_x = $modelist_window_origin_x[$modenum],\n" .
				      "		.window_origin_y = $modelist_window_origin_y[$modenum],\n" .
				      "		.window_width = $modelist_window_width[$modenum],\n" .
				      "		.window_height = $modelist_window_height[$modenum],\n" .
				      "		.pixel_clock = $modelist_pixel_clock[$modenum],\n" .
				      "		.ext_clock = $extclk,\n" .
				      "		.timeperframe = {\n" .
				      "			.numerator = $modelist_tpf_numerator[$modenum],\n" .
				      "			.denominator = $modelist_tpf_denominator[$modenum]\n" .
				      "		},\n" .
				      "		.max_exp = $modelist_max_exp[$modenum],\n" .
				      "		/* .max_gain = $modelist_max_gain[$modenum], */\n" .
				      "		.pixel_format = $modelist_pixel_format[$modenum]\n" .
				      "	},\n";
				$o .= "	.regs = {";
			}
			if ($pass == 3) {
				$o = "		{ .offset = (uintptr_t)&$c },";
			}
		};
		/^F/ && do {
			if ($pass==1) {
				$n = $o;
				$n =~ s/^F[\t ]+[a-zA-Z]+[\t ]+([0-9]+)[\t ].*$/$1/;
				#if ($o =~ /^F[\t ]*imageFormat/) { }
				if ($o =~ /^F[\t ]*imageWidth/)  { $modelist_width[$modenum]     = $n; }
				if ($o =~ /^F[\t ]*imageHeight/) { $modelist_height[$modenum]    = $n; }
				if ($o =~ /^F[\t ]*etMax/)       { $modelist_max_exp[$modenum]   = $n; }
				if ($o =~ /^F[\t ]*agMax/)       { $modelist_max_gain[$modenum]  = $n; }
				next;
			}
			if ($pass==2) {
				flush();
				$o = "/* " . substr($o,2) . " */";
			}
			if ($pass==3) {
				next;
			}
		};
		(/^P/ || /^I/ || /^L/ || /^A/) && do {
			if ($pass!=2) { next; }
			my $o2 = $o;
			$o = "";
			$o .= "		" if ($modenum!=0);
			$o .= "/* " . substr($o2,2) . " */";
		};
		/^C/ && do {
			if ($pass!=1) { next; }
			my $extclk_src = $a[2];
			my $extclk_div = $a[3];
			my $src = -1;
			if ($extclk_src == 1) { $src = 19.200; }
			if ($extclk_src == 2) { $src = 26.000; }
			if ($extclk_src == 3) { $src = 98.304; }
			die "bad extclk $extclk_src" if ($src==-1);
			my $div = -1;
			if ($extclk_div == 0) { $div = 1; }
			if ($extclk_div == 1) { $div = 2; }
			if ($extclk_div == 2) { $div = 4; }
			if ($extclk_div == 3) { $div = 6; }
			if ($extclk_div == 4) { $div = 8; }
			if ($extclk_div == 5) { $div = 10; }
			if ($extclk_div == 6) { $div = 12; }
			if ($extclk_div == 7) { $div = 14; }
			die "bad extclk divisor $extclk_div" if ($div==-1);
			$extclk = int($src*1000000 / $div + 0.5);
			#$o = "#define CAMERA_XCLK_HZ " . $extclk . "	/*	" . substr($o,2) . "	*/";
			next;
		};
		/^D/ && do {
			if ($pass!=2) { next; }
			$o = "		{ SMIA_REG_DELAY, 0, $a[1] },";
		};
		/^N/ && do {
			/^N[ \t]+CCM[ \t]+/i && do {		# Color sensitivity
			};
			/^N[ \t]+GAMMA[ \t]+/i && do {		# Gamma
			};
			/^N[ \t]+ACONTRAST[ \t]+/i && do {	# contrast enhancement: 1=enable, 0=disable
			};
			/^N[ \t]+CONTRLIMITS[ \t]+/i && do {	# contrast limit values: black, white
			};
			/^N[ \t]+AWB[ \t]+/i && do {		# autowhite balance: 1=enabled, 0=disabled
			};
			/^N[ \t]+WBGAINS[ \t]+/i && do {	# wb gains used when awb disabled
			};
			/^N[ \t]+RUNON[ \t]+/i && do {		# wb, ccm, contrast, gamma: 1=enabled, 0=disabled
			};
			/^N[ \t]+BAYER[ \t]+/i && do {		# Bayer format: 0=rggb, 1=grbg, gbrg=2, bggr=3
			};
			/^N[ \t]+CODING[ \t]+/i && do {		# Frame coding: 0=raw8, 1=raw10, 2=raw12, 3=dpcm10to8, 4=dpcm12to8
				my $n = $o;
				$n =~ s/^.*CODING[ \t]+([0-9]+).*$/$1/i;
				if (0) {
					# This cannot be trusted to so disable it for now
					$modelist_pixel_format[0] = "0";
					if ($n == 0) { $modelist_pixel_format[0] = "V4L2_PIX_FMT_SGRBG8"; }
					if ($n == 1) { $modelist_pixel_format[0] = "V4L2_PIX_FMT_SGRBG10"; }
					#if ($n == 2) { $modelist_pixel_format[0] = "V4L2_PIX_FMT_SGRBG12"; }
					if ($n == 3) { $modelist_pixel_format[0] = "V4L2_PIX_FMT_SGRBG10DPCM8"; }
					#if ($n == 4) { $modelist_pixel_format[0] = "V4L2_PIX_FMT_SGRBG12DPCM8"; }
					$modelist_pixel_format[$modenum] = $modelist_pixel_format[0];
				}
			};
			/^N[ \t]+BLACKLVL[ \t]+/i && do {	# Black level
			};
			/^N[ \t]+SATLVL[ \t]+/i && do {		# Saturation level
			};
			next if ($pass != 2);
			my $o2 = $o;
			$o = "";
			$o .= "		" if ($modenum!=0);
			$o .= "/* " . substr($o2,2) . " */";
		};
		/^V/ && do {
			$version = $o;
			next;
		};
		print("$o\n");
	}
	flush() if ($pass==2);
	close($fh);

}

$fmtspec = 0;

print("/* Automatically generated code from Scooby\n" .
      " * configuration file `");
my $s = $inifile;
$s =~ s/^.+\///;
print($s);
print("' by makemodes.pl. */\n\n" .
      "\n" .
      "#include <media/smiaregs.h>\n" .
      "#include <linux/videodev2.h>\n" .
      "\n");
generate_modelist(1);
generate_modelist(2);
print("\n" .
      "struct smia_meta_reglist $name = {\n" .
      "	.version = \"$version\",\n" .
      "	.reglist = {\n");
generate_modelist(3);
print("		{ .offset = 0 }\n" .
      "	}\n" .
      "};\n" .
      "\n");

exit(0);
