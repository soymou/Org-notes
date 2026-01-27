#!/bin/sh

SRC_DIR="org"
DEST_DIR="src/content/docs/notes"
DOCS_ROOT="src/content/docs"

echo "Building notes from $SRC_DIR to $DEST_DIR..."

# 1. Convert/Update existing .org files
find "$SRC_DIR" -type f -name "*.org" | while read -r file; do
    rel_path="${file#$SRC_DIR/}"
    dir_name=$(dirname "$rel_path")
    filename=$(basename "$rel_path" .org)
    
    if [ "$filename" = "how-to-use" ]; then
        mkdir -p "$DOCS_ROOT"
        outfile="$DOCS_ROOT/how-to-use.mdx"
    else
        mkdir -p "$DEST_DIR/$dir_name"
        outfile="$DEST_DIR/$dir_name/$filename.mdx"
    fi
    
    echo "  $file -> $outfile"
    
    # Prepend #+OPTIONS: H:6 to the content before passing to pandoc
    # This ensures that deep headers (level 4+) are not converted to lists.
    (echo "#+OPTIONS: H:6"; cat "$file") | pandoc -f org -t markdown --mathjax -o "$outfile" --standalone
    
    # Post-process with Node.js
    node scripts/post-process.cjs "$outfile"
done

# 2. Cleanup orphaned .mdx files
echo "Cleaning up orphaned notes..."
if [ -d "$DEST_DIR" ]; then
    find "$DEST_DIR" -type f -name "*.mdx" | while read -r mdx_file; do
        rel_path="${mdx_file#$DEST_DIR/}"
        org_file="$SRC_DIR/${rel_path%.mdx}.org"
        if [ ! -f "$org_file" ]; then
            echo "  Removing orphaned file: $mdx_file"
            rm "$mdx_file"
        fi
    done
    find "$DEST_DIR" -type d -empty -delete
fi

find "$DOCS_ROOT" -maxdepth 1 -type f -name "*.mdx" ! -name "index.mdx" | while read -r mdx_file; do
    filename=$(basename "$mdx_file" .mdx)
    org_file="$SRC_DIR/$filename.org"
    if [ ! -f "$org_file" ]; then
        echo "  Removing orphaned root file: $mdx_file"
        rm "$mdx_file"
    fi
done

echo "Done."