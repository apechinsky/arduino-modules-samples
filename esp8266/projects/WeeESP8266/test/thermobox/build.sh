#!/bin/sh

# Build and deploys themobox code.
#
# Requirements:
# - platformio. Installation:
#   python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"
#

pio run --target=upload 
