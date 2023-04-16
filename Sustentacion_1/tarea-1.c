#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>  // Header file encargado de trabajar con tablas hash
#include <linux/gcd.h>  // Header file para el maximo común divisor
#include <asm/param.h>  // Header file contiene parametros básicos del kernel
#include <linux/jiffies.h>  // Permite el acceso a jiffies y sus funciones


// Función llamada cuando el modulo es cargardo
int simple_init(void)
{
	// jiffies la cantidad de tiempo que se demora un ciclo de reloj
	unsigned long tick = jiffies;
	// Es la frecuencia de ciclos por segundo, los hercios
	int tick_freq = HZ;
	// Mensaje cuando carga el kernel
	printk(KERN_INFO "Loading Kernel Module\n");
	// Imprime el número primo más cercano al número aureo
	printk(KERN_INFO "El valor del golden ratio prime es %llu\n", GOLDEN_RATIO_PRIME);
	// Imprime el valor de los jiffies
	printk(KERN_INFO "Valor de los jiffies es %lu\n", tick);
	// Imprime el valor de los hercios
	printk(KERN_INFO "Value de HZ es %d\n", tick_freq);
	return 0;
}

// Función llamada cuando el modulo es descargardo
void simple_exit(void)
{
	// a tine el valor del long sin signo 3300
	unsigned long int a = 3300;
	// b tiene el valor sin signo 24
	unsigned int b = 24;
	// jiffies la cantidad de tiempo que se demora un ciclo de reloj
	unsigned long tick = jiffies;
	// Imprime el MCD de 3300 y 24 usando la función gdc
	printk(KERN_INFO "El MCD de %lu y %u es %lu\n", a, b, gcd(a,b));
	// Imprime el valor de los jiffies 
	printk(KERN_INFO "Valor de jiffies es %lu\n", tick);
	// Mensaje cuando remueve el kernel
	printk(KERN_INFO "Removing Kernel Module\n");
}

// Fuciones llamadas al cargar y descargar el moulo
module_init( simple_init );
module_exit( simple_exit );
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

