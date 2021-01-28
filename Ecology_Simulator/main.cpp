#include <iostream>
#include <map>
#include <typeindex>
#include <memory>
#include <thread>

#include "main.h"
#include "ComponentManager.h"
#include "Simulation.h"
#include "MovementSystem.h"
#include "RenderSystem.h"
#include "TargettingSystem.h"

int main() {

    //testSetComponent();

    std::unique_ptr<Simulation> sim = std::make_unique<Simulation>(1280, 720);

    std::random_device rd;
    std::default_random_engine e(rd());

    // Test sprites
    //for (int i = 0; i < 1000; i++) sim.get()->getEntityManager()->generateTestSprite(100.0f, 300.0f, (float)(e() % 360), 16.0f);

    sim.get()->getEntityManager()->generateTestSprite(100.0f, 300.0f, 15.0f, 8.0f);
    sim.get()->getEntityManager()->generateTestSprite(400.0f, 200.0f, 250.0f, 8.0f);
    /*sim.get()->getEntityManager()->generateTestSprite(800.0f, 200.0f, 250.0f, 2.0f);
    sim.get()->getEntityManager()->generateTestSprite(1000.0f, 600.0f, 290.0f, 4.0f);
    sim.get()->getEntityManager()->generateTestSprite(700.0f, 400.0f, 80.0f, 4.0f);
    sim.get()->getEntityManager()->generateTestSprite(900.0f, 370.0f, 45.0f, 4.0f);*/

    // Main loop
    while (!glfwWindowShouldClose(sim.get()->getWindow())) {

        updateEntityTargets(sim.get());
        moveEntities(sim.get());
        renderEntities(sim.get());

        glfwPollEvents();
    }

}