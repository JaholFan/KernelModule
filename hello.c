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
module_param(apple,int,00644); 
static char *apple_color = "red";
module_param(apple_color, charp, 00644);
static char *fruit[3] = {"apple","banana","watermelon"};
int len = sizeof(fruit)/sizeof(char*);
module_param_array(fruit,charp,&len,S_IRUGO |  S_IWUSR); //Notice:&len
MODULE_PARM_DESC(apple, "A integer");
MODULE_PARM_DESC(apple_color, "A character string");
MODULE_PARM_DESC(fruit, "An array of string");

extern int buy_fruit(char*p_fruit);
static int __init hello_init(void)
{
	int ret = 0;	
	printk(KERN_INFO "Hello World enter\n");
	ret = buy_fruit("apple");
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
