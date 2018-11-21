#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_INFO(intree,"Y");
MODULE_DESCRIPTION("hello2 module");
MODULE_AUTHOR("Yscho.HGU");

//static int hello2_init(void);
//static void hello2_exit(void);


static int __init hello2_init(void)
{
	printk("Loading my first device driver...\n");
	return 0;
}

static void __exit hello2_exit(void)
{
	printk("Unloading my first device driver ...\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
