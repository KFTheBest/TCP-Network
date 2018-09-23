#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/socket.h> /* socket definitions */
#include <sys/types.h> /* socket types */
#include <arpa/inet.h>
#include <unistd.h> 

#define FORMAT_ONE_TYPE 0
#define FORMAT_TWO_TYPE 1
#define FORMAT_ONE_NUM_SIZE 2 // bytes
#define FORMAT_TWO_NUM_SIZE 5 // characters
#define FORMAT_ONE_AMOUNT_SIZE 1 // bytes
#define FORMAT_TWO_AMOUNT_SIZE 3 // bytes
#define NO_BYTES_READ -1
#define SUCCESS_MESSAGE "Success"
#define ERROR_MESSAGE "Format error"
#define NO_FLAGS 0

typedef struct Message {
    uint8_t trans_type;
    uint64_t file_size;
    unsigned char* file;
    uint64_t name_length;
    unsigned char* file_name;
}Message;


uint8_t read_trans_type(int);

uint64_t read_file_size(int);

unsigned char* read_file(int, uint64_t);

uint16_t read_file_name_length(int);

char* read_file_name(int, uint16_t);

bool is_good_format(unsigned char*, unsigned char*);

uint16_t get_format_one_byte_count(unsigned char*, unsigned char*);

uint16_t get_format_two_byte_count(unsigned char*, unsigned char*);

bool is_type(uint8_t);

bool is_end_of_line(unsigned char);

bool is_end_of_number(unsigned char);

uint16_t to_int16(uint8_t, uint8_t);

uint16_t get_format_one_length(uint8_t);

uint32_t get_str_as_int32(unsigned char*, unsigned char*);

uint8_t get_format_two_num_size(unsigned char*);

bool done_parsing_num(unsigned char*, unsigned char*);

Message read_message(int);

void run_server(int);

int create_server(uint16_t);


