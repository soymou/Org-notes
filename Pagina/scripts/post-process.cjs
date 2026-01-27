const fs = require('fs');
const path = require('path');
const fp = process.argv[2];
if (!fp) process.exit(1);
let c = fs.readFileSync(fp, 'utf8');
const fn = path.basename(fp);
c = c.replace(/\\([<>"])/g, '$1');
c = c.replace(/^\s*\\\s*$/gm, '');
c = c.replace(/\[(.*?)\]\{.underline\}/g, '<u>$1</u>');
c = c.replace(/`([^`]+)`\{.verbatim\}/g, '`$1`');
c = c.replace(/\$\$\s*([\s\S]*?)\s*\$\$/g, (m, p1) => `\n\n$$\n${p1.trim()}\n$$\n\n`);
const comps = ['Aside', 'Card', 'CardGrid', 'Steps', 'Tabs', 'TabItem', 'FileTree', 'LinkCard', 'LinkButton'];
const pat = comps.join('|');
const re = new RegExp(`(<\\/?(?:${pat})[\\s\\S]*?>)`, 'g');
c = c.replace(re, (m) => `\n\n${m.replace(/\s+/g, ' ').trim()}\n\n`);
if (fn === 'how-to-use.mdx' && !c.includes('sidebar:')) c = c.replace(/^---/, '---\nsidebar:\n  hidden: true');
const imports = "import { Aside, Badge, Card, CardGrid, Code, FileTree, Icon, LinkButton, LinkCard, Steps, TabItem, Tabs } from '@astrojs/starlight/components';";
if (!c.includes('@astrojs/starlight/components')) {
    const idx = c.indexOf('---', 3);
    if (idx !== -1) c = c.substring(0, idx + 3) + '\n\n' + imports + '\n' + c.substring(idx + 3);
}
c = c.replace(/\n{3,}/g, '\n\n').trim() + '\n';
fs.writeFileSync(fp, c);
