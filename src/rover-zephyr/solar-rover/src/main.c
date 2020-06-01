#include <zephyr.h>
#include <device.h>
#include <drivers/gpio.h>
#include <console/console.h>
#include <string.h>

#define PORTB	"GPIOB"
#define PORTC   "GPIOC"

#define IN1 8
#define IN2 9
#define IN3 0
#define IN4 1

void bwd();
void fwd();
void lft();
void rht();
void stop();

static struct device *gpiob;
static struct device *gpioc;

void main()
{
    console_init();

    printk("Hello World");

    uint32_t ret;

    gpiob = device_get_binding(PORTB);
    if (!gpiob) {
		printk("Cannot find %s!\n", PORTB);
		return;
	}

    gpioc = device_get_binding(PORTC);
    if (!gpioc) {
		printk("Cannot find %s!\n", PORTB);
		return;
	}

    ret = gpio_pin_configure(gpiob, IN1, GPIO_DIR_OUT);
    if (ret) {
		printk("Error configuring PB%d!\n", IN1);
		return;
	}

    ret = gpio_pin_configure(gpiob, IN2, GPIO_DIR_OUT);
    if (ret) {
		printk("Error configuring PB%d!\n", IN2);
		return;
	}

    ret = gpio_pin_configure(gpioc, IN3, GPIO_DIR_OUT);
    if (ret) {
		printk("Error configuring PB%d!\n", IN2);
		return;
	}

    ret = gpio_pin_configure(gpioc, IN4, GPIO_DIR_OUT);
    if (ret) {
		printk("Error configuring PB%d!\n", IN2);
		return;
	}

    char c;

    while(1)
    {
        c = console_getchar();
		printk("char: [0x%x] %c\n", c, c);
        switch(c)
        {
            case 'B' :
                bwd();
                break;
            case 'F' :
                fwd();
                break;
            case 'L' :
                lft();
                break;
            case 'R' :
                rht();
                break;
            default :
                stop();
            
        };
    }


}

void stop()
{
    gpio_pin_set_raw(gpiob, IN1, 1);
    gpio_pin_set_raw(gpiob, IN2, 1);
    gpio_pin_set_raw(gpioc, IN3, 1);
    gpio_pin_set_raw(gpioc, IN4, 1);
}

void rht()
{
    gpio_pin_set_raw(gpiob, IN1, 1);
    gpio_pin_set_raw(gpiob, IN2, 0);
    gpio_pin_set_raw(gpioc, IN3, 1);
    gpio_pin_set_raw(gpioc, IN4, 0);
}

void lft()
{
    gpio_pin_set_raw(gpiob, IN1, 0);
    gpio_pin_set_raw(gpiob, IN2, 1);
    gpio_pin_set_raw(gpioc, IN3, 0);
    gpio_pin_set_raw(gpioc, IN4, 1);
}

void fwd()
{
    gpio_pin_set_raw(gpiob, IN1, 0);
    gpio_pin_set_raw(gpiob, IN2, 1);
    gpio_pin_set_raw(gpioc, IN3, 1);
    gpio_pin_set_raw(gpioc, IN4, 0);
}

void bwd()
{
    gpio_pin_set_raw(gpiob, IN1, 1);
    gpio_pin_set_raw(gpiob, IN2, 0);
    gpio_pin_set_raw(gpioc, IN3, 0);
    gpio_pin_set_raw(gpioc, IN4, 1);
}