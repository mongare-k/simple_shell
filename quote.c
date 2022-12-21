#include "quote.h"

/**
<<<<<<< HEAD
 * quote_state - get the state associated with a given character
 * @c: character
 *
 * Return: the state associated with c
 */
quote_state_t quote_state(char c)
{
	if (_isspace(c))
		return (QUOTE_NONE);
	if (c == '"')
		return (QUOTE_DOUBLE);
	if (c == '\'')
		return (QUOTE_SINGLE);
	if (c == '\\')
		return (QUOTE_ESCAPE);
	return (QUOTE_WORD);
=======
 * _quote_state_none - get state length and next state
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_none(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (_isspace(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
>>>>>>> fc31b8e8fa09ba30b2b8e695a07d95a6295cd87b
}


/**
<<<<<<< HEAD
 * quote_state_f - get the function associated with a given state
 * @s: state
 *
 * Return: the state associated with c
 */
quote_state_fp quote_state_f(quote_state_t s)
{
	switch (s)
	{
	case QUOTE_NONE:
		return (_quote_state_none);
	case QUOTE_WORD:
		return (_quote_state_word);
	case QUOTE_DOUBLE:
		return (_quote_state_double);
	case QUOTE_SINGLE:
		return (_quote_state_single);
	case QUOTE_ESCAPE:
		return (_quote_state_escape);
	}
	return (NULL);
=======
 * _quote_state_word - get state length and next state
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_word(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && !_isspace(*str) && !_isquote(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
>>>>>>> fc31b8e8fa09ba30b2b8e695a07d95a6295cd87b
}


/**
<<<<<<< HEAD
 * quote_state_len - get the length of a given state
 * @str: string
 * @state: state
 *
 * Return: the state associated with c
 */
size_t quote_state_len(const char *str, quote_state_t state)
{
	return (quote_state_f(state)(str, NULL));
}
=======
 * _quote_state_double - get state length and next state
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_double(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '"')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 * _quote_state_single - get state length and next state
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_single(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '\'')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 * _quote_state_escape - get state length and next state
 * @str: string
 * @state: state
 *
 * Return: length of state
 */
size_t _quote_state_escape(const char *str, quote_state_t *state)
{
	if (*str)
	{
		if (state && *(++str))
			*state = quote_state(*str);
		return (1);
	}
	return (0);
}

>>>>>>> fc31b8e8fa09ba30b2b8e695a07d95a6295cd87b
