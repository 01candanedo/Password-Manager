# Password Manager

Welcome to Password Manager! This repository contains the source code and documentation.

## Overview

This project was originally created in August 2019 by @01candanedo, this C++ source code provided a local password management solution.

## Documentation

In this repository, you will find comprehensive documentation to help you understand and use the project effectively. The documentation includes:

- **API Docs:** Detailed documentation for the project's API endpoints, parameters, and responses. You can find the API documentation in the `api-docs/` directory.

- **Diagrams:** Visual representations of the project's architecture, workflows, or other relevant diagrams. Diagrams can be found in the `diagrams/` directory.

- **Guides:** Step-by-step guides and tutorials to help you get started with the project and explore its features. You can find guides in the `guides/` directory.

## Getting Started

To view or use the project, you'll need to switch to the respective frontend and backend branches.

## Contact

If you have any questions, suggestions, or feedback, feel free to contact us at 01candanedo@gmail.com

### Vue.js Integration: 
We've rebuilt the password manager from the ground up using Vue.js, a progressive JavaScript framework, to provide a more dynamic and intuitive user.

### Enhanced Security: 
While maintaining the core security principles of the original version, our Vue.js-powered password manager offers additional layers of encryption.

### Improved User Interface: 
Enjoy a modern and responsive interface designed to streamline your password management experience.

## Recommended IDE Setup

[VSCode](https://code.visualstudio.com/) + [Volar](https://marketplace.visualstudio.com/items?itemName=Vue.volar) (and disable Vetur).

## Type Support for `.vue` Imports in TS

TypeScript cannot handle type information for `.vue` imports by default, so we replace the `tsc` CLI with `vue-tsc` for type checking. In editors, we need [Volar](https://marketplace.visualstudio.com/items?itemName=Vue.volar) to make the TypeScript language service aware of `.vue` types.

## Customize configuration

See [Vite Configuration Reference](https://vitejs.dev/config/).

## Project Setup

```sh
bun install
```

### Compile and Hot-Reload for Development

```sh
bun dev
```

### Type-Check, Compile and Minify for Production

```sh
bun build
```

### Run Headed Component Tests with [Cypress Component Testing](https://on.cypress.io/component)

```sh
bun test:unit:dev # or `bun test:unit` for headless testing
```

### Run End-to-End Tests with [Cypress](https://www.cypress.io/)

```sh
bun test:e2e:dev
```

This runs the end-to-end tests against the Vite development server.
It is much faster than the production build.

But it's still recommended to test the production build with `test:e2e` before deploying (e.g. in CI environments):

```sh
bun build
bun test:e2e
```
