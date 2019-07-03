#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("test user");
MODULE_DESCRIPTION("Hello world kernel module");


static int param1 = 1;

module_param(param1, int, S_IRUGO);

static int mymodule_init(void) {
        printk(KERN_ALERT "Hello world! %d \n",param1);
        return 0;
}

static void mymodule_exit(void) {
        /* Do nothing */
}

module_init(mymodule_init);
module_exit(mymodule_exit);
