/* universal.c

   Test diagnostics for universal character names.
 */

#ifdef TEST1
// ':' via UCN in string
const char *string = u8"\u003a"; /* WARNING */
#endif

#ifdef TEST2
// ':' via UCN in identifier
const char *string\u003a = u8":"; /* ERROR */
#endif

#ifdef TEST3
// € via UCN in string
const char *string = u8"\u20ac";
#endif

