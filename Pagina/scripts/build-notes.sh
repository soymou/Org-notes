#!/bin/sh

SRC_DIR="org"
DEST_DIR="src/content/docs/notes"

echo "Building notes from $SRC_DIR to $DEST_DIR..."

# Find all .org files
find "$SRC_DIR" -type f -name "*.org" | while read -r file; do
    rel_path="${file#$SRC_DIR/}"
    dir_name=$(dirname "$rel_path")
    filename=$(basename "$rel_path" .org)
    
    mkdir -p "$DEST_DIR/$dir_name"
    outfile="$DEST_DIR/$dir_name/$filename.mdx"
    
    echo "  $file -> $outfile"
    
    # 1. Convert Org to Markdown
    pandoc "$file" -f org -t markdown --mathjax -o "$outfile" --standalone
    
    # 2. Ensure display math ($$) has blank lines around it
    perl -i -0777 -pe 's/\n\$\$/\n\n\$\$/g' "$outfile"
    perl -i -0777 -pe 's/\$\$\n/\$\$\n\n/g' "$outfile"
    
    # 3. Post-process with Node.js (unescape components and inject imports)
    node scripts/post-process.cjs "$outfile"

done

echo "Done."
