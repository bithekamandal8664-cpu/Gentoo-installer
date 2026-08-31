#include <stdlib.h>          
#include <stdio.h>     
          
int main() {          
        char DISK2[100];
        char DISK3[100];
        char DISK4[100];
        char DISK5[100];
        char DISK6[100];
          
         snprintf(DISK2, sizeof(DISK2), "sudo mount -t proc none /mnt/gentoo/proc");          
         snprintf(DISK3, sizeof(DISK3), "sudo mount --rbind /sys /mnt/gentoo/sys");          
         snprintf(DISK4, sizeof(DISK4), "sudo mount --make-rslave /mnt/gentoo/sys");          
         snprintf(DISK5, sizeof(DISK5), "sudo mount --rbind /dev /mnt/gentoo/dev");          
         snprintf(DISK6, sizeof(DISK6), "sudo mount --make-rslave /mnt/gentoo/dev");          
         system(DISK2);          
         system(DISK3);          
         system(DISK4);          
         system(DISK5);          
         system(DISK6);          
         printf("\nfilesystem mounted, entering chroot.....\n");          
         system("sudo cp --dereference /etc/resolv.conf /mnt/gentoo/etc/resolv.conf");
         system("sudo cp ~/gentoo-installer/Setup.c /mnt/gentoo/root/Setup.c");
         system("sudo gcc /mnt/gentoo/root/Setup.c -o /mnt/gentoo/Setup");
         system("sudo cp ~/gentoo-installer/eselect.c /mnt/gentoo/eselect.c");
         system("sudo gcc /mnt/gentoo/eselect.c -o /mnt/gentoo/eselect");
         system("sudo chroot /mnt/gentoo /bin/bash -c \"source /etc/profile && export PS1='(chroot) $PS1' && /bin/bash\"");       
   return 0;        
}        
              
                
         
