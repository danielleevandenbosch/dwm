#!/bin/bash
MOM_FILE="$HOME/dwm-luke/larbs.mom"
OUTPUT_FILE="$HOME/dwm-luke/larbs_help.pdf"
MOM_MACRO_PATH="$HOME/dwm-luke/mom-2.6_c"

# Generate PDF from MOM file
groff -M"$MOM_MACRO_PATH" -mom "$MOM_FILE" -Tps | ps2pdf - "$OUTPUT_FILE"

# Check and confirm
if [ $? -eq 0 ]; then
    echo "PDF successfully generated at $OUTPUT_FILE"
else
    echo "An error occurred while generating the PDF."
fi

