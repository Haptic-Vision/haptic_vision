#!/bin/bash

# Function to extract the direct download link from the Google Drive page
get_direct_link() {
    local file_id=$(echo "$1" | awk -F'/' '{print $NF}')
    local confirm=$(curl -sc /tmp/gcookie "https://drive.google.com/uc?export=download&id=${file_id}" | \
                    sed -rn 's/.*confirm=([0-9A-Za-z_]+).*/\1/p')

    curl -Lb /tmp/gcookie "https://drive.google.com/uc?export=download&confirm=${confirm}&id=${file_id}"
}

# Download files using their Google Drive links
# Add more links below if you have additional files to download
get_direct_link "https://drive.google.com/drive/folders/1WLxdlY-uv_qt4S8HHcYhlSxwbkwdMDL?usp=sharing" > libtorch
get_direct_link "https://drive.google.com/file/d/1MXmQSrAa8TgN4nDhPzfwJrWUY1WBS9zK/view?usp=sharing" > yolov5s.torchscript.pt

# Replace "file1.ext" and "file2.ext" with the desired filenames for each downloaded file.
