import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';
import remarkMath from 'remark-math';
import rehypeMathjax from 'rehype-mathjax';

// https://astro.build/config
export default defineConfig({
  integrations: [
    starlight({
      title: 'My Notebook',
      sidebar: [
        {
          label: 'Notes',
          autogenerate: { directory: 'notes' },
        },
      ],
      customCss: [
        './src/styles/custom.css',
      ],
    }),
  ],
  markdown: {
    remarkPlugins: [remarkMath],
    rehypePlugins: [rehypeMathjax],
  },
});
