// gcc redis_test.c -I/usr/local/include/hiredis -o redis_test -lhiredis

#include "stdio.h"
#include "hiredis.h"

int main() {
int port = 6379;
redisContext *c = redisConnect("localhost", port);
if (c != NULL && c->err) {
    printf("Error: %s\n", c->errstr);
    // handle error
} else {
    printf("Connected to Redis\n");
}

redisReply *reply;

//reply = redisCommand(c, "AUTH password");
//freeReplyObject(reply);

reply = redisCommand(c,"SET %s %s","foo","bar");
freeReplyObject(reply);

reply = redisCommand(c,"GET %s","foo");
printf("%s\n",reply->str);
freeReplyObject(reply);

printf("done \n");

redisFree(c);

return 0;
}
