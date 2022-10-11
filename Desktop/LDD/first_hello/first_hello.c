#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_LICENSE("GPL v2");
MODULE_LICENSE("Dual BSD/GPL");

MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("My frist Driver code");
MODULE_VERSION("1:0.0");

static int __init hello_init(void) /*Constructor*/
{
	printk(KERN_INFO "Welcome to my Driver");
	return 0;
}
module_init(hello_init);

void __exit hello_exit(void)
{
	printk(KERN_INFO "Exiting my driver");
}
module_exit(hello_exit);


