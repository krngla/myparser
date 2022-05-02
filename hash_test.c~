#include "p_hashtable.h"
#include <stdio.h>
#include <sys/types.h>

typedef struct myload
{
  int a;
  int b;
  int c;
  char d;
} MyLoad;


int
main ()
{

  MyLoad a = { 1, 2, 3, 4 };
  MyLoad b;
  MyLoad *ap;
  ap = &a;
  b = *ap;

  printf ("%i %i\n", a.b, b.b);

  printf ("Hello, world!\n");
  printf ("sizeof uint: %li, sizeof void*: %li\n", sizeof (ptrdiff_t),
	  sizeof (void *));

  HashTable *table = t_hash_table_create (t_hash_default, 101, "main");
  MyLoad load = { 1, 2, 3, 4 };
  MyLoad loadb = { 5, 6, 7, 8 };
  char *str1 = "Hello, world!\n";
  char *key1 = "greet";
  char *key2 = "load";
  char *key3 = "loadp";
  char *key4_1 = "t4_1";
  char *pld4_1 = "Test4";
  char *key4_2 = "t4_2";
  MyLoad pld4_2 = { 5, 6, 7, 8 };
  char *key4_3 = "t4_3";
  int pld4_3[] = { 2, 3, 4 };
  char *key5 = "subtable";
  HashTable *subtable = t_hash_table_create (t_hash_default, 101, key5);
  char *key5_1 = "51";
  int pld5_1 = 51;
  char *key5_2 = "52";
  char *pld5_2 = "Test5_2";


  //HashNode * node = m_hash_node_create(str1, key1);
  HashNode *node1 =
    m_hash_node_array_create (str1, key1, strlen (str1) + 1, char);
  //HashNode * node1 = m_hash_node_string_create(str1, key1);
  HashNode *node2 = m_hash_node_create (&load, key2, MyLoad);
  HashNode *node3 = m_hash_node_create (&loadb, key3, MyLoad);

  printf ("hashkey: %i\n", t_hash_default (key1, 101));
  t_hash_table_node_insert (table, node1, key1);
  t_hash_table_node_insert (table, node2, key2);
  t_hash_table_node_insert (table, node3, key3);

  //test4
  m_hash_table_insert_string (table, pld4_1, key4_1);
  m_hash_table_insert (table, &pld4_2, key4_2, MyLoad);
  m_hash_table_insert_array (table, pld4_3, key4_3, 3, int);

  //test5
  m_hash_table_insert_table (table, &subtable, key5);
  m_hash_table_insert (subtable, &pld5_1, key5_1, int);
  m_hash_table_insert_string (subtable, pld5_2, key5_2);


  HashNode *node_out1 = t_hash_table_node_extract (table, key1);
  HashNode *node_out2 = t_hash_table_node_extract (table, key2);
  HashNode *node_out3 = t_hash_table_node_extract (table, key3);

  char *str2 = m_extract_p (node_out1, char);
  MyLoad *load2 = m_extract_p (node_out2, MyLoad);
  MyLoad load3 = m_extract (node_out3, MyLoad);
  char *opt4_1 = m_hash_table_extract_p (table, char, key4_1);
  MyLoad opt4_2 = m_hash_table_extract (table, MyLoad, key4_2);
  int *opt4_3 = m_hash_table_extract_p (table, int, key4_3);
  printf ("str : %s", str2);
  printf ("a:%i, b:%i, c:%i, d:%i\n", load2->a, load2->b, load2->c, load2->d);
  printf ("a:%i, b:%i, c:%i, d:%i\n", load3.a, load3.b, load3.c, load3.d);
  printf ("test 4_1 : str4 : %s\n", opt4_1);
  printf ("test 4_2 : a:%i, b:%i, c:%i, d:%i\n", opt4_2.a, opt4_2.b, opt4_2.c,
	  opt4_2.d);
  printf ("test 4_3 : {%i, %i, %i}\n", opt4_3[0], opt4_3[1], opt4_3[2]);

  //test5
  int opt5_1 = m_hash_table_extract_va (table, int, key5, key5_1);
  char *opt5_2 = m_hash_table_extract_va_p (table, char, key5, key5_2);
  printf ("test 5_1 : %i\n", opt5_1);
  printf ("test 5_2 : %s\n", opt5_2);
  t_hash_table_destroy (table);
  return 0;
}
