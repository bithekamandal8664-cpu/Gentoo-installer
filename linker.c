#include <stdlib.h>          
#include <unistd.h>          
          
int main() {          
        system("git clone https://github.com/bithekamandal8664-cpu/gentoo-installer");          
       chdir("gentoo-installer");          
       system("gcc Chroot.c -o Chroot");          
       system("gcc Stage.c -o Stage");          
       system("./Stage");          
      return 0;          
}
