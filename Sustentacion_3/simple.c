#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>

/* This function is called when the module is loaded. */
int simple_init(void) {
	struct task_struct *task; //Pointer to the task whose info will be printed

	printk(KERN_INFO "Insertando el modulo\n");	
	printk(KERN_INFO "Listando las tareas\n");

	for_each_process(task) { //Loop over the tasks using the macro for_each_process

		/* on each iteration task points to the next task */
		//task->comm is the task' name
		//task->state is the task's state (-1 unrunnable, 0 runnable, >0 stopped)
		//task->pid is the task's process ID
        printk(KERN_INFO "%ud %d %s\n", task->__state, task->pid, task->comm);
	}
	
	printk(KERN_INFO "Termino listar tareas\n");
	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removiendo el modulo UwU\n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Lista las tareas linealmente");
MODULE_AUTHOR("SGG");
