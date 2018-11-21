struct file_operations {
	struct module *owner;
	ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
	ssize_t (*write) (struct file *, const char __user *, size_t, loff_t *);
	long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
	int (*open) (struct inode *, struct file *);
	int (*release) (struct inode *, struct file *);
} __randomize_layout;
