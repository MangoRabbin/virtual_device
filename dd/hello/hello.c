#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
	printk("Loading my first device driver...\n");
	return 0;
}

void cleanup_module(void)
{
	printk("Unloading my first device driver ...\n");
}

