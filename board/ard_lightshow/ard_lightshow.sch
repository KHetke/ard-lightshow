EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Arduino Lightshow - Host"
Date "2020-11-17"
Rev "1.0"
Comp "Kamran Hetke"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	3150 4450 3150 2250
Wire Wire Line
	3150 2250 4350 2250
Wire Wire Line
	4350 2250 4350 2650
Wire Wire Line
	3150 4750 3150 5400
Wire Wire Line
	3150 5400 4200 5400
Wire Wire Line
	4200 5400 4200 5200
Wire Wire Line
	7050 4500 7050 5400
Wire Wire Line
	7050 5400 4350 5400
Connection ~ 4200 5400
Wire Wire Line
	5250 2400 5250 3100
Wire Wire Line
	7850 3850 7850 3400
Wire Wire Line
	5100 3250 5400 3250
Wire Wire Line
	5400 3000 5400 3250
Wire Wire Line
	5100 3850 6550 3850
Wire Wire Line
	5100 3700 6550 3700
Wire Wire Line
	8000 2400 8000 4000
Wire Wire Line
	7700 3000 7700 3700
Wire Wire Line
	5100 3100 5250 3100
Wire Wire Line
	5100 3400 7850 3400
Wire Wire Line
	7550 3850 7850 3850
Wire Wire Line
	7550 3700 7700 3700
Wire Wire Line
	5400 3000 7700 3000
Wire Wire Line
	7550 4000 8000 4000
Wire Wire Line
	5250 2400 8000 2400
Wire Wire Line
	4200 2650 4200 2100
Wire Wire Line
	4200 2100 7050 2100
Wire Wire Line
	7050 2100 7050 3250
Text Label 5600 2100 0    50   ~ 0
3V3
Text Label 3700 2250 0    50   ~ 0
5V0
Wire Wire Line
	4350 5200 4350 5400
Connection ~ 4350 5400
Wire Wire Line
	4350 5400 4200 5400
$Comp
L Device:CP1 C0
U 1 1 5FB635C2
P 8250 3200
F 0 "C0" H 8365 3246 50  0000 L CNN
F 1 "100u" H 8365 3155 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D5.0mm_P2.50mm" H 8250 3200 50  0001 C CNN
F 3 "~" H 8250 3200 50  0001 C CNN
	1    8250 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 3050 8250 2100
Wire Wire Line
	8250 2100 7050 2100
Connection ~ 7050 2100
$Comp
L Device:CP1 C1
U 1 1 5FB6C448
P 8650 3200
F 0 "C1" H 8765 3246 50  0000 L CNN
F 1 "1000u" H 8765 3155 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D8.0mm_P3.50mm" H 8650 3200 50  0001 C CNN
F 3 "~" H 8650 3200 50  0001 C CNN
	1    8650 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 3050 8650 2250
Wire Wire Line
	8650 2250 4350 2250
Connection ~ 4350 2250
Wire Wire Line
	8250 3350 8250 5400
Wire Wire Line
	8250 5400 7050 5400
Connection ~ 7050 5400
Wire Wire Line
	8650 3350 8650 5400
Wire Wire Line
	8650 5400 8250 5400
Connection ~ 8250 5400
Text Label 6300 3000 0    50   ~ 0
MISO
Text Label 6300 3400 0    50   ~ 0
MOSI
Text Label 6350 2400 0    50   ~ 0
SCK
Text Label 5800 3700 0    50   ~ 0
CE
Text Label 5750 3850 0    50   ~ 0
CSN
Text Label 5800 5400 0    50   ~ 0
GND
Text Label 3550 3100 0    50   ~ 0
MIC_OUT
$Comp
L custom_arduino:arduino_nano U0
U 1 1 5FB53E9D
P 4000 5000
F 0 "U0" H 4450 7531 50  0000 C CNN
F 1 "arduino_nano" H 4450 7440 50  0000 C CNN
F 2 "custom_arduino:arduino_nano" H 3950 5250 50  0001 C CNN
F 3 "" H 3950 5250 50  0001 C CNN
	1    4000 5000
	1    0    0    -1  
$EndComp
$Comp
L custom_arduino:rf24 U1
U 1 1 5FB58C4D
P 6750 4300
F 0 "U1" H 7050 5531 50  0000 C CNN
F 1 "rf24" H 7050 5440 50  0000 C CNN
F 2 "custom_arduino:rf24" H 6700 4450 50  0001 C CNN
F 3 "" H 6700 4450 50  0001 C CNN
	1    6750 4300
	1    0    0    -1  
$EndComp
$Comp
L custom_arduino:mic_electret U2
U 1 1 5FB4F1AE
P 3150 4850
F 0 "U2" H 3423 5477 50  0000 C CNN
F 1 "mic_electret" H 3423 5386 50  0000 C CNN
F 2 "custom_arduino:mic_electret" H 3750 5000 50  0001 C CNN
F 3 "" H 3750 5000 50  0001 C CNN
	1    3150 4850
	-1   0    0    -1  
$EndComp
$Comp
L custom_arduino:wire_power U3
U 1 1 5FB588F3
P 2350 1700
F 0 "U3" H 2567 2215 50  0000 C CNN
F 1 "wire_power" H 2567 2124 50  0000 C CNN
F 2 "custom_arduino:wire_power" H 2850 1850 50  0001 C CNN
F 3 "" H 2850 1850 50  0001 C CNN
	1    2350 1700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3150 5400 2450 5400
Wire Wire Line
	2450 5400 2450 2000
Wire Wire Line
	2450 1600 2350 1600
Connection ~ 3150 5400
Wire Wire Line
	2350 1450 2700 1450
Wire Wire Line
	4500 1450 4500 2650
Text Label 3250 1450 0    50   ~ 0
VIN
$Comp
L Device:CP1 C2
U 1 1 5FB5A700
P 2700 1750
F 0 "C2" H 2815 1796 50  0000 L CNN
F 1 "100u" H 2815 1705 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D5.0mm_P2.50mm" H 2700 1750 50  0001 C CNN
F 3 "~" H 2700 1750 50  0001 C CNN
	1    2700 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 1600 2700 1450
Connection ~ 2700 1450
Wire Wire Line
	2700 1450 4500 1450
Wire Wire Line
	2700 1900 2700 2000
Wire Wire Line
	2700 2000 2450 2000
Connection ~ 2450 2000
Wire Wire Line
	2450 2000 2450 1600
$Comp
L Device:R_US R0
U 1 1 5FB5A89E
P 3500 4300
F 0 "R0" H 3568 4346 50  0000 L CNN
F 1 "1" H 3568 4255 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 3540 4290 50  0001 C CNN
F 3 "~" H 3500 4300 50  0001 C CNN
	1    3500 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 5FB5B7C3
P 3500 4900
F 0 "R1" H 3568 4946 50  0000 L CNN
F 1 "NS" H 3568 4855 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 3540 4890 50  0001 C CNN
F 3 "~" H 3500 4900 50  0001 C CNN
	1    3500 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4450 3500 4600
Connection ~ 3500 4600
Wire Wire Line
	3500 4600 3500 4750
Wire Wire Line
	3500 5050 3500 5300
Wire Wire Line
	3500 5300 5250 5300
Wire Wire Line
	5250 5300 5250 4600
Wire Wire Line
	5250 4600 5100 4600
Wire Wire Line
	3500 3100 3500 4150
Text Label 3550 5300 0    50   ~ 0
IR_OUT
Text Label 3100 4600 0    50   ~ 0
MODCONN
Wire Wire Line
	3800 3100 3500 3100
Wire Wire Line
	3150 4600 3500 4600
$EndSCHEMATC
