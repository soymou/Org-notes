const fs = require('fs');
const path = require('path');

const filePath = process.argv[2];
if (!filePath) {
    process.exit(1);
}

let content = fs.readFileSync(filePath, 'utf8');
const fileName = path.basename(filePath);

// 1. Broadly unescape tags and quotes
content = content.replace(/\</g, '<');
content = content.replace(/\>/g, '>');
content = content.replace(/\"/g, '"');

// 2. Fix Display Math ($$) 
content = content.replace(/\$\$\s*([\s\S]*?)\s*\$\$/g, (match, p1) => {
    return `

$$
${p1.trim()}
$$

`;
});

// 3. Inject Starlight imports
const components = [
    'Aside', 'Badge', 'Card', 'CardGrid', 'Code', 'FileTree', 
    'Icon', 'LinkButton', 'LinkCard', 'Steps', 'TabItem', 'Tabs'
];
const importLine = `import { ${components.join(', ')} } from '@astrojs/starlight/components';`;

if (!content.includes('@astrojs/starlight/components')) {
    content = content.replace(/^(---[\s\S]*?---)/, `$1

${importLine}
`);
}

// 4. Hide from sidebar if it is the how-to-use guide
if (fileName === 'how-to-use.mdx') {
    if (!content.includes('sidebar:')) {
        content = content.replace(/---/, '---\nsidebar:
  hidden: true');
    }
}

// 5. Cleanup extra newlines
content = content.replace(/\n{3,}/g, '\n\n');

fs.writeFileSync(filePath, content);
