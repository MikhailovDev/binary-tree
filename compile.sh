#!/bin/bash

#read -p "====== Write file name: " filename
filename="main"

if find . -wholename "$filename.cpp"/dev/null
then
    cd $(dirname "$(find . -name "$filename.cpp")")
fi

clang-format -i $filename.cpp
cppcheck --verbose --enable=all --inconclusive --quiet .

if g++ -g -Wall -Werror -Wextra $filename.cpp -o $filename
then
    userChoice=""

	valgrind --leak-check=full --verbose --track-origins=yes --show-leak-kinds=all --log-file="valgrind_log.txt" ./$filename

    while [ "$userChoice" != "n" ]
    do
        read -p "====== Run file? Press y (yes) or n (no): " userChoice

        if [ "$userChoice" == "y" ]
        then
			clear
            echo "=== Output: "
            ./$filename
        elif [ "$userChoice" == "n" ]
        then
			rm valgrind_log.txt
			rm $filename
            exit
        else
            echo "=== Incorrect command!"
        fi
    done
fi
