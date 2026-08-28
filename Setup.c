#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int kernel;
    char GRUB[100];
    char username [64];
    char cmd[256];
    
  system("emerge-webrsync");
  printf("which kernel you want to run?\n");
  printf("1. gentoo-kernel-bin\n");
  printf("2. zenkernel\n");
  printf("3. copying kernel from LiveGUI\n");
  printf("choose (in numbers):- ");
  scanf("%d", &kernel);
  switch (kernel) {
           case 1:
            printf("installing kernel!\n");
            system("mkdir -p /etc/portage/package.use");
            system("echo 'sys-kernel/installkernel dracut' >> /etc/portage/package.use/installkernel");
            system("emerge --autounmask-write=y --autounmask-continue sys-kernel/gentoo-kernel-bin");
            break;
           case 2:
            printf("installing kernel!\n");
            system("mkdir -p /etc/portage/package.use");
            system("echo \"sys-kernel/zen-sources ~amd64\" >> /etc/portage/package.accept_keywords/zen-kernel");
            system("emerge sys-kernel/zen-sources");
            system("emerge sys-kernel/genkernel");
            system("eselect kernel set $(eselect kernel list | grep 'zen' | awk -F'[][]' '{print $2}' | tr -d ' ')");
            system("genkernel all");
            break;
           case 3:
            printf("applying kernel!\n");
            system("sudo cp /boot/vmlinuz* /boot/");
            printf("kernel applied!\n");
            break;
           default:
            printf("option not recognised");
            break;
  }
  printf("you want to install GRUB?:- ");
  scanf("%s", GRUB);
  if (strcmp(GRUB, "yes") == 0) {
           printf("installing GRUB!\n");
           system("emerge sys-boot/grub");
           printf("applying grub\n");
           system("grub-install --target=x86_64-efi --efi-directory=/boot/efi");
           system("grub-mkconfig -o /boot/grub/grub.cfg");
  }
  else {
      printf("ehh skipping then, add later");
  }
  printf("installing firmware....\n");
  system("emerge sys-kernel/linux-firmware");
  printf(" enter your root password!\n");
  system("passwd root");

  printf("enter your username pls:- ");
  scanf("%63s", username);

  snprintf(cmd, sizeof(cmd), "useradd -m -G wheel,audio,video,input -s /bin/bash %s", username);
  system(cmd);
  printf("\nYAY, INSTALLATION COMPLETED! YOU CAN NOW ENTER YOU GENTOO YIPPEE!!!\n");
return 0;
}
