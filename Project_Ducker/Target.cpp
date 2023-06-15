#include "Target.h"

bool Target::Side()
{
	return LeftRight;
}

Target::Target(sf::VideoMode vMode)
{
	this->posXY.x = vMode.width;
	this->posXY.y = vMode.height;

	this->initTexture();
	this->initSprite();
	
	this->spawnTarget();

	//this->targetSide();

	//this->initTarget();

	//this->updateTarget();
	//this->target.setPosition(XY);
}

Target::~Target()
{
	
}

sf::FloatRect Target::getBounds()
{
	return this->sprite.getGlobalBounds();
}

sf::Vector2f Target::getPosition()
{
	return this->sprite.getPosition();
}


void Target::initTexture()
{
	if (!this->texture.loadFromFile("Textures/BirdSpriteBig.png"))
	{
		std::cout << "Nie zaladowano tekstury \n";
	}
}

void Target::initSprite()
{
	//this->target.setPosition(100.f, 100.f);
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 160, 160, 160);
	this->sprite.setTextureRect(this->currentFrame);
}

void Target::initAnimation()
{
	this->animationTimer.restart();
}

//void Target::initTarget()
//{
//	/*this->points = 0;
//	this->targetSpawnTimer = 10.f;
//	this->targetLastSpawn = 0;
//	this->maxTargets = 5;*/
//
//	//this->target.setScale(0.5f, 0.5f);
//	//this->target.setPosition(100.f, 100.f);
//
//	//renderTarget();
//}

void Target::renderTarget(sf::RenderTarget* target)
{
	//std::cout << "pozycja x: " << this->target.getPosition().x << " pozycja y: " << this->target.getPosition().y << "\n";
	target->draw(this->sprite);
}

void Target::updateMovement()
{	
	//this->target.move(5.f, 0.f);
		
	if (LeftRight == true)
	{
		this->sprite.setScale(-0.5f, 0.5f);
		this->sprite.move(5.f, 0.f);
	}

	else
	{
		this->sprite.setScale(0.5f, 0.5f);
		this->sprite.move(-5.f, 0.f);
	}

}


void Target::updateAnimation()
{
	if (this->animationTimer.getElapsedTime().asMilliseconds()>= 200.f)
	{
		this->currentFrame.left += 160.f;
		if (this->currentFrame.left >= 1120.f)
		{
			this->currentFrame.left = 0;
		}
		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void Target::update()
{
	this->updateMovement();
	this->updateAnimation();
}

void Target::spawnTarget()
{
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, this->posXY.y - sprite.getGlobalBounds().height);

	int strona = dist(gen);

	float zmienna = dist(gen);

	if (strona % 2)
	{
		LeftRight = true;
		this->sprite.setPosition(0.f - this->sprite.getGlobalBounds().width, zmienna);
	}

	else
	{
		LeftRight = false;
		this->sprite.setPosition(posXY.x, zmienna);
	}

	//this->target.setPosition(0.f, zmienna);
}
 



//void Target::targetSide()
//{
//	this->target.setPosition(posXY);
//}

//void Target::spawnTarget()
//{
//	this->initTexture();
//	this->initSprite();
//	
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<int> dist(0, this->wielkososcOknaY - this->target.getGlobalBounds().height);
//
//	float zmienna = dist(gen);
//
//	this->target.setPosition(
//		static_cast<float>(static_cast<int>(0 /*- this->target.getGlobalBounds().width*/)),
//		static_cast<float>(zmienna)
//	);
//
//	this->targets.push_back(this->target);
//
//	std::cout << this->targets.size();
//}

//
//void Target::createTarget()
//{
//	this->initTarget();
//
//	this->targetLastSpawn = 0;
//
//	if (this->targets.size() < this->maxTargets)
//	{
//		if (this->targetSpawnTimer >= this->targetLastSpawn)
//		{
//			//this->spawnTarget();
//			this->targetLastSpawn = 0.f;
//		}
//
//		else
//		{
//			this->targetLastSpawn += 1;
//		}
//	}
//
//	//while(maxTargets > this->targets.size() && this->targetLastSpawn < this->targetSpawnTimer)
//	//{
//	//	this->initTexture();
//	//	this->initSprite();
//	//	
//	//	std::random_device rd;
//	//	std::mt19937 gen(rd());
//	//	std::uniform_int_distribution<int> dist(0, this->wielkososcOknaY - this->target.getGlobalBounds().height);
//
//	//	float zmienna = dist(gen);
//
//	//	this->target.setPosition(
//	//		static_cast<float>(static_cast<int>(0 - this->target.getGlobalBounds().width)),
//	//		static_cast<float>(zmienna)
//	//	);
//
//
//	//	this->targetLastSpawn += 1;
//	//	this->targets.push_back(this->target);
//
//	////std::cout << this->targets.size();
//	//}
//	
//	//float zmienna = static_cast<float>(rand() % this->sizeWindow.y + this->target.getGlobalBounds().height);
//	
//	
//	
//
//	//std::cout << "pozycja x: " << target.getPosition().x << " pozycja y: " << target.getPosition().y << "\n";
//
//}



//
//void Target::renderTarget(sf::RenderTarget* target)
//{
//	for (auto& t : this->targets)
//	{
//		target->draw(this->target);
//	}
//}
//
//
//void Target::createTarget()
//{
//	//GLOBAL BOUNDSY DO ZROBIENIA
//	std::random_device rd; 
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<int> dist(0, this->sizeWindow.y - this->target.getGlobalBounds().height);
//
//	float zmienna = dist(gen);
//
//	//float zmienna = static_cast<float>(rand() % this->sizeWindow.y + this->target.getGlobalBounds().height);
//	//std::cout << "Wsp: " << zmienna << std::endl;
//	
//	this->target.setPosition(
//		static_cast<float>(static_cast<int>(this->sizeWindow.x)),
//		static_cast<float>(/*rand() % (this->sizeWindow.y)*/zmienna)
//	);
//
//	//Spawn
//	this->targets.push_back(&target);
//	std::cout << "Cele: " << this->targets.size() << "\n";
//}
//
//
//void Target::updateTarget()
//{
//	if (this->targets.size() < this->maxTargets)
//	{
//		if (this->targetSpawnTimer >= this->targetSpawnTimerMax)
//		{
//			this->createTarget();
//			this->targetSpawnTimer = 0.f;
//		}
//
//		else
//			this->targetSpawnTimer += 1.f;
//	}
//
//	for (auto &s: this->targets)
//	{
//		s->move(-5.f, 0.f);
//	}
//}
