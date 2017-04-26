/*  hash.h
*/

#ifndef HASH_H
#define HASH_H

const int HASH_TABLE_SIZE = 10993; // 101, 8017 , 10993 , 49957

typedef struct nList     /*  table entry:  */
{
	string name;          /*  defined name         */
	struct nList *next;  /*  next entry in chain  */
}nList;

typedef struct nList *NListPtr;

unsigned Hash(string name);
NListPtr Lookup(string name);
NListPtr LookupPrintCount(string s);
NListPtr Insert(string name);

void PrintHashTable();

void PrintHashTableBuckets();

void PrintHashTableBucketsMinMax();

#endif  /*  HASH_H  */