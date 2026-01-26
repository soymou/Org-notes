#!/bin/sh

SRC_DIR="org"
DEST_DIR="src/content/docs/notes"

echo "Building notes from $SRC_DIR to $DEST_DIR..."

# 1. Convert/Update existing .org files
find "$SRC_DIR" -type f -name "*.org" | while read -r file; do
    rel_path="${file#$SRC_DIR/}"
    dir_name=$(dirname "$rel_path")
    filename=$(basename "$rel_path" .org)
    
    mkdir -p "$DEST_DIR/$dir_name"
    outfile="$DEST_DIR/$dir_name/$filename.mdx"
    
    echo "  $file -> $outfile"
    
    # Convert Org to Markdown
    pandoc "$file" -f org -t markdown --mathjax -o "$outfile" --standalone
    
    # Post-process with Node.js
    node scripts/post-process.cjs "$outfile"
done

# 2. Cleanup orphaned .mdx files (files in DEST_DIR that don't have a source in SRC_DIR)
echo "Cleaning up orphaned notes..."
find "$DEST_DIR" -type f -name "*.mdx" | while read -r mdx_file; do
    rel_path="${mdx_file#$DEST_DIR/}"
    org_file="$SRC_DIR/${rel_path%.mdx}.org"
    
    if [ ! -f "$org_file" ]; then
        echo "  Removing $mdx_file"
        rm "$mdx_file"
    fi
done

# 3. Remove empty directories in DEST_DIR
find "$DEST_DIR" -type d -empty -delete

echo "Done."
