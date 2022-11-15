#pragma once

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "glm/glm.hpp"
#include "utilities.h"
#include "sceneStructs.h"
#include <thrust/random.h>

using namespace std;

class Scene {
private:
    ifstream fp_in;
    int loadMaterial(string materialid);
    int loadGeom(string objectid);
    int loadCamera();
    int loadObj(const char* fileName);
    int loadMesh(const char* fileName);
    glm::vec3 loadTexture(Geom &geo, const char* fileName);
    int loadTestScene();
public:
    Scene(string filename);
    ~Scene();

    std::vector<Geom> geoms;
    std::vector<Material> materials;

    //std::vector<Material> m_materials;

    std::vector<Material> OBJ_materials;

    RenderState state;

    std::vector<Geom> Obj_geoms;
    
};
