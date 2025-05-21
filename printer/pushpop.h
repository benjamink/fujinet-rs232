/*
 * Template for writing DOS device drivers in Open Watcom C
 *
 * Copyright (C) 2022, Eduardo Casino (mail@eduardocasino.es)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301, USA.
 *
 */

#if ( _M_IX86 >= 0x200 )
#define push_all "pusha"
#define pop_all "popa"
#else
#define push_all "push ax" "push cx" "push dx" "push bx" "push sp" "push bp" "push si" "push di"
#define pop_all "pop di" "pop si" "pop bp" "pop bx" "pop bx" "pop dx" "pop cx" "pop ax"
#endif

#if ( _M_IX86 >= 0x300 )
#define push_segregs "push ds" "push es" "push fs" "push gs"
#define pop_segregs "pop gs" "pop fs" "pop es" "pop ds"
#else
#define push_segregs "push ds" "push es"
#define pop_segregs "pop es" "pop ds"
#endif

extern void push_regs(void);
#pragma aux push_regs = \
    "pushf" \
    push_all \
    push_segregs \
    "push cs" "pop ds";

extern void pop_regs(void);
#pragma aux pop_regs = \
    pop_segregs \
    pop_all \
    "popf";

