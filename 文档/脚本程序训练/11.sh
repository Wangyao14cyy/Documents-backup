#!/bin/sh

ed a_text_file <<!Funkystuff!
3
d
.,\$s/is/was/
w
q
!Funkystuff!
exit 0
