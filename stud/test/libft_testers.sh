#!/bin/sh
rm -rf "5IGI0"
rm -rf "alelievr"
rm -rf "notjustjoe"
rm -rf "tripouille"
rm -rf "war-machine"
rm -rf "Ysoroko"
echo "norminette..."
(
    cd "libft" || exit
    printf "\033[91m"
    norminette | grep "Error!"
    printf "\033[0m"
)
echo "Norminette completed. "
read -p "Press enter to continue"

echo "cloning repositories..."
git clone https://github.com/5IGI0/libftsigtest.git "5IGI0"
git clone https://github.com/alelievr/libft-unit-test.git "alelievr"
git clone https://github.com/notjustjoe/libfttester.git "notjustjoe"
git clone https://github.com/tripouille/libftTester.git "tripouille"
git clone https://github.com/0x050f/libft-war-machine.git "war-machine"
git clone https://github.com/Ysoroko/FT_SPLIT_TESTER.git "Ysoroko"

tofind_5IGI0="LIBFT_PATH ?= ../"
toreplace_5IGI0="LIBFT_PATH ?= ../libft"
sed -i -e "s~${tofind_5IGI0}~${toreplace_5IGI0}~g" ./5IGI0/Makefile

tofind_notjustjoe="PATH_LIBFT			= ../"
toreplace_notjustjoe="PATH_LIBFT			= ../libft"
sed -i -e "s~${tofind_notjustjoe}~${toreplace_notjustjoe}~g" ./notjustjoe/Makefile

tofind_notjustjoe_h="#include \"../../libft.h\""
toreplace_notjustjoe_h="#include \"../../libft/libft.h\""
find ./notjustjoe/srcs/ -type f -name "*.cpp" | xargs sed -i -e "s~${tofind_notjustjoe_h}~${toreplace_notjustjoe_h}~g"

tofind_notjustjoe_bonus_h="#include \"../../../libft.h\""
toreplace_notjustjoe_bonus_h="#include \"../../../libft/libft.h\""
find ./notjustjoe/srcs/bonus/ -type f -name "*.cpp" | xargs sed -i -e "s~${tofind_notjustjoe_bonus_h}~${toreplace_notjustjoe_bonus_h}~g"

tofind_notjustjoe_errorcorrect1="fakeSubstr = a(\"42Nice\", 2, 50);realSubstr = b(\"42Nice\" + 2, 50);"
toreplace_notjustjoe_errorcorrect1="fakeSubstr = a(\"42Nice\", 2, 50);realSubstr = b(\&\"42Nice\" [+ 2], 50);"
find ./notjustjoe/srcs/ -type f -name "substr.cpp" | xargs sed -i -e "s~${tofind_notjustjoe_errorcorrect1}~${toreplace_notjustjoe_errorcorrect1}~g"

tofind_notjustjoe_errorcorrect2="fakeSubstr = a(\"0560ez65r1rtye961rty650er56tyh0r65\", 5, 20);realSubstr = b(\"0560ez65r1rtye961rty650er56tyh0r65f\" + 5, 20);"
toreplace_notjustjoe_errorcorrect2="fakeSubstr = a(\"0560ez65r1rtye961rty650er56tyh0r65\", 5, 20);realSubstr = b(\&\"0560ez65r1rtye961rty650er56tyh0r65\" [+ 5], 20);"
find ./notjustjoe/srcs/ -type f -name "substr.cpp" | xargs sed -i -e "s~${tofind_notjustjoe_errorcorrect2}~${toreplace_notjustjoe_errorcorrect2}~g"

tofind_notjustjoe_errorcorrect3="fakeSubstr = a(\"pendant (str\[i\])\", 1, 1);realSubstr = b(\"pendant (str\[i\])\" + 1, 1);"
toreplace_notjustjoe_errorcorrect3="fakeSubstr = a(\"pendant (str\[i\])\", 1, 1);realSubstr = b(\&\"pendant (str\[i\])\" [+ 1], 1);"
find ./notjustjoe/srcs/ -type f -name "substr.cpp" | xargs sed -i -e "s~${tofind_notjustjoe_errorcorrect3}~${toreplace_notjustjoe_errorcorrect3}~g"

tofind_notjustjoe_errorcorrect4="fakeSubstr = a(\"pendant (str\[i\])\", 16, 17);realSubstr = b(\"pendant (str\[i\])\" + 16, 17);"
toreplace_notjustjoe_errorcorrect4="fakeSubstr = a(\"pendant (str\[i\])\", 16, 17);realSubstr = b(\&\"pendant (str\[i\])\" [+ 16], 17);"
find ./notjustjoe/srcs/ -type f -name "substr.cpp" | xargs sed -i -e "s~${tofind_notjustjoe_errorcorrect4}~${toreplace_notjustjoe_errorcorrect4}~g"

tofind_tripouille="LIBFT_PATH		= \$(PARENT_DIR)"
toreplace_tripouille="LIBFT_PATH		= ../libft"
sed -i -e "s~${tofind_tripouille}~${toreplace_tripouille}~g" ./tripouille/Makefile

tofind_ysoroko="SRC 			=	../\*.c"
toreplace_ysoroko="SRC 			=	../libft/*.c"
sed -i -e "s~${tofind_ysoroko}~${toreplace_ysoroko}~g" ./Ysoroko/Makefile

sh ./war-machine/grademe.sh
tofind_warmachine="PATH_LIBFT=\"../\""
toreplace_warmachine="PATH_LIBFT=\"../libft\""
sed -i -e "s~${tofind_warmachine}~${toreplace_warmachine}~g" ./war-machine/my_config.sh

echo "\n"
echo "***********************************"
echo "**                               **"
echo "**     ALL SETUP FOR TESTING     **"
echo "**                               **"
echo "***********************************"
echo "\n"

read -r -p "Ready to run 5IGI0 tests (1/6? [Y/n]" answer
case $answer in
      [yY][eE][sS]|[yY]|"")
            echo "Running 5IGI0 tests..."
            (
                cd "5IGI0" || exit
                make all
            )
            echo "5IGI0 tests done."
            ;;
      [nN][oO]|[nN])
            echo "5IGI0 tests skipped."
            ;;
      *)
            echo "Invalid input..."
            echo "5IGI0 tests skipped."
            exit 1
            ;;
esac

read -r -p "Ready to run alelievr tests (2/6)? [Y/n]" answer
case $answer in
      [yY][eE][sS]|[yY]|"")
            echo "Running alelievr tests..."
            (
                cd "alelievr" || exit
                make f
            )
            echo "alelievr tests done."
            ;;
      [nN][oO]|[nN])
            echo "alelievr tests skipped."
            ;;
      *)
            echo "Invalid input..."
            echo "alelievr tests skipped."
            exit 1
            ;;
esac

read -r -p "Do you want to see the result.log? [y/N]" answer
case $answer in
      [yY][eE][sS]|[yY])
            echo "Result log:"
            (
                cd "alelievr" || exit
                cat result.log
            )
            ;;
      [nN][oO]|[nN]|"")
            echo "Result log skipped."
            ;;
      *)
            echo "Invalid input..."
            echo "Result log skipped."
            exit 1
            ;;
esac

read -r -p "Ready to run notjustjoe tests (3/6)? [Y/n]" answer
case $answer in
      [yY][eE][sS]|[yY]|"")
            echo "Running notjustjoe tests..."
            (
                cd "notjustjoe" || exit
                make all
            )
            echo "notjustjoe tests done."
            ;;
      [nN][oO]|[nN])
            echo "notjustjoe tests skipped."
            ;;
      *)
            echo "Invalid input..."
            echo "notjustjoe tests skipped."
            exit 1
            ;;
esac

read -r -p "Ready to run tripouille tests (4/6)? [Y/n]" answer
case $answer in
      [yY][eE][sS]|[yY]|"")
            echo "Running tripouille tests..."
            (
                cd "tripouille" || exit
                make a
            )
            echo "tripouille tests done."
            ;;
      [nN][oO]|[nN])
            echo "tripouille tests skipped."
            ;;
      *)
            echo "Invalid input..."
            echo "tripouille tests skipped."
            exit 1
            ;;
esac

read -r -p "Ready to run War-Machine tests (5/6)? [Y/n]" answer
case $answer in
      [yY][eE][sS]|[yY]|"")
            echo "Running War-Machine tests..."
            (
                cd "war-machine" || exit
                sh grademe.sh
            )
            echo "War-Machine tests done."
            ;;
      [nN][oO]|[nN])
            echo "War-Machine tests skipped."
            ;;
      *)
            echo "Invalid input..."
            echo "War-Machine tests skipped."
            exit 1
            ;;
esac

read -r -p "Ready to run Ysoroko tests (6/6)? [Y/n]" answer
case $answer in
      [yY][eE][sS]|[yY]|"")
            echo "Running Ysoroko tests..."
            (
                cd "Ysoroko" || exit
                make re
            )
            echo "Ysoroko tests done."
            ;;
      [nN][oO]|[nN])
            echo "Ysoroko tests skipped."
            ;;
      *)
            echo "Invalid input..."
            echo "Ysoroko tests skipped."
            exit 1
            ;;
esac

rm -rf "5IGI0"
rm -rf "alelievr"
rm -rf "notjustjoe"
rm -rf "tripouille"
rm -rf "war-machine"
rm -rf "Ysoroko"

echo "All tests done!"
