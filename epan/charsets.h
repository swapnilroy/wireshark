/* charsets.h
 * Routines for handling character sets
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */
#ifndef __CHARSETS_H__
#define __CHARSETS_H__

#include "ws_symbol_export.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*
 * Translation tables that map the upper 128 code points in single-byte
 * "extended ASCII" character encodings to Unicode code points in the
 * Basic Multilingual Plane.
 */

/* Table for windows-1250 */
extern const gunichar2 charset_table_cp1250[0x80];
/* Table for windows-1251 */
extern const gunichar2 charset_table_cp1251[0x80];
/* Table for windows-1252 */
extern const gunichar2 charset_table_cp1252[0x80];

/* Tables for ISO-8859-X */
extern const gunichar2 charset_table_iso_8859_2[0x80];
extern const gunichar2 charset_table_iso_8859_3[0x80];
extern const gunichar2 charset_table_iso_8859_4[0x80];
extern const gunichar2 charset_table_iso_8859_5[0x80];
extern const gunichar2 charset_table_iso_8859_6[0x80];
extern const gunichar2 charset_table_iso_8859_7[0x80];
extern const gunichar2 charset_table_iso_8859_8[0x80];
extern const gunichar2 charset_table_iso_8859_9[0x80];
extern const gunichar2 charset_table_iso_8859_10[0x80];
extern const gunichar2 charset_table_iso_8859_11[0x80];
extern const gunichar2 charset_table_iso_8859_13[0x80];
extern const gunichar2 charset_table_iso_8859_14[0x80];
extern const gunichar2 charset_table_iso_8859_15[0x80];
extern const gunichar2 charset_table_iso_8859_16[0x80];

/* Tables for Mac character sets */
extern const gunichar2 charset_table_mac_roman[0x80];

/* Tables for DOS code pages */
extern const gunichar2 charset_table_cp437[0x80];
extern const gunichar2 charset_table_cp855[0x80];
extern const gunichar2 charset_table_cp866[0x80];


/* Tables for EBCDIC code pages */
extern const gunichar2 charset_table_ebcdic[256];
extern const gunichar2 charset_table_ebcdic_cp037[256];

/*
 * Given a wmem scope, a pointer, and a length, treat the string of bytes
 * referred to by the pointer and length as an ASCII string, with all bytes
 * with the high-order bit set being invalid, and return a pointer to a
 * UTF-8 string, allocated using the wmem scope.
 *
 * Octets with the highest bit set will be converted to the Unicode
 * REPLACEMENT CHARACTER.
 */
WS_DLL_PUBLIC guint8 *
get_ascii_string(wmem_allocator_t *scope, const guint8 *ptr, gint length);

WS_DLL_PUBLIC guint8 *
get_8859_1_string(wmem_allocator_t *scope, const guint8 *ptr, gint length);

WS_DLL_PUBLIC guint8 *
get_unichar2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const gunichar2 table[0x80]);

WS_DLL_PUBLIC guint8 *
get_ucs_2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding);

WS_DLL_PUBLIC guint8 *
get_utf_16_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding);

WS_DLL_PUBLIC guint8 *
get_ucs_4_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const guint encoding);

WS_DLL_PUBLIC guint8 *
get_ts_23_038_7bits_string(wmem_allocator_t *scope, const guint8 *ptr,
        const gint bit_offset, gint no_of_chars);

WS_DLL_PUBLIC guint8 *
get_ascii_7bits_string(wmem_allocator_t *scope, const guint8 *ptr,
        const gint bit_offset, gint no_of_chars);

WS_DLL_PUBLIC guint8 *
get_nonascii_unichar2_string(wmem_allocator_t *scope, const guint8 *ptr, gint length, const gunichar2 table[256]);

WS_DLL_PUBLIC guint8 *
get_t61_string(wmem_allocator_t *scope, const guint8 *ptr, gint length);

#if 0
void ASCII_to_EBCDIC(guint8 *buf, guint bytes);
guint8 ASCII_to_EBCDIC1(guint8 c);
#endif
WS_DLL_PUBLIC
void EBCDIC_to_ASCII(guint8 *buf, guint bytes);
WS_DLL_PUBLIC
guint8 EBCDIC_to_ASCII1(guint8 c);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __CHARSETS_H__ */

/*
 * Editor modelines  -  http://www.wireshark.org/tools/modelines.html
 *
 * Local variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * vi: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
