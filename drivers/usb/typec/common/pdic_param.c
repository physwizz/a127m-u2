/*
 *
 * Copyright (C) 2021 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */
#define pr_fmt(fmt) "pdic_param: " fmt

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/usb/typec/common/pdic_param.h>

static const char * const pdic_param_mode[] = {
	[PDIC_PARAM_MODE_NO]	= "Normal",
	[PDIC_PARAM_MODE_OB]	= "OB",
	[PDIC_PARAM_MODE_IB]	= "IB",
	[PDIC_PARAM_MODE_DL]	= "DL",
	[PDIC_PARAM_MODE_LC]	= "LC",
};

#if IS_ENABLED(CONFIG_USB_FACTORY_MODE) && IS_MODULE(CONFIG_SEC_PARAM)
extern char *f_mode;
#else
static char *f_mode = NULL;
#endif

static unsigned int usb_mode = PDIC_PARAM_MODE_NO;
#if IS_BUILTIN(CONFIG_PDIC_NOTIFIER)
static int __init read_f_mode(char *str)
{
	if (strncmp(str, "LC", 2) == 0)
		usb_mode = PDIC_PARAM_MODE_LC;
	else if (strncmp(str, "IB", 2) == 0)
		usb_mode = PDIC_PARAM_MODE_IB;
	else if (strncmp(str, "OB", 2) == 0)
		usb_mode = PDIC_PARAM_MODE_OB;
	else if (strncmp(str, "DL", 2) == 0)
		usb_mode = PDIC_PARAM_MODE_DL;
	else
		usb_mode = PDIC_PARAM_MODE_NO;
	return 0;
}
early_param("f_mode", read_f_mode);
#endif

int check_factory_mode_boot(void)
{
	int factory = 0;

	if (f_mode) {
		if (!strncmp(f_mode, "LC", 2))
			factory = 1;
		else if (!strncmp(f_mode, "IB", 2))
			factory = 1;
		else if (!strncmp(f_mode, "OB", 2))
			factory = 1;
		else if (!strncmp(f_mode, "DL", 2))
			factory = 1;
		else
			factory = 0;
		goto ret;
	}

	if (usb_mode != PDIC_PARAM_MODE_NO)
		factory = 1;

ret:
	pr_info("%s factory=%d\n", __func__, factory);
	return factory;
}
EXPORT_SYMBOL_GPL(check_factory_mode_boot);

int get_usb_factory_mode(void)
{
	int mode = PDIC_PARAM_MODE_NO;

	if (f_mode) {
		if (!strncmp(f_mode, "LC", 2))
			mode = PDIC_PARAM_MODE_LC;
		else if (!strncmp(f_mode, "IB", 2))
			mode = PDIC_PARAM_MODE_IB;
		else if (!strncmp(f_mode, "OB", 2))
			mode = PDIC_PARAM_MODE_OB;
		else if (!strncmp(f_mode, "DL", 2))
			mode = PDIC_PARAM_MODE_DL;
		else
			mode = PDIC_PARAM_MODE_NO;
		goto ret;
	}

	mode = usb_mode;

ret:
	pr_info("%s mode=%s\n", __func__, pdic_param_mode[mode]);
	return mode;
}
EXPORT_SYMBOL_GPL(get_usb_factory_mode);

