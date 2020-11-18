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
L custom_arduino:wire_ir U2
U 1 1 5FB4C85E
P 3150 4850
F 0 "U2" H 3392 5515 50  0000 C CNN
F 1 "wire_ir" H 3392 5424 50  0000 C CNN
F 2 "custom_arduino:wire_ir" H 3700 5000 50  0001 C CNN
F 3 "" H 3700 5000 50  0001 C CNN
	1    3150 4850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3150 4600 3600 4600
Wire Wire Line
	3600 5300 5250 5300
Wire Wire Line
	5250 4600 5100 4600
Wire Wire Line
	5250 4600 5250 5300
Wire Wire Line
	3600 4600 3600 5300
Text Label 3250 4600 0    50   ~ 0
IR_OUT
$EndSCHEMATC
