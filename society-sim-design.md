# Project Society - Design Document

**Public Name:** Society Simulator  
**Internal Name:** project-society

## Core Concept

A 1:1 scale Earth simulation where players spawn into a pristine, massively multiplayer world and must survive, discover, and build civilizations from absolute zero knowledge.

---

## Technical Foundation

### Voxel-Based World

- **Scale:** 1:1 Earth (6,371km radius, ~40,075km circumference)
- **Resolution:** 1 meter³ voxels
- **Terrain Generation:** Based on real Earth heightmap data (NASA SRTM, GEBCO)
- **Deformable:** Players can modify terrain by breaking/placing voxels

### Optimization Strategy

**Delta Compression / Change Tracking:**
- Procedural generation is deterministic from heightmap
- Only store player modifications, not the entire world
- Default state regenerates on-the-fly
- Modified voxels saved as delta changes

**Rendering Optimization:**
- View frustum culling (only render visible chunks)
- Depth culling (don't render deep underground voxels unless exposed)
- Occlusion culling (don't render blocked geometry)
- Chunk system (divide world into manageable sections)

**Surface-Only Detail:**
- 0 to -10m: Full voxel detail
- -10m to -100m: Generate on-demand when exposed
- Deep core: Purely algorithmic until accessed

### Platform Requirements

- **Native application** (not web-based)
- **Cross-platform:** Windows and Linux
- **Build system:** CMake (likely)
- **Language:** C++ or Rust (TBD based on developer experience)
- **Graphics API:** Vulkan (preferred) or OpenGL

---

## Time System

- **1 game day = 1 real hour**
- **1 game year = 15 real days**
- **80 game years = ~3.3 real years** (may be adjusted during balancing)

### Aging Mechanics

- Players age in real-time
- Gain stat points on age-up
- Early game: Most die before old age due to lack of medicine
- Late game: Discovered medicine can extend lifespan

---

## Spawn Systems

### Omega Spawn

- **Location:** Central Africa (near World Tree)
- **Starting age:** 22 years old
- **Knowledge:** Zero - must learn or join settlement
- **Stats:** Baseline ± random variance

### Family Spawn

- **Mechanism:** Family code allows grouped spawning
- **Location:** Anywhere in the world
- **Shared code:** All family members share the same family code
- **Knowledge:** Tech tree shared (but not automatically unlocked)

### Offspring Spawn

- **Requirements:** Male and female character must join to create offspring code
- **Mechanics:** 
  - Offspring randomly inherit stats from parents
  - Parents are the ceiling (normally)
  - Extremely rare: Nat 100 roll exceeds parent stats
  - Start small and fragile
- **Genetic drift:** Unused stats regress toward omega baseline over generations

---

## Social Structures

### Hierarchy

1. **Family** - Base unit (uses family code to spawn together)
2. **Clan** - 2+ families, can claim territory
3. **Village** - Clan with 10+ families
4. **Town** - Clan with 20+ families
5. **City** - 2+ towns in close proximity
6. **Nation** - Large contiguous land claim encompassing multiple settlements

### Territory Rules

- **Clans** can claim territory (must be able to defend it)
- **Towns/Cities** must be built in close geographic proximity
  - Example: Edinburgh can't span both east and west Scotland
  - City of Edinburgh encompasses surrounding towns within balanced range
- **Nations** require adjacent, contiguous claims
  - Can wage war to claim settlements
  - Settlements can voluntarily join nations
  - Once joined, settlements cannot leave unless conquered
  - Settlements built within nation borders are automatically part of that nation

---

## Knowledge & Technology

### Tech Tree System

- **Discovery-based:** Players must figure out HOW to unlock technologies
- **No instructions:** Players know nothing initially
- **Shared within groups:**
  - Families share tech tree progress
  - Settlements share tech tree progress
  - Individual players must still unlock for themselves
- **Leaving penalties:** Leaving settlement = lose access to unlearned tech
- **National knowledge:** Nations CHOOSE whether to share knowledge

### Discovery Examples

- "This plant cures poison"
- "This plant ground in pestle cures flu"
- Heat sources before nightfall
- Building with prefabs (stone walls, etc.)
- Advanced: Atomic energy, nuclear weapons, atmospheric manipulation

### Player Communication

- Named conditions: "You have radiation sickness", "You have the flu"
- Unknown causes/cures initially
- Players experiment and share findings
- Community knowledge builds over time (Reddit, Discord, in-game)

---

## Survival Systems

### Offline Mechanics

- **No ticking:** Characters don't age, hunger, or get sick while offline
- **Vulnerable:** Can be killed while sleeping
- **Requires safety:** Need secure shelter or trusted allies

### Stats System

**Core stats** (more to be defined):
- Strength
- Agility  
- Constitution (disease/radiation resistance)
- Fortitude (temperature/environmental resistance)

**Stat allocation:**
- Gain points on age-up
- Omega spawns: Baseline ± random variance
- Offspring: Random between baseline and parent max (parents are ceiling)
- Rare exception: Nat 100 equivalent exceeds parents

### Environmental Threats

- Temperature (cold nights, ice ages)
- Radiation (from nuclear events)
- Disease (flu, poison, etc.)
- Starvation
- Potentially: Airborne viruses, oxygen depletion

---

## The World Tree

### Location & Purpose

- **Location:** Central Africa (Omega spawn point)
- **Size:** Large mature tree (not mythically huge)
- **Indestructibility:** Tree itself cannot be destroyed
- **Protected spawn:** 10m radius of indestructible voxels (terrain only)

### Mechanics

**NOT a safe zone:**
- Does not protect from radiation, cold, disease, starvation, or players
- Only prevents terrain destruction (no griefed spawn trap)
- Players can still die at World Tree from any environmental/combat threat

**Planetary Reset Mechanism:**
- If world becomes uninhabitable (nuclear winter, ecological collapse)
- World Tree "wilts" but doesn't die
- When conditions improve, tree becomes healthy again
- Spreads plantlife outward from Central Africa
- Enables planetary recovery and civilization restart

---

## Apocalypse Scenarios

### Extinction Events

Players can trigger through discovery:
- Nuclear winter (split atoms → weapons → overuse)
- Radiation contamination (widespread nuclear damage)
- Ice ages (atmospheric manipulation)
- Ecological collapse (deforestation, pollution)
- Airborne plagues (if implemented)

### Survival of the Fittest

**Evolutionary pressure:**
- Different catastrophes favor different stats
- Nuclear winter: High Constitution survives radiation
- Ice age: High Fortitude survives cold
- 89%+ extinction possible

**Genetic bottleneck:**
- Combat-focused builds die in environmental catastrophes
- Survivors with appropriate stats become breeding population
- Offspring mechanics create adapted bloodlines
- Omega spawns during apocalypse have baseline stats (likely die)

**Meta-game evolution:**
- Pre-apocalypse: Combat stats dominate
- Post-apocalypse: Survivor stats become valuable
- Bloodline sharing on Discord/Reddit
- "Constitution build survived, family code: XK7-2891"
- Adapted population emerges over generations

**Long-term dynamics:**
- Specialized bloodlines valuable during specific catastrophes
- Unused stats drift back toward baseline over generations
- Prevents permanent "master race" scenarios
- Requires active breeding selection to maintain traits

---

## Building & Crafting

### Construction

- Prefab system (stone walls, structures, etc.)
- Must discover/unlock building techniques
- Tech tree gated

### Crafting

- Discovery-based (try combinations, observe results)
- No recipe book initially
- Knowledge shared within settlements
- Documentation mechanics possible (later feature)

---

## Combat & Conflict

### PvP

- Players can kill each other
- Sleeping players vulnerable
- Territory disputes
- Resource competition
- Assassinations (political gameplay)

### Warfare

- Clans/Nations can wage war
- Conquest of settlements
- Territory claims contested by force
- Knowledge theft (conquer city to access tech)

---

## Design Philosophy

### Player Discovery

**Players will NOT know:**
- How stats work (initially)
- What causes diseases
- How to cure ailments  
- That actions can trigger apocalypse
- That offspring inherit stats
- How the World Tree functions
- Detailed game mechanics

**Players WILL discover through:**
- Trial and error
- Observation and experimentation
- Community knowledge sharing
- Catastrophic learning experiences
- Scientific method within settlements
- Reddit/Discord theory-crafting

### No Hand-Holding

- No tutorials
- No tooltips explaining mechanics
- No explicit stat displays (possibly)
- Observable effects only
- Community-driven knowledge base
- Oral traditions and documentation emerge organically

### Long-Term Consequences

- Actions have permanent effects
- Civilizations can collapse
- Extinction events are real
- Knowledge can be lost
- Bloodlines matter
- Geographic advantages/disadvantages matter
- History accumulates

---

## Development Approach

**Iterative build process:**
1. Core voxel engine + rendering
2. Chunk management system
3. Heightmap integration (real Earth data)
4. Basic player movement/interaction
5. Voxel modification + delta saves
6. Multiplayer networking
7. Spawning systems
8. Survival mechanics (stats, aging, conditions)
9. Tech tree framework
10. Social structures (families, clans, settlements)
11. Advanced systems (offspring, apocalypse scenarios, World Tree)

**Build for scale from day one** - architecture must support:
- Massive world size (1:1 Earth)
- Thousands of concurrent players (potentially)
- Long-term persistence (years of playtime)
- Complex emergent gameplay
- Generational progression

---

---

## Technical Decisions

### Core Technology Stack

- **Language:** C++
- **Graphics API:** Vulkan
- **Build System:** CMake
- **Platform Targets:** Windows and Linux
- **Windowing/Input:** GLFW
- **Math Library:** GLM
- **Noise Generation:** FastNoise2 (temporary for prototyping)

### Architecture Decisions

**Voxel Engine:**
- Chunk-based system (size TBD during implementation, likely 16×16×16 or 32×32×32)
- Greedy meshing or optimized cube rendering
- Delta compression for modifications
- On-demand generation with caching

**Networking Model (Future):**
- Authoritative server architecture
- Regional server meshing
  - World divided into large regions (~1000km × 1000km)
  - Each region runs on separate server process
  - Players near borders connect to multiple servers simultaneously
  - Seamless handoff on boundary crossing
- Client-server topology with server-side validation
- Design engine to be network-agnostic initially (plug in later)

**Rendering Optimization:**
- View frustum culling
- Depth culling (don't render deep underground)
- Occlusion culling
- LOD systems (future)
- Chunk streaming based on camera position

---

## Development Roadmap

### Phase 1: Core Voxel Engine (Current)

**Milestone 1 - Proof of Concept:**
- ✅ Window creation with Vulkan context
- ✅ Flying camera (WASD movement, mouse look)
- ✅ Chunk generation (simple noise-based terrain)
- ✅ Voxel rendering (basic meshing)
- ✅ Raycast selection (identify target voxel)
- ✅ Voxel destruction (left-click to remove)
- ✅ Delta tracking (mark modified chunks)

**NOT in Milestone 1:**
- Heightmap integration
- Spherical Earth projection
- Save/load systems
- Player character model
- Multiplayer
- Gameplay systems

### Phase 2: Earth Integration
- Real heightmap data loading (NASA SRTM, GEBCO)
- Spherical coordinate mapping
- Coordinate conversion (voxel ↔ lat/lon)
- Biome systems
- Resource distribution based on real geography

### Phase 3: Player Systems
- Player character (replace flying camera)
- Physics and collision
- Stat system implementation
- Aging mechanics
- Health/survival systems
- Inventory

### Phase 4: Multiplayer Foundation
- Network protocol design
- Client-server synchronization
- Player spawning systems
- Basic chat/communication

### Phase 5: Social Structures
- Family system
- Offspring mechanics
- Clan/settlement code
- Territory claims
- Tech tree framework

### Phase 6: Advanced Systems
- Knowledge/discovery mechanics
- Crafting and building
- Combat systems
- Environmental threats
- Apocalypse scenarios
- World Tree mechanics

### Phase 7: Server Meshing & Scale
- Regional server implementation
- Cross-server communication
- Load balancing
- Server spawning/despawning

---

## Project Structure

```
project-society/
├── CMakeLists.txt
├── README.md
├── copilot-instructions.md
├── docs/
│   └── design-document.md
├── src/
│   ├── main.cpp
│   ├── core/
│   │   ├── Window.cpp/h
│   │   ├── Input.cpp/h
│   │   ├── Camera.cpp/h
│   │   └── Logger.cpp/h
│   ├── renderer/
│   │   ├── VulkanContext.cpp/h
│   │   ├── VulkanRenderer.cpp/h
│   │   ├── Mesh.cpp/h
│   │   └── Shader.cpp/h
│   ├── voxel/
│   │   ├── Chunk.cpp/h
│   │   ├── VoxelWorld.cpp/h
│   │   ├── VoxelData.h
│   │   └── ChunkMesher.cpp/h
│   ├── utils/
│   │   └── Math.cpp/h
│   └── network/ (future)
├── shaders/
│   ├── voxel.vert
│   └── voxel.frag
├── assets/ (future)
│   └── heightmaps/
└── external/
    ├── glfw/
    ├── glm/
    ├── vulkan/
    └── FastNoise2/
```

---

## Open Questions & Future Design

- Exact number and types of stats
- Stat point allocation rates
- Tech tree unlock mechanics (how do players "discover"?)
- Crafting/experimentation UI
- Documentation systems (books, journals)
- Win conditions (if any)
- Chunk size optimization (16³ vs 32³ vs variable)
- Exact region size for server meshing
- Anti-cheat considerations
- Moderation systems
- Knowledge preservation after wipes (if any)

---

**Last Updated:** November 1, 2025  
**Status:** Phase 1 - Core Voxel Engine Development