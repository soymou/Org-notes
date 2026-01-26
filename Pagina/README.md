# Org-mode Notebook (Starlight)

A professional personal notebook built with [Astro Starlight](https://starlight.astro.build) and [Org-mode](https://orgmode.org).

## Features

- **Org-mode Authoring**: Write notes in `.org` files in the `org/` directory.
- **Auto-conversion**: Notes are automatically converted to MDX with LaTeX math support.
- **Hierarchical Navigation**: Directory structure in `org/` is preserved and automatically shown in the sidebar.
- **Math Support**: Beautifully rendered and centered LaTeX equations.
- **Professional Theme**: Built-in search, dark mode, and high-quality typography.

## Usage

### Prerequisites

Ensure you are in the Nix development environment:

```bash
nix develop
# OR if flakes are acting up
nix-shell
```

### Development

Start the development server with live reload and org watching:

```bash
npm run dev
```

Visit `http://localhost:4321`.

### Building

Build the static site:

```bash
npm run build
```

## Adding Notes

Create `.org` files in the `org/` directory. They will appear under the "Notes" section in the sidebar.

Example `org/math/calculus.org`:

```org
#+TITLE: Calculus Basics
#+AUTHOR: Me

* Limits
As $x$ approaches $a$...

$$
\lim_{x \to a} f(x) = L
$$
```