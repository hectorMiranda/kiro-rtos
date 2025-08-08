# Spirit of Kiro - Web Platform

React + Three.js web platform for downloading games, hardware files, and community interaction.

## Features

- **Game Library**: Browse and download games
- **Hardware Downloads**: PCB files and 3D models
- **3D Visualization**: Interactive hardware preview
- **Community**: User-generated content and tutorials
- **Documentation**: Comprehensive guides and API docs

## Technology Stack

- **Frontend**: React 18 + TypeScript
- **3D Graphics**: Three.js + React Three Fiber
- **Styling**: Tailwind CSS
- **State Management**: Zustand
- **Build Tool**: Vite
- **Deployment**: Vercel/Netlify

## Project Structure

```
web-platform/
├── src/
│   ├── components/     # Reusable UI components
│   ├── pages/         # Route components
│   ├── hooks/         # Custom React hooks
│   ├── utils/         # Utility functions
│   ├── assets/        # Static assets
│   └── types/         # TypeScript definitions
├── public/            # Public assets
└── docs/             # Documentation
```

## Key Components

- **GameLibrary**: Browse and filter games
- **HardwareViewer**: 3D PCB and enclosure preview
- **DownloadManager**: File download handling
- **UserDashboard**: Personal game collection
- **CommunityForum**: Discussion and sharing

## Getting Started

```bash
npm install
npm run dev
```