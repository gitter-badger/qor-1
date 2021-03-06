#include "BasicState.h"
#include "BasicPartitioner.h"
#include "IPartitioner.h"
#include "Input.h"
#include "Qor.h"
#include "TileMap.h"
#include "Sprite.h"
#include <glm/glm.hpp>
#include <cstdlib>
#include <chrono>
#include <thread>
//#include <OALWrapper/OAL_Funcs.h>
using namespace std;
using namespace glm;

BasicState :: BasicState(Qor* engine):
    m_pQor(engine),
    m_pInput(engine->input()),
    m_pRoot(make_shared<Node>()),
    m_pPipeline(engine->pipeline())
{
    m_DetailShader = m_pPipeline->load_shaders({"detail"});
}

void BasicState :: preload()
{
    //m_pTemp = make_shared<Node>();
    //m_pRoot->add(m_pTemp);
    m_pCamera = make_shared<Camera>(m_pQor->resources(), m_pQor->window());
    m_pRoot->add(m_pCamera->as_node());
    m_pLight = make_shared<Light>();
    m_pRoot->add(m_pLight);
    //m_pPipeline = make_shared<Pipeline>(
    //    m_pQor->window(),
    //    m_pQor->resources(),
    //    m_pRoot,
    //    m_pCamera
    //);
    
    //m_pRoot->add(m_pMap = make_shared<TileMap>(
    //    //"theGraveyard.tmx",
    //    "modern.tmx",
    //    m_pQor->resources()
    //));

    // spawn a sprite character
    //m_pSprite = make_shared<Sprite>(
    //    "actor.json",
    //    m_pQor->resources(),
    //    "fetusMaximus"
    //);
    //m_pSprite->mesh()->set_geometry(m_pMap->tilted_tile_geometry());

    //m_pSprite->set_all_states({0,1});
    //m_pRoot->add(m_pSprite);

    //m_pPlayer = make_shared<PlayerInterface2D>(
    //    m_pQor->session()->profile(0)->controller(),
    //    m_pSprite,
    //    m_pQor->resources()
    //);
    //m_pPlayer->plug();

    ////m_pCamera->move(glm::vec3(0.0f, 0.0f, -150.0f));
    ////glm::value_ptr(*m_pCamera->matrix())[5] = -1.0f;
    ////glm::value_ptr(*m_pCamera->matrix())[10] = -1.0f;
    ////m_pCamera->pend();
    
    //m_pCamera->track(m_pPlayer->crosshair()->as_node());
    ////m_pCamera->focal_offset(glm::vec3(-200.0f, -200.0f, 0.0f));

    // test loading screen:
    //this_thread::sleep_for(chrono::seconds(3));
}

BasicState :: ~BasicState()
{
    m_pPipeline->partitioner()->clear();
}

void BasicState :: enter()
{
}

void BasicState :: logic(Freq::Time t)
{
    if(m_pInput->key(SDLK_ESCAPE))
        m_pQor->quit();

    float speed = 1000.0f * t.s();
    //if(m_pInput->key(SDLK_r))
    //{
    //    *m_pCamera->matrix() = glm::scale(
    //        *m_pCamera->matrix(), glm::vec3(1.0f-t.s(), 1.0f-t.s(), 1.0f)
    //    );
    //    m_pCamera->pend();
    //}
    //if(m_pInput->key(SDLK_w))
    //{
    //    *m_pCamera->matrix() = glm::scale(
    //        *m_pCamera->matrix(), glm::vec3(1.0f+t.s(), 1.0f+t.s(), 1.0f)
    //    );
    //    m_pCamera->pend();
    //}

    if(m_pInput->key(SDLK_UP))
        m_pCamera->move(glm::vec3(0.0f, -speed, 0.0f));
    if(m_pInput->key(SDLK_DOWN))
        m_pCamera->move(glm::vec3(0.0f, speed, 0.0f));
    
    if(m_pInput->key(SDLK_LEFT))
        m_pCamera->move(glm::vec3(-speed, 0.0f, 0.0f));
    if(m_pInput->key(SDLK_RIGHT))
        m_pCamera->move(glm::vec3(speed, 0.0f, 0.0f));

    m_pRoot->logic(t);
}

void BasicState :: render() const
{
    m_pPipeline->override_shader(PassType::NORMAL, m_DetailShader);
    m_pPipeline->render(m_pRoot.get(), m_pCamera.get());
}

