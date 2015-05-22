#!/bin/sh
echo "Morning or Afternoon? Tell me yes or no"
read today

case "$today" in
	yes | YES |	Y | y )
		echo "Good morning"
		echo "Up bright"
		;;
	[nN]* )
		echo "Good afternoon"
		;;
	* )
		echo "error"
		echo "Sorry , input error"
		exit 1;;
esac

exit 0
