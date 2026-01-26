const fs = require('fs');

const filePath = process.argv[2];
if (!filePath) {
    process.exit(1);
}

let content = fs.readFileSync(filePath, 'utf8');

// 1. Broadly unescape tags and quotes
// This ensures <Component>, <div>, and attributes like title="foo" work.
content = content.replace(/\\</g, '<');
content = content.replace(/\\>/g, '>');
content = content.replace(/\\\"/g, '"');

// 2. Inject comprehensive Starlight components import
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

fs.writeFileSync(filePath, content);
