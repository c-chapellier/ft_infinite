#!/bin/bash

#########################################################
#                                                       #
#                    relationals                        #
#                                                       #
#########################################################

test_relational () {
    
    if ( diff <(./ft_infinite $1 $2 $3) <(echo $4) )
    then
        echo -e "\033[0;32m[OK]\033[0m $1 $2 $3"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $1 $2 $3"
    fi
}

test_relational_random () {

    a=$RANDOM
    b=$RANDOM
    
    if ( diff <(./ft_infinite $a '<' $b) <(printf "%d\n" $((0x$a < 0x$b))) )
    then
        echo -e "\033[0;32m[OK]\033[0m $a '<' $b"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $a '<' $b"
    fi
}

if [[ $1 == '' || $1 == 'relationals' ]]
then
    test_relational 0 = 0 1
    test_relational 10 = 10 1
    test_relational 0 = 1 0
    test_relational 1 = 0 0
    test_relational 13384738744 = 239847 0

    test_relational 0 ! 0 0
    test_relational 0 ! 1 1
    test_relational 1 ! 0 1

    test_relational 0 '<' 1 1
    test_relational 1 '<' 0 0
    test_relational 1 '<' 1 0

    test_relational 0 '>' 1 0
    test_relational 1 '>' 0 1
    test_relational 1 '>' 1 0

    test_relational 0 g 1 0
    test_relational 1 g 0 1
    test_relational 1 g 1 1

    test_relational 0 s 1 1
    test_relational 1 s 0 0
    test_relational 1 s 1 1

    for (( i=0; i<10; i++ )) do
        test_relational_random
    done
fi


#########################################################
#                                                       #
#                     logicals                          #
#                                                       #
#########################################################

test_logical () {
    
    if ( diff <(./ft_infinite $1 $2 $3) <(echo $4) )
    then
        echo -e "\033[0;32m[OK]\033[0m $1 $2 $3"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $1 $2 $3"
    fi
}

if [[ $1 == '' || $1 == 'logicals' ]]
then
    test_logical 0 n 0 1
    test_logical 1 n 0 0
    test_logical 1983479285798234589325 n 0 0

    test_logical 0 '&' 0 0
    test_logical 1 '&' 0 0
    test_logical 0 '&' 1 0
    test_logical 1 '&' 1 1
    test_logical 13872983478 '&' 0 0
    test_logical 13872983478 '&' 89238023874982592845637482374 1

    test_logical 0 '|' 0 0
    test_logical 1 '|' 0 1
    test_logical 0 '|' 1 1
    test_logical 1 '|' 1 1
    test_logical 13872983478 '|' 0 1
    test_logical 13872983478 '|' 89238023874982592845637482374 1
fi


#########################################################
#                                                       #
#                        add                            #
#                                                       #
#########################################################

test_add () {
    
    if ( diff <(./ft_infinite $1 + $2) <(echo $3) )
    then
        echo -e "\033[0;32m[OK]\033[0m $1 + $2"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $1 + $2"
    fi
}

test_add_random () {

    a=$RANDOM
    b=$RANDOM
    
    if ( diff <(./ft_infinite $a + $b) <(printf "%x\n" $((0x$a + 0x$b))) )
    then
        echo -e "\033[0;32m[OK]\033[0m $a + $b"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $a + $b"
    fi
}

if [[ $1 == '' || $1 == 'add' ]]
then
    test_add 1 1 2
    test_add 1 2 3
    test_add ff 1 100
    test_add 0 0 0
    test_add a 1 b
    for (( i=0; i<100; i++ )) do
        test_add_random
    done
fi
