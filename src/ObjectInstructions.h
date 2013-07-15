#ifndef OBJECTINSTRUCTIONS_H
#define OBJECTINSTRUCTIONS_H

int iaload(); /*0x2E*/
int laload(); /*0x2F*/
int faload(); /*0x30*/
int daload(); /*0x31*/
int aaload(); /*0x32*/

int baload(); /*0x33*/
int caload(); /*0x34*/
int saload(); /*0x35*/

int iastore(); /*0x4F*/
int lastore(); /*0x50*/
int fastore(); /*0x51*/
int dastore(); /*0x52*/
int aastore(); /*0x53*/

int bastore(); /*0x54*/
int castore(); /*0x55*/
int sastore(); /*0x56*/

int getstatic(); /*0xB2*/
int putstatic(); /*0xB3*/

int getfield(); /*0xB4*/
int putfield(); /*0xB5*/

int new(); /*0xBB*/

int newarray(); /*0xBC*/
int anewarray(); /*0xBD*/

int arraylength(); /*0xBE*/

int checkcast(); /*0xC0*/
int instanceof(); /*0xC1*/

int multianewarray(); /*0xC5*/


#endif