//
//  GameManager.cpp
//  BilliardsGL
//
//  Created by 比佐 幸基 on 2016/09/15.
//  Copyright © 2016年 比佐 幸基. All rights reserved.
//

#include "GameManager.hpp"

NS_ENGINE_UTIL
template class StateMachine<Game::GameManager>;
NS_END2


NS_GAME

GameManager::GameManager()
: cameraDefaultPosition(Vector3D::zero())
{ /* do nothing */ }

GameManager::~GameManager() { /* do nothing */ }

void GameManager::initialize() {
  // set background color
  glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
  
  shotButton = new UIButton(Point2D(0.0f, 0.0f), Vector2D(640.0f, 640.0f), ETex::None, UI_ALIGNMENT::None, Color::zero());
  shotButton->setHandler(this);
  (ObjectManager::instance()).registerObject(shotButton);
}

void GameManager::awake() {
  stateMachine = new StateMachine<GameManager>;
  State<GameManager>* initState = new InitState(this);
  stateMachine->addState(initState);
  State<GameManager>* shotState = new ShotState(this);
  stateMachine->addState(shotState);
  State<GameManager>* rollState = new RollState(this);
  stateMachine->addState(rollState);
  
  stateMachine->changeState(static_cast<StateId>(EGameManagerState::Init));
}

void GameManager::start() { /* do nothing */ }


void GameManager::update(GLfloat deltaTime) {
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::forward() * sinf(glfwGetTime() * 3.0f));
//  mainCamera->translateTo(cameraDefaultPosition + Vector3D::up()*30.0f + Vector3D::down() * glfwGetTime());
}

void GameManager::destroy() {
  ballManager = nullptr;
  SAFE_DELETE(boardCtrl);
}


void GameManager::onButtonDown() {
  std::cout << "button down" << std::endl;
  ballManager->shotWhiteBall();
}
void GameManager::onButtonDownRepeat() {
  //  std::cout << "button down repeat" << std::endl;
}
void GameManager::onButtonUp() {
  std::cout << "button up" << std::endl;
}




/* -- states ------- */

// Init
GameManager::InitState::InitState(GameManager* _owner) : State<Game::GameManager>(_owner) { /* do nothing */ }
GameManager::InitState::~InitState() { owner = nullptr; }
void GameManager::InitState::enter() {
  owner->mainCamera = (PerspectiveCameraController*)(CameraManager::instance()).getMainCamera();
  owner->mainCamera->translateTo(Vector3D(0.0f, 100.0f, 0.0f));
  owner->cameraDefaultPosition = owner->mainCamera->getPosition();
  
  owner->ballManager = &(BallManager::instance());
  owner->ballManager->initialize();
  (ObjectManager::instance()).registerObject(owner->ballManager);
  
  owner->boardCtrl = new BoardController(Transform::identity());
  (ObjectManager::instance()).registerObject(owner->boardCtrl);
  owner->boardCtrl->setupStage();
  
  owner->stateMachine->changeState(static_cast<StateId>(EGameManagerState::Shot));
}
void GameManager::InitState::execute(GLfloat deltaTime) { /* do nothing */ }
void GameManager::InitState::exit() { /* do nothing */ }

// Shot
GameManager::ShotState::ShotState(GameManager* _owner) : State<Game::GameManager>(_owner) { /* do nothing */ }
GameManager::ShotState::~ShotState() { owner = nullptr; }
void GameManager::ShotState::enter() { std::cout << "shot" << std::endl; }
void GameManager::ShotState::execute(GLfloat deltaTime) { /* do nothing */ }
void GameManager::ShotState::exit() { /* do nothing */ }

// Roll
GameManager::RollState::RollState(GameManager* _owner) : State<Game::GameManager>(_owner) { /* do nothing */ }
GameManager::RollState::~RollState() { owner = nullptr; }
void GameManager::RollState::enter() { /* do nothing */ }
void GameManager::RollState::execute(GLfloat deltaTime) { /* do nothing */ }
void GameManager::RollState::exit() { /* do nothing */ }

NS_END
