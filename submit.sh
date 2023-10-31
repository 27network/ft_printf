#!/bin/bash

#
# Script that removes unwanted elements for submission to the moulinette
#

# Remove git files
find . -name ".git" -exec rm -rf {} \;
find . -name ".gitignore" -type f -exec rm -rf {} \;
find . -name ".gitmodules" -type f -exec rm -rf {} \;
find . -name ".gitattributes" -type f -exec rm -rf {} \;
find . -name ".git-blame-ignore-revs" -type f -exec rm -rf {} \;

# Libft-related
## Remove libft tests/ directory
rm -rf libft/tests/

# If a Makefile exists, run fclean
if [ -f "Makefile" ]; then
	make fclean
fi

# Remove this script
rm -rf submit.sh
