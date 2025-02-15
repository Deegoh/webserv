#!/bin/bash

BIN_FOLDER=../bin/
TEST_FOLDER=./
INCLUDE_FOLDER=../include/

CLASS_NAMES=('JsonString' 'JsonNumber' 'JsonObject' 'JsonArray' 'JsonBoolean' 'JsonParsing')

set -e

build_code () {
    
    printf "[\x1b[32m+\x1b[0m] compile file ${CLASS_NAME} "
    # DEBUG_FLAG="-g "
    DEBUG_FLAG="-g3 -fsanitize=address "
    CMD="gcc ${TEST_FOLDER}test${CLASS_NAME}.cpp ${BIN_FOLDER}json.a -Wall -Wextra -Werror -std=c++98 -I${INCLUDE_FOLDER} -lstdc++ ${DEBUG_FLAG} -lm -o ${BIN_FOLDER}test"
    # 2> /dev/null"
    
    eval $CMD
    # echo $CMD

    if [ $? -ne 0 ] 
    then
        printf "[\x1b[31mKO\x1b[0m] file cannot be compiled\n" ;
        echo $CMD
        return
    fi

    printf "[\x1b[32m+\x1b[0m] execute test "
    ${BIN_FOLDER}test

    if [ $? -ne 0 ] 
    then
        printf "[\x1b[31mKO\x1b[0m] error in execution\n" ;
        return
    fi

    printf "[\x1b[32mOK\x1b[0m]\n" ;
}

for CLASS_NAME in "${CLASS_NAMES[@]}"
do
   build_code
done

