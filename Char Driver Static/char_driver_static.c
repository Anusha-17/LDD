#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/slab.h>

#define MAJORNO 300
#define MINORNO  0
#define CHAR_DEV_NAME "my_cdev"
#define MAX_LENGTH 4000
#define SUCCESS 0


struct cdev *my_cdev;
dev_t mydev;
int count=1,inuse=0;

static int __init char_dev_init(void)
{
	mydev = MKDEV(MAJORNO,MINORNO);                             // step 1 to create major and minor no.==mydev
	register_chrdev_region(mydev,count,CHAR_DEV_NAME);          // step 2:create one name for character driverv  and 
								    // register that name to mydev

//	my_cdev= cdev_alloc();  // allow allocate cdev instance, 
//	cdev_init(my_cdev,&char_dev_fops);                           // step 3 initilizing file operation  to cdev instance 

//	ret=cdev_add(my_cdev,mydev,count);//step 4 step 2 + step 3 ;  register with VFS layer , count = how many minor no. in use .
	
        printk(KERN_INFO"\nDevice Registered %s\n",CHAR_DEV_NAME);
	return 0;
}

static void __exit char_dev_exit(void)
{
	
	 printk(KERN_INFO "\n Driver unregistered \n");
}

module_init(char_dev_init);
module_exit(char_dev_exit);

MODULE_AUTHOR("Anusha");
MODULE_DESCRIPTION("Static Character Device Driver");
MODULE_LICENSE("GPL");
