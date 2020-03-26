sdcc src/main.c -I inc/ -DBANDWIDTH
sudo ~/SimplicityStudio/SimplicityStudio_v4/developer/adapter_packs/c8051/flash8051 -sn TS004A9A92 -tif c2 -upload main.ihx -erasemode full
sudo python test/bandwidth.py

sdcc src/main.c -I inc/ -DCLOG2_TEST
sudo ~/SimplicityStudio/SimplicityStudio_v4/developer/adapter_packs/c8051/flash8051 -sn TS004A9A92 -tif c2 -upload main.ihx -erasemode full
sudo python test/clog2.py

sdcc src/main.c -I inc/ -DCORDIC_TEST
sudo ~/SimplicityStudio/SimplicityStudio_v4/developer/adapter_packs/c8051/flash8051 -sn TS004A9A92 -tif c2 -upload main.ihx -erasemode full
sudo python test/sine.py
