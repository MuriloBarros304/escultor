#ifndef VOXEL_H
#define VOXEL_H

/// @brief Tipo estruturado para representar um voxel
struct Voxel {
    float r, g, b;  // Cores
    float a;        // Transparência
    bool show;      // Incluído ou não
};
#endif  // VOXEL_H