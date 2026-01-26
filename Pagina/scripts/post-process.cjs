const fs = require('fs');
const path = require('path');

const filePath = process.argv[2];
if (!filePath) {
    console.error('No file path provided');
    process.exit(1);
}

let content = fs.readFileSync(filePath, 'utf8');

// 1. Unescape Starlight components
// Pandoc escapes < as \< and > as \> and " as \"
// We unescape them globally. MDX is fine with raw < > ".
content = content.replace(/\\</g, '<');
content = content.replace(/\\>/g, '>');
content = content.replace(/\\"/g, '"');

// 2. Inject Starlight imports
const imports = "import { Card, CardGrid, Aside, Steps, Tabs, TabItem, Icon } from '@astrojs/starlight/components';";

if (!content.includes('@astrojs/starlight/components')) {
    // Inject after frontmatter (the second ---)
    content = content.replace(/^(---[\s\S]*?---)/, `$1\n\n${imports}\n`);
}

fs.writeFileSync(filePath, content);
console.log(`  Processed ${filePath}`);
