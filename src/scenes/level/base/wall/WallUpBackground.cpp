#include "WallUpBackground.hpp"

using namespace godot;

WallUpBackground::WallUpBackground() {}

WallUpBackground::~WallUpBackground() {}

void WallUpBackground::_bind_methods() {
}
void WallUpBackground::_process(double delta) {

}

void WallUpBackground::_ready() {
    this->setup();
}

void WallUpBackground::setup(){
    this->setupMaterialPlaneMesh();
    this->mesh = memnew(MeshInstance3D());
    this->mesh->set_mesh(this->planeMesh);
    this->mesh->set_rotation(Vector3(90, 0, 0));
    this->mesh->set_visible(true);
    this->add_child(this->mesh);
}

void WallUpBackground::setPlaneMeshSize(Vector2 vector){
    this->planeMesh->set_size(vector);
}

void WallUpBackground::setupMaterialPlaneMesh(){
    this->planeMesh = memnew(PlaneMesh());
    this->setPlaneMeshSize(Vector2(15, 2));
    this->materialPlaneMesh = memnew(StandardMaterial3D());
    ResourceLoader* loader = ResourceLoader::get_singleton();
    this->texture = loader->load("res://assets/levels/backgrounds/background_2.png");
    this->materialPlaneMesh->set_texture(BaseMaterial3D::TextureParam::TEXTURE_ALBEDO, this->texture );
    this->materialPlaneMesh->set_transparency(BaseMaterial3D::Transparency::TRANSPARENCY_ALPHA);
    this->planeMesh->set_material(this->materialPlaneMesh);
}