#!/bin/bash

set -e

# Check if this is a first run of this container
if [[ ! -e /var/run/irods_installed ]]; then
    # set up iRODS
    python /var/lib/irods/scripts/setup_irods.py < /etc/irods/setup_responses

    touch /var/run/irods_installed

else
    service irods start
fi

# this script must end with a persistent foreground process 
tail -F /var/lib/irods/log/rodsLog.*
