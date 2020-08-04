
#ifndef STRUCTURE_DATA_HPP
#define STRUCTURE_DATA_HPP

// Structural data for unit cell shapes.
// "Handle" vertices are those who will be Y-measured to connect sides of the unit cell to external faces.
// they are dangling from the main structure.
struct unit_cell {
    std::list<vec3d> coordinates;
    edge_io_list_t edges;
    vertex_ind num_vertices;
    vertex_list_t handle_vertices;
};

class structure_data {
public:
    const unit_cell raussendorf_uc = {
            .coordinates = {
                    {}
            },
            .edges = {
                    {0,  2},
                    {1,  2},
                    {2,  3},
                    {2,  4},
                    {0,  6},
                    {1,  8},
                    {3,  9},
                    {4,  11},
                    {5,  6},
                    {5,  8},
                    {6,  7},
                    {7,  9},
                    {8,  10},
                    {9,  12},
                    {10, 11},
                    {11, 12},
                    {6,  13},
                    {8,  14},
                    {9,  16},
                    {11, 17},
                    {13, 15},
                    {14, 15},
                    {15, 16},
                    {15, 17}
            },
            .num_vertices = 18,
            .handle_vertices = {1, 2, 3, 4} //TODO handles for R-cell
    };
};


#endif //STRUCTURE_DATA_HPP
