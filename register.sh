#! /bin/sh

if [[ $EUID -ne 0 ]]; then
    echo "Must be run as root! Exiting..." 2>&1
    exit 1
else
    mount binfmt_misc -t binfmt_misc /proc/sys/fs/binfmt_misc
    echo ':nine:M::::' > /proc/sys/fs/binfmt_misc/register
fi