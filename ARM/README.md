## Installation of SDK

```bash
sudo apt-get install libc6-armel-cross libc6-dev-armel-cross binutils-arm-linux-gnueabi libncurses5-dev
sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
```

## Memory map

lwfpgaslaves	FPGA Slaves Accessed Via Lightweight HPS2FPGA AXI Bridge
0xFF200000 -> 0xFF3FFFFF

lwhps2fpgaregs	LWHPS2FPGA AXI Bridge Module
0xFF400000 -> 0xFF47FFFF