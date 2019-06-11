find . -depth -name "*.sh" -print | sed 's/\.sh$//' | sed 's/\(.*\)\///g'
