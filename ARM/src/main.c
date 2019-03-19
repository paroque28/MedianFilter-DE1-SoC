#include <stdlib.h>
#include <sys/mman.h>

#include "stdio.h"
#include "alt_generalpurpose_io.h"
#include "socal/hps.h"


#define HPS_FPGA_LEDS_BASE 0X2000

// physical memory file descriptor
int fd_dev_mem = 0; void open_physical_memory_device() {
// We need to access the system's physical memory so we can map it to user
// space. We will use the /dev/mem file to do this. /dev/mem is a character
// device file that is an image of the main memory of the computer. Byte
// addresses in /dev/mem are interpreted as physical memory addresses.
// Remember that you need to execute this program as ROOT in order to have
// access to /dev/mem.
fd_dev_mem = open("/dev/mem", O_RDWR | O_SYNC);
if(fd_dev_mem == -1) {
printf("ERROR: could not open \"/dev/mem\".\n");
printf(" errno = %s\n", strerror(errno));
exit(EXIT_FAILURE);
}

 void *h2f_lw_axi_master = NULL;
size_t h2f_lw_axi_master_span = ALT_LWFPGASLVS_UB_ADDR - ALT_LWFPGASLVS_LB_ADDR + 1;
size_t h2f_lw_axi_master_ofst = ALT_LWFPGASLVS_OFST;
void *fpga_leds = NULL; void mmap_fpga_peripherals() {
// Use mmap() to map the address space related to the fpga leds into user
// space so we can interact with them.
// The fpga leds are connected to the h2f_lw_axi_master, so its base
// address is calculated from that of the h2f_lw_axi_master.
// IMPORTANT: If you try to only mmap the fpga leds, it is possible for the
// operation to fail, and you will get "Invalid argument" as errno. The
// mmap() manual page says that you can only map a file from an offset which
// is a multiple of the system's page size.
// In our specific case, our fpga leds are located at address 0xFF200000,
// which is a multiple of the page size, however this is due to luck because
// the fpga leds are the only peripheral connected to the h2f_lw_axi_master.
// The typical page size in Linux is 0x1000 bytes.
// So, generally speaking, you will have to mmap() the closest address which
// is a multiple of your page size and access your peripheral by a specific
// offset from the mapped address.
h2f_lw_axi_master = mmap(NULL, h2f_lw_axi_master_span, PROT_READ | PROT_WRITE, MAP_SHARED, fd_dev_mem, h2f_lw_axi_master_ofst);
if (h2f_lw_axi_master == MAP_FAILED) {
printf("Error: h2f_lw_axi_master mmap() failed.\n");
printf(" errno = %s\n", strerror(errno));
close(fd_dev_mem);
exit(EXIT_FAILURE);
}
fpga_leds = h2f_lw_axi_master + HPS_FPGA_LEDS_BASE;
}

int main() {
printf("DE1-SoC linux demo\n");
open_physical_memory_device();
mmap_peripherals();
setup_hps_gpio();
setup_fpga_leds();
while (true) {
handle_hps_led();
handle_fpga_leds();
usleep(ALT_MICROSECS_IN_A_SEC / 10);
}
munmap_peripherals();
close_physical_memory_device();