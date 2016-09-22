#!/bin/bash
set -e

red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr 0`
error=false

echo "-=[ Test Suit 1.0 ]=-"
echo ""
echo " Making project..."
make > /dev/null

echo ""

for i in `seq 1 6`; do
echo " Compiling test $i..."
./bin/compiler -d -o tests/test$i/test$i.c tests/test$i/test$i.lua > /dev/null
g++ -o tests/test$i/test$i tests/test$i/test$i.c > /dev/null
#make graph > /dev/null
#mv *.pdf tests/test$i/ > /dev/null
done

echo ""

# Test 1
if [[ $(./tests/test1/test1) == "497" ]]; then
  echo " Test 1: ${green}OK!${reset}"
else
  echo " Test 1: ${red}ERROR!${reset}"
  error=true
fi

# Test 2
if [[ $(./tests/test2/test2) == "27" ]]; then
  echo " Test 2: ${green}OK!${reset}"
else
  echo " Test 2: ${red}ERROR!${reset}"
  error=true
fi

# Test 3
if [[ $(echo 5 | ./tests/test3/test3 | grep "factorial of 5 is 120") == "factorial of 5 is 120" ]]; then
  echo " Test 3: ${green}OK!${reset}"
else
  echo " Test 3: ${red}ERROR!${reset}"
  error=true
fi

# Test 4
if [[ $(echo 13 | ./tests/test4/test4 | grep "13 is a factor of 13") == "13 is a factor of 13" ]]; then
  echo " Test 4: ${green}OK!${reset}"
else
  echo " Test 4: ${red}ERROR!${reset}"
  error=true
fi

# Test 6
if [[ $(./tests/test6/test6) == "1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, ..." ]]; then
  echo " Test 6: ${green}OK!${reset}"
else
  echo " Test 6: ${red}ERROR!${reset}"
  error=true
fi

if [[ "$error" == true ]]; then
  exit 1
else
  exit 0
fi

#./tests/test5/test5
