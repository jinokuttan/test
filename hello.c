#include<linux/init.h>
#include<linux/module.h>
#include<arch/x86/include/generated/asm/syscalls_32.h>
static int hell0_init(void){
	printk(KERN_ALERT,"my first module writing program");
	return 0;
}

static void hello_exit(void){
	printk(KERN_ALERT,"exiting from the module");
}
module_init(hello_init);
module_exit(hello_exit);

