#include <linux/init.h>
#include <linux/module.h>
static int buy_fruit(char*p_fruit)
{
	if(NULL == p_fruit)
		return -1;
	printk(KERN_INFO "buy some %s",p_fruit);
	return 0;
}
EXPORT_SYMBOL_GPL(buy_fruit);

static int __init by_fruit_init(void)
{
	printk(KERN_INFO "By Fruit enter\n");
	return 0;
}
module_init(by_fruit_init);

static void __exit by_fruit_exit(void)
{
	printk(KERN_INFO "By Fruit exit\n");
}
module_exit(by_fruit_exit);

MODULE_AUTHOR("Jahol Fan");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple By Fruit Module");
MODULE_ALIAS("a simplest module");