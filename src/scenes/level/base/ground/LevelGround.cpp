#include "LevelGround.hpp"

using namespace godot;

LevelGround::LevelGround() {}

LevelGround::~LevelGround() {}

void LevelGround::_bind_methods() {
}
void LevelGround::_process(double delta) {

}

void LevelGround::_ready() {
    this->setup();
}

void LevelGround::setup(){
    this->setupPlaneMesh();
    this->setupArea3d();
}

void LevelGround::setupPlaneMesh(){
    this->mesh = memnew(MeshInstance3D);
    this->planeMesh = memnew(PlaneMesh);
    this->planeMesh->set_size(Vector2(15,2));
    this->materialPlaneMesh = memnew(StandardMaterial3D);
    ResourceLoader* loader = ResourceLoader::get_singleton();
    this->texture = loader->load("res://assets/levels/1/ground/ground_4.png");
    this->materialPlaneMesh->set_texture(BaseMaterial3D::TextureParam::TEXTURE_ALBEDO, this->texture );
    this->materialPlaneMesh->set_transparency(BaseMaterial3D::Transparency::TRANSPARENCY_ALPHA);
    this->planeMesh->set_material(this->materialPlaneMesh);
    this->mesh->set_mesh(this->planeMesh);
    this->add_child(this->mesh);
}

void LevelGround::setupArea3d(){
    this->area3d = memnew(Area3D);
    this->checkpoint = memnew(CollisionShape3D);
    this->area3d->add_child(this->checkpoint);
    this->add_child(this->area3d);
}