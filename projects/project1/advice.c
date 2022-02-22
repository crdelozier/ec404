#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#define BUFFER_SIZE 128
#define PROC_NAME ""

ssize_t proc_read(struct file *file, char __user *usr_buf,
		  size_t count, loff_t *pos);

ssize_t proc_write(struct file *file, const char __user *usr_buf,
		  size_t count, loff_t *pos);

static struct proc_ops proc_file_ops = {
  .proc_read = proc_read,
};

int proc_init(void){
  
  return 0;
}

void proc_exit(void){

}

ssize_t proc_read(struct file *file, char __user *usr_buf,
		  size_t count, loff_t *pos){
  int rv = 0;
  
  return rv;
}

ssize_t proc_write(struct file *file, const char __user *usr_buf,
		  size_t count, loff_t *pos){

  return count;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Advice module");
MODULE_AUTHOR("Your Name Here");
