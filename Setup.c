#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int kernel;
    char GRUB[100];
    char username [64];
    char cmd1[100];

  printf("which kernel you want to run?\n");
  printf("1. gentoo-kernel-bin\n");
  printf("2. zenkernel\n");
  printf("3. copying kernel from LiveGUI\n");
  printf("choose (in numbers):- ");
  scanf("%d" &kernel);
  switch (kernel) {
           case 1:
            printf("installing kernel!\n");
            system("emerge sys-kernel/gentoo-kernel-bin");
            break;
           case 2:
            printf("installing kernel!\n");
            system("emerge sys-kernel/zen-sources");
            break;
           case 3:
            printf("applying kernel!\n");
            system("sudo cp /boot/vmlinuz* /mnt/gentoo/boot/");
            printf("kernel applied!\n");
            break;
           default:
            printf("option not recognised");
            break;
  }
  printf("you want to install GRUB?\n");
  scanf("%s", GRUB);
  if (strcmp(GRUB, "yes") == 0) {
           printf("installing GRUB!\n");
           system("emerge sys-boot/grub");
           printf("applying grub\n");
           system("grub-install --target=x86_64-efi --efi-directory=/boot/efi");
           system("grub-mkconfig -o /boot/grub/grub.cfg");
           continue;
  }
  else {
      return 0;
  }
  printf("installing firmware....\n");
  system("emerge sys-kernel/linux-firmware");
  printf(" enter your root password!\n");
  system("passwd root");

  printf("enter your username pls"\n);
  scanf("%s", username);

  snprintf(cmd, sizeof(cmd), "useradd -m -G wheel,audio,video -s /bin/bash %s", username);
  system(cmd);
  printf("\nYAY, INSTALLATION COMPLETED! YOU CAN NOW ENTER YOU GENTOO YIPPEE!!!\n");
return 0;
}
