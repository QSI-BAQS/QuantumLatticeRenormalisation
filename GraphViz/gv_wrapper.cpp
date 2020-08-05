
#include <string>
#include "gv_wrapper.hpp"
#include <graphviz/gvc.h>

// From https://stackoverflow.com/questions/45225761/generate-image-of-graphviz-graph-given-dot-text-c/51990640
bool saveImageGV(std::string file_path) {
    GVC_t *gvc;
    Agraph_t *g;
    FILE *fp;
    gvc = gvContext();
    fp = fopen((file_path + ".dot").c_str(), "r");
    g = agread(fp, 0);
    gvLayout(gvc, g, "dot");
    gvRender(gvc, g, "png", fopen((file_path + ".png").c_str(), "w"));
    gvFreeLayout(gvc, g);
    agclose(g);
    return (gvFreeContext(gvc));
}