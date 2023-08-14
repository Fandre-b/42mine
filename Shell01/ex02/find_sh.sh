find . -type f -name "*.sh" -execdir basename {} \; | sed 's/\.sh$//'
