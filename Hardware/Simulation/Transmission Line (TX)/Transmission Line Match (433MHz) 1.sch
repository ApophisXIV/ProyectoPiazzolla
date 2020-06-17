<QucsStudio Schematic 2.5.7>
<Properties>
  <View=386,-29,1804,946,0.989166,0,40>
  <Grid=10,10,1>
  <DataSet=Transmission Line Match (433MHz) 1.dat>
  <DataDisplay=Transmission Line Match (433MHz) 1.dpl>
  <OpenDisplay=1>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 730 410 0 0 0 0>
  <GND * 1 1050 410 0 0 0 0>
  <GND * 1 1210 410 0 0 0 0>
  <SPfile X1 1 730 310 -11 -36 1 2 "E:/Google Drive Sync/Electronica/Proyectos 2019/Balloon/Software/GUI/ProyectoPiazzolla/Hardware/Measurement/Transmission Line (TX)/Measurement 1/400-500MHz S11.s1p" 0 "rectangular" 0 "linear" 0 "short" 0 "no" 0 "1" 0 "block" 0 "SOT23" 0>
  <GND * 1 1520 410 0 0 0 0>
  <Eqn Pérdidas_por_retorno 1 1000 500 -29 16 0 0 "db_S11=dB(S[1,1])" 1 "yes" 0>
  <.SP SP1 1 740 490 0 60 0 0 "lin" 1 "400M" 1 "500M" 1 "101" 1 "no" 0 "1" 0 "2" 0 "none" 0>
  <SUBST FR4 1 780 710 -30 24 0 0 "4.5" 1 "1mm" 1 "35µm" 1 "0.002" 1 "1.72e-08" 1 "0.1µm" 1>
  <Pac P1 1 1520 360 18 -26 0 0 "1" 1 "37.07+59.19*i" 1 "18dBm" 0 "433MHz" 1 "26.85" 0 "SUBCLICK" 0>
  <CLIN TL1 1 840 310 -26 25 0 0 "FR4" 1 "1.85mm" 1 "0.254mm" 1 "1mm" 1 "Metal" 1 "26.85" 0>
  <CLIN TL2 1 1340 310 -26 25 0 0 "FR4" 1 "1.85mm" 1 "0.254mm" 1 "3.76mm" 1 "Metal" 1 "26.85" 0>
  <Eqn Críterio_de_aceptación_de_valores 1 1320 500 -29 16 0 0 "ok1=min(range(dB(S[1,1]),432MHz,434MHz))" 1 "yes" 0>
  <Eqn Impedancia 1 1180 500 -29 16 0 0 "Z=rtoz(S[1,1])" 1 "yes" 0>
  <Eqn ROE_VSWR 1 1000 590 -29 16 0 0 "VSWR=(1+abs(S[1,1]))/(1-abs(S[1,1]))" 1 "yes" 0>
  <.Opt Opt1 0 970 690 0 37 0 0 "Sim=SP1" 1 "Algo=6|20000|0.95|0.8|50|15" 0 "Var=C4_C|yes|1e-12|5.6e-13|100e-9|linear" 0 "Var=C3_C|yes|1e-12|5.6e-13|100e-9|linear" 0 "Var=L1_L|no|5.6e-09|1e-9|330e-06|linear" 0 "Goal=ok1|MIN|9|yes" 0>
  <L L1 1 1130 310 -33 -50 1 2 "18nH" 1 "" 0 "SELF-WE-PD3S" 0>
  <C C4 1 1050 370 -89 -25 0 3 "3.9pF" 1 "" 0 "neutral" 0 "SMD0603" 0>
  <C C3 1 1210 370 -85 -26 0 3 "10pF" 1 "" 0 "neutral" 0 "SMD0603" 0>
</Components>
<Wires>
  <1050 310 1050 340 "" 0 0 0 "">
  <1210 310 1210 340 "" 0 0 0 "">
  <1160 310 1210 310 "" 0 0 0 "">
  <1050 310 1100 310 "" 0 0 0 "">
  <870 310 1050 310 "" 0 0 0 "">
  <760 310 810 310 "" 0 0 0 "">
  <730 340 730 410 "" 0 0 0 "">
  <1050 400 1050 410 "" 0 0 0 "">
  <1210 400 1210 410 "" 0 0 0 "">
  <1210 310 1310 310 "" 0 0 0 "">
  <1520 390 1520 410 "" 0 0 0 "">
  <1370 310 1520 310 "" 0 0 0 "">
  <1520 310 1520 330 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
  <Rectangle 950 240 330 210 #000000 2 1 #c0c0c0 1 0>
  <Rectangle 670 240 120 210 #000000 2 1 #c0c0c0 1 0>
  <Rectangle 1440 240 230 210 #000000 2 1 #c0c0c0 1 0>
  <Ellipse 650 180 160 50 #000000 2 1 #c0c0c0 4 1>
  <Text 695 191 18 #000000 0 "Antena">
  <Ellipse 1000 180 240 50 #000000 2 1 #c0c0c0 4 1>
  <Text 1035 191 18 #000000 0 "Red adaptadora">
  <Ellipse 1460 180 180 50 #000000 2 1 #c0c0c0 4 1>
  <Text 1495 191 18 #000000 0 "Transmisor">
  <Arrow 930 140 -80 130 20 8 #000000 2 1 0>
  <Arrow 1410 140 -80 130 20 8 #000000 2 1 0>
  <Text 855 111 12 #000000 0 "Segmento de línea CPWG">
  <Text 1335 111 12 #000000 0 "Segmento de línea CPWG">
  <Rectangle 950 480 720 170 #000000 2 1 #c0c0c0 1 0>
  <Rectangle 670 480 260 400 #000000 2 1 #c0c0c0 1 0>
  <Rectangle 950 670 720 210 #000000 2 1 #c0c0c0 1 0>
  <Rectangle 1440 610 230 40 #000000 2 1 #c0c0c0 4 1>
  <Text 1465 621 12 #000000 0 "Ecuaciones desarrolladas">
  <Rectangle 1440 840 230 40 #000000 2 1 #c0c0c0 4 1>
  <Text 1465 851 12 #000000 0 "Algoritmo de optimización">
</Paintings>
