EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 12
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1000 1000 1000 500 
U 5F08D407
F0 "Sheet5F08D406" 50
F1 "fft8051_leds.sch" 50
F2 "SDA" B R 2000 1100 50 
F3 "SCL" I R 2000 1200 50 
$EndSheet
$Comp
L fft8051:C8051F850-A-GU U6
U 1 1 5EAEC67B
P 2250 1000
F 0 "U6" H 2450 1050 50  0000 C CNN
F 1 "C8051F850-A-GU" H 2750 -850 50  0000 C CNN
F 2 "fft8051:C8051F850-A-GU" H 2300 900 50  0001 C CNN
F 3 "" H 2300 900 50  0001 C CNN
	1    2250 1000
	1    0    0    -1  
$EndComp
NoConn ~ 3250 2500
NoConn ~ 3250 2600
NoConn ~ 3250 2700
$Comp
L fft8051:CAP_0603 C6
U 1 1 5EB1AC91
P 3600 1150
F 0 "C6" H 3698 1116 50  0000 L CNN
F 1 "CAP_0603" H 3698 1025 50  0000 L CNN
F 2 "fft8051:0603" H 3600 1150 50  0001 C CNN
F 3 "" H 3600 1150 50  0001 C CNN
F 4 "100nF" H 3698 934 50  0000 L CNN "Capacitance"
	1    3600 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1100 3600 1100
Wire Wire Line
	3600 1100 3600 1050
Wire Wire Line
	3600 1150 3600 1100
Connection ~ 3600 1100
Wire Wire Line
	3250 1800 3350 1800
Wire Wire Line
	3350 1800 3350 1500
Wire Wire Line
	3350 1500 3600 1500
Wire Wire Line
	3600 1500 3600 1400
Wire Wire Line
	3600 1600 3600 1500
Connection ~ 3600 1500
$Comp
L power:+3.3VA #PWR0132
U 1 1 5EB1F03B
P 3600 1050
F 0 "#PWR0132" H 3600 900 50  0001 C CNN
F 1 "+3.3VA" H 3615 1223 50  0000 C CNN
F 2 "" H 3600 1050 50  0001 C CNN
F 3 "" H 3600 1050 50  0001 C CNN
	1    3600 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 1100 2300 1100
Wire Wire Line
	2300 1200 2000 1200
$Comp
L MAX1626:MAX1626ESA+ U7
U 1 1 5EB33E62
P 2050 5000
F 0 "U7" H 3150 5387 60  0000 C CNN
F 1 "MAX1626ESA+" H 3150 5281 60  0000 C CNN
F 2 "MAX1626:MAX1626ESA&plus_" H 3150 5240 60  0001 C CNN
F 3 "" H 2050 5000 60  0000 C CNN
	1    2050 5000
	1    0    0    1   
$EndComp
$Comp
L power:GNDREF #PWR0133
U 1 1 5EB93E3A
P 5000 5800
F 0 "#PWR0133" H 5000 5550 50  0001 C CNN
F 1 "GNDREF" H 5005 5627 50  0000 C CNN
F 2 "" H 5000 5800 50  0001 C CNN
F 3 "" H 5000 5800 50  0001 C CNN
	1    5000 5800
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0134
U 1 1 5EB948F7
P 5000 3500
F 0 "#PWR0134" H 5000 3350 50  0001 C CNN
F 1 "+BATT" H 5015 3673 50  0000 C CNN
F 2 "" H 5000 3500 50  0001 C CNN
F 3 "" H 5000 3500 50  0001 C CNN
	1    5000 3500
	1    0    0    -1  
$EndComp
$Comp
L fft8051:MBRS340T3G D1
U 1 1 5EB96858
P 5050 5600
F 0 "D1" H 5012 5529 50  0000 R CNN
F 1 "MBRS340T3G" H 5012 5620 50  0000 R CNN
F 2 "fft8051:MBRS340T3G" H 5050 5600 50  0001 C CNN
F 3 "" H 5050 5600 50  0001 C CNN
	1    5050 5600
	-1   0    0    1   
$EndComp
$Comp
L fft8051:SI4463CDY-T1-GE3 Q17
U 1 1 5EBFA40E
P 5000 4700
F 0 "Q17" H 5100 4450 50  0000 L CNN
F 1 "SI4463CDY-T1-GE3" H 5100 4350 50  0000 L CNN
F 2 "fft8051:SI4463CDY-T1-GE3" H 5000 4700 50  0001 C CNN
F 3 "" H 5000 4700 50  0001 C CNN
	1    5000 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4600 5100 4600
Wire Wire Line
	5200 4600 5200 4700
Connection ~ 5000 4600
Wire Wire Line
	5000 4600 5000 4700
Wire Wire Line
	5100 4700 5100 4600
Connection ~ 5100 4600
Wire Wire Line
	5100 4600 5200 4600
Wire Wire Line
	5000 5800 5000 5750
Wire Wire Line
	5000 5450 5000 5350
Wire Wire Line
	5000 5350 5100 5350
Wire Wire Line
	5300 5350 5300 5250
Connection ~ 5000 5350
Wire Wire Line
	5000 5350 5000 5250
Wire Wire Line
	5200 5250 5200 5350
Connection ~ 5200 5350
Wire Wire Line
	5200 5350 5300 5350
Wire Wire Line
	5100 5250 5100 5350
Connection ~ 5100 5350
Wire Wire Line
	5100 5350 5200 5350
Wire Wire Line
	4600 5000 4600 5550
Wire Wire Line
	4600 5750 5000 5750
Connection ~ 5000 5750
Wire Wire Line
	5000 5750 5000 5700
$Comp
L fft8051:RES_0603 R19
U 1 1 5EC09C37
P 5000 4100
F 0 "R19" V 5100 4150 50  0000 L CNN
F 1 "RES_0603" V 5175 4188 50  0001 L CNN
F 2 "fft8051:0603" H 5000 4100 50  0001 C CNN
F 3 "" H 5000 4100 50  0001 C CNN
F 4 "0.08R" V 5200 4150 50  0000 L CNN "Resistance"
	1    5000 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 4450 5000 4500
Wire Wire Line
	4450 4700 4450 4050
Wire Wire Line
	4450 4050 4600 4050
Wire Wire Line
	5000 4050 5000 4100
Connection ~ 5000 4050
Wire Wire Line
	4600 4800 4600 4500
Wire Wire Line
	4600 4500 5000 4500
Connection ~ 5000 4500
Wire Wire Line
	5000 4500 5000 4600
$Comp
L fft8051:CAP_0603 C7
U 1 1 5EC0CA67
P 4400 5150
F 0 "C7" H 4200 5100 50  0000 L CNN
F 1 "CAP_0603" H 3900 5000 50  0000 L CNN
F 2 "fft8051:0603" H 4400 5150 50  0001 C CNN
F 3 "" H 4400 5150 50  0001 C CNN
F 4 "0.47uF" H 4050 4900 50  0000 L CNN "Capacitance"
	1    4400 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 4700 4400 4700
Wire Wire Line
	4250 4800 4600 4800
Wire Wire Line
	4250 5000 4600 5000
Wire Wire Line
	4400 5150 4400 4700
Connection ~ 4400 4700
Wire Wire Line
	4400 4700 4450 4700
Wire Wire Line
	4400 5400 4400 5550
Wire Wire Line
	4400 5550 4600 5550
Connection ~ 4600 5550
Wire Wire Line
	4600 5550 4600 5750
$Comp
L fft8051:SDR1006-220ML L1
U 1 1 5ECA55EE
P 5850 5350
F 0 "L1" H 6150 5575 50  0000 C CNN
F 1 "SDR1006-220ML" H 6150 5484 50  0000 C CNN
F 2 "fft8051:SDR1006-220ML" H 5850 5350 50  0001 C CNN
F 3 "" H 5850 5350 50  0001 C CNN
	1    5850 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 5350 5300 5350
Connection ~ 5300 5350
$Comp
L power:+3.3V #PWR0135
U 1 1 5ECEC844
P 6700 5200
F 0 "#PWR0135" H 6700 5050 50  0001 C CNN
F 1 "+3.3V" H 6715 5373 50  0000 C CNN
F 2 "" H 6700 5200 50  0001 C CNN
F 3 "" H 6700 5200 50  0001 C CNN
	1    6700 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 5350 6700 5350
Wire Wire Line
	6700 5350 6700 5200
$Comp
L fft8051:T55B686M6R3C0070 C8
U 1 1 5ECEF581
P 5400 3600
F 0 "C8" H 5488 3521 50  0000 L CNN
F 1 "T55B686M6R3C0070" H 5550 3100 50  0001 L CNN
F 2 "fft8051:T55B686M6R3C0070" H 5400 3600 50  0001 C CNN
F 3 "" H 5400 3600 50  0001 C CNN
F 4 "68uF" H 5500 3400 50  0000 C CNN "Capacitance"
	1    5400 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 3500 5000 3550
Wire Wire Line
	5400 3600 5400 3550
Wire Wire Line
	5400 3550 5000 3550
Connection ~ 5000 3550
Wire Wire Line
	5000 3550 5000 4050
Wire Wire Line
	5700 3600 5700 3550
Wire Wire Line
	5700 3550 5400 3550
Connection ~ 5400 3550
$Comp
L power:GNDREF #PWR0136
U 1 1 5ECF7A65
P 5400 3900
F 0 "#PWR0136" H 5400 3650 50  0001 C CNN
F 1 "GNDREF" H 5405 3727 50  0000 C CNN
F 2 "" H 5400 3900 50  0001 C CNN
F 3 "" H 5400 3900 50  0001 C CNN
	1    5400 3900
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0137
U 1 1 5ECF81DF
P 5700 3900
F 0 "#PWR0137" H 5700 3650 50  0001 C CNN
F 1 "GNDREF" H 5705 3727 50  0000 C CNN
F 2 "" H 5700 3900 50  0001 C CNN
F 3 "" H 5700 3900 50  0001 C CNN
	1    5700 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3900 5700 3850
Wire Wire Line
	5400 3900 5400 3850
Wire Wire Line
	6700 5350 6700 5400
Connection ~ 6700 5350
Wire Wire Line
	6700 5400 7000 5400
Wire Wire Line
	7600 5400 7600 5450
Connection ~ 6700 5400
Wire Wire Line
	6700 5400 6700 5450
Wire Wire Line
	7300 5450 7300 5400
Connection ~ 7300 5400
Wire Wire Line
	7300 5400 7600 5400
Wire Wire Line
	7000 5450 7000 5400
Connection ~ 7000 5400
Wire Wire Line
	7000 5400 7300 5400
Wire Wire Line
	6700 5700 6700 5750
Wire Wire Line
	6700 5750 7000 5750
Wire Wire Line
	7600 5750 7600 5700
Wire Wire Line
	7300 5700 7300 5750
Connection ~ 7300 5750
Wire Wire Line
	7300 5750 7600 5750
Wire Wire Line
	7000 5700 7000 5750
Connection ~ 7000 5750
Wire Wire Line
	7000 5750 7300 5750
$Comp
L power:GNDREF #PWR0138
U 1 1 5ED0311B
P 6700 5800
F 0 "#PWR0138" H 6700 5550 50  0001 C CNN
F 1 "GNDREF" H 6705 5627 50  0000 C CNN
F 2 "" H 6700 5800 50  0001 C CNN
F 3 "" H 6700 5800 50  0001 C CNN
	1    6700 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 5800 6700 5750
Connection ~ 6700 5750
$Comp
L fft8051:T55B686M6R3C0070 C9
U 1 1 5ED0C55D
P 5700 3600
F 0 "C9" H 5788 3521 50  0000 L CNN
F 1 "T55B686M6R3C0070" H 5850 3100 50  0001 L CNN
F 2 "fft8051:T55B686M6R3C0070" H 5700 3600 50  0001 C CNN
F 3 "" H 5700 3600 50  0001 C CNN
F 4 "68uF" H 5800 3400 50  0000 C CNN "Capacitance"
	1    5700 3600
	1    0    0    -1  
$EndComp
$Comp
L fft8051:T55B686M6R3C0070 C10
U 1 1 5ED0CB5E
P 6700 5450
F 0 "C10" H 6788 5371 50  0000 L CNN
F 1 "T55B686M6R3C0070" H 6850 4950 50  0001 L CNN
F 2 "fft8051:T55B686M6R3C0070" H 6700 5450 50  0001 C CNN
F 3 "" H 6700 5450 50  0001 C CNN
F 4 "68uF" H 6800 5250 50  0000 C CNN "Capacitance"
	1    6700 5450
	1    0    0    -1  
$EndComp
$Comp
L fft8051:T55B686M6R3C0070 C11
U 1 1 5ED0D66B
P 7000 5450
F 0 "C11" H 7088 5371 50  0000 L CNN
F 1 "T55B686M6R3C0070" H 7150 4950 50  0001 L CNN
F 2 "fft8051:T55B686M6R3C0070" H 7000 5450 50  0001 C CNN
F 3 "" H 7000 5450 50  0001 C CNN
F 4 "68uF" H 7100 5250 50  0000 C CNN "Capacitance"
	1    7000 5450
	1    0    0    -1  
$EndComp
$Comp
L fft8051:T55B686M6R3C0070 C12
U 1 1 5ED0DE6A
P 7300 5450
F 0 "C12" H 7388 5371 50  0000 L CNN
F 1 "T55B686M6R3C0070" H 7450 4950 50  0001 L CNN
F 2 "fft8051:T55B686M6R3C0070" H 7300 5450 50  0001 C CNN
F 3 "" H 7300 5450 50  0001 C CNN
F 4 "68uF" H 7400 5250 50  0000 C CIN "Capacitance"
	1    7300 5450
	1    0    0    -1  
$EndComp
$Comp
L fft8051:T55B686M6R3C0070 C13
U 1 1 5ED0E537
P 7600 5450
F 0 "C13" H 7688 5371 50  0000 L CNN
F 1 "T55B686M6R3C0070" H 7750 4950 50  0001 L CNN
F 2 "fft8051:T55B686M6R3C0070" H 7600 5450 50  0001 C CNN
F 3 "" H 7600 5450 50  0001 C CNN
F 4 "68uF" H 7700 5250 50  0000 C CNN "Capacitance"
	1    7600 5450
	1    0    0    -1  
$EndComp
$Comp
L fft8051:CAP_0603 C14
U 1 1 5ED611B0
P 1100 5100
F 0 "C14" H 1198 5066 50  0000 L CNN
F 1 "CAP_0603" H 1198 4975 50  0000 L CNN
F 2 "fft8051:0603" H 1100 5100 50  0001 C CNN
F 3 "" H 1100 5100 50  0001 C CNN
F 4 "100nF" H 1198 4884 50  0000 L CNN "Capacitance"
	1    1100 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4700 1100 4700
Wire Wire Line
	1100 4700 1100 5100
$Comp
L power:GNDREF #PWR0139
U 1 1 5ED65416
P 1100 5500
F 0 "#PWR0139" H 1100 5250 50  0001 C CNN
F 1 "GNDREF" H 1105 5327 50  0000 C CNN
F 2 "" H 1100 5500 50  0001 C CNN
F 3 "" H 1100 5500 50  0001 C CNN
	1    1100 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 5350 1100 5500
$Comp
L power:+3.3V #PWR0140
U 1 1 5ED67217
P 1900 4500
F 0 "#PWR0140" H 1900 4350 50  0001 C CNN
F 1 "+3.3V" H 1915 4673 50  0000 C CNN
F 2 "" H 1900 4500 50  0001 C CNN
F 3 "" H 1900 4500 50  0001 C CNN
	1    1900 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 5000 1900 5000
Wire Wire Line
	1900 5000 1900 4500
$Comp
L power:GNDREF #PWR0141
U 1 1 5ED6A1DA
P 1750 5500
F 0 "#PWR0141" H 1750 5250 50  0001 C CNN
F 1 "GNDREF" H 1755 5327 50  0000 C CNN
F 2 "" H 1750 5500 50  0001 C CNN
F 3 "" H 1750 5500 50  0001 C CNN
	1    1750 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 4900 1750 4900
Wire Wire Line
	1750 4900 1750 5500
Wire Wire Line
	1200 4800 2050 4800
Text Label 1200 4800 0    50   ~ 0
SHDN
$Comp
L fft8051:RES_0603 R18
U 1 1 5ED6EE1B
P 4600 4100
F 0 "R18" V 4700 4150 50  0000 L CNN
F 1 "RES_0603" V 4775 4188 50  0001 L CNN
F 2 "fft8051:0603" H 4600 4100 50  0001 C CNN
F 3 "" H 4600 4100 50  0001 C CNN
F 4 "0.08R" V 4800 4150 50  0000 L CNN "Resistance"
	1    4600 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 4450 4600 4500
Connection ~ 4600 4500
Wire Wire Line
	4600 4100 4600 4050
Connection ~ 4600 4050
Wire Wire Line
	4600 4050 5000 4050
Text Label 1950 2000 0    50   ~ 0
SHDN
Wire Notes Line
	800  650  800  2950
Wire Notes Line
	800  2950 4150 2950
Wire Notes Line
	4150 2950 4150 650 
Wire Notes Line
	4150 650  800  650 
Wire Notes Line
	800  3200 800  6150
Wire Notes Line
	800  6150 7900 6150
Wire Notes Line
	7900 6150 7900 3200
Wire Notes Line
	800  3200 7900 3200
Text Notes 800  3200 0    50   ~ 0
SMPS
Text Notes 800  650  0    50   ~ 0
MCU and LEDs
$Comp
L fft8051:TPS73133DBVR U8
U 1 1 5EAF2E46
P 5200 1300
F 0 "U8" H 5550 1525 50  0000 C CNN
F 1 "TPS73133DBVR" H 5550 1434 50  0000 C CNN
F 2 "fft8051:TPS73133DBVR" H 5200 1300 50  0001 C CNN
F 3 "" H 5200 1300 50  0001 C CNN
	1    5200 1300
	1    0    0    -1  
$EndComp
$Comp
L fft8051:CAP_0603 C16
U 1 1 5EAF3C1D
P 6050 1550
F 0 "C16" H 6148 1516 50  0000 L CNN
F 1 "CAP_0603" H 6148 1425 50  0000 L CNN
F 2 "fft8051:0603" H 6050 1550 50  0001 C CNN
F 3 "" H 6050 1550 50  0001 C CNN
F 4 "100nF" H 6148 1334 50  0000 L CNN "Capacitance"
	1    6050 1550
	1    0    0    -1  
$EndComp
$Comp
L fft8051:CAP_0603 C17
U 1 1 5EAF5412
P 6650 1350
F 0 "C17" H 6748 1316 50  0000 L CNN
F 1 "CAP_0603" H 6748 1225 50  0000 L CNN
F 2 "fft8051:0603" H 6650 1350 50  0001 C CNN
F 3 "" H 6650 1350 50  0001 C CNN
F 4 "100nF" H 6748 1134 50  0000 L CNN "Capacitance"
	1    6650 1350
	1    0    0    -1  
$EndComp
$Comp
L fft8051:CAP_0603 C15
U 1 1 5EAF5C1D
P 4700 1450
F 0 "C15" H 4798 1416 50  0000 L CNN
F 1 "CAP_0603" H 4798 1325 50  0000 L CNN
F 2 "fft8051:0603" H 4700 1450 50  0001 C CNN
F 3 "" H 4700 1450 50  0001 C CNN
F 4 "100nF" H 4798 1234 50  0000 L CNN "Capacitance"
	1    4700 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1300 4700 1450
Wire Wire Line
	5200 1450 5050 1450
Wire Wire Line
	5050 1450 5050 1300
Wire Wire Line
	5050 1300 4700 1300
Wire Wire Line
	5900 1450 6050 1450
Wire Wire Line
	6050 1450 6050 1550
Wire Wire Line
	5900 1300 6350 1300
Wire Wire Line
	6650 1300 6650 1350
$Comp
L power:GNDREF #PWR0131
U 1 1 5EB030D2
P 4700 1750
F 0 "#PWR0131" H 4700 1500 50  0001 C CNN
F 1 "GNDREF" H 4705 1577 50  0000 C CNN
F 2 "" H 4700 1750 50  0001 C CNN
F 3 "" H 4700 1750 50  0001 C CNN
	1    4700 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0142
U 1 1 5EB03D2C
P 5550 1800
F 0 "#PWR0142" H 5550 1550 50  0001 C CNN
F 1 "GNDREF" H 5555 1627 50  0000 C CNN
F 2 "" H 5550 1800 50  0001 C CNN
F 3 "" H 5550 1800 50  0001 C CNN
	1    5550 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1750 4700 1700
Wire Wire Line
	5550 1800 5550 1750
Wire Wire Line
	6050 1850 6050 1800
Wire Wire Line
	6650 1650 6650 1600
$Comp
L power:+3.3VA #PWR0143
U 1 1 5EB0F47A
P 6350 1200
F 0 "#PWR0143" H 6350 1050 50  0001 C CNN
F 1 "+3.3VA" H 6365 1373 50  0000 C CNN
F 2 "" H 6350 1200 50  0001 C CNN
F 3 "" H 6350 1200 50  0001 C CNN
	1    6350 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 1300 6350 1200
Connection ~ 6350 1300
Wire Wire Line
	6350 1300 6650 1300
$Comp
L power:+BATT #PWR0144
U 1 1 5EB12797
P 4700 1250
F 0 "#PWR0144" H 4700 1100 50  0001 C CNN
F 1 "+BATT" H 4715 1423 50  0000 C CNN
F 2 "" H 4700 1250 50  0001 C CNN
F 3 "" H 4700 1250 50  0001 C CNN
	1    4700 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 1300 4700 1250
Connection ~ 4700 1300
Wire Notes Line
	4450 650  4450 2950
Wire Notes Line
	4450 2950 7400 2950
Wire Notes Line
	7400 2950 7400 650 
Wire Notes Line
	7400 650  4450 650 
Text Notes 4450 650  0    50   ~ 0
LDO 
Text Notes 5200 900  0    50   ~ 0
30mV Dropout
$Comp
L power:GNDA #PWR0145
U 1 1 5EB25CAB
P 6650 1650
F 0 "#PWR0145" H 6650 1400 50  0001 C CNN
F 1 "GNDA" H 6655 1477 50  0000 C CNN
F 2 "" H 6650 1650 50  0001 C CNN
F 3 "" H 6650 1650 50  0001 C CNN
	1    6650 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0146
U 1 1 5EB2E5EF
P 6050 1850
F 0 "#PWR0146" H 6050 1600 50  0001 C CNN
F 1 "GNDREF" H 6055 1677 50  0000 C CNN
F 2 "" H 6050 1850 50  0001 C CNN
F 3 "" H 6050 1850 50  0001 C CNN
	1    6050 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0147
U 1 1 5EB319D4
P 3600 1600
F 0 "#PWR0147" H 3600 1350 50  0001 C CNN
F 1 "GNDA" H 3605 1427 50  0000 C CNN
F 2 "" H 3600 1600 50  0001 C CNN
F 3 "" H 3600 1600 50  0001 C CNN
	1    3600 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0148
U 1 1 5EB32BE1
P 10450 2250
F 0 "#PWR0148" H 10450 2000 50  0001 C CNN
F 1 "GNDA" H 10455 2077 50  0000 C CNN
F 2 "" H 10450 2250 50  0001 C CNN
F 3 "" H 10450 2250 50  0001 C CNN
	1    10450 2250
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0149
U 1 1 5EB3618F
P 10000 2250
F 0 "#PWR0149" H 10000 2000 50  0001 C CNN
F 1 "GNDREF" H 10005 2077 50  0000 C CNN
F 2 "" H 10000 2250 50  0001 C CNN
F 3 "" H 10000 2250 50  0001 C CNN
	1    10000 2250
	1    0    0    -1  
$EndComp
$Comp
L fft8051:RES_0603 R20
U 1 1 5EB36C0F
P 10050 2100
F 0 "R20" H 10150 2300 50  0000 L CNN
F 1 "RES_0603" V 10225 2188 50  0001 L CNN
F 2 "fft8051:0603" H 10050 2100 50  0001 C CNN
F 3 "" H 10050 2100 50  0001 C CNN
F 4 "0R" H 10150 2200 50  0000 L CNN "Resistance"
	1    10050 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 2100 10000 2100
Wire Wire Line
	10000 2100 10000 2250
Wire Wire Line
	10400 2100 10450 2100
Wire Wire Line
	10450 2100 10450 2250
$Comp
L power:GNDREF #PWR0150
U 1 1 5EB4A3A8
P 8200 2200
F 0 "#PWR0150" H 8200 1950 50  0001 C CNN
F 1 "GNDREF" H 8205 2027 50  0000 C CNN
F 2 "" H 8200 2200 50  0001 C CNN
F 3 "" H 8200 2200 50  0001 C CNN
	1    8200 2200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0151
U 1 1 5EB4AFD6
P 8700 2200
F 0 "#PWR0151" H 8700 1950 50  0001 C CNN
F 1 "GNDA" H 8705 2027 50  0000 C CNN
F 2 "" H 8700 2200 50  0001 C CNN
F 3 "" H 8700 2200 50  0001 C CNN
	1    8700 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 2100 8200 2150
Wire Wire Line
	8200 2150 8450 2150
Wire Wire Line
	8450 2150 8450 2100
Connection ~ 8200 2150
Wire Wire Line
	8200 2150 8200 2200
Wire Wire Line
	8700 2100 8700 2150
Wire Wire Line
	8700 2150 8950 2150
Wire Wire Line
	8950 2150 8950 2100
Connection ~ 8700 2150
Wire Wire Line
	8700 2150 8700 2200
$Comp
L power:+3.3VA #PWR0152
U 1 1 5EB61D09
P 8700 1500
F 0 "#PWR0152" H 8700 1350 50  0001 C CNN
F 1 "+3.3VA" H 8715 1673 50  0000 C CNN
F 2 "" H 8700 1500 50  0001 C CNN
F 3 "" H 8700 1500 50  0001 C CNN
	1    8700 1500
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0153
U 1 1 5EB62420
P 8200 1500
F 0 "#PWR0153" H 8200 1350 50  0001 C CNN
F 1 "+3.3V" H 8215 1673 50  0000 C CNN
F 2 "" H 8200 1500 50  0001 C CNN
F 3 "" H 8200 1500 50  0001 C CNN
	1    8200 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1600 8200 1550
Wire Wire Line
	8200 1550 8450 1550
Wire Wire Line
	8450 1550 8450 1600
Connection ~ 8200 1550
Wire Wire Line
	8200 1550 8200 1500
Wire Wire Line
	8700 1500 8700 1550
Wire Wire Line
	8700 1550 8950 1550
Wire Wire Line
	8950 1550 8950 1600
Connection ~ 8700 1550
Wire Wire Line
	8700 1550 8700 1600
$Comp
L power:+BATT #PWR0154
U 1 1 5EB7085F
P 9200 1500
F 0 "#PWR0154" H 9200 1350 50  0001 C CNN
F 1 "+BATT" H 9215 1673 50  0000 C CNN
F 2 "" H 9200 1500 50  0001 C CNN
F 3 "" H 9200 1500 50  0001 C CNN
	1    9200 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 1500 9200 1550
Wire Wire Line
	9200 1550 9500 1550
Wire Wire Line
	9500 1550 9500 1600
Connection ~ 9200 1550
Wire Wire Line
	9200 1550 9200 1600
$Comp
L fft8051:Connector J1
U 1 1 5EB835F4
P 10050 1250
F 0 "J1" H 10328 1251 50  0000 L CNN
F 1 "Connector" H 10328 1160 50  0000 L CNN
F 2 "fft8051:Connector" H 10050 1250 50  0001 C CNN
F 3 "" H 10050 1250 50  0001 C CNN
	1    10050 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR0155
U 1 1 5EB8421D
P 10000 1200
F 0 "#PWR0155" H 10000 1050 50  0001 C CNN
F 1 "+BATT" H 10015 1373 50  0000 C CNN
F 2 "" H 10000 1200 50  0001 C CNN
F 3 "" H 10000 1200 50  0001 C CNN
	1    10000 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDREF #PWR0156
U 1 1 5EB8480B
P 10000 1400
F 0 "#PWR0156" H 10000 1150 50  0001 C CNN
F 1 "GNDREF" H 10005 1227 50  0000 C CNN
F 2 "" H 10000 1400 50  0001 C CNN
F 3 "" H 10000 1400 50  0001 C CNN
	1    10000 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10050 1350 10000 1350
Wire Wire Line
	10000 1350 10000 1400
Wire Wire Line
	10050 1250 10000 1250
Wire Wire Line
	10000 1250 10000 1200
Wire Notes Line
	7750 650  7750 2950
Wire Notes Line
	7750 2950 10900 2950
Wire Notes Line
	10900 2950 10900 650 
Wire Notes Line
	10900 650  7750 650 
Text Notes 7750 650  0    50   ~ 0
Test
$Comp
L fft8051:TestPoints T1
U 1 1 5EBF93FE
P 8200 1600
F 0 "T1" V 8292 1688 50  0000 L CNN
F 1 "TestPoints" H 8100 1350 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8200 1600 50  0001 C CNN
F 3 "" H 8200 1600 50  0001 C CNN
	1    8200 1600
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T2
U 1 1 5EBF9C3B
P 8450 1600
F 0 "T2" V 8542 1688 50  0000 L CNN
F 1 "TestPoints" H 8350 1350 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8450 1600 50  0001 C CNN
F 3 "" H 8450 1600 50  0001 C CNN
	1    8450 1600
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T3
U 1 1 5EBF9EED
P 8700 1600
F 0 "T3" V 8792 1688 50  0000 L CNN
F 1 "TestPoints" H 8600 1350 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8700 1600 50  0001 C CNN
F 3 "" H 8700 1600 50  0001 C CNN
	1    8700 1600
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T4
U 1 1 5EBFA049
P 8950 1600
F 0 "T4" V 9042 1688 50  0000 L CNN
F 1 "TestPoints" H 8850 1350 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8950 1600 50  0001 C CNN
F 3 "" H 8950 1600 50  0001 C CNN
	1    8950 1600
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T5
U 1 1 5EBFA23D
P 9200 1600
F 0 "T5" V 9292 1688 50  0000 L CNN
F 1 "TestPoints" H 9100 1350 50  0001 C CNN
F 2 "fft8051:TestPoint" H 9200 1600 50  0001 C CNN
F 3 "" H 9200 1600 50  0001 C CNN
	1    9200 1600
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T6
U 1 1 5EBFA53B
P 9500 1600
F 0 "T6" V 9592 1688 50  0000 L CNN
F 1 "TestPoints" H 9400 1350 50  0001 C CNN
F 2 "fft8051:TestPoint" H 9500 1600 50  0001 C CNN
F 3 "" H 9500 1600 50  0001 C CNN
	1    9500 1600
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T7
U 1 1 5EBFA6D0
P 8200 2100
F 0 "T7" V 8292 2022 50  0000 R CNN
F 1 "TestPoints" H 8100 1850 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8200 2100 50  0001 C CNN
F 3 "" H 8200 2100 50  0001 C CNN
	1    8200 2100
	0    -1   -1   0   
$EndComp
$Comp
L fft8051:TestPoints T8
U 1 1 5EBFB37F
P 8450 2100
F 0 "T8" V 8542 2022 50  0000 R CNN
F 1 "TestPoints" H 8350 1850 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8450 2100 50  0001 C CNN
F 3 "" H 8450 2100 50  0001 C CNN
	1    8450 2100
	0    -1   -1   0   
$EndComp
$Comp
L fft8051:TestPoints T9
U 1 1 5EBFB6B6
P 8700 2100
F 0 "T9" V 8792 2022 50  0000 R CNN
F 1 "TestPoints" H 8600 1850 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8700 2100 50  0001 C CNN
F 3 "" H 8700 2100 50  0001 C CNN
	1    8700 2100
	0    -1   -1   0   
$EndComp
$Comp
L fft8051:TestPoints T10
U 1 1 5EBFBA39
P 8950 2100
F 0 "T10" V 9042 2022 50  0000 R CNN
F 1 "TestPoints" H 8850 1850 50  0001 C CNN
F 2 "fft8051:TestPoint" H 8950 2100 50  0001 C CNN
F 3 "" H 8950 2100 50  0001 C CNN
	1    8950 2100
	0    -1   -1   0   
$EndComp
$Comp
L fft8051:MCP601RT-E_OT U9
U 1 1 5EC66FC0
P 9300 4250
F 0 "U9" H 9350 4200 50  0000 L CNN
F 1 "MCP601RT-E_OT" H 9550 4100 50  0000 L CNN
F 2 "fft8051:MCP601RT" H 9300 4250 50  0001 C CNN
F 3 "" H 9300 4250 50  0001 C CNN
	1    9300 4250
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3VA #PWR0157
U 1 1 5EC689E3
P 9500 3600
F 0 "#PWR0157" H 9500 3450 50  0001 C CNN
F 1 "+3.3VA" H 9515 3773 50  0000 C CNN
F 2 "" H 9500 3600 50  0001 C CNN
F 3 "" H 9500 3600 50  0001 C CNN
	1    9500 3600
	1    0    0    -1  
$EndComp
$Comp
L fft8051:CAP_0603 C18
U 1 1 5EC699B9
P 9750 3750
F 0 "C18" H 9848 3716 50  0000 L CNN
F 1 "CAP_0603" H 9848 3625 50  0000 L CNN
F 2 "fft8051:0603" H 9750 3750 50  0001 C CNN
F 3 "" H 9750 3750 50  0001 C CNN
F 4 "100nF" H 9848 3534 50  0000 L CNN "Capacitance"
	1    9750 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0158
U 1 1 5EC6BBB7
P 9750 4100
F 0 "#PWR0158" H 9750 3850 50  0001 C CNN
F 1 "GNDA" H 9755 3927 50  0000 C CNN
F 2 "" H 9750 4100 50  0001 C CNN
F 3 "" H 9750 4100 50  0001 C CNN
	1    9750 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 3750 9750 3700
Wire Wire Line
	9750 3700 9500 3700
Connection ~ 9500 3700
Wire Wire Line
	9500 3700 9500 4300
Wire Wire Line
	9750 4100 9750 4000
$Comp
L power:GNDA #PWR0159
U 1 1 5EC7DC50
P 9500 4900
F 0 "#PWR0159" H 9500 4650 50  0001 C CNN
F 1 "GNDA" H 9505 4727 50  0000 C CNN
F 2 "" H 9500 4900 50  0001 C CNN
F 3 "" H 9500 4900 50  0001 C CNN
	1    9500 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 4900 9500 4800
$Comp
L fft8051:ABM-714-RC M1
U 1 1 5EB10F1A
P 8300 5400
F 0 "M1" H 8398 5296 50  0000 L CNN
F 1 "ABM-714-RC" H 8398 5205 50  0000 L CNN
F 2 "fft8051:ABM-714-RC" H 8300 5400 50  0001 C CNN
F 3 "" H 8300 5400 50  0001 C CNN
	1    8300 5400
	1    0    0    -1  
$EndComp
$Comp
L fft8051:RES_0603 R23
U 1 1 5EB5E63B
P 8300 4800
F 0 "R23" V 8384 4888 50  0000 L CNN
F 1 "RES_0603" V 8475 4888 50  0000 L CNN
F 2 "fft8051:0603" H 8300 4800 50  0001 C CNN
F 3 "" H 8300 4800 50  0001 C CNN
F 4 "13.7K" V 8566 4888 50  0000 L CNN "Resistance"
	1    8300 4800
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR0160
U 1 1 5EB60A3D
P 8300 5750
F 0 "#PWR0160" H 8300 5500 50  0001 C CNN
F 1 "GNDA" H 8305 5577 50  0000 C CNN
F 2 "" H 8300 5750 50  0001 C CNN
F 3 "" H 8300 5750 50  0001 C CNN
	1    8300 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 5700 8300 5750
$Comp
L fft8051:CAP_0603 C19
U 1 1 5EB766C9
P 8900 5200
F 0 "C19" V 8800 5050 50  0000 C CNN
F 1 "CAP_0603" V 9150 5100 50  0000 C CNN
F 2 "fft8051:0603" H 8900 5200 50  0001 C CNN
F 3 "" H 8900 5200 50  0001 C CNN
F 4 "2.2uF" V 9050 5100 50  0000 C CNN "Capacitance"
	1    8900 5200
	0    1    1    0   
$EndComp
Wire Wire Line
	9200 4650 9150 4650
$Comp
L fft8051:CAP_0603 C20
U 1 1 5EB8D0BC
P 9650 5350
F 0 "C20" V 9550 5250 50  0000 C CNN
F 1 "CAP_0603" V 9900 5250 50  0000 C CNN
F 2 "fft8051:0603" H 9650 5350 50  0001 C CNN
F 3 "" H 9650 5350 50  0001 C CNN
F 4 "15pF" V 9800 5250 50  0000 C CNN "Capacitance"
	1    9650 5350
	0    1    1    0   
$EndComp
$Comp
L fft8051:RES_0603 R25
U 1 1 5EB8E66B
P 9700 5800
F 0 "R25" H 9900 5750 50  0000 C CNN
F 1 "RES_0603" H 9850 6000 50  0000 C CNN
F 2 "fft8051:0603" H 9700 5800 50  0001 C CNN
F 3 "" H 9700 5800 50  0001 C CNN
F 4 "220K" H 9900 5900 50  0000 C CNN "Resistance"
	1    9700 5800
	-1   0    0    1   
$EndComp
Wire Wire Line
	9350 5800 9150 5800
$Comp
L fft8051:RES_0603 R24
U 1 1 5EBA67C8
P 10100 4950
F 0 "R24" H 10250 5050 50  0000 C CNN
F 1 "RES_0603" H 10300 4750 50  0000 C CNN
F 2 "fft8051:0603" H 10100 4950 50  0001 C CNN
F 3 "" H 10100 4950 50  0001 C CNN
F 4 "150R" H 10300 4850 50  0000 C CNN "Resistance"
	1    10100 4950
	1    0    0    -1  
$EndComp
$Comp
L fft8051:CAP_0603 C21
U 1 1 5EBA7051
P 10550 5350
F 0 "C21" H 10350 5300 50  0000 C CNN
F 1 "CAP_0603" H 10200 5100 50  0000 C CNN
F 2 "fft8051:0603" H 10550 5350 50  0001 C CNN
F 3 "" H 10550 5350 50  0001 C CNN
F 4 "100nF" H 10300 5200 50  0000 C CNN "Capacitance"
	1    10550 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 4550 9800 4550
Wire Wire Line
	9900 5800 9700 5800
Wire Wire Line
	10100 4950 9900 4950
Connection ~ 9900 4950
Wire Wire Line
	9900 4950 9900 4550
Wire Wire Line
	10450 4950 10550 4950
Wire Wire Line
	10550 4950 10550 5350
Wire Wire Line
	10550 5600 10550 5700
$Comp
L power:GNDA #PWR0161
U 1 1 5EBC4BB6
P 10550 5700
F 0 "#PWR0161" H 10550 5450 50  0001 C CNN
F 1 "GNDA" H 10555 5527 50  0000 C CNN
F 2 "" H 10550 5700 50  0001 C CNN
F 3 "" H 10550 5700 50  0001 C CNN
	1    10550 5700
	1    0    0    -1  
$EndComp
$Comp
L fft8051:CAP_0603 C22
U 1 1 5EBC7624
P 8650 4250
F 0 "C22" H 8500 4250 50  0000 C CNN
F 1 "CAP_0603" H 8350 3950 50  0001 C CNN
F 2 "fft8051:0603" H 8650 4250 50  0001 C CNN
F 3 "" H 8650 4250 50  0001 C CNN
F 4 "2.2uF" H 8450 4150 50  0000 C CNN "Capacitance"
	1    8650 4250
	1    0    0    -1  
$EndComp
$Comp
L fft8051:RES_0603 R22
U 1 1 5EBCAD37
P 8850 4150
F 0 "R22" V 8950 4200 50  0000 L CNN
F 1 "RES_0603" V 9050 4250 50  0001 L CNN
F 2 "fft8051:0603" H 8850 4150 50  0001 C CNN
F 3 "" H 8850 4150 50  0001 C CNN
F 4 "100K" V 9050 4200 50  0000 L CNN "Resistance"
	1    8850 4150
	0    1    1    0   
$EndComp
$Comp
L fft8051:RES_0603 R21
U 1 1 5EBCB686
P 8850 3650
F 0 "R21" V 8979 3738 50  0000 L CNN
F 1 "RES_0603" V 9025 3738 50  0001 L CNN
F 2 "fft8051:0603" H 8850 3650 50  0001 C CNN
F 3 "" H 8850 3650 50  0001 C CNN
F 4 "100K" V 9070 3738 50  0000 L CNN "Resistance"
	1    8850 3650
	0    1    1    0   
$EndComp
$Comp
L power:+3.3VA #PWR0162
U 1 1 5EBD3880
P 8300 4750
F 0 "#PWR0162" H 8300 4600 50  0001 C CNN
F 1 "+3.3VA" H 8315 4923 50  0000 C CNN
F 2 "" H 8300 4750 50  0001 C CNN
F 3 "" H 8300 4750 50  0001 C CNN
	1    8300 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 4800 8300 4750
$Comp
L power:GNDA #PWR0163
U 1 1 5EBF07E7
P 8750 4600
F 0 "#PWR0163" H 8750 4350 50  0001 C CNN
F 1 "GNDA" H 8755 4427 50  0000 C CNN
F 2 "" H 8750 4600 50  0001 C CNN
F 3 "" H 8750 4600 50  0001 C CNN
	1    8750 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4500 8650 4550
Wire Wire Line
	8650 4550 8750 4550
Wire Wire Line
	8850 4550 8850 4500
Wire Wire Line
	8750 4600 8750 4550
Connection ~ 8750 4550
Wire Wire Line
	8750 4550 8850 4550
Wire Wire Line
	8650 4250 8650 4100
Wire Wire Line
	8650 4100 8850 4100
Wire Wire Line
	8850 4100 8850 4150
Connection ~ 8850 4100
$Comp
L power:+3.3VA #PWR0164
U 1 1 5EC46D2E
P 8850 3600
F 0 "#PWR0164" H 8850 3450 50  0001 C CNN
F 1 "+3.3VA" H 8865 3773 50  0000 C CNN
F 2 "" H 8850 3600 50  0001 C CNN
F 3 "" H 8850 3600 50  0001 C CNN
	1    8850 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 4000 8850 4050
Wire Wire Line
	8850 4050 9150 4050
Wire Wire Line
	9150 4050 9150 4450
Wire Wire Line
	9150 4450 9200 4450
Connection ~ 8850 4050
Wire Wire Line
	8850 4050 8850 4100
Wire Wire Line
	9500 3600 9500 3700
Wire Wire Line
	8850 3650 8850 3600
Wire Wire Line
	8300 5150 8300 5200
Wire Wire Line
	8900 5200 9150 5200
Connection ~ 9150 5200
Wire Wire Line
	9150 5200 9150 4650
Wire Wire Line
	8650 5200 8300 5200
Connection ~ 8300 5200
Wire Wire Line
	8300 5200 8300 5400
Wire Notes Line
	8100 3200 8100 6150
Wire Notes Line
	8100 6150 10900 6150
Wire Notes Line
	10900 6150 10900 3200
Wire Notes Line
	10900 3200 8100 3200
Text Notes 8100 3200 0    50   ~ 0
Mic
Wire Wire Line
	9900 5350 9900 5800
Wire Wire Line
	9900 5350 9900 4950
Connection ~ 9900 5350
Wire Wire Line
	9650 5350 9900 5350
Wire Wire Line
	9150 5800 9150 5350
Wire Wire Line
	9150 5350 9150 5200
Connection ~ 9150 5350
Wire Wire Line
	9400 5350 9150 5350
$Comp
L fft8051:TestPoints T12
U 1 1 5EB5CD29
P 1200 1950
F 0 "T12" H 1500 1950 50  0000 C CNN
F 1 "TestPoints" H 1100 1700 50  0001 C CNN
F 2 "fft8051:TestPoint" H 1200 1950 50  0001 C CNN
F 3 "" H 1200 1950 50  0001 C CNN
	1    1200 1950
	-1   0    0    1   
$EndComp
$Comp
L fft8051:TestPoints T11
U 1 1 5EB65944
P 1200 1800
F 0 "T11" H 1500 1800 50  0000 C CNN
F 1 "TestPoints" H 1100 1550 50  0001 C CNN
F 2 "fft8051:TestPoint" H 1200 1800 50  0001 C CNN
F 3 "" H 1200 1800 50  0001 C CNN
	1    1200 1800
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 1500 2100 1500
Wire Wire Line
	2100 1500 2100 1800
Wire Wire Line
	2100 1800 1250 1800
Wire Wire Line
	1200 1950 1250 1950
Wire Wire Line
	1250 1950 1250 1800
Connection ~ 1250 1800
Wire Wire Line
	1250 1800 1200 1800
$Comp
L fft8051:TestPoints T13
U 1 1 5EB7CC1C
P 1200 2100
F 0 "T13" H 1500 2100 50  0000 C CNN
F 1 "TestPoints" H 1100 1850 50  0001 C CNN
F 2 "fft8051:TestPoint" H 1200 2100 50  0001 C CNN
F 3 "" H 1200 2100 50  0001 C CNN
	1    1200 2100
	-1   0    0    1   
$EndComp
$Comp
L fft8051:TestPoints T14
U 1 1 5EB7CF1A
P 1200 2250
F 0 "T14" H 1500 2250 50  0000 C CNN
F 1 "TestPoints" H 1100 2000 50  0001 C CNN
F 2 "fft8051:TestPoint" H 1200 2250 50  0001 C CNN
F 3 "" H 1200 2250 50  0001 C CNN
	1    1200 2250
	-1   0    0    1   
$EndComp
Wire Wire Line
	1200 2250 1250 2250
Wire Wire Line
	1250 2250 1250 2100
Wire Wire Line
	1250 2100 1200 2100
Text Label 10550 4950 0    50   ~ 0
ADC
Wire Wire Line
	2300 1400 2050 1400
Text Label 2050 1400 0    50   ~ 0
ADC
Text Label 1350 1800 0    50   ~ 0
MCU_RX
Text Label 1350 2100 0    50   ~ 0
MCU_TX
NoConn ~ 2300 1300
NoConn ~ 2300 1700
NoConn ~ 2300 1800
$Comp
L fft8051:MP001249 D2
U 1 1 63F10616
P 1450 6850
F 0 "D2" V 1404 6938 50  0000 L CNN
F 1 "MP001249" V 1495 6938 50  0000 L CNN
F 2 "fft8051:MP001249" H 1450 6850 50  0001 C CNN
F 3 "" H 1450 6850 50  0001 C CNN
	1    1450 6850
	0    1    1    0   
$EndComp
$Comp
L fft8051:RES_0603 R26
U 1 1 63F12DE2
P 3450 2550
F 0 "R26" V 3671 2497 50  0000 R CNN
F 1 "RES_0603" V 3625 2497 50  0001 R CNN
F 2 "fft8051:0603" H 3450 2550 50  0001 C CNN
F 3 "" H 3450 2550 50  0001 C CNN
F 4 "10K" V 3580 2497 50  0000 R CNN "Resistance"
	1    3450 2550
	0    -1   -1   0   
$EndComp
NoConn ~ 3250 2200
$Comp
L fft8051:RES_0603 R27
U 1 1 63FA99E5
P 3850 2550
F 0 "R27" V 4071 2497 50  0000 R CNN
F 1 "RES_0603" V 4025 2497 50  0001 R CNN
F 2 "fft8051:0603" H 3850 2550 50  0001 C CNN
F 3 "" H 3850 2550 50  0001 C CNN
F 4 "10K" V 3980 2497 50  0000 R CNN "Resistance"
	1    3850 2550
	0    -1   -1   0   
$EndComp
$Comp
L fft8051:RES_0603 R29
U 1 1 63FA9DCA
P 3850 2100
F 0 "R29" V 4071 2047 50  0000 R CNN
F 1 "RES_0603" V 4025 2047 50  0001 R CNN
F 2 "fft8051:0603" H 3850 2100 50  0001 C CNN
F 3 "" H 3850 2100 50  0001 C CNN
F 4 "10K" V 3980 2047 50  0000 R CNN "Resistance"
	1    3850 2100
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3VA #PWR0165
U 1 1 63FAB528
P 3850 1700
F 0 "#PWR0165" H 3850 1550 50  0001 C CNN
F 1 "+3.3VA" H 3865 1873 50  0000 C CNN
F 2 "" H 3850 1700 50  0001 C CNN
F 3 "" H 3850 1700 50  0001 C CNN
	1    3850 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 1750 3850 1700
Wire Wire Line
	3250 2000 3650 2000
Wire Wire Line
	3650 2000 3650 2150
Wire Wire Line
	3650 2150 3850 2150
Wire Wire Line
	3850 2150 3850 2100
Wire Wire Line
	3850 2200 3850 2150
Connection ~ 3850 2150
Wire Wire Line
	3250 2100 3450 2100
Wire Wire Line
	3450 2100 3450 2200
$Comp
L fft8051:TestPoints T17
U 1 1 63FD088A
P 3350 2650
F 0 "T17" V 3600 2650 50  0000 C CNN
F 1 "TestPoints" H 3250 2400 50  0001 C CNN
F 2 "fft8051:TestPoint" H 3350 2650 50  0001 C CNN
F 3 "" H 3350 2650 50  0001 C CNN
	1    3350 2650
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T18
U 1 1 63FD2900
P 3550 2650
F 0 "T18" V 3800 2650 50  0000 C CNN
F 1 "TestPoints" H 3450 2400 50  0001 C CNN
F 2 "fft8051:TestPoint" H 3550 2650 50  0001 C CNN
F 3 "" H 3550 2650 50  0001 C CNN
	1    3550 2650
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T19
U 1 1 63FD2D43
P 3750 2650
F 0 "T19" V 4000 2650 50  0000 C CNN
F 1 "TestPoints" H 3650 2400 50  0001 C CNN
F 2 "fft8051:TestPoint" H 3750 2650 50  0001 C CNN
F 3 "" H 3750 2650 50  0001 C CNN
	1    3750 2650
	0    1    1    0   
$EndComp
$Comp
L fft8051:TestPoints T20
U 1 1 63FD2FE2
P 3950 2650
F 0 "T20" V 4200 2650 50  0000 C CNN
F 1 "TestPoints" H 3850 2400 50  0001 C CNN
F 2 "fft8051:TestPoint" H 3950 2650 50  0001 C CNN
F 3 "" H 3950 2650 50  0001 C CNN
	1    3950 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 2650 3350 2600
Wire Wire Line
	3350 2600 3450 2600
Wire Wire Line
	3550 2600 3550 2650
Wire Wire Line
	3450 2550 3450 2600
Connection ~ 3450 2600
Wire Wire Line
	3450 2600 3550 2600
Wire Wire Line
	3750 2650 3750 2600
Wire Wire Line
	3750 2600 3850 2600
Wire Wire Line
	3950 2600 3950 2650
Wire Wire Line
	3850 2550 3850 2600
Connection ~ 3850 2600
Wire Wire Line
	3850 2600 3950 2600
Text Label 1950 2100 0    50   ~ 0
MCU_LED
Wire Wire Line
	1950 2000 2300 2000
Wire Wire Line
	1950 2100 2300 2100
Wire Wire Line
	2300 1600 1800 1600
Wire Wire Line
	1800 1600 1800 2100
Wire Wire Line
	1800 2100 1250 2100
Connection ~ 1250 2100
$Comp
L fft8051:RES_0603 R28
U 1 1 64069240
P 1450 7050
F 0 "R28" V 1550 7100 50  0000 L CNN
F 1 "RES_0603" V 1625 7138 50  0001 L CNN
F 2 "fft8051:0603" H 1450 7050 50  0001 C CNN
F 3 "" H 1450 7050 50  0001 C CNN
F 4 "62R" V 1650 7100 50  0000 L CNN "Resistance"
	1    1450 7050
	0    1    1    0   
$EndComp
$Comp
L power:+3.3VA #PWR0166
U 1 1 64069E0D
P 1450 6650
F 0 "#PWR0166" H 1450 6500 50  0001 C CNN
F 1 "+3.3VA" H 1465 6823 50  0000 C CNN
F 2 "" H 1450 6650 50  0001 C CNN
F 3 "" H 1450 6650 50  0001 C CNN
	1    1450 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 6700 1450 6650
Text Label 1750 7450 0    50   ~ 0
MCU_LED
Wire Wire Line
	1450 7000 1450 7050
Wire Wire Line
	1450 7400 1450 7450
Wire Wire Line
	1450 7450 1750 7450
Wire Notes Line
	800  6400 2350 6400
Wire Notes Line
	2350 6400 2350 7600
Wire Notes Line
	2350 7600 800  7600
Wire Notes Line
	800  7600 800  6400
Text Notes 800  6400 0    50   ~ 0
MCU LED
$Comp
L fft8051:TestPoints T15
U 1 1 640FEB00
P 1200 2400
F 0 "T15" H 1500 2400 50  0000 C CNN
F 1 "TestPoints" H 1100 2150 50  0001 C CNN
F 2 "fft8051:TestPoint" H 1200 2400 50  0001 C CNN
F 3 "" H 1200 2400 50  0001 C CNN
	1    1200 2400
	-1   0    0    1   
$EndComp
$Comp
L fft8051:TestPoints T16
U 1 1 640FF038
P 1200 2550
F 0 "T16" H 1500 2550 50  0000 C CNN
F 1 "TestPoints" H 1100 2300 50  0001 C CNN
F 2 "fft8051:TestPoint" H 1200 2550 50  0001 C CNN
F 3 "" H 1200 2550 50  0001 C CNN
	1    1200 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 2200 1300 2200
Wire Wire Line
	1300 2200 1300 2400
Wire Wire Line
	1300 2400 1200 2400
Wire Wire Line
	1200 2550 1400 2550
Wire Wire Line
	1400 2550 1400 2300
Wire Wire Line
	1400 2300 2300 2300
NoConn ~ 2300 2400
NoConn ~ 2300 2500
NoConn ~ 2300 2600
NoConn ~ 2300 2700
Wire Wire Line
	5200 1300 5050 1300
Connection ~ 5050 1300
Wire Wire Line
	4800 4900 4250 4900
$EndSCHEMATC
