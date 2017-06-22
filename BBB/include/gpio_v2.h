/* gpio_v2.h */

/* GPIO bits for pin direction */
#define GPIO_DIR_INPUT        0x00 /**< set pin for input                  */
#define GPIO_DIR_OUTPUT       0x01 /**< set pin for output                 */

/* Values helping to decide the value on a GPIO pin. */
#define GPIO_PIN_LOW                     (0x0)
#define GPIO_PIN_HIGH                    (0x1)

/*
 * Control and Status Register (CSR) definintions for the GPIO.
 * The code maps the structure structure directly onto the base address
 * CSR address for the device.
 */


//Macro for hardware access
#define HWREG(x)    (*((volatile unsigned int *)(x)))


#define CONTROL_CONF_GPMC_A(n)   (0x840 + (n * 4))
#define CONTROL_CONF_MUXMODE(n)        (n)

#define CONTROL_CONF_GPMC_AD(n)   (0x800 + (n * 4))
#define CONTROL_CONF_GPMC_AD_CONF_GPMC_AD_SLEWCTRL   (0x00000040u)
#define CONTROL_CONF_GPMC_AD_CONF_GPMC_AD_RXACTIVE   (0x00000020u)
#define CONTROL_CONF_GPMC_AD_CONF_GPMC_AD_PUDEN   (0x00000008u)
#define CONTROL_CONF_GPMC_AD_CONF_GPMC_AD_PUTYPESEL   (0x00000010u)


/** @brief Base address of control module memory mapped registers             */
#define SOC_PRCM_REGS                        (0x44E00000)
#define SOC_GPIO_1_REGS                      (0x4804C000)
#define SOC_CONTROL_REGS                     (0x44E10000)
#define SOC_CM_PER_REGS                      (SOC_PRCM_REGS + 0)

#define CM_PER_GPIO1_CLKCTRL   (0xac)
#define CM_PER_GPIO1_CLKCTRL_MODULEMODE   (0x00000003u)
#define CM_PER_GPIO1_CLKCTRL_MODULEMODE_ENABLE   (0x2u)
#define CM_PER_GPIO1_CLKCTRL_OPTFCLKEN_GPIO_1_GDBCLK   (0x00040000u)
#define CM_PER_GPIO1_CLKCTRL_IDLEST   (0x00030000u)
#define CM_PER_GPIO1_CLKCTRL_IDLEST_FUNC   (0x0u)
#define CM_PER_GPIO1_CLKCTRL_IDLEST_SHIFT   (0x00000010u)
#define CM_PER_L4LS_CLKSTCTRL   (0x0)
#define CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GPIO_1_GDBCLK   (0x00080000u)

/* GPIO memory-mapped I/O address */
#define GPIO0_ADDR 0x44E07000
#define GPIO1_ADDR 0x4804C000
#define GPIO2_ADDR 0x481AC000
#define GPIO3_ADDR 0x481AF000

#define GPIO_REVISION   (0x0)
#define GPIO_SYSCONFIG   (0x10)
#define GPIO_IRQSTATUS_RAW(n)   (0x24 + (n * 4))
#define GPIO_IRQSTATUS(n)   (0x2C + (n * 4))
#define GPIO_IRQSTATUS_SET(n)   (0x34 + (n * 4))
#define GPIO_IRQSTATUS_CLR(n)   (0x3C + (n * 4))
#define GPIO_IRQWAKEN(n)   (0x44 + (n * 4))
#define GPIO_SYSSTATUS   (0x114)
#define GPIO_CTRL   (0x130)
#define GPIO_OE   (0x134)
#define GPIO_DATAIN   (0x138)
#define GPIO_DATAOUT   (0x13C)
#define GPIO_LEVELDETECT(n)   (0x140 + (n * 4))
#define GPIO_RISINGDETECT   (0x148)
#define GPIO_FALLINGDETECT   (0x14C)
#define GPIO_DEBOUNCENABLE   (0x150)
#define GPIO_DEBOUNCINGTIME   (0x154)
#define GPIO_CLEARDATAOUT   (0x190)
#define GPIO_SETDATAOUT   (0x194)

// Field Definition Macros
//system config
#define GPIO_SYSCONFIG_SOFTRESET   (0x00000002u)

//system status
#define GPIO_SYSSTATUS_RESETDONE   (0x00000001u)

/* CTRL */
#define GPIO_CTRL_DISABLEMODULE   (0x00000001u)
