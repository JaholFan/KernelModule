/*
 * a simple kernel module: hello
 *
 * Copyright (C) 2014 Jahol Fan  (Jahol@kernel.org)
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/init.h>
#include <linux/module.h>

static int apple = 4;
module_param(apple,int,S_IRUGO); 
static char *apple_color = "red";
module_param(apple_color, charp, S_IRUGO);

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello World enter\n");
	printk(KERN_INFO "apple=%d\n",apple);
	printk(KERN_INFO "apple_color=%s\n",apple_color);
	return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Hello World exit\n ");
}
module_exit(hello_exit);

MODULE_AUTHOR("Jahol Fan");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello World Module");
MODULE_ALIAS("a simplest module");
