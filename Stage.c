#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
         char disk[256];          
         char partition[256];
         char DISK1[256];                    
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
         printf("mounting disks...");           
         snprintf(DISK1, sizeof(DISK1), "sudo mount %s /mnt/gentoo", disk);
         system(DISK1);
         system("STAGE3_URL=$(curl -s https://...; "
       "wget -qO- \"$STAGE3_URL\" | "
       "sudo tar -xPF - -C /mnt/gentoo "
       "--xattrs-include='*.*' --numeric-owner");
return 0;
}
