#!/bin/bash
read iden
while [ ! -z $iden ]
do
echo $iden | grep '_' >/dev/null
if [ $? -eq 0 ]
then
	#c++
	echo $iden | grep '_$' > /dev/null
	if [ $? -eq 0 ]
	then
		echo "Error!"
	else
		echo $iden | grep '[A-Z]' > /dev/null
		if [ $? -ne 0 ]
		then
			#valid
			while [ ! -z `echo $iden | grep '_'` ]
			do
				iden=`echo $iden | sed 's/\([a-z]*\)_\(.*\)/\1\u\2/'`
			done
			echo $iden
		else
			#invalid
			echo "Error!"
		fi
	fi
else
	echo $iden | grep '^[A-Z]' > /dev/null
	if [ $? -eq 0 ]
	then
		echo "Error!"
	else
		echo $iden | grep '_' > /dev/null
		if [ $? -ne 0 ]
		then
			#valid
			while [ ! -z `echo $iden | grep '[A-Z]'` ]
			do
				iden=`echo $iden | sed 's/\([a-z]*\)\(.*\)/\1_\l\2/'`
			done
			echo $iden
		else
			#invalid
			echo "Error!"
		fi
	fi
fi
read iden
done
exit 0
