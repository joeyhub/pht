#ifndef PHT_STRING_H
#define PHT_STRING_H

#define PHT_STRL(s) (s).len
#define PHT_STRV(s) (s).val
#define PHT_STRL_P(s) PHT_STRL(*(s))
#define PHT_STRV_P(s) PHT_STRV(*(s))

typedef struct _pht_string_t {
    int len;
    char *val;
} pht_string_t;

void pht_str_set_len(pht_string_t *pstr, int len);
pht_string_t *pht_str_new(char *s, int len);
void pht_str_update(pht_string_t *str, char *s, int len);
int pht_str_eq(pht_string_t *phtstr1, pht_string_t *phtstr2);
void pht_str_free(pht_string_t *str);

#endif
