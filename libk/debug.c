/**
 * Copyright (C) 2020-2021 KeyboardSlayer (Jordan Dalcq)
 * 
 * This file is part of Navy.
 * 
 * Navy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Navy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Navy.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdarg.h>
#include <stdlib.h>
#include <libk/debug.h>

#include "devices/serial.h"
#include "devices/framebuffer.h"


void 
__assert(const char *expr, const char *file, const char *func, int line)
{
    char line_str[64];
    itoa(line, line_str, 10);

    puts_serial(COM1, "Assertion failed: ");
    puts_serial(COM1, expr);
    puts_serial(COM1, " in ");
    puts_serial(COM1, file);
    puts_serial(COM1, " (");
    puts_serial(COM1, func);
    puts_serial(COM1, ": line ");
    puts_serial(COM1, line_str);
    puts_serial(COM1, ")");

    printf_fb("\nAssertion failed: %s in %s (%s: line %d)", expr, file, func, line);
    __asm__("int $1");
}
