echo "Menu"
echo "(1) Print user"
echo "(2) Print process"
echo "(3) Print number of files in directory"

read -p "Enter your choice: " choice

case $choice in
  1)
    echo "Current user: $(whoami)"
    ;;
  2)
    echo "Running processes:"
    ps
    ;;
  3)
    read -p "Enter directory path: " dir
    if [ -d "$dir" ]; then
      count=$(ls -1 "$dir" | wc -l)
      echo "Number of items in '$dir': $count"
    else
      echo "Directory does not exist."
    fi
    ;;
  *)
    echo "Invalid choice."
    ;;
esac

