/* Return the length of the null-terminated string STR.
   Optimized to scan for the null terminator quickly by testing
   multiple bytes at once (word-sized chunks) instead of byte by byte. */
size_t
__strlen (const char *str)
{
  /* Cast the starting pointer to an integer for alignment calculations. */
  const uintptr_t s_int = (uintptr_t) str;

  /* Align the pointer down to the nearest word boundary (size of op_t). 
     This ensures word_ptr can be dereferenced safely as op_t*. */

	// This means we are reading before the start of the string. Later on
	// we create a mask that masks out this early data to not consider it
	// Because chars in C are not necessarily aligned (they are only 1 byte long)
  const op_t *word_ptr = (const op_t*) PTR_ALIGN_DOWN (str, sizeof (op_t));

  /* Load the first word (word-sized chunk of memory). */
  op_t word = *word_ptr;

  /* Create a mask that indicates if a zero byte is found in this word,
     taking into account the unaligned starting position (s_int). */
  find_t mask = shift_find (find_zero_all (word), s_int);

  /* If mask is nonzero, that means we found the null terminator
     within this first unaligned word. */
  if (mask != 0)
    return index_first (mask);

  /* Otherwise, scan forward one word at a time until a word with
     a zero byte is found. */
  do
    word = *++word_ptr;
  while (! has_zero (word));

  /* At this point, we know word contains at least one zero byte.
     Compute the string length by finding the byte offset of the first
     zero within the word, then subtract the original starting address. */
  return ((const char *) word_ptr) + index_first_zero (word) - str;
}

#ifndef STRLEN
/* Define strlen as a weak alias to __strlen, so that other code can
   use 'strlen' while this optimized implementation is provided here.
   The alias is hidden from symbol interposition to allow compiler
   optimizations on strlen calls. */
weak_alias (__strlen, strlen)
libc_hidden_builtin_def (strlen)
#endif

