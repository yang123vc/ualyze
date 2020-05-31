//
//  ucdu.h
//
//  Copyright (C) 2012 Grigori Goronzy <greg@kinoho.net>
//  Copyright (C) 2020 Edmund Kapusniak.
//
//  Permission to use, copy, modify, and/or distribute this software for any
//  purpose with or without fee is hereby granted, provided that the above
//  copyright notice and this permission notice appear in all copies.
//
//  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
//  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
//  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
//  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
//  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
//  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
//  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//

#ifndef UCDU_H
#define UCDU_H

#include <stddef.h>
#include <stdint.h>

/*
    Based on ucdn https://github.com/grigorig/ucdn, this is a stripped-down
    version which only provides the properties that ualyze cares about.

    We depend on the ordering of property values, which must match the order
    in the state machines.  Bidi analysis also depends on this ordering.
*/

enum ucdu_script
{
    UCDU_SCRIPT_COMMON,
    UCDU_SCRIPT_INHERITED,
    UCDU_SCRIPT_UNKNOWN,
    UCDU_SCRIPT_LATIN,
    UCDU_SCRIPT_GREEK,
    UCDU_SCRIPT_CYRILLIC,
    UCDU_SCRIPT_ARMENIAN,
    UCDU_SCRIPT_HEBREW,
    UCDU_SCRIPT_ARABIC,
    UCDU_SCRIPT_SYRIAC,
    UCDU_SCRIPT_THAANA,
    UCDU_SCRIPT_DEVANAGARI,
    UCDU_SCRIPT_BENGALI,
    UCDU_SCRIPT_GURMUKHI,
    UCDU_SCRIPT_GUJARATI,
    UCDU_SCRIPT_ORIYA,
    UCDU_SCRIPT_TAMIL,
    UCDU_SCRIPT_TELUGU,
    UCDU_SCRIPT_KANNADA,
    UCDU_SCRIPT_MALAYALAM,
    UCDU_SCRIPT_SINHALA,
    UCDU_SCRIPT_THAI,
    UCDU_SCRIPT_LAO,
    UCDU_SCRIPT_TIBETAN,
    UCDU_SCRIPT_MYANMAR,
    UCDU_SCRIPT_GEORGIAN,
    UCDU_SCRIPT_HANGUL,
    UCDU_SCRIPT_ETHIOPIC,
    UCDU_SCRIPT_CHEROKEE,
    UCDU_SCRIPT_CANADIAN_ABORIGINAL,
    UCDU_SCRIPT_OGHAM,
    UCDU_SCRIPT_RUNIC,
    UCDU_SCRIPT_KHMER,
    UCDU_SCRIPT_MONGOLIAN,
    UCDU_SCRIPT_HIRAGANA,
    UCDU_SCRIPT_KATAKANA,
    UCDU_SCRIPT_BOPOMOFO,
    UCDU_SCRIPT_HAN,
    UCDU_SCRIPT_YI,
    UCDU_SCRIPT_OLD_ITALIC,
    UCDU_SCRIPT_GOTHIC,
    UCDU_SCRIPT_DESERET,
    UCDU_SCRIPT_TAGALOG,
    UCDU_SCRIPT_HANUNOO,
    UCDU_SCRIPT_BUHID,
    UCDU_SCRIPT_TAGBANWA,
    UCDU_SCRIPT_LIMBU,
    UCDU_SCRIPT_TAI_LE,
    UCDU_SCRIPT_LINEAR_B,
    UCDU_SCRIPT_UGARITIC,
    UCDU_SCRIPT_SHAVIAN,
    UCDU_SCRIPT_OSMANYA,
    UCDU_SCRIPT_CYPRIOT,
    UCDU_SCRIPT_BRAILLE,
    UCDU_SCRIPT_BUGINESE,
    UCDU_SCRIPT_COPTIC,
    UCDU_SCRIPT_NEW_TAI_LUE,
    UCDU_SCRIPT_GLAGOLITIC,
    UCDU_SCRIPT_TIFINAGH,
    UCDU_SCRIPT_SYLOTI_NAGRI,
    UCDU_SCRIPT_OLD_PERSIAN,
    UCDU_SCRIPT_KHAROSHTHI,
    UCDU_SCRIPT_BALINESE,
    UCDU_SCRIPT_CUNEIFORM,
    UCDU_SCRIPT_PHOENICIAN,
    UCDU_SCRIPT_PHAGS_PA,
    UCDU_SCRIPT_NKO,
    UCDU_SCRIPT_SUNDANESE,
    UCDU_SCRIPT_LEPCHA,
    UCDU_SCRIPT_OL_CHIKI,
    UCDU_SCRIPT_VAI,
    UCDU_SCRIPT_SAURASHTRA,
    UCDU_SCRIPT_KAYAH_LI,
    UCDU_SCRIPT_REJANG,
    UCDU_SCRIPT_LYCIAN,
    UCDU_SCRIPT_CARIAN,
    UCDU_SCRIPT_LYDIAN,
    UCDU_SCRIPT_CHAM,
    UCDU_SCRIPT_TAI_THAM,
    UCDU_SCRIPT_TAI_VIET,
    UCDU_SCRIPT_AVESTAN,
    UCDU_SCRIPT_EGYPTIAN_HIEROGLYPHS,
    UCDU_SCRIPT_SAMARITAN,
    UCDU_SCRIPT_LISU,
    UCDU_SCRIPT_BAMUM,
    UCDU_SCRIPT_JAVANESE,
    UCDU_SCRIPT_MEETEI_MAYEK,
    UCDU_SCRIPT_IMPERIAL_ARAMAIC,
    UCDU_SCRIPT_OLD_SOUTH_ARABIAN,
    UCDU_SCRIPT_INSCRIPTIONAL_PARTHIAN,
    UCDU_SCRIPT_INSCRIPTIONAL_PAHLAVI,
    UCDU_SCRIPT_OLD_TURKIC,
    UCDU_SCRIPT_KAITHI,
    UCDU_SCRIPT_BATAK,
    UCDU_SCRIPT_BRAHMI,
    UCDU_SCRIPT_MANDAIC,
    UCDU_SCRIPT_CHAKMA,
    UCDU_SCRIPT_MEROITIC_CURSIVE,
    UCDU_SCRIPT_MEROITIC_HIEROGLYPHS,
    UCDU_SCRIPT_MIAO,
    UCDU_SCRIPT_SHARADA,
    UCDU_SCRIPT_SORA_SOMPENG,
    UCDU_SCRIPT_TAKRI,
    UCDU_SCRIPT_BASSA_VAH,
    UCDU_SCRIPT_CAUCASIAN_ALBANIAN,
    UCDU_SCRIPT_DUPLOYAN,
    UCDU_SCRIPT_ELBASAN,
    UCDU_SCRIPT_GRANTHA,
    UCDU_SCRIPT_KHOJKI,
    UCDU_SCRIPT_KHUDAWADI,
    UCDU_SCRIPT_LINEAR_A,
    UCDU_SCRIPT_MAHAJANI,
    UCDU_SCRIPT_MANICHAEAN,
    UCDU_SCRIPT_MENDE_KIKAKUI,
    UCDU_SCRIPT_MODI,
    UCDU_SCRIPT_MRO,
    UCDU_SCRIPT_NABATAEAN,
    UCDU_SCRIPT_OLD_NORTH_ARABIAN,
    UCDU_SCRIPT_OLD_PERMIC,
    UCDU_SCRIPT_PAHAWH_HMONG,
    UCDU_SCRIPT_PALMYRENE,
    UCDU_SCRIPT_PAU_CIN_HAU,
    UCDU_SCRIPT_PSALTER_PAHLAVI,
    UCDU_SCRIPT_SIDDHAM,
    UCDU_SCRIPT_TIRHUTA,
    UCDU_SCRIPT_WARANG_CITI,
    UCDU_SCRIPT_AHOM,
    UCDU_SCRIPT_ANATOLIAN_HIEROGLYPHS,
    UCDU_SCRIPT_HATRAN,
    UCDU_SCRIPT_MULTANI,
    UCDU_SCRIPT_OLD_HUNGARIAN,
    UCDU_SCRIPT_SIGNWRITING,
    UCDU_SCRIPT_ADLAM,
    UCDU_SCRIPT_BHAIKSUKI,
    UCDU_SCRIPT_MARCHEN,
    UCDU_SCRIPT_NEWA,
    UCDU_SCRIPT_OSAGE,
    UCDU_SCRIPT_TANGUT,
    UCDU_SCRIPT_MASARAM_GONDI,
    UCDU_SCRIPT_NUSHU,
    UCDU_SCRIPT_SOYOMBO,
    UCDU_SCRIPT_ZANABAZAR_SQUARE,
    UCDU_SCRIPT_DOGRA,
    UCDU_SCRIPT_GUNJALA_GONDI,
    UCDU_SCRIPT_HANIFI_ROHINGYA,
    UCDU_SCRIPT_MAKASAR,
    UCDU_SCRIPT_MEDEFAIDRIN,
    UCDU_SCRIPT_OLD_SOGDIAN,
    UCDU_SCRIPT_SOGDIAN,
    UCDU_SCRIPT_ELYMAIC,
    UCDU_SCRIPT_NANDINAGARI,
    UCDU_SCRIPT_NYIAKENG_PUACHUE_HMONG,
    UCDU_SCRIPT_WANCHO,
    UCDU_SCRIPT_YEZIDI,
    UCDU_SCRIPT_CHORASMIAN,
    UCDU_SCRIPT_DIVES_AKURU,
    UCDU_SCRIPT_KHITAN_SMALL_SCRIPT,
};

enum ucdu_bidi
{
    UCDU_BIDI_L,
    UCDU_BIDI_R,
    UCDU_BIDI_AL,
    UCDU_BIDI_LRE,
    UCDU_BIDI_LRO,
    UCDU_BIDI_RLE,
    UCDU_BIDI_RLO,
    UCDU_BIDI_PDF,
    UCDU_BIDI_EN,
    UCDU_BIDI_ES,
    UCDU_BIDI_ET,
    UCDU_BIDI_AN,
    UCDU_BIDI_CS,
    UCDU_BIDI_NSM,
    UCDU_BIDI_BN,
    UCDU_BIDI_B,
    UCDU_BIDI_S,
    UCDU_BIDI_WS,
    UCDU_BIDI_ON,
    UCDU_BIDI_LRI,
    UCDU_BIDI_RLI,
    UCDU_BIDI_FSI,
    UCDU_BIDI_PDI,
};

enum ucdu_lbreak
{
    UCDU_LBREAK_OP,
    UCDU_LBREAK_CL,
    UCDU_LBREAK_CP,
    UCDU_LBREAK_QU,
    UCDU_LBREAK_GL,
    UCDU_LBREAK_NS,
    UCDU_LBREAK_EX,
    UCDU_LBREAK_SY,
    UCDU_LBREAK_IS,
    UCDU_LBREAK_PR,
    UCDU_LBREAK_PO,
    UCDU_LBREAK_NU,
    UCDU_LBREAK_AL,
    UCDU_LBREAK_HL,
    UCDU_LBREAK_ID,
    UCDU_LBREAK_IN,
    UCDU_LBREAK_HY,
    UCDU_LBREAK_BA,
    UCDU_LBREAK_BB,
    UCDU_LBREAK_B2,
    UCDU_LBREAK_ZW,
    UCDU_LBREAK_CM,
    UCDU_LBREAK_WJ,
    UCDU_LBREAK_H2,
    UCDU_LBREAK_H3,
    UCDU_LBREAK_JL,
    UCDU_LBREAK_JV,
    UCDU_LBREAK_JT,
    UCDU_LBREAK_RI,
    UCDU_LBREAK_AI,
    UCDU_LBREAK_BK,
    UCDU_LBREAK_CB,
    UCDU_LBREAK_CJ,
    UCDU_LBREAK_CR,
    UCDU_LBREAK_LF,
    UCDU_LBREAK_NL,
    UCDU_LBREAK_SA,
    UCDU_LBREAK_SG,
    UCDU_LBREAK_SP,
    UCDU_LBREAK_XX,
    UCDU_LBREAK_ZWJ,
    UCDU_LBREAK_EB,
    UCDU_LBREAK_EM,
    UCDU_LBREAK_EAST_ASIAN_OP,
    UCDU_LBREAK_EAST_ASIAN_CP,
};

enum ucdu_cbreak_class
{
    UCDU_CBREAK_CR,
    UCDU_CBREAK_LF,
    UCDU_CBREAK_CONTROL,
    UCDU_CBREAK_EXTEND,
    UCDU_CBREAK_ZWJ,
    UCDU_CBREAK_REGIONAL_INDICATOR,
    UCDU_CBREAK_PREPEND,
    UCDU_CBREAK_SPACINGMARK,
    UCDU_CBREAK_L,
    UCDU_CBREAK_V,
    UCDU_CBREAK_T,
    UCDU_CBREAK_LV,
    UCDU_CBREAK_LVT,
    UCDU_CBREAK_XX,
    UCDU_CBREAK_EXTENDED_PICTOGRAPHIC,
};

enum ucdu_bracket_kind
{
    UCDU_BRACKET_NONE,
    UCDU_BRACKET_OPEN,
    UCDU_BRACKET_CLOSE,
};

/*
    The record table.
*/

struct ucdu_record
{
    unsigned char script;       // script
    unsigned char bidi_class;   // bidi class
    unsigned char lbreak : 7;   // resolved line break class.
    unsigned char zspace : 1;   // general category Zs
    unsigned char cbreak : 7;   // grapheme cluster break class.
    unsigned char paired : 1;   // has entry in paired bracket table.
};

extern const ucdu_record UCDU_TABLE[];

/*
    Bracket pairs.
*/

struct ucdu_bracket_record
{
    uint16_t bracket;
    uint16_t paired;
    uint16_t kind;
};

extern const ucdu_bracket_record UCDU_BRACKETS[];

/*
    Get index in table of a character's property record.
*/

size_t ucdu_lookup( char32_t c );

/*
    Get paired bracket for c.
*/

ucdu_bracket_kind ucdu_paired_bracket( char32_t bracket, char32_t* out_paired );


#endif
