#!/bin/bash
HI='\033[0;32m'
NORMAL='\033[0m'
echo -e "${HI} 1. Starts or ends with Jose.$NORMAL"
grep -E '^Jose|Jose$' $1
echo -e "${HI} 2. Contains at least 27 upper or lower case letters a - z.$NORMAL"
grep -E '[a-zA-Z]{27}' $1
echo -e "${HI} 3. Consists of more than 18 characters. The character can be anything.$NORMAL"
grep -E '.{18}' $1
echo -e "${HI} 4. Contains exactly 10 characters. The character can be anything.$NORMAL"
grep -E '^.{10}.${10}' $1
echo -e "${HI} 5. Contains words between 6 - 8 characters with a space on each side.$NORMAL"
grep -E ' [a-zA-Z]{6,8} ' $1
echo -e "${HI} 6. Contains a Local Phone Number, 3 Digits - 4 Digits.$NORMAL"
grep -E '^[^-][0-9]{3}-[0-9]{4}|^[0-9]{3}-[0-9]{4}' $1
echo -e "${HI} 7. Contains a valid URL on a line by itself.$NORMAL"
grep -E '(http|HTTP)://www\.[a-zA-Z]+\.(com|edu)' $1
