# Project Society - AI Coding Agent Instructions

## Project Overview
Society Simulator is a 1:1 scale Earth voxel simulation where players build civilizations from zero knowledge. Currently in **Phase 1** - developing core voxel engine with C++/Vulkan.

## Architecture & Key Concepts

### Voxel System Foundation
- **Scale**: 1:1 Earth (6,371km radius) with 1m³ voxels
- **Delta Compression**: Only store player modifications, not entire world - procedural generation is deterministic from heightmap
- **Chunk System**: Divide world into manageable sections (size TBD: 16³ vs 32³)
- **Surface Priority**: 0 to -10m full detail, -10m to -100m on-demand, deep core algorithmic

### Current Tech Stack
```cpp
// Core established technologies:
Language: C++
Graphics: Vulkan (primary) 
Build: CMake
Libraries: GLFW (windowing), GLM (math), FastNoise2 (temporary)
Platforms: Windows + Linux
```

### Planned Project Structure
```
src/
├── core/        # Window, Input, Camera, Logger
├── renderer/    # VulkanContext, VulkanRenderer, Mesh, Shader  
├── voxel/       # Chunk, VoxelWorld, ChunkMesher, VoxelData
├── utils/       # Math utilities
└── network/     # Future multiplayer systems
```

## Development Philosophy

### No Hand-Holding Design
- **Zero tutorials/tooltips** - players discover everything through experimentation
- **Hidden mechanics** - stats, breeding, apocalypse triggers not explicitly explained
- **Discovery-driven** - tech tree unlocked by figuring out HOW, not following recipes
- Community knowledge sharing expected (Reddit/Discord theory-crafting)

### Long-Term Consequences Matter
- **Permanent effects** - civilizations can collapse, knowledge can be lost
- **Generational gameplay** - offspring inherit parent stats, bloodlines matter
- **Apocalypse scenarios** - nuclear winter, ice ages triggered by player actions
- **World Tree reset** - planetary recovery mechanism from Central Africa

## Critical Implementation Patterns

### Optimization Strategy
Always implement these rendering optimizations:
- View frustum culling (only render visible chunks)
- Depth culling (don't render deep underground unless exposed)  
- Occlusion culling (don't render blocked geometry)
- Chunk streaming based on camera position

### Delta Tracking Pattern
```cpp
// Essential: Only store modifications, not entire world
// Procedural generation must be deterministic
// Modified chunks flagged for save/load
// Default state regenerates on-the-fly
```

### Future Networking Design
- **Regional server meshing** - world divided into ~1000km regions
- **Authoritative server** with client-server validation
- **Cross-server handoff** for seamless boundary crossing
- Design engine to be network-agnostic initially

## Current Phase 1 Goals

### Target Milestones
- Window creation with Vulkan context
- Flying camera (WASD movement, mouse look)
- Chunk generation (noise-based terrain)
- Basic voxel rendering and meshing
- Raycast selection for voxel targeting
- Voxel destruction (left-click removal)
- Delta tracking for modified chunks

### Phase 1 Focus: Game Engine Foundation
- **Engine-first approach** - build extensible, modular systems that can evolve
- **Multiplayer-ready architecture** - design client-side with networking in mind (even without implementing multiplayer)
- **Component separation** - rendering, world management, input handling as distinct modules
- **Future-proof interfaces** - abstractions that can support upcoming features

### Phase 1 Exclusions
- Heightmap integration (NASA SRTM data)
- Spherical Earth projection/coordinates
- Save/load systems
- Player character model
- Actual multiplayer implementation
- Gameplay mechanics (stats, aging, survival)

## Key Files to Reference
- `society-sim-design.md` - Complete technical specification and game design
- Future `src/voxel/VoxelWorld.cpp` - Core world management and delta compression
- Future `src/renderer/VulkanRenderer.cpp` - Rendering optimization implementations

## Development Priorities
1. **Performance first** - must support massive world scale from day one
2. **Deterministic generation** - same seed = same world (enables delta compression)
3. **Chunk-based everything** - world management, rendering, networking
4. **SOLID principles** - maintainable, extensible C++ architecture for long-term development
5. **Modern Vulkan conventions** - descriptor sets, dynamic rendering, memory management best practices

Focus on solid voxel engine foundations before adding gameplay systems. The architecture must support thousands of players across a planet-sized world with years of persistent gameplay.