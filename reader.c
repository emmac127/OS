/* Author: Robbert van Renesse 2018
 *
 * The interface is as follows:
 *	reader_t reader_create(int fd);
 *		Create a reader that reads characters from the given file descriptor.
 *
 *	char reader_next(reader_t reader):
 *		Return the next character or -1 upon EOF (or error...)
 *
 *	void reader_free(reader_t reader):
 *		Release any memory allocated.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "shall.h"

struct reader {
	int fd;
	char arr[512];
	int index;
};

reader_t reader_create(int fd){
	reader_t reader = (reader_t) calloc(1, sizeof(*reader));
	reader->index = 512;
	reader->fd = fd;
	return reader;
}

char reader_next(reader_t reader){

	char c;
	int n = read(reader->fd, &c, 1);
	return n == 1 ? c : EOF;

	//char c;
	// if(reader->index == -1){
	// 	char c;
	// 	int n = read(reader->fd, &c, 1);
	// 	return n == 1 ? c : EOF;
	// }
	// else if(reader->index == 512){
	// 	int n = read(reader->fd, &(reader->arr), 512);
	//
	// 	reader->index = 0;
	// 	if(n ==1)
	// 		return reader->arr[0];
	// 	else{
	// 		reader->index = -1;
	// 		return reader_next(reader);
	// 	}
	// }
	// else{
	// 	char c = reader->arr[reader->index];
	// 	reader -> index +=1;
	// 	if(c == EOF)
	// 		reader-> index= -1;
	//
	// 	return c;
	// }

}

void reader_free(reader_t reader){
	free(reader);
}
