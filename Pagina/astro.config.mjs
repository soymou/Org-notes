import { defineConfig } from 'astro/config';
import starlight from '@astrojs/starlight';
import remarkMath from 'remark-math';
import rehypeMathjax from 'rehype-mathjax';

// https://astro.build/config
export default defineConfig({
  integrations: [
    starlight({
      title: 'Notas',
      // Using 'root' locale ensures Spanish is served at the root URL (/)
      // instead of /es/
      defaultLocale: 'root',
      locales: {
        root: {
          label: 'Español',
          lang: 'es',
        },
      },
      sidebar: [
        {
          label: 'Notas',
          autogenerate: { directory: 'notes' },
          collapsed: true,
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