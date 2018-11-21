/* iom_virtual_dd.c */
/* PWD = ~/work/dd/iom-mydevice */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/init.h>

#define DEV_NAME "/dev/iom_virtual_dd"
#define IOM_mydevice_MAJOR_NUM 0

MODULE_LICENSE("GPL");
MODULE_INFO(intree,"Y");
MODULE_DESCRIPTION("iom_virtual_dd module");
MODULE_AUTHOR("Yscho.HGU");

//static int hello2_init(void);
//static void hello2_exit(void);



	ssize_t iom_virtual_dd_read (struct file *, char __user *, size_t, loff_t *);
	ssize_t iom_virtual_dd_write (struct file *, const char __user *, size_t, loff_t *);
	long iom_virtual_dd_ioctl (struct file *, unsigned int, unsigned long);
	int iom_virtual_dd_open (struct inode *, struct file *);
	int iom_virtual_dd_release (struct inode *, struct file *);

struct file_operations iom_virtual_dd_fops={
	.owner = THIS_MODULE,
	.open = iom_virtual_dd_open,
	.release = iom_virtual_dd_release,
	.read = iom_virtual_dd_read,
	.write =iom_virtual_dd_write,
	.unlocked_ioctl = iom_virtual_dd_ioctl
};


int iom_virtual_dd_open (struct inode *inode, struct file *filep){
//
	printk("iom_virtual_dd_open (): open virtual device !!!\n");
	return 0;
}



int iom_virtual_dd_release (struct inode *inode, struct file *filep){
	printk("iom_virtual_dd_release (): close virtual device !!!\n");
	return 0;
}

ssize_t iom_virtual_dd_read (struct file *filep, char __user *buf, size_t count, loff_t *f_pos){
	printk("iom_virtual_dd_read () function\n");
	return 0;
}



ssize_t iom_virtual_dd_write (struct file *filep, const char __user *buf, size_t count, loff_t *f_pos){
	printk("iom_virtual_dd_write () function\n");
	return 0;
}


long iom_virtual_dd_ioctl (struct file *filep, unsigned int cmd, unsigned long arg){
return 0;
}





static int __init hello2_init(void)
{
	int major_num;
	major_num = register_chrdev(IOM_mydevice_MAJOR_NUM, DEV_NAME, &iom_virtual_dd_fops);
	if (major_num < 0) {
		printk(KERN_WARNING"%s: can't get or assign major number %d\n", DEV_NAME, major_num);
		return major_num;
	}

	printk("Success to load the device %s. Major number is %d\n", DEV_NAME, major_num);

	return 0;
}

static void __exit hello2_exit(void)
{
	unregister_chrdev(IOM_mydevice_MAJOR_NUM, DEV_NAME);
	printk("Unload the device %s...\n", DEV_NAME);
}

module_init(hello2_init);
module_exit(hello2_exit);
