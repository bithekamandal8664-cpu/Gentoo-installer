#include <stdlib.h>          
#include <stdio.h>       
#include <string.h>       
          
int main() {          
         char disk[256];          
         char partition[256];          
        char DISK1[256];          
         char DISK2[256];          
         char DISK3[256];          
         char DISK4[256];          
         char DISK5[256];          
         char DISK6[256];          
        char PARTITION[256];          
                 
         printf("which partition you wanna choose? (Ext4, btrfs, xfs, other):- ");          
         fgets(partition, sizeof(partition), stdin);    
         partition[strcspn(partition, "\n")] = '\0';         
         printf("which disk you want to cutely destroy? :-\n");          
         system("lsblk -f\n");          
         printf("please choose here:- ");          
         fgets(disk, sizeof(disk), stdin);     
         disk[strcspn(disk, "\n")] = '\0';         
         printf("destroying cutely.......");          
         snprintf(PARTITION, sizeof(PARTITION), "mkfs.%s %s", partition, disk);        
         system(PARTITION);          
         printf("making mount folder\n");          
         system("sudo mkdir /mnt/gentoo");          
         printf("mounting disks and filesystems..");           
         snprintf(DISK1, sizeof(DISK1), "sudo mount %s /mnt/gentoo", disk);          
         snprintf(DISK2, sizeof(DISK2), "sudo mount -t proc none /mnt/gentoo/proc");          
         snprintf(DISK3, sizeof(DISK3), "sudo mount --rbind /sys /mnt/gentoo/sys");          
         snprintf(DISK4, sizeof(DISK4), "sudo mount --make-rslave /mnt/gentoo/sys");          
         snprintf(DISK5, sizeof(DISK5), "sudo mount --rbind /dev /mnt/gentoo/dev");          
         snprintf(DISK6, sizeof(DISK6), "sudo mount --make-rslave /mnt/gentoo/dev");          
         system(DISK1);          
         system(DISK2);          
         system(DISK3);          
         system(DISK4);          
         system(DISK5);          
         system(DISK6);          
         printf("\nfilesystem mounted, entering chroot.....\n");          
         system("cp --dereference /etc/resolv.conf /mnt/gentoo/etc/resolv.conf");          
         system("sudo chroot /mnt/gentoo /bin/bash -c \"source /etc/profile && export PS1='(chroot) $PS1' && /bin/bash\"");       
   return 0;        
}        
              
                
         
