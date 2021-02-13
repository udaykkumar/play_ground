#!/bin/bash
set -e


build ()
{
	if [ -f "Makefile" ];
	then
    	make
    else
    	printf "No Make in $(PWD) Fix This .. \n"
    	exit
	fi	
}


run () 
{
	for testexec in $(find ./ -name "test.debug");
	do

    	printf "Running Test ... ${testexec} \n" 
		./${testexec} > /dev/null 2>&1 
	done

}


clean()
{
	if [ -f "Makefile" ];
	then
    	make clean
    else
    	printf "No Make in $(PWD) Fix This .. \n"
    	exit
	fi		
}


all()
{
	printf "\n\nCleaning ..\n\n"
	clean

	printf "\n\nBuilding ...\n\n"
	build
	
	printf "\n\nNot Testing  ...\n\n"
	#run
}

case "$1" 	in
	"build")
		build
		;;
	"clean")
		clean
		;;
	"test")
		run
		;;

	"all")
		all
		;;

	*)
		printf "supplied Option is [$1] It did not match the usage\n\n"
		printf "Usage : $0 [ clean | build | test | all ] \n\n"
		printf "Still Triggering the build anyway with all \n"
		printf "Wait for 5 seconds before we trigger build\n\n"

		sleep 5

		all
		;;
esac

