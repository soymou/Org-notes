const fs = require('fs');

const filePath = process.argv[2];
if (!filePath) {
    process.exit(1);
}

let content = fs.readFileSync(filePath, 'utf8');

// 1. Broadly unescape tags and quotes
content = content.replace(/\</g, '<');
content = content.replace(/\>/g, '>');
content = content.replace(/\"/g, '"');

// 2. Fix Display Math ($$) 
// Ensure it has its own lines and is not collapsed to $$test$$
// We look for $$ something $$
// $$
// something
// $$
content = content.replace(/\$\$\s*([\s\S]*?)\s*\$\$/g, (match, p1) => {
    return `\n\n$$\n${p1.trim()}\n$$\n\n`;
});

// 3. Inject comprehensive Starlight components import
const components = [
    'Aside',
    'Badge',
    'Card',
    'CardGrid',
    'Code',
    'FileTree',
    'Icon',
    'LinkButton',
    'LinkCard',
    'Steps',
    'TabItem',
    'Tabs'
];

const importLine = `import { ${components.join(', ')} } from '@astrojs/starlight/components';`;

if (!content.includes('@astrojs/starlight/components')) {
    content = content.replace(/^(---[\s\S]*?---)/, `$1\n\n${importLine}\n`);
}

// 4. Cleanup extra newlines that might have been created
content = content.replace(/\n{3,}/g, '\n\n');

fs.writeFileSync(filePath, content);