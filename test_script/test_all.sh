GREEN="\033[0;32m"
  RED="\033[0;31m"
RESET="\033[0m"

FILE="so_long"

echo "Checking if so_long executable file exists.."
if [ ! -f ${FILE} ]
then
	echo "No so_long executable file found, creating one.."
	make fclean
	make re
else
	echo "Executable file exists! time to check"
fi

# Checking for no input
NO_INPUT_ERROR=$(./so_long  | grep "Not enough arguments, try again" | wc -l)

if [ ${NO_INPUT_ERROR} -ge 1 ]
then
	echo "Checking for no input: $GREEN [OK] $RESET"
else
	echo "Checking for no input: $RED [KO] $RESET"
fi

# Checking for maps that do not exist
NO_MAP="no_map"
NO_MAP_ERROR=$(./so_long $NO_MAP | grep "Choose a correct map!" | wc -l)

if [ ${NO_MAP_ERROR} -ge 1 ]
then
	echo "Checking for invalid input: $GREEN [OK] $RESET"
else
	echo "Checking for invalid input: $RED [KO] $RESET"
fi

# Checking for invalid walls
INVALID_WALL_MAP="./maps/maps_test/maps_invalid_map.ber"
INVALID_WALL_MAP_ERROR=$(./so_long $INVALID_WALL_MAP | grep "Invalid walls, map is not fully covered with walls!" | wc -l)

if [ ${INVALID_WALL_MAP_ERROR} -ge 1 ]
then
	echo "Checking for invalid walls: $GREEN [OK] $RESET"
else
	echo "Checking for invalid walls: $RED [KO] $RESET"
fi

# Checking for missing player (P)
MISSING_P="./maps/maps_test/maps_missing_p.ber"
MISSING_P_ERROR=$(./so_long $MISSING_P | grep "There are not enough players, exits or collectables!" | wc -l)

if [ ${MISSING_P_ERROR} -ge 1 ]
then
	echo "Checking for missing player: $GREEN [OK] $RESET"
else
	echo "Checking for missing player: $RED [KO] $RESET"
fi

# Checking for missing exit (E)
MISSING_E="./maps/maps_test/maps_missing_e.ber"
MISSING_E_ERROR=$(./so_long $MISSING_E | grep "There are not enough players, exits or collectables!" | wc -l)

if [ ${MISSING_E_ERROR} -ge 1 ]
then
	echo "Checking for missing exit: $GREEN [OK] $RESET"
else
	echo "Checking for missing exit: $RED [KO] $RESET"
fi

# Checking for missing collectables (COLLECTABLES)
MISSING_C="./maps/maps_test/maps_missing_c.ber"
MISSING_C_ERROR=$(./so_long $MISSING_C | grep "There are not enough players, exits or collectables!" | wc -l)

if [ ${MISSING_C_ERROR} -ge 1 ]
then
	echo "Checking for missing collectables: $GREEN [OK] $RESET"
else
	echo "Checking for missing collectables: $RED [KO] $RESET"
fi

# Checking for missing .ber extension
MISSING_BER="./maps/maps_test/maps_without_ber.be"
MISSING_BER_ERROR=$(./so_long $MISSING_BER | grep "Wrong extension, use a file with .ber" | wc -l)

if [ ${MISSING_BER_ERROR} -ge 1 ]
then
	echo "Checking for missing .ber extension: $GREEN [OK] $RESET"
else
	echo "Checking for missing .ber extension: $RED [KO] $RESET"
fi

# Checking for empty map
EMPTY_MAP="./maps/maps_test/maps_empty_map.ber"
EMPTY_MAP_ERROR=$(./so_long $EMPTY_MAP | grep "No new line, choose a correct map!" | wc -l)

if [ ${EMPTY_MAP_ERROR} -ge 1 ]
then
	echo "Checking for empty map: $GREEN [OK] $RESET"
else
	echo "Checking for empty map: $RED [KO] $RESET"
fi

echo "For the following 2 tests, press D multiple times:"

# Checking for dead character
DEAD_CHAR="./maps/maps_test/maps_kill_player.ber"
DEAD_CHAR_ERROR=$(./so_long $DEAD_CHAR | grep "Player got caught! Try again" | wc -l)

if [ ${DEAD_CHAR_ERROR} -ge 1 ]
then
	echo "Checking for player caught: $GREEN [OK] $RESET"
else
	echo "Checking for player caught: $RED [KO] $RESET"
fi

# Checking for working map
WORKING_MAP="./maps/maps_test/maps_ggwp.ber"
WORKING_MAP_ERROR=$(./so_long $WORKING_MAP | grep "GG WP" | wc -l)

if [ ${WORKING_MAP_ERROR} -ge 1 ]
then
	echo "Checking for working map: $GREEN [OK] $RESET"
else
	echo "Checking for working map: $RED [KO] $RESET"
fi

echo "Press the escape (ESC) button:"

# Checking for escape button
ESC_BUTTON="./maps/maps_test/maps_esc_map.ber"
ESC_BUTTON_ERROR=$(./so_long $ESC_BUTTON | grep "Exit game..." | wc -l)

if [ ${ESC_BUTTON_ERROR} -ge 1 ]
then
	echo "Checking for ESC button: $GREEN [OK] $RESET"
else
	echo "Checking for ESC button: $RED [KO] $RESET"
fi

echo "Press the cross button:"

# Checking for cross button
CROSS_BUTTON="./maps/maps_test/maps_press_cross.ber"
CROSS_BUTTON_ERROR=$(./so_long $CROSS_BUTTON | grep "Exit game" | wc -l)

if [ ${CROSS_BUTTON_ERROR} -ge 1 ]
then
	echo "Checking for cross button: $GREEN [OK] $RESET"
else
	echo "Checking for cross button: $RED [KO] $RESET"
fi
