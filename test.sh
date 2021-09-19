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

    test_relational 0 != 0 0
    test_relational 0 != 1 1
    test_relational 1 != 0 1

    test_relational 0 '<' 1 1
    test_relational 1 '<' 0 0
    test_relational 1 '<' 1 0

    test_relational 0 '>' 1 0
    test_relational 1 '>' 0 1
    test_relational 1 '>' 1 0

    test_relational 0 '>=' 1 0
    test_relational 1 '>=' 0 1
    test_relational 1 '>=' 1 1

    test_relational 0 '<=' 1 1
    test_relational 1 '<=' 0 0
    test_relational 1 '<=' 1 1

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
    test_logical 0 ! 0 1
    test_logical 1 ! 0 0
    test_logical 1983479285798234589325 ! 0 0

    test_logical 0 '&&' 0 0
    test_logical 1 '&&' 0 0
    test_logical 0 '&&' 1 0
    test_logical 1 '&&' 1 1
    test_logical 13872983478 '&&' 0 0
    test_logical 13872983478 '&&' 89238023874982592845637482374 1

    test_logical 0 '||' 0 0
    test_logical 1 '||' 0 1
    test_logical 0 '||' 1 1
    test_logical 1 '||' 1 1
    test_logical 13872983478 '||' 0 1
    test_logical 13872983478 '||' 89238023874982592845637482374 1
fi

#########################################################
#                                                       #
#                     bitwises                          #
#                                                       #
#########################################################

test_bitwise () {
    
    if ( diff <(./ft_infinite $1 $2 $3) <(echo $4) )
    then
        echo -e "\033[0;32m[OK]\033[0m $1 $2 $3"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $1 $2 $3"
    fi
}

if [[ $1 == '' || $1 == 'bitwises' ]]
then
    test_logical 0 '&' 0 0
    test_logical 1 '&' 1 1
    test_logical 1 '&' 0 0

    test_logical 0 '|' 0 0
    test_logical 1 '|' 1 1
    test_logical 1 '|' 0 1

    test_logical 0 '^' 0 0
    test_logical 1 '^' 1 0
    test_logical 1 '^' 0 1

    test_logical 0 '~' 0 ff
    test_logical 1 '~' 0 fe
    test_logical ff '~' 0 0
    test_logical fe '~' 0 1

    test_logical 0 '<<' 0 0
    test_logical 1 '<<' 0 2
    test_logical 2 '<<' 0 4
    test_logical 3 '<<' 0 6

    test_logical 0 '>>' 0 0
    test_logical 1 '>>' 0 0
    test_logical 2 '>>' 0 1
    test_logical 6 '>>' 0 3
    test_logical 100 '>>' 0 80
    test_logical 80 '>>' 0 40
    test_logical 22905 '>>' 0 11482
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

#########################################################
#                                                       #
#                        sub                            #
#                                                       #
#########################################################

test_sub () {
    
    if ( diff <(./ft_infinite $1 - $2) <(echo $3) )
    then
        echo -e "\033[0;32m[OK]\033[0m $1 - $2"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $1 - $2"
    fi
}

test_sub_random () {

    a=$RANDOM
    b=$RANDOM
    
    if ( diff <(./ft_infinite $a - $b) <(printf "%x\n" $((0x$a - 0x$b))) )
    then
        echo -e "\033[0;32m[OK]\033[0m $a - $b"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $a - $b"
    fi
}

if [[ $1 == '' || $1 == 'sub' ]]
then
    test_sub 1 1 0
    test_sub 12 2 10
    test_sub ff 1 fe
    test_sub 100 1 ff

    test_sub 1 1 0
    test_sub 2 12 -10
    test_sub 1 ff -fe
    test_sub 1 100 -ff
    # for (( i=0; i<100; i++ )) do
    #     test_sub_random
    # done
fi

#########################################################
#                                                       #
#                        mul                            #
#                                                       #
#########################################################

test_mul () {
    
    if ( diff <(./ft_infinite $1 \* $2) <(echo $3) )
    then
        echo -e "\033[0;32m[OK]\033[0m $1 * $2"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $1 * $2"
    fi
}

test_mul_random () {

    a=$RANDOM
    b=$RANDOM
    
    if ( diff <(./ft_infinite $a \* $b) <(printf "%x\n" $((0x$a * 0x$b))) )
    then
        echo -e "\033[0;32m[OK]\033[0m $a * $b"
    else
        echo -e "\033[0;31m[ERROR]\033[0m $a * $b"
    fi
}

if [[ $1 == '' || $1 == 'mul' ]]
then
    test_mul 1 1 1
    test_mul 2 2 4
    test_mul 4 4 10
    test_mul 1d 9 105
    test_mul 10000000000000000 2 20000000000000000
    test_mul 21644 22905 482235354

    for (( i=0; i<100; i++ )) do
        test_mul_random
    done
fi