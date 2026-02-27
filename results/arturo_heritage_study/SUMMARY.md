# 🔬 BeamScan Simulation Results

**Author:** ArturoS (example)  
**Description:** Heritage materials from the Sierras de Córdoba: minerals and pigments  
**Generated:** 2026-02-27 21:29 UTC  
**Method:** Highland formula (analytical)

## Beam Settings
- Particle: `e-`
- Momenta: [4.0, 5.0] GeV/c
- Events requested: 5,000

## Predictions

| Material | p (GeV/c) | θ₀ (mrad) | ΔE (MeV) | X₀ (cm) | Thickness |
|----------|-----------|-----------|----------|---------|----------|
| Quartz | 4.0 | **0.877** | 4.4 | 12.29 | 10.0 mm |
| Quartz | 5.0 | **0.702** | 4.4 | 12.29 | 10.0 mm |
| Calcite | 4.0 | **1.058** | 5.6 | 8.7 | 10.0 mm |
| Calcite | 5.0 | **0.846** | 5.6 | 8.7 | 10.0 mm |
| Alumina | 4.0 | **1.181** | 7.9 | 7.1 | 10.0 mm |
| Alumina | 5.0 | **0.945** | 7.9 | 7.1 | 10.0 mm |
| Iron_pigment | 4.0 | **1.787** | 10.5 | 3.3 | 10.0 mm |
| Iron_pigment | 5.0 | **1.429** | 10.5 | 3.3 | 10.0 mm |

## Discrimination Power (at 4.0 GeV/c)

Events needed for 3σ separation:

| | Quartz | Calcite | Alumina | Iron_pigment |
|---|---|---|---|---|
| **Quartz** | — | ✅ 517 | ✅ 207 | ✅ 39 |
| **Calcite** | ✅ 517 | — | ✅ 1,491 | ✅ 69 |
| **Alumina** | ✅ 207 | ✅ 1,491 | — | ✅ 109 |
| **Iron_pigment** | ✅ 39 | ✅ 69 | ✅ 109 | — |

✅ Easy (<5k events) | ⚠️ Moderate (5k–100k) | ❌ Impractical (>100k)

## Figures

![distributions.png](distributions.png)

![classification.png](classification.png)


---
*Generated automatically by BeamScan Highland Calculator*
